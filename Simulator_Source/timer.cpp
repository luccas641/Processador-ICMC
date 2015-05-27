#include "timer.h"

using namespace std;

timer::timer(ControllerInterface *con) : c(con) {
}


void timer::incC0(){
	while(1){
		c0++;
		if(c0 == d0){
			c0 = 0;
			c->irq(0);
		}
		sleep(1);
	}
}
void timer::incC1(){
	while(1){
		c1++;
		if(c1 == d1){
			c1 = 0;
			c->irq(1);
		}
		sleep(10);
	}

}
void timer::incC2(){
	while(1){
		c2++;
		if(c2 == d2){
			c2 = 0;
			c->irq(2);
		}
		sleep(100);
	}

}

void timer::setD0(unsigned d){
	d0 = d;
}
void timer::setD1(unsigned d){
	d1 = d;
}
void timer::setD2(unsigned d){
	d2 = d;
}

void timer::setC(unsigned c){
	c = c;
	int rc;

	if(c & 1){
		rc = pthread_create(&threads[0], NULL,
		                  incC0, (void));
		if (rc){
		 cout << "Error:unable to create thread C0," << rc << endl;
		 exit(-1);
		}
	}else{

	}

	if(c>>1 & 1){
		rc = pthread_create(&threads[1], NULL,
		                  incC1, (void);
		if (rc){
		 cout << "Error:unable to create thread C0," << rc << endl;
		 exit(-1);
		}
	}else{

	}

	if(c>>2 & 1){
		rc = pthread_create(&threads[2], NULL,
		                  incC2, (void);
		if (rc){
		 cout << "Error:unable to create thread C0," << rc << endl;
		 exit(-1);
		}
	}else{

	}
}

unsigned timer::getC0(){
	return c0;
}
unsigned timer::getC1(){
	return c1;
}
unsigned timer::getC2(){
	return c2;
}