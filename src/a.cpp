#include <iostream>
#include <cmath>

using namespace std;

double compute_e_integral(double epsilon) {
	double e_estimate = 2.0; // Starting with a guess
	double e_previous = 0.0;

	while (abs(e_estimate - e_previous) > epsilon) {
		cout << e_estimate << endl;
		e_previous = e_estimate;
		e_estimate = exp(1/e_estimate);
	}

	return e_estimate;
}

int main() {
	double epsilon = 1e-10;
	double e = compute_e_integral(epsilon);
	cout << "Approximation of e (integral definition): " << e << endl;

	return 0;
}