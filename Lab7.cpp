#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;



double Func(double x, double y1, double y2) {
	return sin(4 * x)*exp(x) - 16 * y2 + 16 * y1;
}

double Proizv(double x, double y2, double y3) {
	return exp(x)*sin(4 * x) + 4 * exp(x)*cos(4 * x) - 16 * y3 - 16 * y2;
}
double Tailor1(double x, double y1, double y2, double h, double y3) {
	return y1 + h * (y2 + h / 2 * (Func(x, y1, y2) + y2));
}

double Tailor2(double x, double y1, double y2, double h, double y3) {
	return y2 + h * (Func(x, y1, y2) + h / 2 * (Proizv(x, y2, y3) - Func(x, y1, y2)));
}


int main() {
	double y1 = 1, y2 = 0, y3 = 16, y1n = 0, y2n = 0, h = 0.01, x = 0;
	ofstream f("ans1.dat");
	f << " " << x << " " << y1 << " " << y2 << endl;
	cout << x << "\t" << y1 << endl;
	while (x >= 0 && x <= 2)
	{
		y1n = Tailor1(x, y1, y2, h, y3);
		y2n = Tailor2(x, y1, y2, h, y3);
		x += h;
		y1 = y1n;
		y2 = y2n;
		f << x << " " << y1 << " " << y2 << endl;
		cout << x << "\t" << y1 << endl;
	}
	f.close();
	return 0;
}