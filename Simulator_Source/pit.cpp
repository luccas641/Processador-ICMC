#include "pit.h"

using namespace std;

PIT::PIT(ControllerInterface *con) : c(con) {
}


void* PIT::incC0(void* arg){
	ControllerInterface* c = (ControllerInterface*) arg;
	while(1){
		c0++;
		if(c0 == d0){
			c0 = 0;
			c->irq(0);
		}
		sleep(1);
	}
}
void* PIT::incC1(void* arg){
	ControllerInterface* c = (ControllerInterface*) arg;
	while(1){
		c1++;
		if(c1 == d1){
			c1 = 0;
			c->irq(1);
		}
		sleep(10);
	}

}
void* PIT::incC2(void* arg){
	ControllerInterface* c = (ControllerInterface*) arg;
	while(1){
		c2++;
		if(c2 == d2){
			c2 = 0;
			c->irq(2);
		}
		sleep(100);
	}

}

void PIT::setD0(unsigned d){
	d0 = d;
}
void PIT::setD1(unsigned d){
	d1 = d;
}
void PIT::setD2(unsigned d){
	d2 = d;
}

void PIT::setC(unsigned con){
	this->con = con;
	int rc;

	if(con & 1){
		rc = pthread_create(&threads[0], NULL,
		                  incC0, (void*)c);
		if (rc){
		 cout << "Error:unable to create thread C0," << rc << endl;
		 exit(-1);
		}
	}else{

	}

	if(con>>1 & 1){
		rc = pthread_create(&threads[1], NULL,
		                  incC1, (void*)c);
		if (rc){
		 cout << "Error:unable to create thread C0," << rc << endl;
		 exit(-1);
		}
	}else{

	}

	if(con>>2 & 1){
		rc = pthread_create(&threads[2], NULL,
		                  incC2, (void*)c);
		if (rc){
		 cout << "Error:unable to create thread C0," << rc << endl;
		 exit(-1);
		}
	}else{

	}
}

unsigned PIT::getC0(){
	return c0;
}
unsigned PIT::getC1(){
	return c1;
}
unsigned PIT::getC2(){
	return c2;
}