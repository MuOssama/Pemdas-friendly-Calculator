#include "Calc.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
// Function to calculate the power of a number (base^exponent) without using pow function
float custom_pow(float base, int exponent) {
    float result = 1;
    // Multiply the base 'exponent' times
    for (int i = 0; i < exponent; i++) {
        result *= base;
    }
    return result;
}


// Function to parse and evaluate the expression
float calculate_product(char *input) {
    float result = 0;
    float current_num = 0;
    char operator = '+';
    bool neg_num = false;

    for (int i = 0; input[i] != '\0'; i++) {
        if (input[i] == '-') {
            if (i == 0 || input[i - 1] == '(') {
                neg_num = true;
                continue;
            }
        }

        if (input[i] >= '0' && input[i] <= '9') {
            int num = input[i] - '0';
            current_num = current_num * 10 + num;
        } else if (input[i] == '^') {
            int exponent = input[i + 1] - '0';
            current_num = custom_pow(current_num, exponent);
            i++; // skip the next character, which is the exponent
        } else if (input[i] == '*' || input[i] == '/') {
            if (neg_num) {
                current_num = -current_num;
                neg_num = false;
            }
            if (operator == '*') {
                result *= current_num;
            } else if (operator == '/') {
                if (current_num != 0) {
                    result /= current_num;
                } else {
                    printf("Error: Division by zero\n");
                    return 0;
                }
            } else {
                result = current_num;
            }
            operator = input[i];
            current_num = 0;
        } else if (input[i] == '+' || input[i] == '-') {
            if (neg_num) {
                current_num = -current_num;
                neg_num = false;
            }
            if (operator == '+') {
                result += current_num;
            } else if (operator == '-') {
                result -= current_num;
            }
            operator = input[i];
            current_num = 0;
        } else if (input[i] == '(') {
            // Find the matching closing parenthesis
            int start = i + 1;
            int end = start;
            int open_parentheses = 1;
            while (open_parentheses > 0 && input[end] != '\0') {
                if (input[end] == '(') {
                    open_parentheses++;
                } else if (input[end] == ')') {
                    open_parentheses--;
                }
                end++;
            }
            // Calculate the value inside the parentheses
            char sub_expression[end - start];
            for (int j = start; j < end - 1; j++) {
                sub_expression[j - start] = input[j];
            }
            sub_expression[end - start - 1] = '\0';
            float sub_result = calculate_product(sub_expression);

            if (neg_num) {
                sub_result = -sub_result;
                neg_num = false;
            }

            // Apply the operation outside the parentheses
            if (operator == '+') {
                result += sub_result;
            } else if (operator == '-') {
                result -= sub_result;
            }
            i = end - 1; // Skip past the closing parenthesis
        }

        if (neg_num && input[i] != '-') {
            current_num = -current_num;
            neg_num = false;
        }
    }

    // Handle the last number in the expression
    if (neg_num) {
        current_num = -current_num;
    }
    if (operator == '*') {
        result *= current_num;
    } else if (operator == '/') {
        if (current_num != 0) {
            result /= current_num;
        } else {
            printf("Error: Division by zero\n");
            return 0;
        }
    } else {
        result += current_num;
    }

    return result;
}


