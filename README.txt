This program simulates the function of a package-processing facility. It has 
provisions for multiple assembly lines, each of which has a "rate" - this rate
reprsents the number of units of work the line can process in one minute. 

The facility takes in a bunch of package data from a file, parses through it,
and stores it in a prebuffering queue. 

As the packages reach designated arrival times, they are moved from this first
queue to one of the assembly lines. A "dispatcher" determines which assembly
line will be fastest, and sends the package to the "fastest" assembly line.
There are three different methods of choosing the fastest line: 
    1. lowest number of packages 
    2. lowest total number of units 
    3. lowest estimated time 
Once a package is loaded, it remains on the line until work is done and the package is completed. 


The assembly line does work on packages at specified time intervals as 
determined by the factory's timer. An assembly line does work on one package
at a time, on a first come, first serve basis. When the packages are completed,
they ship from the assembly line back to the factory. 

The factory takes the "assembled" packages and stores them in a third queue, 
a postbuffer. When all packages have been assembled and shipped off the 
assembly lines, they're printed from the postbuffer.

Incidentally, the program design doesn't require additional destructors. When
the program pops from a queue, it deletes the node. You pop all nodes in the 
prebuffer when you send them to assembly, all the nodes in the assembly queue 
when you ship to the postbuffer, and all the nodes in the postbuffer when 
you print. All queues are implicitly destroyed as part of the function of the 
program. Only the empty pointers to first nodes require deletion. 


Packages-> Each package has an amount of units to be processed

LinkedTypeQueue -> A data structure (queue) to store  packages

Factory -> Packages are taken in by the Factory into a buffer(a queue), where
	   they await to be dispatched and worked on by several Assembly Lines.

AssemblyLine -> There are many AssemblyLines.
       They have an associated rate
       of work at which the process packages. They process Packages
       and then they ship them.

Scheduler-> Decides where to send the packages. There are three versions of
	this class that assign packages to assembly lines using these
	criterion:
	version P) Smallest number of packages in the line
	version U) Smallest number od total units in the line
	version T) Smallest estimated time (total_units/rate)



Factory -> Handles input of Packages into a queue and runs Assembly Lines.
	Important Functions:
		Factory(int nAsslines, double* wRate)
		int run()

AssemblyLine -> Processes packages and outputs to console the shipping time.
	Important Functions:
		void setWorkerBusy(int workerID, const Package& new_Package)
		void addPackageToQueue(const Package& cPackage)
	Imporntant Data:
		int numberOfWorkers;  
		Worker* workers

Scheduler -> controls what packages go to the AssemblyLine
  	Important Functions:
	    int findBestLine(AssemblyLine* Assmblylne, int numAsslne)

LinkedTypeQueue ->  A queue implementation using linked lists.
	Important Functions:
		bool isEmpty();
                void enqueue(Package pkg);
                void dequeue();
                void display();

 Struct/Class Inheritance hierarchy

facmain
	Factory
		Scheduler			//there is an important collaboration between
		     AssemblyLine               // the Scheduler and the AssemblyLine class
				Worker          // for ultimate efficiency, the scheduler has total control
				   LinkedTypeQueue
					Package
					  