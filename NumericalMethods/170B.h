#pragma once
#include <iostream>

/*
* Implementation of the bisection method to find roots of a continuous function.
* Requires input `function`, a function continuous from `a` to `b`, with a root
* between `a` and `b`. Also requires f(a) and f(b) have opposite signs. Epsilon
* is our accuracy threshold. Epsilon should be close to 0. Guaranteed to converge
* so long as the prerequisites are met.
*/
double bisectionMethod(double a, double b, double (*function)(double x), double epsilon);

/*
 * Implementation of the secant method to find the roots of a continuous function.
 * Requires input `function`, a continuous function. Inputs x0 and x1 should be 
 * two points close to the root, with f(x0) != f(x1). Epsilon is our accuracy threshold,
 * should be close to 0. This method is not guaranteed to converge.
 */
double secantMethod(double x0, double x1, double (*function)(double x), double epsilon);