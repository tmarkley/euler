// project euler problem 17
// If all the numbers from 1 to 1000 were written out in words, how many letters would be used?

// this code can be used later to convert numbers to a string.

#include <iostream>
#include <string>
#include <vector>

using namespace std;

string digits[] = {"One", "Two", "Three", "Four", "Five", 
				   "Six", "Seven", "Eight", "Nine"};

string teens[] = {"Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen",
				  "Sixteen", "Seventeen", "Eighteen", "Nineteen"};

string tens[] = {"Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty",
				 "Seventy", "Eighty", "Ninety"};

string bigs[] = {"Hundred", "Thousand", "Million"};

string numToString(int num) {

	string str = "";

	if (num >= 100) {
		str += digits[num/100 - 1] + bigs[0];
		num %= 100;
		if (num)
			str += "and";
	}

	if (num >= 20) {
		str += tens[num/10 - 1];
		num %= 10;
	}

	if (num >= 11 && num <= 19) {
		str += teens[num-11];
	}

	else if(num == 10) {
		str += tens[0];
	}

	else if (num > 0) {
		str += digits[num-1];
	}

	return str;
}

int main() {
	
	string nums = "";
	for (int i=1; i < 1000; i++) {
		nums += numToString(i);
	}

	nums += "OneThousand";

	cout << "number of letters: " << nums.size() << endl;
	return 0;
}