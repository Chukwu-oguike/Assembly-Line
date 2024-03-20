#include "Package.h"
#include "LinkedTypeQueue.h"
#include "Worker.h"
#include "AssemblyLine.h"
#include "factory.h"

//default construtor initializes numofAssemblyLines

Factory::Factory(int nAsslines, double* wRate)
{
  numOfAssemblyLines = nAsslines;
  
  AssmbLine  = new AssemblyLine[nAsslines];
  
  setAworkerWorkRate(wRate);
  //set the rate of the only worker  

  factoryClock = 0;
}

//function simulates the factory
int Factory::run()
{
  get_data();
  //gets data from commandline
  //and stores in a temporary queue
  
 int i;
 
  do
   { 
     
     if(factoryClock == bufferQueue.frontOfQueue().getArrivalTime())
     {

        i = dispatcher.findBestLine(AssmbLine, numOfAssemblyLines);
        //find the right assembly line
       
        simulateTime(i);
        //function uses a mathematical relation I discovered
        // to set the waiting times of all packages depending on 
        // the time frame of the previous package being processed
     
        assgnPackageToWokers();
        //assign first package in the assemblyline queue to a worker
     }
       
     setAssblWorkersFree();
     
     incrementFactoryClock();
     //increments the FactoryClock
    
     //when the buffer queue is empty some packages might be left 
     //in the assemblyline queue
     if(bufferQueue.isQueueEmpty())
     {
	 int k;
	 
         //the assembly line queue will be empty when one last package is still
         //being processed
	 int j = findMaxQueueSize() + 1;
	 
	 while(j > 0)
	 {   
	      assgnPackageToWokers();
	   
	      for(k = 0; k < numOfAssemblyLines; k++)
	      {
	         printFactoryOutPut(k);
		      
	         AssmbLine[k].soleWorker.setWorkerFree();
	      }
	     
	      j--;
	 }
	      
     }
   }
  
  while(!bufferQueue.isQueueEmpty());   
  
  return 0;
}


//function gets data from the command line
//and stores this in a queue
void Factory::get_data()
{
       string junk;
       
       int arlvTime;
       
       int nmUnits;
       
       string ordNumb;
       
       while (cin >> junk)
	 //stores the info from the command line into a package
       {
	 cin>>junk >>junk >> ordNumb >>junk>>nmUnits >>junk >>junk >>
	 junk >>junk >>arlvTime;
	 
	 
	 bufferPackage.setPackageInfo(ordNumb, nmUnits, arlvTime);
	 //initializes a package
	 
	 bufferQueue.pushToQueue(bufferPackage);
	 //stores this initialized package in the bufferQueue
       }
}


// set the work rate of workers in all assembly lines
// function needs to be modified to accommodate assemblylines and more worker   
void Factory::setAworkerWorkRate(double* ra_te)
{
  int i;
  
  for(i = 0; i < numOfAssemblyLines; i++)
  { 
     AssmbLine[i].setProRateOfWOrkers(ra_te, i);
  }
  
}

int  Factory::findMaxQueueSize()
{
    int i;
    
    int tempSize = 0;
 
    for(i = 0; i < numOfAssemblyLines; i++)
    {
       if(AssmbLine[i].wQueue.getQueueSize() >= tempSize)
       {
         tempSize = AssmbLine[i].wQueue.getQueueSize();
       }
    }
    
    return tempSize;
}

// puts all the packages into the queue of an assemblyline
// function needs to be modified to accommodate assemblylines and more worker
void Factory::pushPackageToAssQueue(int id)
{ 
   
       if (!bufferQueue.isQueueEmpty())
       {
          Package newP = bufferQueue.frontOfQueue();
    
          AssmbLine[id].addPackageToQueue(newP);
          //move package from buffer queue to the front of the queue
    
          bufferQueue.popFromQueue();
          //decrement the bufferqueue
       } 
}

//assigns packages to workers
// function needs to be modified to accommodate assemblylines and more worker
void Factory::assgnPackageToWokers()
{  
    int i;
     
    for(i = 0; i < numOfAssemblyLines; i++)
    {
       if (!(AssmbLine[i].wQueue.isQueueEmpty()) && 
	 AssmbLine[i].soleWorker.isWorkerFree())  
       {
          AssmbLine[i].setWorkerBusy(0,AssmbLine[i].wQueue.frontOfQueue());
          //assign package to soleWorker
      
          AssmbLine[i].soleWorker.setProcessingTime();
          // set the processing time of the package 
      
          AssmbLine[i].wQueue.popFromQueue();
          //remove package from queue once it has been assigned to worker
	 
       }
    }
}

void Factory::setAssblWorkersFree()
{
    int i;
  
    for(i = 0; i < numOfAssemblyLines; i++)
    {
      
       if(AssmbLine[i].soleWorker.getClockTime() == 0)
       {
          printFactoryOutPut(i);   
          
	  AssmbLine[i].soleWorker.setWorkerFree(); 
       }
        
       else
       {
	 if(!AssmbLine[i].soleWorker.isWorkerFree())
	 {
            AssmbLine[i].decrementClock();
	 }
       }
       
    }
}

//this function sets the waiting time of incoming
//packages depending on the time frame in which they arrive
void Factory::simulateTime(int iD)
{
  int nextPackageTime = bufferQueue.frontOfQueue().getArrivalTime();
  
  int totalTimeFrame = findTimeFrame(iD);
  
  if(totalTimeFrame == 0)
  {
    pushPackageToAssQueue(iD);
  }
  
  else if(nextPackageTime <= totalTimeFrame)
    //if arrival time of the next package falls 
    //within the time frame of the current package
    // set its wating time
  {
    int waitTime =  (totalTimeFrame - nextPackageTime);
    // I discovered that the waiting times
    //of packages that fall within the time frame of 
    //other packages can be determined by this formula
    
    bufferQueue.setWaitingTime(waitTime);
    
    AssmbLine[iD].addPackageToQueue(bufferQueue.frontOfQueue());
    //transfers package to assemblyline queue
        
    bufferQueue.popFromQueue();
  }
  
  else
    //if the next package doesn't fall within the processing time interval
    // of the current package it doesn't have to wait.
  {
    AssmbLine[iD].addPackageToQueue(bufferQueue.frontOfQueue());
    
    bufferQueue.popFromQueue();
  }
  
}

int Factory::findProcessingTime(const Package& newP, int assId)
{
  double pTime = 
  ceil((double)newP.getNumberOfUnits() 
  / (double)AssmbLine[assId].soleWorker.getProcessingRate());
  
  return (int)pTime;
}

int Factory::findTimeFrame(int inDx)
{
    int pt, wt, at, su_m;
    
    if(AssmbLine[inDx].wQueue.isQueueEmpty())
    {
         pt = AssmbLine[inDx].soleWorker.getProcessingTime();
         //gets the processing time of the current package
    
         wt = AssmbLine[inDx].soleWorker.getCurrentPackageWaitTime();
         //gets the waiting time of the current package

         at = AssmbLine[inDx].soleWorker.getCurrentPackageArrivalTime();
         // gets the arrival time of the current package
 
	 su_m = at + pt + wt;
         //su_m stores the time frame of the current package 
    }
      
    else
    {
  
         pt = findProcessingTime(AssmbLine[inDx].wQueue.rearOfQueue(), inDx);
         //gets the processing time of the last package on the assemblyline queue
          
         wt = AssmbLine[inDx].wQueue.rearOfQueue().getWaitingTime();
         //gets the waiting time of the last package on the assemblyline queue
          
         at = AssmbLine[inDx].wQueue.rearOfQueue().getArrivalTime();
         // gets the arrival time of the last package on the assemblyline queue
          
         su_m = at + pt + wt;
         //su_m stores the time frame of the current package  
       
    }
    
    return su_m;
}

void Factory::incrementFactoryClock()
{
   factoryClock++;
}

void Factory::printFactoryOutPut(int idd)
{
  if(!AssmbLine[idd].soleWorker.isWorkerFree())
  {
     AssmbLine[idd].soleWorker.printWorkerThrghPut();
     cout<<" from "<<(idd + 1)<<endl;
  }
}

//function gets rid of the bufferQueue
Factory::~Factory()
{
  bufferQueue.destroyQueue();
  
  delete [] AssmbLine;
}
