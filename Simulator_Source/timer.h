#ifndef _TIMER_H
#define _TIMER_H

#include "ControllerInterface.h"

#include <iostream>
#include <cstdlib>
#include <pthread.h>

class timer{

	pthread_t threads[3];

	unsigned c0;
	unsigned c1;
	unsigned c2;

	unsigned d0;
	unsigned d1;
	unsigned d2;

	ControllerInterface *c;
	public:
		timer(ControllerInterface *c);	

		void incC0();
		void incC1();
		void incC2();

		void setD0(unsigned);
		void setD1(unsigned);
		void setD2(unsigned);

		unsigned getC0();
		unsigned getC1();
		unsigned getC2();


		void setC(unsigned);
};


#endif