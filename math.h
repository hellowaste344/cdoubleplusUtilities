#ifndef MATH_H
#define MATH_H

typedef struct {
	double pi;
} V;

struct Point{
	double x;
	double y;
	double area;
	V st;
}; 

struct outerStruct{
	const char *name;
	struct Point p;
};

void foo(double *x, double *y);

#endif
