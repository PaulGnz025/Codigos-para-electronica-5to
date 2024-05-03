int i=0;
void setup(){
  Serial.begin(9600);
  pinMode(2,INPUT);
  pinMode(3,INPUT);
  pinMode(4,INPUT);
}
  void loop(){
    if(digitalRead(2)==HIGH){
      for(i=0;i<=9;i++){
      Serial.println(i);
        delay(1000);
      }
    
    }
    else if(digitalRead(3)==HIGH){
      for(i=0;i<=9;i++){
      Serial.println(i);
        delay(2000);
      }
           }

      else if(digitalRead(4)==HIGH){
    for(i=0;i<=9;i++){
      Serial.println(i);
        delay(3000);
    }
        }
    else if(2==HIGH && 3==HIGH){
       for(i=0;i<=9;i++){
      Serial.println(i);
        delay(500);
        
    }
        }
    else
       for(i=0;i<=9;i++){
      Serial.println(i);
        delay(500);
    }
  }
