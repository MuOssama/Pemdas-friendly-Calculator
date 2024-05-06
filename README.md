# Pemdas-friendly-Calculator
this repo is Pemdas friendly Calculator which is a calculator which uses the precedence of operation which is bracketed at first then exponentials then mult and div finally add and subs
## how to use
### Simple initialization 
copy the two functions
float calculate_product(char *input) {}\
float custom_pow(float base, int exponent){}\
and put them into your code
### Neat initialization 
copy Calc.c and Calc.h into your project
### usage
call the function calculate_product(arr);
arr must be like ""2^3-2+5+(3+2)"

## Algorithm for `calculate_product` function

1. **Initialization**:
   - Set `result` to 0, `current_num` to 0, `operator` to '+', and `neg_num` to false.

2. **Parsing Numbers**:
   - If the character is a digit (0-9), parse it and update `current_num`.
   - If the character is '-', check if it is the first character or follows an opening parenthesis. If so, set `neg_num` to true.

3. **Handling Parentheses**:
   - If an opening parenthesis '(' is encountered, find the matching closing parenthesis ')' and recursively evaluate the expression inside.
   - Apply the result of the sub-expression based on the current operator ('+' or '-').

4. **Handling Operators**:
   - If a '^' is encountered, calculate the power of the current number with the next digit as the exponent.
   - If a '*' or '/' is encountered, apply the current operator to the result and the current number. Update the result accordingly.
   - If a '+' or '-' is encountered, apply the current operator to the result and the current number. Update the result accordingly and update the operator.

5. **Handling End of Expression**:
   - After processing all characters, apply the final operation based on the last operator and the current number.

6. **Return Result**:
   - Return the final result of the expression.
