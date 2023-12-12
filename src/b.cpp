#include <iostream>
#include <cmath>

using namespace std;

typedef struct Result {
  double e;
  int iterations;
} Result;

void compute_e(double epsilon, Result *result) {
  double limit = 1, limit_prevoius = 0;
  int n = 1;
  while (abs(limit - limit_prevoius) > epsilon) {
    limit_prevoius = limit;
    limit = pow((1+1.0/n), n);
    n++;
  }
  result->e = limit;
  result->iterations = n;
}

int main() {
  double epsilon = 1e-10;
  Result result;
  compute_e(epsilon, &result);
  cout << "Calculated e: " << result.e << endl;
  cout << "Number of iterations: " << result.iterations;
}