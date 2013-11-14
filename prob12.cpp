// project Euler problem 12
// What is the value of the first triangle number to have over five hundred divisors?

#include <iostream>
#include <math.h>
using namespace std;

int getTriangle(int num) {
	int sum = 0;
	for (int i = 1; i <= num; i++)
		sum += i;

	return sum;
}

int getDivisors(int num) {
	int count = 0;
	for (int i = 2; i <= sqrt(num); i++) {
		if (num % i == 0)
			count++;
	}

	return (count<<1)+2;
}

int main() {

	int divisors = 0;
	int number;
	int i = 12000;
	while(divisors <= 500) {
		number = getTriangle(i);
		int tmp = getDivisors(number);
		if (tmp > divisors) {
			divisors = tmp;
			cout << "new max: " << divisors << " (" << i << "," << number << ")" << endl;
		}
		i++;
	}

	cout << "The first triangle number to have over five hundred divisors is " << number << "!" << endl;

	return 0;
}