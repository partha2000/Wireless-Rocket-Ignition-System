
#include <VirtualWire.h>
int ledpin =10;
int relay=6;
void setup()
{
    Serial.begin(9600); // Debugging only
    Serial.println("setup");
    vw_set_ptt_inverted(true); // sets the state to high
    vw_setup(4000);      // Bits per sec
    vw_rx_start();       // Start the receiver 
    pinMode(ledpin,OUTPUT);
    pinMode(relay,OUTPUT);
}
void loop()
{
    char ch;
    uint8_t buf[VW_MAX_MESSAGE_LEN];
    uint8_t buflen = VW_MAX_MESSAGE_LEN;
    if (vw_get_message(buf, &buflen)) // Non-blocking
    {
       
        // int i;
        //digitalWrite(13, HIGH); // Flash a light to show received good message
        Serial.print("REcieved: ");
        
            ch=(char)buf[0];
            Serial.print((char)buf[0]);
            
        Serial.println(" ");
        if(ch=='1')
        {
          Serial.println("hiiiiiiiii");
        digitalWrite(relay,HIGH);
        delay(2000);
        digitalWrite(relay,LOW);
        
        }
        else 
        digitalWrite(relay,LOW);
        //digitalWrite(13, LOW);
    }
}
