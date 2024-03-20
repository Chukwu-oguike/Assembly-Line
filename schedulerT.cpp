#include "AssemblyLine.h"
#include "scheduler.h"

scheduler::scheduler()
{
  assemblyLineID = 0;
}

//a cyclic distribution of packages to all the assemblylines will
//ensure that the assemblylines with the list amount of processing time is
// assgined the next
int scheduler::findBestLine(AssemblyLine* Assmblylne, int numAsslne)
{
  int i = 0;
  
  //divides the total number of packages on the assembly line 
  //by the processing of the assembly line
  int tempProTime = ceil(assmblyLne[i].wQueue.sumOfPackageUnits()
                          / assmblyLne[i].soleWkoker.getProcessingRate());
  
  for(i = 1; i < numAsslne; i++)
    {
      
      if(ceil(assmblyLne[i].wQueue.sumOfPackageUnits()
	/ assmblyLne[i].soleWkoker.getProcessingRate()) < tempProTime)
      {
          
	tempProTime = ceil(assmblyLne[i].wQueue.sumOfPackageUnits()
                           / assmblyLne[i].soleWkoker.getProcessingRate());
			   
        assemblyLineID = i;
      }
  
  return assemblyLineID;
}