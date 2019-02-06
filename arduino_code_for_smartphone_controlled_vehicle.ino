/*
 * Arduino based Smartphone controlled vehicle using Bluetooth Module HC-06, Arduino Board, L293D motor controller integrated circuit
     Written by: Sachin Kumar Sinha, Indian Institute of Information Technology Senapati, Manipur
     Date: 29th November 2017

•  The Bluetooth module (HC-06) is having four pins (+5V, GND, Rx, Tx) which connected to the Arduino board at (+5V, GND, Rx, Tx) respectively.
• In the Arduino board the pin (12, 11, 10, 9) are the output pins which are connected to the motor driver circuits input pins (2, 7, 10, 15). The Arduino board works in 5v voltage supply.
• In the motor driver circuits the input pins are (2, 7, 10, 15) and the output pins are (3,6,11,14) which is connected to the two DC geared motor through a 100 microfarad capacitor on each side. 
• The pins(1,9) are the enable pins which is connected to the pin (16) Vcc 5V .
• The pin (16) is getting 5V constant voltage supply through voltage regulator (IC7805).
• The pin (8) Vss is getting 14v voltage supply to drive the motor.
• The pins (4,5,12,13) are the GND pins .


 The working principle of this robot is that there is a Bluetooth module which is having four pins (+5V, GND, Rx, Tx) which connected to the Arduino board at (+5V, GND, Rx, Tx) respectively .
 The Bluetooth module at first connects with the android phone. When the phone gives a command, the RX (Receiver) of the Bluetooth module receives the command and transmit it to the Arduino board at the TX (transceiver) pin.
 The motor driver circuit is connected to the Arduino board with four inputs and the output from the motor driver circuit is connected to the two motors.
 The Received command from the Bluetooth module is processed by the Arduino board according to the code uploaded in the Arduino board 
 which then sends accordingly the output command to the motor driver circuit input pins (2, 7, 10, 15) and then accordingly the output pins (3,6,11,14) of the motor driver circuit connected to the motors rotates the motor in clockwise or anticlockwise direction.

*/

/*Initializing the recieved data from user via HC-06 Arduino compatible bluetooth module*/
char data = 0;       //Variable for storing received data


/*Setting pinmodes and baud rate*/
void setup() 
{
  Serial.begin(9600);         //Sets the data rate in bits per second (baud) for serial data transmission
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT); 
}


/*Defining funciton for making both the LEDs connected with 
pin 13 and 12 to glow on command from user's mobile application*/



void ledon() {
  digitalWrite(13,HIGH);
  digitalWrite(2,HIGH);
  digitalWrite(3,LOW);
}



/*Defining funciton for making both the LEDs connected with 
pin 13 and 12 to off on command from user's mobile application*/
void ledoff()  {
  digitalWrite(13,LOW);
  digitalWrite(2,LOW);
  digitalWrite(3,LOW);  
}


/*Function setting motors to move forward*/
void forward(){
     digitalWrite(12, HIGH);
      digitalWrite(11,LOW);
      digitalWrite(10, LOW);
      digitalWrite(9, HIGH);
      delay(10);
  }


/*Function setting motors to move reverse*/
 void reverse(){

      digitalWrite(12, LOW);
      digitalWrite(11, HIGH);
      digitalWrite(10, HIGH);
      digitalWrite(9, LOW);
      delay(10);
  }

/*Function setting motors to turn left with left wheels moving reverse and right wheel moving forward*/
  void left(){
      digitalWrite(12, LOW);
      digitalWrite(11, HIGH);
      digitalWrite(10, LOW);
      digitalWrite(9, HIGH);
      delay(10);
    }



/*Function setting motors to turn right with right wheels moving reverse and left wheel moving forward*/
void right(){
      digitalWrite(12, HIGH);
      digitalWrite(11, LOW);
      digitalWrite(10, HIGH);
      digitalWrite(9, LOW);
      delay(10);
    }  


/*Function defining all pins to set low to stop the vehicle*/
 void stopp(){ 
      digitalWrite(12, LOW);
      digitalWrite(11, LOW);
      digitalWrite(10, LOW);
      digitalWrite(9, LOW);
      delay(10);
     }     

void loop()
{
  if(Serial.available() > 0)  // Send data only when you receive data:
  {

   /*Getting data given by user through application on Serial Monitor*/
    data = Serial.read();      
    Serial.print(data);        
    Serial.print("\n");        

/*Decision making statements to excute instructions provided by user.*/
if(data=='a')
forward();

if(data=='e')
reverse();

if(data=='b')
left();

if(data=='d')
right();

if(data=='c')
stopp();

if(data=='f')
ledon();

if(data=='g')
ledoff();
    

}
}
