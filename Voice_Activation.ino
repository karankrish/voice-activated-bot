
//Voice Activated Arduino (Bluetooth + Android)


String voice;
int IN1 = 12; //GPIO D12  
int IN2 = 11; //GPIO D11
int IN3 = 10; //GPIO D10
int IN4 = 9;  //GPIO D9

const int VCC = 8;
 
void forward(){
    Serial.println("MOVING FORWARD");
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2,LOW);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4,LOW);
}
void backward(){
    Serial.println("MOVING BACKWARD");
    digitalWrite(IN1, LOW);
    digitalWrite(IN2,HIGH);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4,HIGH);
}
void left(){
    Serial.println("TURNING LEFT");
    digitalWrite(IN1, LOW);
    digitalWrite(IN2,LOW);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4,LOW);
}
void right(){
    Serial.println("TURNING ROGHT");
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2,LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4,LOW);
}
void sto(){
    Serial.println("STOP");
    digitalWrite(IN1, LOW);
    digitalWrite(IN2,LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4,LOW);
}

 
void setup() {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(VCC, OUTPUT);
  digitalWrite(VCC,HIGH);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
Serial.begin(9600);
Serial.print("ROBOTICS");

}
  
void loop() {
  while (Serial.available()){  //Check if there is an available byte to read
  delay(10); //Delay added to make thing stable 
  char c = Serial.read(); //Conduct a serial read
  if (c == '#') {break;} //Exit the loop when the # is detected after the word
  voice += c; //Shorthand for voice = voice + c
  }  
  if (voice.length() > 0) {
    Serial.println(voice); 
    
  //----------Control Multiple Pins/ LEDs----------//  
       if(voice == "*forward") {
        forward();
        }  //Turn Off All Pins (Call Function)
  else if(voice == "*backward"){backward();} //Turn On  All Pins (Call Function)
  
  //----------Turn On One-By-One----------// 
  else if(voice == "*left") {left();
  }
   else if(voice == "*right") {right();
  }
   else if(voice == "*stop") {sto();
  }


voice="";}} //Reset the variable after initiating
