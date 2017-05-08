const byte avionChasse[] PROGMEM = {
  16,10,
  0x00,0x3E,
  0x00,0x78,
  0x0F,0x84,
  0x1F,0xFC,
  0x31,0xF8,
  0x77,0xC8,
  0xBF,0xB8,
  0xFF,0x7C,
  0x0F,0xFE,
  0x00,0x3F,
};

#define NB_PLANES 3
typedef struct{
  int x;
  int y;
} Planes;
Planes planes[NB_PLANES];

void initPlanes()
{
    planes[0].x = 680;
    planes[0].y = 240;
    planes[1].x = 670;
    planes[1].y = 250;
    planes[2].x = 680;
    planes[2].y = 260;
}

void updatePlanes()
{

  for(byte i=0;i<NB_PLANES;i++){
    planes[i].x -=3;

    if(planes[i].x<16) planes[i].x += 680; 
  } 
}


void drawPlanes()
{
  for(byte i=0;i<NB_PLANES;i++){
       coordx=fnctn_lndscapeXpos(planes[i].x );
       coordy=fnctn_lndscapeYpos(planes[i].y);
         
      if(coordx<SCREENWIDTH  && coordx>0-bkgrnd[i].width   && coordy<SCREENHEIGHT    && coordy>0-bkgrnd[i].height){
         gb.display.drawBitmap(coordx, coordy, avionChasse);
      }
  }
}
