#include <iostream>
#include <cmath>
#include <iomanip>

// Fungsi yang diberikan
double f(double x) {
    return x * x * exp(3 * x);
}

// Turunan pertama dengan metode selisih maju
double forward_difference(double x, double h) {
    return (f(x + h) - f(x)) / h;
}

// Turunan pertama dengan metode selisih tengahan
double central_difference(double x, double h) {
    return (f(x + h) - f(x - h)) / (2 * h);
}

// Turunan pertama dengan metode selisih mundur
double backward_difference(double x, double h) {
    return (f(x) - f(x - h)) / h;
}

// Fungsi analitik untuk turunan pertama
double analytical_derivative(double x) {
    return exp(3 * x) * (2 * x + 3 * x * x);
}

int main() {
    double h = 0.05;
    double x_start = 0.0;
    double x_end = 1.0;

    // Mencetak header tabel
    std::cout << std::setw(10) << "x" << std::setw(20) << "Analytical" << std::setw(20) << "Forward" << std::setw(20) << "Central" << std::setw(20) << "Backward" << "\n";

    for (double x = x_start; x <= x_end; x += h) {
        // Nilai turunan analitik
        double f_prime_analytical = analytical_derivative(x);

        // Nilai turunan numerik
        double f_prime_forward = forward_difference(x, h);
        double f_prime_central = central_difference(x, h);
        double f_prime_backward = backward_difference(x, h);

        // Menampilkan hasil dalam tabel
        std::cout << std::setw(10) << x
                  << std::setw(20) << f_prime_analytical
                  << std::setw(20) << f_prime_forward
                  << std::setw(20) << f_prime_central
                  << std::setw(20) << f_prime_backward << "\n";
    }

    return 0;
}
