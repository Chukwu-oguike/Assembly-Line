#include "AssemblyLine.h"
#include "scheduler.h"

scheduler::scheduler()
{
  assemblyLineID = 0;
}

//a cyclic distribution of packages to all the assemblylines will
//ensure that the assemblylines with the list number of packages
// assgined the next
int scheduler::findBestLine(AssemblyLine* assmblyLne, int numAsslne)
{
    int i = 0;
    
    int tempSize = assmblyLne[i].wQueue.getQueueSize();
  
    for(i = 1; i < numAsslne; i++)
    { 
      if(assmblyLne[i].wQueue.getQueueSize() < tempSize)
      {
         tempSize = assmblyLne[i].wQueue.getQueueSize();
         
         assemblyLineID = i;
      }
    }
   
    return assemblyLineID;

}