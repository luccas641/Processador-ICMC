#ifndef _PIT_H
#define _PIT_H

#include "ControllerInterface.h"

#include <iostream>
#include <cstdlib>
#include <pthread.h>

class PIT{
public:
	pthread_t threads[3];

	unsigned short c0;
	unsigned short c1;
	unsigned short c2;
	unsigned short con;

	unsigned short d0;
	unsigned short d1;
	unsigned short d2;

	ControllerInterface *c;
	
		PIT(ControllerInterface *c);	

		static void* incC0(void* arg);
		static void* incC1(void* arg);
		static void* incC2(void* arg);

		void setD0(unsigned short);
		void setD1(unsigned short);
		void setD2(unsigned short);

		unsigned short getC0();
		unsigned short getC1();
		unsigned short getC2();


		void setC(unsigned short);
};


#endif