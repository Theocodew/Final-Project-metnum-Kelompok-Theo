#include <iostream>
#include <cmath>

// Fungsi untuk menyelesaikan persamaan diferensial numerik
double f(double x, double y) {
    return 2 * pow(x, 2) * y + 3 * pow(y, 2) + pow(x, 2) + 3;
}

// Metode Euler
void euler(double x0, double y0, double h, int n) {
    double x = x0;
    double y = y0;

    std::cout << "Metode Euler:" << std::endl;
    for (int i = 0; i < n; i++) {
        std::cout << "x(" << i << ") = " << x << ", y(" << i << ") = " << y << std::endl;
        y += h * f(x, y);
        x += h;
    }
}

// Metode Runge-Kutta
void rungeKutta(double x0, double y0, double h, int n) {
    double x = x0;
    double y = y0;

    std::cout << "Metode Runge-Kutta:" << std::endl;
    for (int i = 0; i < n; i++) {
        double k1 = h * f(x, y);
        double k2 = h * f(x + 0.5 * h, y + 0.5 * k1);
        double k3 = h * f(x + 0.5 * h, y + 0.5 * k2);
        double k4 = h * f(x + h, y + k3);

        y += (k1 + 2 * k2 + 2 * k3 + k4) / 6;
        x += h;
        std::cout << "x(" << i << ") = " << x << ", y(" << i << ") = " << y << std::endl;
    }
}

int main() {
    double x0 = 0.0; // Nilai awal x
    double y0 = 1.0; // Nilai awal y
    double h = 0.1; // Nilai step
    int n = 10; // Jumlah iterasi

    euler(x0, y0, h, n);
    rungeKutta(x0, y0, h, n);

    return 0;
}