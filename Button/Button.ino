int sw = 2;


void setup(){
//pinMode(sw, INPUT) ;
Serial.begin(9600);  
}

void loop(){
int val = digitalRead(sw);
if (val == 1){
Serial.println("Park Woojin");
    delay(500);
}

}