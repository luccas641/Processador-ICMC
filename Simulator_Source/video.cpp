#include "Video.h"
#include <iostream>

using namespace std;
Video::Video()
{
	sprites.resize(2048);
	oam.resize(128);
	bg.resize(1200);
	palette.resize(128);
}

void Video::addSprite(unsigned int data)
{
	this->sprites[addrSprite>>3].p[addrSprite & 7] = (uint16_t) data;
	addrSprite = (addrSprite + 1) %2048;
}

void Video::addObject(unsigned int data)
{
	if((addrOAM & 3) == 0){
		this->oam[addrOAM>>2].x = (uint16_t)data;
	}else if((addrOAM & 3) == 1){
		this->oam[addrOAM>>2].y = (uint16_t)data;
	}else if((addrOAM & 3) == 2){
		this->oam[addrOAM>>2].c = (uint8_t)data;
	}else if((addrOAM & 3) == 3){
		this->oam[addrOAM>>2].p = (data) & 7;
		this->oam[addrOAM>>2].v = (data >> 1) & 1;
		this->oam[addrOAM>>2].h = (data >> 2) & 1;
	}
	addrOAM = (addrOAM +1) %128;
}

void Video::addBG(unsigned int data)
{
	if((addrBG & 1) == 0){
		this->bg[addrBG>>1].c = (uint8_t) data;
	}else if((addrBG & 1) == 1){
		this->bg[addrBG>>1].p = (data) & 7;
		this->bg[addrBG>>1].v = (data >> 1) & 1;
		this->bg[addrBG>>1].h = (data >> 2) & 1;
	}
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
	oam.resize(128);
	bg.resize(1200);
	palette.resize(128);
}