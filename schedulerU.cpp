#include "AssemblyLine.h"
#include "scheduler.h"

scheduler::scheduler()
{
  assemblyLineID = 0;
}

//a cyclic distribution of packages to all the assemblylines will
//ensure that the assemblylines with the list number of units time is
// assgined the next
int scheduler::findBestLine(AssemblyLine* assmblyLne, int numAsslne)
{
  int i = 0;
  
  //the total number of packages on the assembly line
  int tempNumUNnits = assmblyLne[i].wQueue.sumOfPackageUnits();
  
  for(i = 1; i < numAsslne; i++)
    {
      if(assmblyLne[i].wQueue.sumOfPackageUnits() < tempNumUNnits)
      {
	  tempNumUNnits = assmblyLne[i].wQueue.sumOfPackageUnits();
	
          assemblyLineID = i;
      }
    }
  
  return assemblyLineID;
}