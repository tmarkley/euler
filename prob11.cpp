// project Euler problem 11
// largest product of four adjacent numbers in 11.txt
#include <iostream>
using namespace std;

int product(int a, int b, int c, int d) {
	return a*b*c*d;
}

int main() {

	int arr[400];
	int i=0;
	while(cin >> arr[i]) {
		i++;
	}
	int max = 0;
	// start with up-down
	for (int i = 0; i < 340; i++) {
		int tmp = product(arr[i], arr[i+20], arr[i+40], arr[i+60]);
		if (tmp > max)
			max = tmp;
	}
	
	// left-right
	for (int i = 0; i <= 19; i++)
		for (int j = 20*i; j <= (20*i)+16; j++) {
			int tmp = product(arr[j], arr[j+1], arr[j+2], arr[j+3]);
			if (tmp > max)
				max = tmp;
		}

	// diagonal left to right
	for (int i = 0; i <= 16; i++)
		for (int j = 20*i; j <= (20*i)+16; j++) {
			int tmp = product(arr[j], arr[j+21], arr[j+42], arr[j+63]);
			if (tmp > max)
				max = tmp;
		}

	// diagonal right to left
	for (int i = 0; i <= 16; i++)
		for (int j = (20*i)+3; j <= (20*i)+19; j++) {
			int tmp = product(arr[j], arr[j+19], arr[j+38], arr[j+57]);
			if (tmp > max)
				max = tmp;
		}

	cout << "The max is " << max << "!" << endl;

	return 0;
}