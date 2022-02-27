#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

double x, y, c;
double x_square, y_square;

void binary_search(const double& left, const double& right) {
	double mid = (left + right) / 2;
	double mid_square = pow(mid, 2);

	double h_1 = sqrt(x_square - mid_square);
	double h_2 = sqrt(y_square - mid_square);

	double result = h_1 * h_2 / (h_1 + h_2);

	if (abs(result - c) < 0.001) {
		cout << mid << endl;
		exit(0);
	}
	else if (result - c < -0.001) {
		binary_search(left, mid);
	}
	else {
		binary_search(mid + 0.000001, right);
	}
}

void binary_search() {
	double left = 0;
	double right = min(x, y);
	double mid, mid_square, h_1, h_2, result;

	while (true) {
		mid = (left + right) / 2;
		mid_square = pow(mid, 2);

		h_1 = sqrt(x_square - mid_square);
		h_2 = sqrt(y_square - mid_square);

		result = h_1 * h_2 / (h_1 + h_2);

		if (abs(result - c) < 0.001) {
			cout << mid << endl;
			exit(0);
		}
		else if (result - c < -0.001) {
			right = mid;
		}
		else {
			left = mid + 0.000001;
		}
	}
}

int main() {
	cin >> x >> y >> c;
	x_square = pow(x, 2);
	y_square = pow(y, 2);
	
	cout << fixed;
	cout.precision(3);

	binary_search(0, min(x, y));
	//binary_search();
}