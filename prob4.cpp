// project Euler problem 4
// largest palindrome made from the product of two 3-digit numbers
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int isPalindrome(int num) {

	stringstream ss;
	ss << num;
	string str = ss.str();

	int length = str.length();

	for (int i = 0; i < length/2; i++) {
		if (str[i] != str[length-1-i])
			return 0;
	}

	return 1;
}


int main() {

	int max;

	for (int i = 999; i > 900; i--) {
		for (int j = 999; j > 900; j--) {
			if (isPalindrome(i*j) && (i*j > max)) {
				max = i*j;
			}
		}
	}

	cout << "Largest palindrome is " << max << "!" << endl;

	return 0;

}