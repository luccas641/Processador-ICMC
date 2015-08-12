#ifndef VIDEO_H
#define VIDEO_H

#include <vector>
using namespace std;
typedef struct
{
	unsigned char x, y, c;
	bool v:1, h:1;
	unsigned int p:3;
} OAMe;

typedef struct 
{
	unsigned char c;
	bool v:1, h:1;
	unsigned int p:3;
} BGMAPe;

typedef struct 
{
	unsigned short p[8];	
} SPRITEe;

typedef struct 
{
	unsigned int red:5;
	unsigned int green:5;
	unsigned int blue:5;
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
