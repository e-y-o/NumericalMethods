#include<iostream>
#include<math.h>
#include "170B.h"
#include "Tester.h"
#include<vector>
#include<set>
#include<list>
# define M_PI 3.14159265358979323846
using namespace std;

void test(int& x, int y) {
	x = x + y;
	y = 5;
}

int main() {
	vector<int> v = { 1, 2, 3, 4 };
	auto itr = v.begin();
	while (itr != v.end()) {
		itr++;
	}
	cout << (*itr) << endl;
	return 0;
}

double function(double x) {
	return pow(x, -1) - tan(x);
}