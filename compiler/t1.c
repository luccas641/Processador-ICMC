int x=0, y=220;

void kbHandler(){
	asm("push fr");
	asm("pop r4");
	asm("mov r5, r0");
	asm("mov r6, r1");
	char c = in(2304);
	if(c=='d')
		x++;
	else if(c=='a')
		x--;
	else if(c=='w')
		y--;
	else if(c=='s')
		y++;
	asm("mov r0, r5");
	asm("mov r1, r6");
	asm("push r4");
	asm("pop fr");
	asm("RTI");
}

void main(){
	int xg;
	int *pos = 16131;
	*pos = &kbHandler;
	asm("EI");

	int i;
	out(0,0);	//setAddrBG
	for(i=0;i<1200;i++){
		out(0,1);	//BG c
		out(0,1);	//BG attr
	}

	out(0,4); // AddrSprite 0
	out(255, 5); 
	out(255, 5);
	out(255, 5);
	out(255, 5);
	out(255, 5);
	out(255, 5);
	out(255, 5);
	out(255, 5);

	out(8,5);	//addSprite2 grama
	out(90,5);
	out(42330,5);
	out(42330,5);
	out(255,5);
	out(20735,5);
	out(63999,5);
	out(65535,5);

	out(15420,5);	//addSprite2 mario
	out(15934,5);
	out(5160,5);
	out(60,5);
	out(32475,5);
	out(15360,5);
	out(15360,5);
	out(9252,5);

	out(255,5);	//addSprite3 terra
	out(16575,5);
	out(1275,5);
	out(255,5);
	out(1275,5);
	out(255,5);
	out(8415,5);
	out(255,5);

	out(0,6); // Addrcolor 0
	out(0,7);
	out(7674, 7);
	out(7674, 7);
	out(7674, 7);

	out(0,7);// Addrcolor 1
	out(5923, 7);
	out(5763, 7);
	out(27378, 7);

	out(0,7);// Addrcolor 2
	out(25521, 7);
	out(31, 7);
	out(31744, 7);


	out(0,7);// Addrcolor 3
	out(17490, 7);
	out(27378, 7);

	out(4,2);
	for(i=0;i<40;i++){
		//grama
		xg = i*8;
		out(xg,3);
		out(224,3);
		out(8,3);
		out(1,3);

		//terra
		out(xg,3);
		out(232,3);
		out(24,3);
		out(3,3);
	}

	//mario
	out(0,2);
	out(x,3);
	out(y,3);
	out(16,3);
	out(2,3);
	while(1){	
		out(0,2);
		out(x,3);
		out(y,3); 
		out(16,3);
		out(2,3);
	}
}
