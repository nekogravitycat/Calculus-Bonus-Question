#include <iostream>
#include <iomanip>

#define ull unsigned long long
#define ld long double

using namespace std;

typedef struct Result {
  ld e;
  ull iterations;
} Result;

void method_a(ld epsilon, Result *result) {
  ld riemann = 2, x = 1;
  ull iterations = 0;
  for (ull n = 2; riemann - 1.0 > epsilon; n++) {
    riemann = 0;
    for (ull i = 0; riemann < 1; i++) {
      x = 1 + (1.0/n)*i;
      riemann += (1.0 / x) * (1.0/n);
      iterations++;
    }
  }
  result->e = x;
  result->iterations = iterations;
}

void method_b(ld epsilon, Result *result) {
  ld limit = 1, limit_prevoius = 0;
  ull iterations = 0;
  for (ull n = 1; limit - limit_prevoius > epsilon; n++) {
    limit_prevoius = limit;
    // limit = pow((1+1.0/n), n);
    // Binary Exponentiation: a^b
    limit = 1;
    ld a = 1 + 1.0/n;
    ull b = n;
    while (b != 0) {
      if (b & 1) { limit *= a; }
      a *= a;
      b = b >> 1;
      iterations++;
    }
  }
  result->e = limit;
  result->iterations = iterations;
}

void method_c(ld epsilon, Result *result) {
  ld sum = 1, sum_previous = 0;
  ull n = 1;
  for (ull denominator = 1; sum - sum_previous > epsilon; n++) {
    sum_previous = sum;
    denominator *= n;
    sum += 1.0 / denominator;
  }
  result->e = sum;
  result->iterations = n - 1;
}

int main() {
  const ld epsilon = 1e-10;
  cout << "Epsilon: " << epsilon << endl;
  
  cout << endl << fixed << setprecision(10);

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