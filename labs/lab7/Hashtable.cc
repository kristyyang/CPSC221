#include "Hashtable.h"
#include <cstdlib>
#include <iostream>
#include <cassert> 
#include <cmath>        // std::sqrt(double)

using namespace std; 

Hashtable::Hashtable(int size) {
	//constructor
	int prime = nextPrime( size ); 
	_size = size;
	if (prime != size) { 
	  cout << "Warning: size = " << size << " is not a prime number." << endl; 
/* uncomment these if you want */ 
	  cout << "Using " << prime << " instead." << endl; 
	  _size = prime; 
	}
	_totalProbes = 0;
	_numInserts = 0;
	_numFailures = 0; 
	_table = new int [ _size ];
	for (int ii=0; ii < _size; ii++) {
		_table[ ii ] = EMPTY;
	}
}
void Hashtable::clear(void) {
	_totalProbes = 0;
	_numInserts = 0;
	_numFailures = 0; 
	for (int ii=0; ii < _size; ii++) {
		_table[ ii ] = EMPTY;
	}
}    
    

Hashtable::~Hashtable() {
	//deconstructor
	delete[] _table;
}

void Hashtable::tallyProbes(int p) {
	// Add the number of probes, p, for one insert operation to the tally.
	_totalProbes += p;
	_numInserts += 1;
}

void Hashtable::printStats() {
	cout << "Average probes/insert = " <<
			probeRate() << " = " <<
			_totalProbes << "/" << _numInserts;
	cout <<", size = "<< _size;
	cout <<", failures = " << _numFailures << endl;
}

float Hashtable::probeRate() {
	return (float)_totalProbes / (float)_numInserts;
}

int Hashtable::hash(int k) {
	return k % _size;
}

/*

int Hashtable::hash2(int k){
	const int R = (this->_size >> 3)+3;
	//cout<< "Number is "<< R <<endl;
	return R - ( k % R );
}
*/

void Hashtable::qinsert(int k) {

	int prob = hash(k);
	int a = 1;
	while(this->_table[prob]  != EMPTY && this->_table[prob] !=k){
		if(a> this->_size){
			std::cout<<"Error - Couldn't insert "<< k <<" into hashtable. "<<std::endl;
			exit(-1);
		}
		_numFailures += 1;
		prob =(prob + a * 2 - 1) % this->_size;
		a++;
		//cout << "Warning: qinsert(" << k << ") found no EMPTY slot, so no insert was done." << endl; 
	}
	this->tallyProbes(a);
	this->_table[prob]= k;
	// Insert k in the hash table.
	// Use open addressing with quadratic probing and hash(k) = k % _size.

	// Tips:
	// - Look at the lecture slides if you don't remember how to implement these.
	// - You need to prevent against infinite loops. You should limit the number
	// of times you probe and print an error message upon exceeding this limit.
	// - You're welcome to add new declarations to hash.h, add to the constructor,
	// include libraries, or anything else you need. 
	// - You're also welcome to modify the main() method to automate your testing.

    // ************* ADD YOUR CODE HERE *******************
    
    
    
    // Your method should return after it stores the value in an EMPTY slot 
    // and calls tallyProbes, so if it gets here, it didn't find an EMPTY slot 
  //  _numFailures += 1; 
    //cout << "Warning: qinsert(" << k << ") found no EMPTY slot, so no insert was done." << endl; 
}

void Hashtable::linsert(int k) {

	int prob = hash(k);
	int a = 1;
	while(this->_table[prob] != EMPTY && this->_table[prob] != k){
		if( a>this->_size){
			std::cout<<" Error - Couldn't insert "<< k << " in the table "<<std::endl;
			exit(-1);
		}
		_numFailures += 1;
		prob = (prob + 1) % this->_size;
		a++;
		//cout << "Warning: linsert(" << k << ") found no EMPTY slot, so no insert was done." << endl; 
	}
	this->tallyProbes(a);
	this->_table[prob] = k;
	// Insert k in the hash table.
	// Use open addressing with linear probing and hash(k) = k % _size.

    // ************* ADD YOUR CODE HERE *******************
    
    
    
    // Your method should return after it stores the value in an EMPTY slot 
    // and calls tallyProbes, so if it gets here, it didn't find an EMPTY slot 
   // _numFailures += 1; 
    //cout << "Warning: linsert(" << k << ") found no EMPTY slot, so no insert was done." << endl; 
}


/*

int Hashtable::FindPrime(int m){
	int Mp = 0;
	int i = m;
	bool prime = false;
	while( !prime && i >2){
		if(isPrime(i)){
			prime = true;
			Mp = i;
			return Mp;
		}
		i--;
	}
	return 0;
}

int Hashtable::hash2(int k, int m){
	int r = FindPrime(m);
	return r -(k % r);
}
*/
int Hashtable::findPrime (int m ) {
  //start at 1 below m
  m -= 1;
  for ( int i = 0; i < m; i++ ) {
    //check if the number is prime.
    bool foundPrime = true;
    for ( int j = 2; j <= sqrt(m); j++ ) {
      if(m%j == 0) {
        //not prime.
        j = m;
        foundPrime = false;
      }
    }
    if ( foundPrime ) {
      return m;
    }
    m--;
  }
  //not found, so we return the smallest prime number.
  return 2;
}

int Hashtable::hash2(int m, int k) {
  //find the prime number. (takes ages)
  int prime = findPrime(m);
  //cout <<"Number is "<<prime<<endl;
  return ( prime - (k % prime) );
}

void Hashtable::dinsert(int k) {

	int prob = hash(k);
	int m = 1;
	int n = hash2(this->_size,k);
	while(this->_table[prob] !=EMPTY &&this->_table[prob] != k){
		if(m >this->_size){
			std::cout<<" Error - Couldn't insert "<< k <<" in the table "<< std::endl; 
			exit(-1);
		}
		_numFailures += 1;
		prob = (prob + n)% this->_size;
		m++;
	    //cout << "Warning: dinsert(" << k << ") found no EMPTY slot, so no insert was done." << endl; 
	}
	this->tallyProbes(m);
	this->_table[prob]=k;

	// Insert k in the hash table.
	// Use open addressing with double hashing. Use the existing hash function
	// and also implement a second hash function.

    // ************* ADD YOUR CODE HERE *******************
    
    
    
    // Your method should return after it stores the value in an EMPTY slot 
    // and calls tallyProbes, so if it gets here, it didn't find an EMPTY slot 
   // _numFailures += 1; 
    //cout << "Warning: dinsert(" << k << ") found no EMPTY slot, so no insert was done." << endl; 
}

void Hashtable::print() {
	// Print the content of the hash table.

	for (int i=0; i<_size; i++) {
		cout<<"["<<i<<"] ";
		if (_table[i] != EMPTY)
			cout << _table[i];
		cout << endl;
	}
}

bool Hashtable::checkValue(int k, int i) {
	// Check if value k is at index i. Use this to help you with testing.

	return (_table[i] == k);
}

int Hashtable::nextPrime( int n ) { 
    int loops = (n < 100) ? 100 : n;
    for (int ii = 0; ii < loops; ii++ ){ 
      if ( isPrime( n + ii ) ) return (n + ii); 
    }
    assert( false ); // logic error 
}
bool Hashtable::isPrime( int n ) { 
    if (n < 2) return false; 
    if (n == 2) return true;
    if (n % 2 == 0) return false;  
    return isPrime( n, 3 ); 
}
bool Hashtable::isPrime( int n, int divisor ){ 
    if ((divisor * divisor) > n) return true; 
    if ((n % divisor) == 0) return false; 
    return isPrime( n, divisor + 2 ); 
}

