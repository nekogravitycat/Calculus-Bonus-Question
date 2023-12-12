#include <iostream>
#include <cmath>

using namespace std;

typedef struct Result {
  double e;
  int iterations;
} Result;

void method_a(double epsilon, Result *result) {
  
  
}

void method_b(double epsilon, Result *result) {
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

void method_c(double epsilon, Result *result) {
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

  cout << "Method A" << endl;
  Result result_a;
  method_a(epsilon, &result_a);
  cout << "Calculated e: " << result_a.e << endl;
  cout << "Number of iterations: " << result_a.iterations << endl;

  cout << endl;

  cout << "Method B" << endl;
  Result result_b;
  method_b(epsilon, &result_b);
  cout << "Calculated e: " << result_b.e << endl;
  cout << "Number of iterations: " << result_b.iterations << endl;

  cout << endl;

  cout << "Method C" << endl;
  Result result_c;
  method_c(epsilon, &result_c);
  cout << "Calculated e: " << result_c.e << endl;
  cout << "Number of iterations: " << result_c.iterations << endl;
}