// project Euler problem 7
// What is the 10,001st prime number?
#include <iostream>
#include <math.h>
using namespace std;

int isPrime(long num) {

	if (num % 2 == 0 && num != 2)
		return 0;
	else {
		for (long i = 3; i <= sqrt(num); i++) {
			if (num % i == 0)	
				return 0;
		}
		return 1;
	}
}

int main() {

	int count = 0;
	int prime = 0;
	int i = 2;
	while (count != 10001) {
		if (isPrime(i)) {
			count++;
			prime = i;
		}
		i++;
	}

	cout << "The 10001th prime is " << prime << "!" << endl;

	cout << "2: " << isPrime(2) << endl;

	return 0;
}