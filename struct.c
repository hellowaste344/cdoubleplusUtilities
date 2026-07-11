/*
 * Copyright (C) 2026-2027 x-ashe
*/ 

#include <stdio.h>
#include <float.h>
#include "math.h"


void foo(double *x, double *y){
	double temp = *x;
	*x = *y;
	*y = *x;
};

int main(){
	// Creating an instance of the outer struct
	static struct outerStruct ms;
	ms.name = "x-ashe";
	ms.p.st.pi = 3.145926;
	ms.p.x = 4;
	ms.p.y = 5;
	foo(&ms.p.x, &ms.p.y); // increment one 
	ms.p.area = (ms.p.y * ms.p.x) * ms.p.st.pi;
	printf("Area %F\n", ms.p.area);
	printf("%.2f\n", ms.p.x);
	printf("%.2f\n", ms.p.y);
	printf("%s\n", ms.name);
	
	return 0;
}


