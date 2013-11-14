// project Euler problem 8
// find the greatest product of five consecutive digits in 8txt.txt
#include <iostream>
#include <string>
using namespace std;

int product(int a, int b, int c, int d, int e) {

	return a*b*c*d*e;
}

int main() {

	string Big;
	string small;

	int max = 0;

	while(getline(cin, small)) {
		Big += small;
	}

	for (int i = 0; i < Big.length()-4; i++) {
		int tmp = product((int)Big[i]-48,(int)Big[i+1]-48,(int)Big[i+2]-48,(int)Big[i+3]-48,(int)Big[i+4]-48);
		if (tmp > max) {
			max = tmp;
		}
	}

	cout << "The max is " << max << "!" << endl;

	return 0;

}