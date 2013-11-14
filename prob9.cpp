// project Euler problem 9
// one Pythagorean triplet for which a + b + c = 1000. Find a*b*c.
#include <iostream>
#include <math.h>
using namespace std;

int triplet(int a, int b, int c) {

	if (((a*a)+(b*b) == (c*c)) && (a+b+c == 1000)) {
		return a*b*c;
	}
	return 0;
}

int main() {

	for (int a = 1; a < 333; a++)
		for (int b = a+1; b < 498; b++)
			for (int c = b+1; c < 997; c++) {
				int tmp = triplet(a,b,c);
				if (tmp) {
					cout << "Found it! a: " << a << " b: " << b << " c: " << c << " product: " << tmp << endl;
					return 0;
				}
			}

	return 0;
}