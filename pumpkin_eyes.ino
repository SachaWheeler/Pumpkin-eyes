//We always have to include the library
#include "LedControl.h"
#include "binary.h";

/*
 Now we need a LedControl to work with.
 ***** These pin numbers will probably not work with your hardware *****
 pin 12 is connected to the DataIn 
 pin 11 is connected to the CLK 
 pin 10 is connected to LOAD 
 */
LedControl lc=LedControl(12, 11, 10, 2);

byte frames[][8] = {
 { // left
  B01111100,
  B10000010,
  B10000001,
  B10011001,
  B10011001,
  B10000001,
  B10000001,
  B01111110
}, 
 { // right
  B00111110,
  B01000001,
  B10000001,
  B10011001,
  B10011001,
  B10000001,
  B10000001,
  B01111110
}, 
{ //left
  B01111000,
  B10000100,
  B10000010,
  B10011001,
  B10011001,
  B10000001,
  B10000001,
  B01111110
}, 
 { //right
  B00011110,
  B00100001,
  B01000001,
  B10011001,
  B10011001,
  B10000001,
  B10000001,
  B01111110
}, 
{ //left
  B01110000,
  B10001000,
  B10000100,
  B10011010,
  B10011001,
  B10000001,
  B10000001,
  B01111110
}, 
 { //right
  B00001110,
  B00010001,
  B00100001,
  B01011001,
  B10011001,
  B10000001,
  B10000001,
  B01111110
}, 
{ //left
  B01110000,
  B10001000,
  B10000100,
  B10011010,
  B10011001,
  B10000001,
  B10000001,
  B01111110
}, 
 { //right
  B00001110,
  B00010001,
  B00100001,
  B01011001,
  B10011001,
  B10000001,
  B10000001,
  B01111110
}
};


/* we always wait a bit between updates of the display */
unsigned long delaytime=300;

void setup() {
  /*
   The MAX72XX is in power-saving mode on startup,
   we have to do a wakeup call
   */
   for(int i=0;i<2;i++){
      lc.shutdown(i,false);
      lc.setIntensity(i,10);
      lc.clearDisplay(i);
   }

//  test_leds();
}

void test_leds(){
  for (int h=0; h < 2; h++){
    for (int i=0; i < 8; i++){
      for (int j=0; j < 8; j++){
        lc.setLed(h, i, j, true);
        delay(10);
        lc.setLed(h, i, j, false);
      }
    }
  }
}


void loop() { 
  for(int i=0;i<=4;i+=2){
    for(int j=0;j<8;j++){
     lc.setRow(0, j, frames[i][j]);
     lc.setRow(1, j, frames[i+1][j]);
    }
    delay(delaytime);
  }
  delay(1000);
  for(int i=4;i>=0;i-=2){
    for(int j=0;j<8;j++){
     lc.setRow(0, j, frames[i][j]);
     lc.setRow(1, j, frames[i+1][j]);
    }
    delay(delaytime);
  }
  delay(1000);
}


