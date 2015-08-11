#include "pit.h"
#include <string.h>

using namespace std;

PIT::PIT(ControllerInterface *con) : c(con) {
	pthread_cancel(threads[0]);
	pthread_cancel(threads[1]);
	pthread_cancel(threads[2]);
	memset(threads, 0, 3*sizeof(pthread_t));
}


void* PIT::incC0(void* arg){
	PIT* pit = (PIT*) arg;
	while(1){
		pit->c0++;
		if(pit->c0 == pit->d0){
			pit->c0 = 0;
			pit->c->irq(0);
		}
		usleep(1);
	}
	return NULL;
}

void* PIT::incC1(void* arg){
	PIT* pit = (PIT*) arg;
	while(1){
		pit->c1++;
		if(pit->c1 == pit->d1){
			pit->c1 = 0;
			pit->c->irq(1);
		}
		usleep(10);
	}
	return NULL;
}

void* PIT::incC2(void* arg){
	PIT* pit = (PIT*) arg;
	while(1){
		pit->c2++;
		if(pit->c2 == pit->d2){
			pit->c2 = 0;
			pit->c->irq(2);
		}
		usleep(100);
	}
	return NULL;
}

void PIT::setD0(unsigned short d){
	d0 = d;
}
void PIT::setD1(unsigned short d){
	d1 = d;
}
void PIT::setD2(unsigned short d){
	d2 = d;
}

void PIT::setC(unsigned short con){
	this->con = con;
	int rc;
	if(con & 1 && !threads[0]){
		rc = pthread_create(&threads[0], NULL,
		                  incC0, (void*)this);
		if (rc){
		 cout << "Error:unable to create thread C0," << rc << endl;
		 exit(-1);
		}
	}else if(threads[0]){
		pthread_cancel(threads[0]);
		memset(&threads[0], 0, sizeof(pthread_t));
	}

	if(con>>1 & 1 && !threads[1]){
		rc = pthread_create(&threads[1], NULL,
		                  incC1, (void*)this);
		if (rc){
		 cout << "Error:unable to create thread C0," << rc << endl;
		 exit(-1);
		}
	}else if(threads[1]){
		pthread_cancel(threads[1]);
		memset(&threads[1], 0, sizeof(pthread_t));
	}

	if(con>>2 & 1  && !threads[2]){
		rc = pthread_create(&threads[2], NULL,
		                  incC2, (void*)this);
		if (rc){
		 cout << "Error:unable to create thread C0," << rc << endl;
		 exit(-1);
		}
	}else if(threads[2]){
		pthread_cancel(threads[2]);
		memset(&threads[2], 0, sizeof(pthread_t));
	}
}

unsigned short PIT::getC0(){
	return c0;
}
unsigned short PIT::getC1(){
	return c1;
}
unsigned short PIT::getC2(){
	return c2;
}