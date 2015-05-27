#ifndef _PIT_H
#define _PIT_H

#include "ControllerInterface.h"

#include <iostream>
#include <cstdlib>
#include <pthread.h>

class PIT{

	pthread_t threads[3];

	static unsigned c0;
	static unsigned c1;
	static unsigned c2;
	static unsigned con;

	unsigned d0;
	unsigned d1;
	unsigned d2;

	ControllerInterface *c;
	public:
		PIT(ControllerInterface *c);	

		static void* incC0(void* arg);
		static void* incC1(void* arg);
		static void* incC2(void* arg);

		void setD0(unsigned);
		void setD1(unsigned);
		void setD2(unsigned);

		unsigned getC0();
		unsigned getC1();
		unsigned getC2();


		void setC(unsigned);
};


#endif