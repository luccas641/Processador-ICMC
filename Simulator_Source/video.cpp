#include "Video.h"

Video::Video()
{
	sprites.resize(128);
	oam.resize(128);
	bg.resize(1024);
	palette.resize(128);
}

void Video::addSprite(SPRITEe sprite)
{
	this->sprites[addrSprite++] = sprite;
}

void Video::addObject(OAMe obj)
{
	this->oam[addrOAM++] = (obj);
}

void Video::addBG(BGMAPe bg)
{
	this->bg[addrBG++] = (bg);
}

void Video::addPalette(COLORe p)
{
	this->palette[addrPalette++] = p;
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

void  Video::setAddrSprite(int addr)
{
	addrSprite = addr;
}

void  Video::setAddrOAM(int addr)
{
	addrOAM = addr;
}

void  Video::setAddrPalette(int addr)
{
	addrPalette = addr;
}

void  Video::setAddrBG(int addr)
{
	addrBG = addr;
}


void  Video::reset()
{
	sprites.clear();
	oam.clear();
	bg.clear();
	palette.clear();

	sprites.resize(128);
	oam.resize(128);
	bg.resize(1024);
	palette.resize(128);
}