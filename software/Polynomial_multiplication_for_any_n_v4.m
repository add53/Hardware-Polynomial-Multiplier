% --- Step 1: Input Polynomials ---
poly1 = input('1st polynomial as a vector: ');  % Example: [12, 4, 9, 2]
poly2 = input('2nd polynomial as a vector: ');  % Example: [11, 7, 5, 3]

% --- Step 2: Polynomial Multiplication ---
mod_value = 13;  % Modulo value
result = conv(poly1, poly2);  % Multiply the polynomials
result = mod(result, mod_value);  % Apply mod 13 to coefficients

disp('Final resulting polynomial coefficients (mod 13 applied):');
disp(result);

% --- Step 3: Division by x^n + 1 ---
n = input('Enter the degree of divisor (x^n + 1): ');  % Example: n = 6
divisor = [1, zeros(1, n - 1), 1];  % Create divisor polynomial: x^n + 1

% --- Step 4: Element-wise Division ---
% Perform element-wise division
division_result = result ./ divisor;

% Extract the last meaningful non-zero quotient
quotient = mod(division_result(end), mod_value);

disp('Quotient:');
disp(quotient);

% --- Step 5: Compute Remainder ---
% Compute the product of quotient and divisor
quotient_times_divisor = mod(quotient * divisor, mod_value);

% Pad the scaled divisor to match the length of the result
if length(quotient_times_divisor) < length(result)
    quotient_times_divisor = [quotient_times_divisor, ...
                              zeros(1, length(result) - length(quotient_times_divisor))];
end

% Subtract to get the remainder
remainder = mod(result - quotient_times_divisor, mod_value);

disp('Remainder:');
disp(remainder);
