#pragma once
#include <iostream>

/*
* Implementation of the bisection method to find roots of a continuous function.
* Requires input `function`, a function continuous from `a` to `b`, with a root
* between `a` and `b`. Also requires f(a) and f(b) have opposite signs. Epsilon
* is our accuracy threshold. Epsilon should be close to 0.
*/
double bisection(double a, double b, double (*function)(double x), double epsilon);