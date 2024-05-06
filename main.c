#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Calc.h"
int main() {
    char input[] = "2^3-2+5+(3+2)";  // Input expression to evaluate
    float product = calculate_product(input);  // Evaluate the expression
    printf("Product: %.2f\n", product);  // Print the result
    return 0;
}
