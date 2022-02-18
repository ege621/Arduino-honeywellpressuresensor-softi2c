#include "SoftwareI2C.h"
volatile bool toggle = 1;
volatile bool flag = 0;



SoftwareI2C hny1;
SoftwareI2C hny2;
SoftwareI2C hny3;

const float FULLSCALE = 80;
const float OFFSET = 0.0;
const float OMIN =10.0;
const float OMAX = 90.0;

byte datain [4];
int i, m1, m2;
float outputPercent, PSI1 , PSI2 , PSI3 , Hz;
float pressurePSI;
unsigned long bitU32;

byte cnt = 0;


//void setBaseTimer(float seconds)
//{
//  //cli();
// //set timer1 interrupt at 1Hz
//  TCCR1A = 0;// set entire TCCR1A register to 0
//  TCCR1B = 0;// same for TCCR1B
//  TCNT1  = 0;//initialize counter value to 0
//  // set compare match register for 1hz increments
//  OCR1A = seconds * 250000 -1; // (must be <65536)
//  // turn on CTC mode
//  TCCR1B |= (1 << WGM12);
//  // Set CS12 and CS10 bits for 1024 prescaler
//  TCCR1B |= (1 << CS11) | (1 << CS10);  
//  // enable timer compare interrupt
//  TIMSK1 |= (1 << OCIE1A);
//  //sei();
//} 


void setup() {
 
Serial.begin(9600);
delay(100);


hny1.begin(4,3);    // sda, scl
hny2.begin(6,5);
hny3.begin(8,7);
    
}



void loop()
{
 //SETUP
hny1.beginTransmission(24);
hny1.write(0xAA);
hny1.write(0x00);
hny1.write(0x00);
hny1.endTransmission();
delay(5);


hny2.beginTransmission(24);
hny2.write(0xAA);
hny2.write(0x00);
hny2.write(0x00);
hny2.endTransmission();
delay(5);

hny3.beginTransmission(24);
hny3.write(0xAA);
hny3.write(0x00);
hny3.write(0x00);
hny3.endTransmission();
delay(5);






//sensor1
i = 0;
hny1.requestFrom(24, 4);
while(hny1.available() )
{
datain[i] = hny1.read();
//Serial.print(datain[i]);
//Serial.print("  "); 
i++;
}
bitU32 = datain[1];
bitU32 = (bitU32 << 8) | datain [2];
bitU32 = (bitU32 << 8) | datain [3];

PSI1 = (float)bitU32 * 0.00089 - 379.33-30;


//sens2
i = 0;
hny2.requestFrom(24, 4);
while(hny2.available() )
{
datain[i] = hny2.read();
//Serial.print(datain[i]);
//Serial.print("  "); 
i++;
}
bitU32 = datain[1];
bitU32 = (bitU32 << 8) | datain [2];
bitU32 = (bitU32 << 8) | datain [3];

PSI2 = (float)bitU32 * 0.00089 - 379.33-35;



//sens3
i = 0;
hny3.requestFrom(24, 4);
while(hny3.available() )
{
datain[i] = hny3.read();
//Serial.print(datain[i]);
//Serial.print("  "); 
i++;
}
bitU32 = datain[1];
bitU32 = (bitU32 << 8) | datain [2];
bitU32 = (bitU32 << 8) | datain [3];

PSI3 = (float)bitU32 * 0.00089 - 379.33-45;



//Serial.print("NO1: "); //Serial.print(", ");
Serial.print(PSI1); //Serial.print(", ");
Serial.print(" ");


//Serial.print("NO2: "); //Serial.print(", ");
Serial.print(PSI2); //Serial.print(", ");
Serial.print(" ");

//Serial.print("NO3: "); //Serial.print(", ");
Serial.println(PSI3); //Serial.print(", ");
Serial.print(" ");

}
