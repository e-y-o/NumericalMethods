#include <iostream>
#include<math.h>
#include <vector>

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

std::vector<double> linSpace(int x, int y, int z) {
	std::vector<double> s(z);
	s[0] = x;
	s[z - 1] = y;
	double d = ((double)y - (double)x) / ((double)z - 1);
	for (int i = 1; i < z - 1; ++i) {
		s[i] = s[i - 1] + d;
	}
	return s;
}

std::vector<double> newtonTable(std::vector<double> x, std::vector<double> y) {
	
	try {
		if (x.size() != y.size()) {
			throw 1;
		}
	}
	catch(int e) {
		std::cerr << "Input vectors do not have matching size" << std::endl;
	}

	unsigned int n = x.size();
	std::vector<double> d(n);
	for (unsigned int i = 0; i < n; ++i) {
		d[i] = y[i];
	}
	for (unsigned int j = 0; j < n; ++j) {
		for (unsigned int i = n - 1; i > j; --i) {
			d[i] = (d[i] - d[i - 1]) / (x[i] - x[i - j - 1]);
		}
	}
	return d;
}

std::vector<double> evaluateNewton(std::vector<double> x, std::vector<double>y, std::vector<double> x_eval) {
	std::vector<double> d = newtonTable(x, y);
	unsigned int n = x.size();
	unsigned int m = x_eval.size();
	std::vector<double> y_eval(m);

	for (unsigned int i = 0; i < m; ++i) {
		y_eval[i] = d[0];
		for (int j = 1; j < n; ++j) {
			double prod = d[j] * (x_eval[i] - x[0]);
			for (int k = 1; k <= j - 1; ++k) {
				prod *= (x_eval[i] - x[k]);
			}
			
			y_eval[i] += prod;
		}
	}
	return y_eval;
}
