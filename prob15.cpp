// project euler problem 15
// How many routes are there on a 20x20 grid if you can only
//   move down and right?

// This is also a representation of Pascal's Triangle, so we could
//   solve with binomial coefficients:

//   (X+Y)!
//   ------
//    X!Y!

// I decided to do some dynamic programming:

#include <iostream>
#include <vector>

using namespace std;

long long explore(int n, vector<long long>& map, int width) {
	if (n < 0) {
		// this is just an error check. Probably won't happen, but who knows
		return 0;
	}
	else if (n == 0) {
		// every path starts at (0,0)
		return 1;
	}
	else if (map[n] > 0) {
		// if we have already calculated one of the paths, return it.
		return map[n];
	}
	else {
		// uncalculated paths
		if ((n%width) == 0) {
			// if we're on the left edge, we only have one choice (up)
			map[n] = explore(n-width, map, width);
			return map[n];
		}
		else if (n-width < 0) {
			// if we're on the top edge, we can only trace to the left
			map[n] = explore(n-1, map, width);
			return map[n];
		}
		else {
			// else check both ways
			map[n] = explore(n-1, map, width) + explore(n-width, map, width);
			return map[n];
		}
	}
}

int main() {

	int x,y;
	cout << "How big is your grid?" << endl;
	cout << "Enter X: "; cin >> x;
	cout << "Enter Y: "; cin >> y;

	int size = (x+1)*(y+1); // Remember that we're moving between corners
	vector<long long> arr(size,0);
	cout << "Total routes for 20x20: " << explore(size-1, arr, x+1) << endl;

	return 0;
}