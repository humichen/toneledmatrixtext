#include "pitches.h"
#include "muisc.h"
#include "picture.h"
int btnpin=13;
int tonePin=8;
int latchPin = 11;
int clockPin = 7;
int dataPin = 12;

int btnstate=0;
int thisNote = 0;
int i = 0;
int check=1;
boolean picst=true;

void setup() {
  pinMode(latchPin,OUTPUT);
  pinMode(clockPin,OUTPUT);
  pinMode(dataPin,OUTPUT);
  pinMode(btnpin,INPUT);
}



void loop() {
  while(1){  
          if(check==1){
            i=0;
            thisNote=0;
            while(thisNote < 8){ 
                int noteDuration = 1000 / noteDurations[thisNote];
                tone(tonePin, melody[thisNote], noteDuration);

                int pauseBetweenNotes = noteDuration*0.12+5;
                
                for(int j=0;j<pauseBetweenNotes;j++){
                  if(picst){
                    for(i=0;i<8;i++){
                      digitalWrite(latchPin,LOW);
                      shiftOut(dataPin, clockPin, MSBFIRST, colDataMatrix[i]);
                      shiftOut(dataPin, clockPin, MSBFIRST, rowDataMatrix[i]);
                      digitalWrite(latchPin,HIGH);
                      delay(1);
                   }
                  }
                  else{
                    for(i=0;i<8;i++){
                      digitalWrite(latchPin,LOW);
                      shiftOut(dataPin, clockPin, MSBFIRST, colDataMatrix[i]);
                      shiftOut(dataPin, clockPin, MSBFIRST, rowDataMatrix2[i]);
                      digitalWrite(latchPin,HIGH);
                      delay(1);
                   }
                  }
                }
                picst=!picst;
                
                noTone(tonePin);
                thisNote++;
                
                btnstate=digitalRead(btnpin);
                if(btnstate==HIGH){
                  check=2;
                  break;
                  }
                
                if(thisNote==8){
                  check=2;
                  break;
                  }
              
              }
          }
          if(check==2){
            i=0;
            thisNote=0;
            while(thisNote < 42){
                int noteDuration = 1000 / noteDurations2[thisNote];
                tone(tonePin, melody2[thisNote], noteDuration);

                int pauseBetweenNotes = noteDuration*0.12+5;
                
                for(int j=0;j<pauseBetweenNotes;j++){
                  if(picst){
                    for(i=0;i<8;i++){
                      digitalWrite(latchPin,LOW);
                      shiftOut(dataPin, clockPin, MSBFIRST, colDataMatrix[i]);
                      shiftOut(dataPin, clockPin, MSBFIRST, rowDataMatrix3[i]);
                      digitalWrite(latchPin,HIGH);
                      delay(1);
                   }
                  }
                  else{
                    for(i=0;i<8;i++){
                      digitalWrite(latchPin,LOW);
                      shiftOut(dataPin, clockPin, MSBFIRST, colDataMatrix[i]);
                      shiftOut(dataPin, clockPin, MSBFIRST, rowDataMatrix4[i]);
                      digitalWrite(latchPin,HIGH);
                      delay(1);
                   }
                  }
                }
                picst=!picst;
               
                noTone(tonePin);
                thisNote++;
                
                btnstate=digitalRead(btnpin);
                if(btnstate==HIGH){
                  check=1;
                  break;
                  }
                
                if(thisNote==42){
                  check=1;
                  break;
                }
                //if(i==8)i=0;

                }
          }
  }
}
