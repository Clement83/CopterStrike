
const byte mer1[] PROGMEM = {16,6,0x0,0x0,0x0,0x0,0x0,0x0,0xC3,0x0,0x3C,0x0,0x0,0x0,};
const byte mer2[] PROGMEM = {16,6,0x0,0x0,0x3,0x0,0xD,0x80,0x38,0xE0,0x0,0x0,0x0,0x0,};



#define NB_ELM_VAGUE 3
const byte posMer[NB_ELM_VAGUE][2] = {
  {10,10},
  {30,16},
  {22,35}
};

void initWorld()
{
  timerToWin=NB_SEC_TO_WIN;
}

void updateWorld()
{
  if(timerToWin>0 && gb.frameCount%20 == 0) {
    timerToWin--;
  }
}


void drawWorld()
{
  //LEVELHEIGHT
  for(int lvlW = 0; lvlW<8; lvlW++){
    for(int lvlH = 0; lvlH<13; lvlH++){
      for(byte i=0;i<NB_ELM_VAGUE; i++){
         coordx=fnctn_lndscapeXpos((posMer[i][0] + (84*lvlW)));
         coordy=fnctn_lndscapeYpos((posMer[i][1] + (48*lvlH)));
         if(coordx<SCREENWIDTH  && coordx>0-bkgrnd[i].width   && coordy<SCREENHEIGHT    && coordy>0-bkgrnd[i].height){
           if(gb.frameCount%20>9) {
             gb.display.drawBitmap(coordx, coordy, mer1);
           } else {
             gb.display.drawBitmap(coordx, coordy, mer2);
           }
         }
        //gb.display.drawBitmap((posMer[i][0] + (84*lvlW)),(posMer[i][1] + (48*lvlH),mer1);  
      }
    }
  }
}
