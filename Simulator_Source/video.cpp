
#include "Video.h"
#include <iostream>

using namespace std;
Video::Video()
{
	sprites.resize(2048);
	oam.resize(512);
	bg.resize(1200);
	palette.resize(128);
}

void Video::addSprite(unsigned int data)
{
	this->sprites[addrSprite>>3].p[addrSprite & 7] = (uint16_t) data;
	addrSprite = (addrSprite + 1) %2048;
}

void Video::addObject(unsigned short data)
{
	if((addrOAM & 3) == 0){
		this->oam[addrOAM>>2].x = data;
	}else if((addrOAM & 3) == 1){
		this->oam[addrOAM>>2].y = data;
	}else if((addrOAM & 3) == 2){
		this->oam[addrOAM>>2].c = data;
	}else if((addrOAM & 3) == 3){
		this->oam[addrOAM>>2].p = (data & 0x1F);
		this->oam[addrOAM>>2].v = (data>>8 & 0x1);
		this->oam[addrOAM>>2].h = (data>>9 & 0x1);
	}
	addrOAM = (addrOAM +1) %512;
}

void Video::addBG(unsigned int data)
{
	this->bg[addrBG].c = (data & 0xFF);
	this->bg[addrBG].v = (data>>8 & 0x1);
	this->bg[addrBG].h = (data>>9 & 0x1);
	this->bg[addrBG].p = (data>>10 & 0x1F);
	addrBG = (addrBG+1)%1200  ;
}

void Video::addPalette(unsigned int data)
{
	this->palette[addrPalette].red = (data>>10)&31;
	this->palette[addrPalette].green = (data>>5)&31;
	this->palette[addrPalette].blue = (data)&31;

	addrPalette = (addrPalette +1) % 128;
}


const vector<SPRITEe>&  Video::getSprites()
{
	return sprites;
}

const vector<OAMe>&  Video::getOAM()
{
	return oam;
}

const vector<BGMAPe>&  Video::getBG()
{
	return bg;
}

const vector<COLORe>&  Video::getPalette()
{
	return palette;
}

void  Video::setAddrSprite(unsigned int addr)
{
	addrSprite = addr;
}

void  Video::setAddrOAM(unsigned int addr)
{
	addrOAM = addr;
}

void  Video::setAddrPalette(unsigned int addr)
{
	addrPalette = addr;
}

void  Video::setAddrBG(unsigned int addr)
{
	addrBG = addr;
}


void  Video::reset()
{
	sprites.clear();
	oam.clear();
	bg.clear();
	palette.clear();

	sprites.resize(2048);
	oam.resize(512);
	bg.resize(1200);
	palette.resize(128);
}
