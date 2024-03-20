#include "Package.h"

//default constructor
//postcondition: numberofunits, arrivaltime, processingTime, 
//waitingTime, orderNumber are initialized to zero 
Package::Package()
{
    
    numberOfUnits = 0;//initialize to 0
    
    arrivalTime = 0;//initialize to 0
    
    waitingTime = 0;//initialize to 0
}


// used to give package it's identity when if the default constructor is used
//postcondition: orderNumber = pNum
//               arrivalTime = arrTime
//               numberOfUnits = nUnits
void Package::setPackageInfo(string pNum, int nUnits, int arrTime)
{
   //if(arrTime >= 0 && nUnits >= 0)
     // check if ArvlTime and are valid
   //{
     orderNumber = pNum;// assign orderNumber a value
    
     numberOfUnits = nUnits;// assign numberOfUnits a value
    
     arrivalTime = arrTime;// assign arrivalTime a value
  // }
   
   /*else//if ArvlTime and are not valid
   //{
     cerr<<"arrival time and number of units of"<<
     "  package must be non-negative"<<endl;
     //output error message
     
     exit(1);
     //exit program
   }*/
    
}

 //function returns the waiting time of a package
int Package::getWaitingTime() const
{
  return waitingTime;
}

 //function returnst the order number of package
string Package::getOrderNumber() const
{
  return orderNumber;//return orderNumber
}

//function returns the number of units in a package
int Package::getNumberOfUnits() const
{
  return numberOfUnits;//return numberOfUnits
}

//function sets waiting time
void Package::setWaitingTime(int ts)
{
  waitingTime = ts;
}

//Function returns the arrival time of a package
int Package::getArrivalTime() const
{
  return arrivalTime;//return arrivalTime
}

