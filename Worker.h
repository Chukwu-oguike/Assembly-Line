//class that serves as a model for workers

#include <iostream>
#include <cstdlib>
#include <cmath>
#include "Package.h"
#ifndef W_ORKER
#define W_ORKER

using namespace std;

class Worker
{
  public:
    
    Worker();
    //default constructor
    //initializes stat-us to free, processingTime to 0 a
    
    void setCurrentPackage(const Package& newPackage);
    //function assigns a new package to currentPackage
    //precondition: newPackage.ArrivalTime > 0 && newPackage.NumberOfUnits > 0
    //postcondition: currentPackage = newPackage
    
    void setProcessingTime();
    //function set the processing time of a package
    //postcondition: processingTime = processingRate * currentPackage.getNumberOfUnits()
    
    
    
    int getProcessingTime();
    //function returns the processingTime
    
    void setWorkerBusy();
    //determines if worker is busy
    
    void setWorkerFree();
    //sets worker free
    
    void decrementClock();
    //decrements the clock (the clock represents the processing time
    
    int getClockTime();
    //returns clocktime
    
    bool isWorkerFree();
    //checks if worker is free so another package can
    //be assigned to the worker
    
    double getProcessingRate();
    //gets the processing time of the current Package
    
    void setProcessingRate(double R);
    //function set the processing rate
    //postcondition: processingRate = R
    
    int getCurrentPackageArrivalTime();
    //fucntion returns the arrival time of currentPackage
    
    int getCurrentPackageWaitTime();
    //function returns the waiting time of currentPackage
    
    int getCurrentPackageNumUnits();
    
    void printWorkerThrghPut();
    //function prints the time a package arrives and departs
    
  private:
    
    string statu_s;
 
     
    Package currentPackage;
    //stores the the package being processed by a worker
    
    int processingTime;
    //stores the time it takes a worker to process a package

    double processingRate;
    // stores the working rate of a worker
    
    int clock;
};

#endif
