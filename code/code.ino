String readString;
void setup(){
  Serial.begin(9600);
  pinMode(6, OUTPUT);
  pinMode(5, OUTPUT);
}
void loop(){
  while(Serial.available()){
    delay(3);
    char c = Serial.read();
    readString+=c;
  }
  if(readString.length() >0){
    Serial.println(readString);
    if(readString == "turn on light"){
      digitalWrite(5, HIGH);
    }else if(readString == "turn off light"){
      digitalWrite(5, LOW);
    }else if(readString == "turn on fan"){
      digitalWrite(6, HIGH);
    }else if(readString == "turn off fan"){
      digitalWrite(6, LOW);
    }else if(readString == "turn on all"){
      digitalWrite(6, HIGH);
      digitalWrite(5, HIGH);
    }else if(readString == "turn off all"){
      digitalWrite(6, LOW);
      digitalWrite(5, LOW);
    }
    
  }
  readString = "";
}
