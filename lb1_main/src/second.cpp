#include "second.h"

float second_equation() {
    return (std::fabs(x - y) * (1 + (std::pow(std::sin(z), 2) / (x + y))) /
            (std::exp(std::fabs(x - y)) + 0.5 * x));
}
