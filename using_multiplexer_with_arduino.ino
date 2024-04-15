//Constants
#define number_of_mux 1
#define numOfMuxPins number_of_mux * 8
#define enPin 2
#define channelA 4
#define channelB 7
#define channelC 8
//Parameters
const int comPin 	= 3;
void setup(){
//Init Serial USB
Serial.begin(9600);
Serial.println(F("Initialize System"));
//Init CD4051B
 	pinMode(channelA, OUTPUT);
 	pinMode(channelB, OUTPUT);
 	pinMode(channelC, OUTPUT);
 	pinMode(enPin, OUTPUT);
 	digitalWrite(channelA, LOW);
 	digitalWrite(channelB, LOW);
 	digitalWrite(channelC, LOW);
 	digitalWrite(enPin, LOW);
}
void loop(){
MuxLED();
}
void selectChannel(int chnl){/* function selectChannel */
//// Select channel of the multiplexer 
 	int A = bitRead(chnl,0); //Take first bit from binary value of i channel.
 	int B = bitRead(chnl,1); //Take second bit from binary value of i channel.
 	int C = bitRead(chnl,2); //Take third bit from value of i channel.
 	digitalWrite(channelA, A);
 	digitalWrite(channelB, B);
 	digitalWrite(channelC, C);
 	
 	Serial.print(F("channel "));Serial.print(chnl);Serial.print(F(" : "));
 	Serial.print(C);
 	Serial.print(F(","));
 	Serial.print(B);
 	Serial.print(F(","));
 	Serial.print(A);
 	Serial.println();
}
void MuxLED(){/* function MuxLED */
//// blink leds 
for(int i = 0; i < 	numOfMuxPins; i++){
 			selectChannel(i);
 			Serial.print(F("LED "));Serial.print(i);Serial.println(F(" HIGH"));
 			analogWrite(comPin,200);
 			delay(200);
 			Serial.print(F("LED "));Serial.print(i);Serial.println(F(" LOW"));
 			analogWrite(comPin,0);
 					}
}