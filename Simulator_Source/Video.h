#ifndef VIDEO_H
#define VIDEO_H

#include <vector>
#include <stdint.h>
using namespace std;
typedef struct
{
	uint16_t x, y;
	uint8_t c;
	bool v:1, h:1;
	uint8_t p:3;
} OAMe;

typedef struct 
{
	uint8_t c;
	bool v:1, h:1;
	unsigned int p:3;
} BGMAPe;

typedef struct 
{
	uint16_t p[8];	
} SPRITEe;

typedef struct 
{
	uint8_t red:5;
	uint8_t green:5;
	uint8_t blue:5;
} COLORe;

class Video
{	
	unsigned int addrSprite;
	unsigned int addrOAM;
	unsigned int addrPalette;
	unsigned int addrBG;

	vector<SPRITEe> sprites;
	vector<OAMe> oam;
	vector<BGMAPe> bg;
	vector<COLORe> palette;
	public:
		Video();

		void addSprite(unsigned int); 
		void addObject(unsigned int);
		void addBG(unsigned int);
		void addPalette(unsigned int);

		const vector<SPRITEe>& getSprites();
		const vector<OAMe>& getOAM();
		const vector<BGMAPe>& getBG();
		const vector<COLORe>& getPalette();

		void setAddrSprite(unsigned int);
		void setAddrOAM(unsigned int);
		void setAddrPalette(unsigned int);
		void setAddrBG(unsigned int);

		void reset();
};

#endif
