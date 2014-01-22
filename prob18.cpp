// project euler problem 18
// maximum total for pyramid of numbers

#include <iostream>
#include <fstream>
#include <vector>
#include <assert.h>
#include <algorithm>

using namespace std;

struct Node {
	int num;
	bool checked;
	Node(int n, bool c): num(n), checked(c) {}
};

int* canCheck(int startRow, int index, int level) {
	int nextRow = startRow+level;
	int position = index-startRow;
	int *check = new int[2];
	check[0] = nextRow+position;
	check[1] = nextRow+position+1;
	return check;
}

int explore(int n, int level, int startRow, vector<Node>& tree) {

	if ((n+level) > tree.size()-1) {
		return tree[n].num;
	}
	else if (tree[n].checked) {
		return tree[n].num;
	}
	else if (n >= 0) {
		int *next = canCheck(startRow, n, level);
		int left = explore(next[0], level+1, startRow+level, tree);
		int right = explore(next[1], level+1, startRow+level, tree);
		tree[n].num += left>=right ? left:right;
		tree[n].checked = true;
		return tree[n].num;
	}
	else {
		assert(n < 0 && "Error! n can't be less than 0!");
		return -1;
	}
}


int main() {
	vector <Node> tree;
	ifstream f("prob18.txt");
	if (!f.good()) {
		cerr << "Error opening file! Exiting." << endl;
		return 1;
	}
	int n;
	while (f >> n) {
		// cout << "n: " << n << endl;
		Node temp(n,false);
		tree.push_back(temp);
	}

	cout << "maximum total: " << explore(0, 1, 0, tree) << endl;

	// for (int i=0; i < tree.size(); i++) {
	// 	cout << i << ": " << tree[i].num << endl;
	// }

	return 0;
}