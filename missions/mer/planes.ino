
void initPlanes()
{

}

void updatePlanes()
{

}


void drawPlanes()
{
    byte coordx= PORTEAVION_XWORLD - player.x_world;
    byte coordy= PORTEAVION_YWORLD - player.y_world;

    if( player.x_world>154 && player.x_world<315 && player.y_world>230 && player.y_world<334){
      gb.display.drawBitmap(coordx,coordy,porteAvion2);
    }
}
