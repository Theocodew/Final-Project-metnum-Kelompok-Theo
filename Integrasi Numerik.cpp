#include <iostream>
using namespace std;

double fungsi(double x) {
    return x * x - x - 6; // Contoh fungsi yang diberikan
}

int main() {
	cout << "Integrasi Numerik" << endl;
	cout << " y = x^2-x-6" << endl;    
	int choice;
    cout << "Pilih metode" << endl;
    cout << "1. Metode Riemann" << endl;
    cout << "2. Metode Trapezoida" << endl;
    cin >> choice;

    switch (choice) {
        case 1: {
            double a, b, h;
            cout << "Masukkan batas bawah: ";
            cin >> a;
            cout << "Masukkan batas atas: ";
            cin >> b;
            cout << "Masukkan beda x: ";
            cin >> h;

            double f = 0;
            for (double x = a; x <= b; x += h) {
                f += fungsi(x);
            }

            cout << "Jumlah f(x): " << f << endl;
            cout << "Luas: " << f * h << endl;
            break;
        }
        case 2: {
            double a, b, h;
            cout << "Masukkan batas bawah: ";
            cin >> a;
            cout << "Masukkan batas atas: ";
            cin >> b;
            cout << "Masukkan beda x: ";
            cin >> h;

            double f = 0;
            for (double x = a + h; x < b; x += h) {
                f += fungsi(x);
            }

            double hasil = (h / 2) * (fungsi(a) + 2 * f + fungsi(b));
            cout << "Hasil integrasi numerik: " << hasil << endl;
            break;
        }
        default:
            cout << "Tidak ada dalam pilihan." << endl;
            break;
    }

    return 0;
}

