#include <iostream>
#include <cmath>

// Define a type alias for a function pointer that takes a double and returns a double
using FunctionPtr = double (*)(double);

/**
 * Computes the derivative using the Newton Forward Difference method.
 * 
 * @param y A function pointer to the mathematical function y(x)
 * @param x The point at which to evaluate the derivative
 * @param h The step size
 * @return The approximated numerical derivative
 */
double newton_forward_derivative(FunctionPtr y, double x, double h) {
    // Formula: y'(x) ≈ (y(x + h) - y(x)) / h
    return (y(x + h) - y(x)) / h;
}

// An example mathematical function to test: y(x) = x^2 + 3x
// (The exact analytical derivative is y'(x) = 2x + 3)
double sample_function(double x) {
    return x * x + 3.0 * x;
}

int main() {
    double x, h;

    std::cout << "--- Newton Forward Numerical Differentiation ---\n";
    std::cout << "Testing function: y(x) = x^2 + 3x\n\n";

    // Read the value of x from standard input
    std::cout << "Enter the value of x: ";
    if (!(std::cin >> x)) {
        std::cerr << "Invalid input for x.\n";
        return 1;
    }

    // Read the step size h from standard input
    std::cout << "Enter the step size h (e.g., 0.001): ";
    if (!(std::cin >> h)) {
        std::cerr << "Invalid input for h.\n";
        return 1;
    }

    // Prevent division by zero
    if (h == 0.0) {
        std::cerr << "Error: Step size 'h' cannot be exactly zero.\n";
        return 1;
    }

    // Calculate the numerical derivative by passing the function pointer
    double approx_derivative = newton_forward_derivative(sample_function, x, h);

    // Calculate the exact mathematical derivative for comparison (y' = 2x + 3)
    double exact_derivative = 2.0 * x + 3.0;

    // Output the results
    std::cout << "\n--- Results ---\n";
    std::cout << "Numerical approximation y'(" << x << ") : " << approx_derivative << "\n";
    std::cout << "Exact analytical value y'(" << x << ")  : " << exact_derivative << "\n";
    std::cout << "Absolute Error                    : " << std::abs(approx_derivative - exact_derivative) << "\n";

    return 0;
}