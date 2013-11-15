// project Euler problem 14
// Which starting number under one million produces the longest chain
//   using the Collatz sequence:
//
//     n -> n/2 (n is even)
//     n -> 3n + 1 (n is odd)
#include <iostream>
using namespace std;


long getCollatz(long num) {

	if (num % 2 == 0)
		return (num >> 1);
	else
		return (3*num + 1);
}

int main() {

	long max = 0, number = 0;

	for (long i = 1; i < 1000000; i++) {
		long count = 1;
		long next = i;
		while (next > 1) {
			count++;
			next = getCollatz(next);
		}
		if (count > max) {
			max = count; 
			number = i;
		}
	}

	cout << "The starting number with the longest chain is " << number << " (" << max << " terms)." << endl;

	return 0;
}