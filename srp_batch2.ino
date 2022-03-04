int Status=0;
#include <SoftwareSerial.h>

SoftwareSerial mySerial(9, 10);

void setup()
{
  pinMode(2,INPUT);
  mySerial.begin(9600);   // Setting the baud rate of GSM Module  
  Serial.begin(9600);    // Setting the baud rate of Serial Monitor (Arduino)
  delay(100);
}


void loop()
{
Status=digitalRead(4);
  if (Status=='1')
{
 void SendMessage();
 Serial.println("detected ");
 delay(20);
}
else
{
 Serial.println("not detected ");
 delay(1000);
}
}




 void SendMessage()
{
  mySerial.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode
  delay(1000);  // Delay of 1000 milli seconds or 1 second

  mySerial.println("AT+CMGS=\"+919494330461\"\r"); // Replace x with mobile number
  delay(1000);
  mySerial.println("Help,I am in Trouble.Save Me");// The SMS text you want to send
  delay(100);
  mySerial.println((char)26);// ASCII code of CTRL+Z
  delay(1000);

  //mySerial.println("AT+CMGS=\"+917337500244\"\r"); // Replace x with mobile number
  //delay(1000);
  //mySerial.println("Help,I am in Trouble.Save Me");// The SMS text you want to send
  //delay(100);
  //mySerial.println((char)26);// ASCII code of CTRL+Z
  //delay(1000);
}
