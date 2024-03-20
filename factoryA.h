//class that coordinates the activities of the factory


//head class that runs the factory

#include <iostream>
#include <cstdlib>
#include "Package.h"
#include "LinkedTypeQueue.h"
#include "Worker.h"
#include "AssemblyLine.h"

#ifndef F_ACTORYTIME
#define F_ACTORYTIME

using namespace std;

//struct to serve as data structure for the list of assemblylines

class Factory
{
  public:
   
    Factory();
    //default construtor initializes numofAssemblyLines
    //postcondition: numofAssemblyLines = 0
    
    int run(int nWorker, double* wRate);
    //function simulates the factory
    // funciton sets the worker rate, takes in the number of packages
    // and takes in a pointer to a list of packages 
    
    void setAworkerWorkRate(double* ra_te);
    // set the work rate of workers in all assembly lines
    
    void pushPackageToAssQueue();
    
    void assgnPackageToWokers();
    //assigns packages to workers
    
    void get_data();
    //gets data from comaandline
    //postcondition: a bufferQueue is created
    
    
    void simulateTime();
    //this function sets the waiting time of 
    //packages depending on the time frame in which they arrive
    
    ~Factory();
    //destroys the bufferQueue
    
  private:
    
    int numOfAssemblyLines;
    //stores the number of assemblylines in the factory
    
    AssemblyLine soleAssmbLine;
    //assemblyline that is used when only one assemblyline is needed
    
    Package bufferPackage;
    //helps to build the bufferQueue
    
    LinkedTypeQueue bufferQueue;
    //serves as a temporary waiting queue for packages
};
#endif
