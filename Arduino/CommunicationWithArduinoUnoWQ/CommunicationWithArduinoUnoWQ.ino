char in_char = "";
String data1;
String data2;
  
int i = 0;
void setup() {
  // put your setup code here, to run once:
  Serial1.begin(9600);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  float t = millis();

   while (Serial1.available()) {
                 
        in_char = Serial1.read();
        data1 = String(in_char);
        
        //sprintf(data, in_char);
        //Serial.print(in_char);
        if(in_char != '\n')           
          data2 = data2 + data1;
                                
        
      }
   delay(100);
  // if(data2 != "")
    Serial.println(data2);
  //data2 = "";

    
  //Serial.print(data);
//  
//  delay(200);
//  if(i>3){
//    i = -1;
//    Serial.println(data);
//    data = "";
//    
//  }
//  i++;
  
  
}
