//class that serves as queue to assemblylines 
 
#include <iostream>
#include <cstdlib>
#include <cassert>
#include "Package.h"
#ifndef L_Queue
#define L_Queue

using namespace std;


//struct to form queue
struct linkedQueue
{
 Package info;

 linkedQueue *next;//pointer to next node
};

class LinkedTypeQueue
{
  public:
    
    LinkedTypeQueue();
    //default constructor 
    //postcondition: queueFront = NULL;
    //               queueSize = 0;
    //               queueRear = NULL;
    
    bool isQueueEmpty();
    //function checks if queue is empty
    // postcondition: returns true if empty
    
    Package frontOfQueue();
    // returns the first element of the queue
    //precondition: queue is not empty
    
    void pushToQueue(const Package& queueELement);
    //function adds a package to the queue
    
    void destroyQueue();
    //function gets deletes all the existing packages in the queue
    
    void popFromQueue();
    //function removes the first element in a queueELement
    //precondition: queue is not empty
    //postconditon: queueSize--
    
    void setWaitingTime(int t);
    //updates the waiting time of all the element in the queue
    
    int getQueueSize();
    //returns the size of the queue( will be necessary if more assemblylines are used)
    
    
  private:
    
    linkedQueue *queueFront;
    //pointer the first element on the queue
    
    linkedQueue *queueRear;
    //pointer to the last element on the queue
    
    int queueSize;
    //stores the queue's size
  
};

#endif