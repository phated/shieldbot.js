//Make sure the dip switches are turned ON, and none of your shields are using pins A0,A1,A2,A3 or D4

#include <Shieldbot.h>

Shieldbot shieldbot = Shieldbot();
int D1,D2,D3,D4,D5;

void setup(){
  Serial.begin(9600);
  shieldbot.setMaxSpeed(50);//255 is max
}

void loop(){
  D1 = shieldbot.readS1();
  D2 = shieldbot.readS2();
  D3 = shieldbot.readS3();
  D4 = shieldbot.readS4();
  D5 = shieldbot.readS5();

  Serial.print("D5: ");
  Serial.print(D5);
  Serial.print(" D4: ");
  Serial.print(D4);
  Serial.print(" D3: ");
  Serial.print(D3);
  Serial.print(" D2: ");
  Serial.print(D2);
  Serial.print(" D1: ");
  Serial.print(D1);
  Serial.println();
  
  if(D1 == HIGH && D5 == HIGH){
    shieldbot.forward();
  }else if(D1 == LOW && D5 == LOW){
    shieldbot.fastStop();
    delay(1000);
  }else if((D1 == LOW) || (D2 == LOW)){
    shieldbot.right(255);
    delay(100);
  }else if((D5 == LOW) || (D4 == LOW)){
    shieldbot.left(255);
    delay(100);
  }else 
    shieldbot.forward();
    
}
