int x=0, y=0;

void kbHandler(){
	x++;
}

void main(){
	int i;
	out(0,0);	//setAddrBG
	for(i=0;i<1200;i++){
		out(0,1);	//BG c
		out(0,1);	//BG attr
	}

	int *pos = 32767;
	*pos = &kbHandler;

	asm("EI");


	out(0,4); // AddrSprite 0
	out(255, 5); 
	out(255, 5);
	out(255, 5);
	out(255, 5);
	out(255, 5);
	out(255, 5);
	out(255, 5);
	out(255, 5);

	out(16,4); // AddrSprite 2
	out(15420,5);	//addSprite2 mario
	out(15934,5);
	out(5160,5);
	out(60,5);
	out(32475,5);
	out(15360,5);
	out(15360,5);
	out(9252,5);

	

	out(0,6); // Addrcolor 0
	out(0,7);
	out(7674, 7);
	out(7674, 7);
	out(7674, 7);

	out(8,6); // Addrcolor 2
	out(0,7);
	out(25521, 7);
	out(31, 7);
	out(31744, 7);

	//mario
	out(0,2);
	out(x,3);
	out(y,3);
	out(16,3);
	out(2,3);
	while(1){	
		x= (x+1)%320;	
		y= (y+1)%240;
		out(0,2);
		out(x,3);
		out(y,3);
		for(i=0;i<1000;i++){}
	}
}
