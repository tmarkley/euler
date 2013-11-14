// problem 3 on Project Euler
// largest prime factor of 600851475143
#include <iostream>
#include <math.h>
using namespace std;

#define TOTAL 600851475143

int isPrime(long num) {

	if (num % 2 == 0)
		return 0;
	else {
		for (long i = 3; i < sqrt(num); i++) {
			if (num % i == 0)	
				return 0;
		}
		return 1;
	}
}

int main() {

	for (long i = sqrt(TOTAL); i > 2; i--) {
		if (isPrime(i) && (TOTAL % i == 0)) {
			cout << "Highest prime factor is " << i << "!" << endl;
			break;
		}
	}
}