void main(){
	int i;/*
	out(0,0);	//setAddrBG
	out(8,1);	//BG c
	out(0,1);	//BG attr	*/
	

	out(8,4); // AddrSprite 0
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
	out(25521, 7);
	out(31, 7);
	out(31744, 7);

	int x, y;
	while(1){	
		x = (x + 1) % 512;
		y = (y + 1) % 512;
		out(0,2);
		out(x,3);
		out(y,3);
		out(8,3);
		out(0,3);
		for(i=0;i<2000;i++){}
	}
}
