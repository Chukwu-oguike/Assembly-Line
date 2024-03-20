#include "Worker.h"
#include "Package.h"
#include "LinkedTypeQueue.h"

//default constructor
//initializes stat-us to free, processingTime to 0 a
Worker::Worker()
{   
   processingTime = 0;
   
   statu_s = "FREE";
   
   clock = 0;
}


//function assigns a new package to currentPackage
//precondition: newPackage.ArrivalTime > 0 && newPackage.NumberOfUnits > 0
//postcondition: currentPackage = newPackage
void Worker::setCurrentPackage(const Package& newPackage)
{
  if(newPackage.getArrivalTime() >= 0 && newPackage.getNumberOfUnits() >= 0)
    // if the newPackage is valid
  {
    currentPackage = newPackage;//assign package to currentPackage
  }
  
  else
   {
     cerr<<"arrival time and number of units of package must be "<<
     "non-negative"<<endl;
     //output error message
     
     exit(1);
     //exit program
   }
}

//function set the processing time of a package
//postcondition: processingTime = 
//processingRate * currentPackage.getNumberOfUnits()
void Worker::setProcessingTime()
{
  double initialprocessingTime = 
  ceil((double)currentPackage.getNumberOfUnits() / (double) processingRate);
  
  processingTime = (int)initialprocessingTime;
  //ceiling function prevents program from dealing with doubles
  
  clock = processingTime;
}

//function set the processing rate
//postcondition: processingRate = R
void Worker::setProcessingRate(double R)
{
  processingRate = R;
}

//fucntion returns the arrival time of currentPackage
int Worker::getCurrentPackageArrivalTime()
{
  return currentPackage.getArrivalTime();
}

void Worker::setWorkerBusy()
{
  statu_s = "BUSY"; 
}

bool Worker::isWorkerFree()
{
  return(statu_s == "FREE");
}

void Worker::decrementClock()
{
  clock--;
}

int Worker::getClockTime()
{
 return clock; 
}

void Worker::setWorkerFree()
{
  statu_s = "FREE";
}

//function returns the processingTime
int Worker::getProcessingTime()
{
  return processingTime;
}

double Worker::getProcessingRate()
{
  return processingRate;
}

//function returns the waiting time of currentPackage
int Worker::getCurrentPackageWaitTime()
{
  return currentPackage.getWaitingTime();
}

int Worker::getCurrentPackageNumUnits()
{
  return currentPackage.getNumberOfUnits();
}

//function prints the time a package arrives and departs
void Worker::printWorkerThrghPut()
{
      cout<<"Package order number "<<
         currentPackage.getOrderNumber()<<" with "<<
         currentPackage.getNumberOfUnits()<<" units arrived at time "<<
         getCurrentPackageArrivalTime()<<" and left at time "<<
         getCurrentPackageArrivalTime()
         + getCurrentPackageWaitTime() + getProcessingTime();  
}



