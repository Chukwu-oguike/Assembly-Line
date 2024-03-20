//class that coordinates the activities of the factory


//head class that runs the factory

#include <iostream>
#include <cstdlib>
#include "Package.h"
#include "LinkedTypeQueue.h"
#include "Worker.h"
#include "AssemblyLine.h"
#include "scheduler.h"

#ifndef F_ACTORYTIME
#define F_ACTORYTIME

using namespace std;

//struct to serve as data structure for the list of assemblylines

class Factory
{
  public:
   
    Factory(int nAsslines, double* wRate);
    //construtor takes in the number of assemblylines
    //and the work rate of the assemblylines
    //postcondition: initializes numofAssemblyLines
    // creates an array of assembly lines
    
    int run();
    //function simulates the factory
    
    void setAworkerWorkRate(double* ra_te);
    //set the work rate of workers in all assembly lines
    
    void pushPackageToAssQueue(int id);
    //moves packages from the bufferQueue
    //to the assemblyline queue
    
    void assgnPackageToWokers();
    //assigns packages to workers
    
    void setAssblWorkersFree();
    //function decrements the processing time
    //of all packages assigned to workers in the
    //factory
    
    void get_data();
    //gets data from comaandline
    //postcondition: a bufferQueue is created
    
    void simulateTime(int iD);
    //this function sets the waiting time of 
    //packages depending on the time frame in which they arrive
    
    int findMaxQueueSize();
    //find the largest assemblyline queue in the factory
    
    int findProcessingTime(const Package& newP, int assId);
    //function finds the processing time of any package
    
    int findTimeFrame(int inDx);
    //finds time frome of a package on the buffer queue

    void incrementFactoryClock();
    //this increments the clock so that packages leave the
    //buffer queue at the right time

    void printFactoryOutPut(int idd);
    //prints out the details of a package: the arrival time
    // number of units depature time and the factory it departed from
    
    ~Factory();
    //destroys the bufferQueue and the assemblylines
    
  private:
    
    int numOfAssemblyLines;
    //stores the number of assemblylines in the factory
    
    AssemblyLine* AssmbLine;
    //assemblyline that is used when only one assemblyline is needed
    
    Package bufferPackage;
    //helps to build the bufferQueue
    
    LinkedTypeQueue bufferQueue;
    //serves as a temporary waiting queue for packages
    
    scheduler dispatcher;
    //decides which assemblylines get packages

    int factoryClock;
};

#endif

