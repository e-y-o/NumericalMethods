#include <iostream>
#include<math.h>

double bisectionMethod(double a, double b, double (*function)(double x), double epsilon) {
	double fa = function(a);
	double fb = function(b);
	double c = 0;
	if (fa * fb < 0) {
		c = (a + b) / 2;
	}
	else {
		std::cerr << "f(a) and f(b) do not have opposite signs.\n" << std::endl;
		throw;
	}
	double fc = function(c);
	if (abs(fc) < epsilon) {
		return c;
	}
	if (fa * fc < 0) {
		return bisectionMethod(a, c, *function, epsilon);
	}
	else if (fb * fc < 0) {
		return bisectionMethod(c, b, *function, epsilon);
	}
}

double secantMethod(double x, double y, double (*function)(double x), double epsilon) {	
	double a = x;
	double b = y;
	double fa = function(a);
	double fb = function(b);

	while (abs(fb) > epsilon) {
		double temp = b;
		b = (a * fb - b * fa) / (fb - fa);
		a = temp;
		fa = fb;
		fb = function(b);
	}
	return b;
}