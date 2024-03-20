#include"AssemblyLine.h"
#include "Package.h"
#include "LinkedTypeQueue.h"
#include "Worker.h"

//default constructor 
AssemblyLine::AssemblyLine()
{
    numberOfWorkers = 1;// initialize number of workers
    workers = NULL;
}


//function adds packages to wQueue (every assemblyline has it's own queue)
void AssemblyLine::addPackageToQueue(const Package& cPackage)
{
  
  //check if the packages have a valid arrival time and numberOfUnits
  if(cPackage.getArrivalTime() >= 0 && cPackage.getNumberOfUnits() >= 0)
  {
    wQueue.pushToQueue(cPackage);// if valid push package to queue
  }
  
  else
   {
     cout<<"arrival time and number of units of"<<
     " package must be non-negative"<<endl;
     
     exit(1);
   }
    
}

//returns the number of workers in an assemblyline
//(necessary when there is more than one worker)
int AssemblyLine::getNumOfWorkers()
{
  return numberOfWorkers;
}

void AssemblyLine::decrementClock()
{
  soleWorker.decrementClock();
}

void AssemblyLine::addWorkers(int N)
{ 
  if (workers != NULL)//prevents segmentation faults
    {
      delete [] workers;
      
      workers = new Worker[N];
      
      numberOfWorkers = N;
    }
  //update number of workers
  
}
//sets the worker with index (workerID) busy and assigns
//new_Package to this worker or assigns the solWorker the package if 
//one worker is used
void AssemblyLine::setWorkerBusy(int workerID, const Package& new_Package)
{
  int wID = workerID;
  
  if(wID == 0)
    //if numberOfWorkers = 0, assign package to soleWorker
  { 
      soleWorker.setCurrentPackage(new_Package);//soleWorker takes package
   
      soleWorker.setWorkerBusy();

  }
  
  else// if there are numerous workers
  {
     if(wID < numberOfWorkers)
       //check if the workerID is greater than the number of workers
     {
    
      workers[wID].setCurrentPackage(new_Package);

  
     }
     
     else 
     {
       cerr<<"workerID must be less than the number"<<
       " of workers in the assemblyline";
       // print out error message
       
       exit(1);
       //exit program
       
     }
     
  }
 
}

//sets the work rate of all workers
void AssemblyLine::setProRateOfWOrkers(double* rList, int indx)
{
  if(numberOfWorkers == 1)//if only one worker is used
  {
    if (workers != NULL)//prevents segmentation faults
    {
      delete [] workers;
      workers = NULL;
    }
    // get read of dynamic memory and use soleWorker
    
    soleWorker.setProcessingRate(rList[indx]);
  }
  
  else//if more workers are used
  {
    soleWorker.setProcessingRate(rList[0]);
    //since this is the prime worker used
    //always make sure it hs a working rate
    
    int i;
  
    for(i = 0; i < numberOfWorkers; i++)
    {
       workers[i].setProcessingRate(rList[i]);
       //set the work rate of all workers
    }
  
  }
}

//destroy the list of workers created
//useful when more than one workers are used
AssemblyLine::~AssemblyLine()
{
  wQueue.destroyQueue();

  if (workers != NULL) //prevents segmentation faults
  {
    delete [] workers;
    workers = NULL;
  }
    
}