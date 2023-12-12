#include <iostream>
#include <cmath>

using namespace std;

typedef struct Result {
  double e;
  int iterations;
} Result;

void compute_e(double epsilon, Result *result) {
  double sum = 1, sum_previous = 0;
  long long denominator = 1;
  int n = 1;
  while (abs(sum - sum_previous) > epsilon) {
    sum_previous = sum;
    denominator *= n++;
    sum += 1.0 / denominator;
  }
  result->e = sum;
  result->iterations = n;
}

int main() {
  double epsilon = 1e-10;
  Result result;
  compute_e(epsilon, &result);
  cout << "Calculated e: " << result.e << endl;
  cout << "Number of iterations: " << result.iterations;
}