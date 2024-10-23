% Ask for polynomial coefficients
poly1 = input('1st polynomial as a vector: ');

% Ask for polynomial coefficients
poly2 = input('2nd polynomial as a vector: ');

% Modulo value
mod_value = 13;

% lengths of both polynomials
len1 = length(poly1);
len2 = length(poly2);

% Initialize
result_matrix = zeros(len1, len2);

% Store polynomial in matrix
for i = 1:len1
    for j = 1:len2
        result_matrix(i, j) = poly1(i) * poly2(j);
    end
end

% Final polynomial result
result_size = len1 + len2 - 1;
result = zeros(1, result_size);

for i = 1:len1
    for j = 1:len2
        result(i + j - 1) = result(i + j - 1) + result_matrix(i, j);
    end
end

disp('Multiplication result matrix:'); 
disp(result_matrix); 

% Apply the modulo
result = mod(result, mod_value);

% Final result (with modulo 13 applied)
disp('Final resulting polynomial coefficients (mod 13 applied):');
disp(result);

% Dividing by x^(n+1)
n = length(result) - 2;  % Degree of the final result is length(result) - 1
divisor = [1, zeros(1, n+1)];  % This represents x^(n+1) 

% Polynomial division
[quotient, remainder] = deconv(result, divisor);

% Display the quotient and remainder
disp('Quotient:');
disp(quotient);

disp('Remainder:');
disp(remainder);
