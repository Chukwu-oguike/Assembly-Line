//class that serves as a model for packages

#include <iostream>
#include <cstdlib>

#ifndef P_ACKAGE
#define P_ACKAGE

using namespace std;

class Package
{
  public:
    
    Package();
    //default constructor
    //postcondition: numberofunits, arrivaltime, processingTime, 
    //waitingTime, orderNumber are initialized to zero  
      
    void setPackageInfo(string pNum, int nUnits, int arrTime );
    // used to give package it's identity when if the default constructor is used
    //postcondition: orderNumber = pNum
    //               arrivalTime = arrTime
    //               numberOfUnits = nUnits
    
    void setWaitingTime(int ts);
    //function sets waiting time
    // postcondition: waiting time  = ts
   
    int getWaitingTime() const;
    //function returns the waiting time of a package
    
    string getOrderNumber() const;
    //function returnst the order number of package
    
    int getNumberOfUnits() const;
    //function returns the number of units in a package
    
    int getArrivalTime() const;
    //Function returns the arrival time of a package
    
    
  private:
    
    string orderNumber;
    //stores the order number
    
    int numberOfUnits;
    //stores the number of units in a package
    
    int arrivalTime;
    //stores the arrival time of a package
    
    int waitingTime;
    //stores the waiting time of a package
};

#endif

