#include <iostream>
#include <cstdlib>
#include "Package.h"
#include "LinkedTypeQueue.h"
#include "Worker.h"

#ifndef A_SSEMBLYLINE
#define A_SSEMBLYLINE

using namespace std;

class AssemblyLine
{
  public:
    
    AssemblyLine();
    //default constructor 
    // postcondition: numberOfWorkers = 0
    
    void addPackageToQueue(const Package& cPackage);
    //function adds packages to wQueue (every assemblyline has it's own queue)
    
    int getNumOfWorkers();
    //returns the number of workers in an assemblyline
    //(necessary when there is more than one worker)
    
    void decrementClock();
    
    void addWorkers(int N);
    //adds workers to the factory
    
    void setWorkerBusy(int workerID, const Package& new_Package);
    //sets the worker with index (workerID) busy and assigns 
    //(since only one worker is used, workerID is defaulted to 0)
    //new_Package to this worker or assigns the solWorker the package if 
    //one worker is used
    
    void setProRateOfWOrkers(double* rList, int indx);
    //sets the work rate of all workers
    //if only one worker is used, set the rate of soleWorker
    
    LinkedTypeQueue wQueue;
    // holds the queue of packages for each assemblyline
    
    Worker soleWorker;
    //worker that is used when factory is simulated with one worker
    
    ~AssemblyLine();
    //deconstructor deletes all the workers in the assemblyline
    //(usefull when more than worker exists)
    
  private:
    
    int numberOfWorkers;
    //stores the number workers in assemblyline
    //(usefull when more than worker exists)
    
    
    Worker *workers;
    //useful for creating an array of workers
    //(usefull when more than worker exists)
    
};

#endif
