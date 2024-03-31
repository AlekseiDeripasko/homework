#include "B_equation.h"

int factorial(int n){
  return (n == 1 || n == 0) ? 1 : factorial(n - 1) * n;
}

float B_equation() {
    return x - pow(x,3)/factorial(3) - pow(x,5)/factorial(5);
}
