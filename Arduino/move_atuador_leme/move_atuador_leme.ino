                                                                                                                                                                                                                                                                                                                                                                                                           #include "DualVNH5019MotorShield.h" //drive motor
DualVNH5019MotorShield md;

//640
//80

void setup() {
  md.init();
  Serial.begin(9600);
}

void loop() {

  /*for (int i = 0; i >= -200; i--)
  {
    md.setM1Speed(i);
    //stopIfFault();
    int pot_r = analogRead(A3);
    Serial.println(pot_r);
    delay(10);
  }
  delay(1000);
  for (int i = -200; i <= 200; i++)
  {
    md.setM1Speed(i);
    int pot_r = analogRead(A3);
    Serial.println(pot_r);
    delay(10);
  }
  delay(1000);*/
 
  md.setM1Speed(400);
  //delay(2000);
  //md.setM1Speed(0);
  //delay(500);
  //md.setM1Speed(200);
  //delay(2000);
  int pot_r = analogRead(A2);
  Serial.println(pot_r);
  //delay(4000);
  //md.setM1Speed(0);
  //delay(500);
  //md.setM1Speed(400);
  //delay(4000);
  //md.setM1Speed(0);
  //delay(500);
}
