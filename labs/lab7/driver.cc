#include "Hashtable.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;


void usage(char* argv[]) {
	cerr << "Usage: " << argv[0] << " scheme numberOfKeys sizeOfTable" << endl;
	exit(-1);
}

int main(int argc, char *argv[]) {
	int n, m;
	srand(time(0));

	if (argc == 1) {
		cout << "Running your test code..." << endl;

		Hashtable H(10000);
		for (int i = 0; i < 7500; i++) {
			H.linsert(rand() + 1);
		}
		cout << "Linear with 7500 keys and size 10000: ";
		H.printStats();

		Hashtable H1(10000);
		for(int i =0; i < 7500; i++){
			H1.qinsert(rand()+1);
		}

		cout << "Quadratic with 7500 keys and size 10000: ";
		H1.printStats();

		Hashtable H2(10000);
		for(int i =0; i < 7500; i++){
			H2.dinsert(rand() +1);
		}

		cout<< "Double with 7500 keys and size 10000: ";
		H2.printStats();
		/* ADD YOUR TEST CODE HERE */

		return 0;
	}
	
	if (argc != 4) {
		usage(argv);
	}
	n = atoi(argv[2]);
	m = atoi(argv[3]);
	Hashtable H(m);
	
	switch(argv[1][0]) {
	case 'l':
		for (int i=0; i<n; ++i) {
			H.linsert(rand() + 1);
		}
		//    H.print();
		cout << "Linear: ";  
		H.printStats();
		break;
	case 'q':
		for (int i=0; i<n; ++i) {
			H.qinsert(rand() + 1);
		}
		//    H.print();
		cout << "Quadratic: ";
		H.printStats();
		break;
	case 'd':
		for (int i=0; i<n; ++i) {
			H.dinsert(rand() + 1);
		}
		//    H.print();
		cout << "Double Hashing: "; 
		H.printStats();
		break;
	default:
		usage(argv);
	}
}

