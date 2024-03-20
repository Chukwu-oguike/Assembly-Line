//
// main() function for the factory simulation
//


#include <cstdlib>		// for atof()
#include "factory.h"
using namespace std;

int main(int ac, char *av[])
{
	double	*rates;
	int	num_workers;
	int	result;
	int	i;

	if ( ac < 3 ){
		cerr << "usage: " << av[0] << ": num_workers rate1 [rate2 ...]\n";
		exit(1);
	}

	num_workers = atoi(av[1]);	// get number of workers
	if ( ac-2 != num_workers ){	// deduct 1 for cmd, 1 for count
		cerr << av[0] << ": incorrect number of rates\n";
		exit(1);
	}

	rates = new double[num_workers];
	for(i=2; i<ac; i++)
		rates[i-2] = atof(av[i]);

	Factory	fac(num_workers, rates);
	result = fac.run();
	return result;
}
