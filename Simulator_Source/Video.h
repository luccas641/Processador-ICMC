#ifndef VIDEO_H
#define VIDEO_H

#include <vector>
using namespace std;
typedef struct
{
	char x, y, c;
	bool v:1, h:1;
	int p:3;
} OAMe;

typedef struct 
{
	bool v:1, h:1;
	int p:3;
	char c;
} BGMAPe;

typedef struct 
{
	char p[8][16];	
} SPRITEe;

typedef struct 
{
	int red:5;
	int green:5;
	int blue:5;
} COLORe;

class Video
{	
	int addrSprite;
	int addrOAM;
	int addrPalette;
	int addrBG;

	vector<SPRITEe> sprites;
	vector<OAMe> oam;
	vector<BGMAPe> bg;
	vector<COLORe> palette;
	public:
		Video();

		void addSprite(SPRITEe); 
		void addObject(OAMe);
		void addBG(BGMAPe);
		void addPalette(COLORe);

		const vector<SPRITEe>& getSprites();
		const vector<OAMe>& getOAM();
		const vector<BGMAPe>& getBG();
		const vector<COLORe>& getPalette();

		void setAddrSprite(int);
		void setAddrOAM(int);
		void setAddrPalette(int);
		void setAddrBG(int);

		void reset();
};

#endif
