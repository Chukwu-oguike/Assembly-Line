#include "Package.h"
#include "LinkedTypeQueue.h"

//default constructor
LinkedTypeQueue::LinkedTypeQueue()
{
    queueFront = NULL;//initializes queueFront
    
    queueRear = NULL;//initializes queueRear
    
    queueSize = 0;//initializes queueSize
}

//function checks if queue is empty
bool LinkedTypeQueue::isQueueEmpty()
{
  return (queueFront == NULL);
  //check if two conditions that are 
  //true when queue is empty are satisfied
}

// returns the first element of the queue
Package LinkedTypeQueue::frontOfQueue()
{
    assert(queueFront != NULL);
    //prevents function from retrieving from an empty queue
    
    return queueFront->info;
}

//returns the size of the queue
//( will be necessary if more assemblylines are used)
int LinkedTypeQueue::getQueueSize()
{
  return queueSize;
}

//function adds a package to the queue
void LinkedTypeQueue::pushToQueue(const Package& queueELement)
{
  linkedQueue *newLink;//create a pointer to a temporary node
  
  newLink = new linkedQueue;//create temporary node
  
  newLink->next = NULL;// initializes pointer of new node to NULL
  
  newLink->info = queueELement;// copy contents into new node
  
  if(isQueueEmpty())// check if queue is empty
  {
    queueFront = newLink;//point queueFront to new node
    
    queueRear = newLink;//point queueRear to new node
  }
  
  else// if queue is not empty
  {
    queueRear->next = newLink;//point queueRear to new node
    
    queueRear = queueRear->next;//point queueRear to last node
    
  }
  
  queueSize++;//update queue size
}

//function removes the first element in a queueELement
void LinkedTypeQueue::popFromQueue()
{

  linkedQueue *tempLink;//temporary pointer

  if(!isQueueEmpty())//check if queue is empty
  {
    tempLink = queueFront;//point tempLink to first node
  
    queueFront = queueFront->next;
    //point queueFront to the second node
  
    delete tempLink;//delete the first node
    
    queueSize--;//update the queue size
    
    if(queueFront == NULL)//if the last node was removed
    {
      queueRear = NULL;//point queueRear to NULL
    }
  }
  
  else
  {
    cerr<<"Cannot pop an empty queue"<<endl;
    //output error message
    
    exit(1);
    //end program
  }
}

//set the waiting time of the front of the queue
void LinkedTypeQueue::setWaitingTime(int t)
{
  queueFront->info.setWaitingTime(t);
}
//function gets deletes all the existing packages in the queue
void LinkedTypeQueue::destroyQueue()
{
  
  linkedQueue *tempLink;// create temporary pointer
  
  while(queueFront != NULL)//check if queue is empty
  {
     tempLink = queueFront;
     // point temporary pointer to front of queue
  
     queueFront = queueFront->next;
     // point queueFront to second element in queue
  
     delete tempLink;// delete the front of the queue
     
  }
  
  queueSize = 0;//update queueSize
  
  queueRear = NULL;//point queueRear to NULL
}

