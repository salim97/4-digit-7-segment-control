#include <Arduino.h>
#include <MCP23017.h>
#include <Wire.h>

#include "mynetwork.h"

/*---------------*/
// MCP23017 handler
/*----------------*/
MCP23017 expander;
String currentValue ;
bool dp1 = false ;
bool dp2 = false ;
bool dp3 = false ;
bool dp4 = false ;


void zero()
{
  expander.getPin(MCP23017_GPB0).setValue(LOW); // 0 A
  expander.getPin(MCP23017_GPB1).setValue(LOW);  // 1 B
  expander.getPin(MCP23017_GPB2).setValue(LOW);  // 2 C
  expander.getPin(MCP23017_GPB3).setValue(LOW); // 3 D
  expander.getPin(MCP23017_GPB4).setValue(LOW); // 4 E
  expander.getPin(MCP23017_GPB5).setValue(LOW); // 5 F
  expander.getPin(MCP23017_GPB6).setValue(HIGH); // 6 G
}

void one()
{
  expander.getPin(MCP23017_GPB0).setValue(HIGH); // 0 A
  expander.getPin(MCP23017_GPB1).setValue(LOW);  // 1 B
  expander.getPin(MCP23017_GPB2).setValue(LOW);  // 2 C
  expander.getPin(MCP23017_GPB3).setValue(HIGH); // 3 D
  expander.getPin(MCP23017_GPB4).setValue(HIGH); // 4 E
  expander.getPin(MCP23017_GPB5).setValue(HIGH); // 5 F
  expander.getPin(MCP23017_GPB6).setValue(HIGH); // 6 G
}

void two()
{
  expander.getPin(MCP23017_GPB0).setValue(LOW); // 0 A
  expander.getPin(MCP23017_GPB1).setValue(LOW);  // 1 B
  expander.getPin(MCP23017_GPB2).setValue(HIGH);  // 2 C
  expander.getPin(MCP23017_GPB3).setValue(LOW); // 3 D
  expander.getPin(MCP23017_GPB4).setValue(LOW); // 4 E
  expander.getPin(MCP23017_GPB5).setValue(HIGH); // 5 F
  expander.getPin(MCP23017_GPB6).setValue(LOW); // 6 G
}

void three()
{
  expander.getPin(MCP23017_GPB0).setValue(LOW); // 0 A
  expander.getPin(MCP23017_GPB1).setValue(LOW);  // 1 B
  expander.getPin(MCP23017_GPB2).setValue(LOW);  // 2 C
  expander.getPin(MCP23017_GPB3).setValue(LOW); // 3 D
  expander.getPin(MCP23017_GPB4).setValue(HIGH); // 4 E
  expander.getPin(MCP23017_GPB5).setValue(HIGH); // 5 F
  expander.getPin(MCP23017_GPB6).setValue(LOW); // 6 G
}

void four()
{
  expander.getPin(MCP23017_GPB0).setValue(HIGH); // 0 A
  expander.getPin(MCP23017_GPB1).setValue(LOW);  // 1 B
  expander.getPin(MCP23017_GPB2).setValue(LOW);  // 2 C
  expander.getPin(MCP23017_GPB3).setValue(HIGH); // 3 D
  expander.getPin(MCP23017_GPB4).setValue(HIGH); // 4 E
  expander.getPin(MCP23017_GPB5).setValue(LOW); // 5 F
  expander.getPin(MCP23017_GPB6).setValue(LOW); // 6 G
}

void five()
{
  expander.getPin(MCP23017_GPB0).setValue(LOW); // 0 A
  expander.getPin(MCP23017_GPB1).setValue(HIGH);  // 1 B
  expander.getPin(MCP23017_GPB2).setValue(LOW);  // 2 C
  expander.getPin(MCP23017_GPB3).setValue(LOW); // 3 D
  expander.getPin(MCP23017_GPB4).setValue(HIGH); // 4 E
  expander.getPin(MCP23017_GPB5).setValue(LOW); // 5 F
  expander.getPin(MCP23017_GPB6).setValue(LOW); // 6 G
}

void six()
{
  expander.getPin(MCP23017_GPB0).setValue(LOW); // 0 A
  expander.getPin(MCP23017_GPB1).setValue(HIGH);  // 1 B
  expander.getPin(MCP23017_GPB2).setValue(LOW);  // 2 C
  expander.getPin(MCP23017_GPB3).setValue(LOW); // 3 D
  expander.getPin(MCP23017_GPB4).setValue(LOW); // 4 E
  expander.getPin(MCP23017_GPB5).setValue(LOW); // 5 F
  expander.getPin(MCP23017_GPB6).setValue(LOW); // 6 G
}

void seven()
{
  expander.getPin(MCP23017_GPB0).setValue(LOW); // 0 A
  expander.getPin(MCP23017_GPB1).setValue(LOW);  // 1 B
  expander.getPin(MCP23017_GPB2).setValue(LOW);  // 2 C
  expander.getPin(MCP23017_GPB3).setValue(HIGH); // 3 D
  expander.getPin(MCP23017_GPB4).setValue(HIGH); // 4 E
  expander.getPin(MCP23017_GPB5).setValue(HIGH); // 5 F
  expander.getPin(MCP23017_GPB6).setValue(HIGH); // 6 G
}

void eight()
{
  expander.getPin(MCP23017_GPB0).setValue(LOW); // 0 A
  expander.getPin(MCP23017_GPB1).setValue(LOW);  // 1 B
  expander.getPin(MCP23017_GPB2).setValue(LOW);  // 2 C
  expander.getPin(MCP23017_GPB3).setValue(LOW); // 3 D
  expander.getPin(MCP23017_GPB4).setValue(LOW); // 4 E
  expander.getPin(MCP23017_GPB5).setValue(LOW); // 5 F
  expander.getPin(MCP23017_GPB6).setValue(LOW); // 6 G
}

void nine()
{
  expander.getPin(MCP23017_GPB0).setValue(LOW); // 0 A
  expander.getPin(MCP23017_GPB1).setValue(LOW);  // 1 B
  expander.getPin(MCP23017_GPB2).setValue(LOW);  // 2 C
  expander.getPin(MCP23017_GPB3).setValue(LOW); // 3 D
  expander.getPin(MCP23017_GPB4).setValue(HIGH); // 4 E
  expander.getPin(MCP23017_GPB5).setValue(LOW); // 5 F
  expander.getPin(MCP23017_GPB6).setValue(LOW); // 6 G
}

void numberToDigite(String value)
{
  String tmp = value ;
  int index  = 0;
  for(int i = tmp.length()-1 ; i >= 0 ; i-- )
  {
    //all off
    expander.getPin(MCP23017_GPB0).setValue(HIGH);
    expander.getPin(MCP23017_GPB1).setValue(HIGH);
    expander.getPin(MCP23017_GPB2).setValue(HIGH);
    expander.getPin(MCP23017_GPB3).setValue(HIGH);
    expander.getPin(MCP23017_GPB4).setValue(HIGH);
    expander.getPin(MCP23017_GPB5).setValue(HIGH);
    expander.getPin(MCP23017_GPB6).setValue(HIGH);
    expander.getPin(MCP23017_GPB7).setValue(HIGH);

    expander.getPin(MCP23017_GPA0).setValue(LOW);
    expander.getPin(MCP23017_GPA1).setValue(LOW);
    expander.getPin(MCP23017_GPA2).setValue(LOW);
    expander.getPin(MCP23017_GPA3).setValue(LOW);

    expander.write();
    //drawing number
    if(tmp[i] == '0') zero() ;
    else if(tmp[i] == '1') one() ;
    else if(tmp[i] == '2') two() ;
    else if(tmp[i] == '3') three() ;
    else if(tmp[i] == '4') four() ;
    else if(tmp[i] == '5') five() ;
    else if(tmp[i] == '6') six() ;
    else if(tmp[i] == '7') seven() ;
    else if(tmp[i] == '8') eight() ;
    else if(tmp[i] == '9') nine() ;




    if(index == 0) {
      expander.getPin(MCP23017_GPA0).setValue(HIGH);
      if(dp1) expander.getPin(MCP23017_GPB7).setValue(LOW);
    }
    if(index == 1) {
      expander.getPin(MCP23017_GPA1).setValue(HIGH);
      if(dp2) expander.getPin(MCP23017_GPB7).setValue(LOW);
    }
    if(index == 2) {
      expander.getPin(MCP23017_GPA2).setValue(HIGH);
      if(dp3) expander.getPin(MCP23017_GPB7).setValue(LOW);
    }
    if(index == 3) {
      expander.getPin(MCP23017_GPA3).setValue(HIGH);
      if(dp4) expander.getPin(MCP23017_GPB7).setValue(LOW);
    }
    expander.write();
    //delay(200) ;
    //Serial.println(String(index)+" == "+ tmp[i]);
    index++ ;
  }

  //all off
  expander.getPin(MCP23017_GPB0).setValue(HIGH);
  expander.getPin(MCP23017_GPB1).setValue(HIGH);
  expander.getPin(MCP23017_GPB2).setValue(HIGH);
  expander.getPin(MCP23017_GPB3).setValue(HIGH);
  expander.getPin(MCP23017_GPB4).setValue(HIGH);
  expander.getPin(MCP23017_GPB5).setValue(HIGH);
  expander.getPin(MCP23017_GPB6).setValue(HIGH);
  expander.getPin(MCP23017_GPB7).setValue(HIGH);

  expander.getPin(MCP23017_GPA0).setValue(LOW);
  expander.getPin(MCP23017_GPA1).setValue(LOW);
  expander.getPin(MCP23017_GPA2).setValue(LOW);
  expander.getPin(MCP23017_GPA3).setValue(LOW);

  expander.write();

}


void setup() {
  currentValue = "1997" ;
  // pinMode(3, OUTPUT);
  // TCCR2A = 0x23;
  // TCCR2B = 0x09;
  // OCR2A = 15;
  // OCR2B = 1;
  Serial.begin(115200);
  if(mynetwork_init()) Serial.println("IP:"+mynetwork_localIP());
  else Serial.println("network Failed ...") ;
ether.packetLoop(ether.packetReceive());

// initialize TwoWire communication
Wire.begin();

// set GPB0 to be an output (LED)
expander.getPin(MCP23017_GPB0).setPinMode(OUTPUT);
expander.getPin(MCP23017_GPB1).setPinMode(OUTPUT);
expander.getPin(MCP23017_GPB2).setPinMode(OUTPUT);
expander.getPin(MCP23017_GPB3).setPinMode(OUTPUT);
expander.getPin(MCP23017_GPB4).setPinMode(OUTPUT);
expander.getPin(MCP23017_GPB5).setPinMode(OUTPUT);
expander.getPin(MCP23017_GPB6).setPinMode(OUTPUT);
expander.getPin(MCP23017_GPB7).setPinMode(OUTPUT);

expander.getPin(MCP23017_GPA0).setPinMode(OUTPUT);
expander.getPin(MCP23017_GPA1).setPinMode(OUTPUT);
expander.getPin(MCP23017_GPA2).setPinMode(OUTPUT);
expander.getPin(MCP23017_GPA3).setPinMode(OUTPUT);

// // set GPB0 to be inverted (pull to ground instead of up)
// expander.getPin(MCP23017_GPB0).setPolarityInvert(true);
// set GPA0 to be an input (push button)
//expander.getPin(MCP23017_GPA0).setPinMode(INPUT);

// setup the MCP23017
expander.setup();
}

void loop() {
  //this must be called for ethercard functions to work.
  ether.packetLoop(ether.packetReceive());
  if(udpBuffer.length() != 0)
  {
    if( udpBuffer.indexOf("<digit>") >= 0)
    {
        udpBuffer.replace("<digit>","");
        currentValue = udpBuffer ;

    }
    else if( udpBuffer.indexOf("<DP1>") >= 0)
    {
        udpBuffer.replace("<DP1>","");
        dp1 = false ;
        if(udpBuffer.toInt() == 1 ) dp1 = true ;
    }
    else if( udpBuffer.indexOf("<DP2>") >= 0)
    {
        udpBuffer.replace("<DP2>","");
        dp2 = false ;
        if(udpBuffer.toInt() == 1 ) dp2 = true ;
    }
    else if( udpBuffer.indexOf("<DP3>") >= 0)
    {
        udpBuffer.replace("<DP3>","");
        dp3 = false ;
        if(udpBuffer.toInt() == 1 ) dp3 = true ;
    }
    else if( udpBuffer.indexOf("<DP4>") >= 0)
    {
        udpBuffer.replace("<DP4>","");
        dp4 = false ;
        if(udpBuffer.toInt() == 1 ) dp4 = true ;
    }
    udpBuffer = "" ;
  }

  numberToDigite(currentValue);


}
