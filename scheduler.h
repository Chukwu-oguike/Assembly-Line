#include <iostream>
#include <cstdlib>
#include <cmath>
#include "AssemblyLine.h"
#ifndef SCHEDULE_R
#define SCHEDULE_R

using namespace std;

class scheduler
{
  
  public:
    
    scheduler();
    //default constructor
    
    int findBestLine(AssemblyLine* Assmblylne, int numAsslne);
    //function takes a pointer to an array of asssembly lines and the 
    // number of assembly lines
  
  private:
    
    int assemblyLineID;
    //stores the the index of the right asssembly line
  };

#endif
