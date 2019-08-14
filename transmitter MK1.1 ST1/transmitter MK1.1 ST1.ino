#include <TM1637Display.h>
#include <VirtualWire.h>
#include <Arduino.h>
int rev_sec;
int arm_pin=1;
int trigger_pin=1;
int c=0;

const int CLK = 2; //Set the CLK pin connection to the display
const int DIO = 3; 

void setup()
    {
        Serial.begin(9600);   // Debugging only
        Serial.println("setup");
        vw_set_ptt_inverted(true); // Required for DR3100
        vw_setup(4000);      // Bits per sec
        pinMode(10,OUTPUT);
    
    
     }

 TM1637Display display(CLK, DIO);

void loop()
    {
        int i=10;    // for delay
        display.setBrightness(0x0f);
        uint8_t data[] = { 0x0, 0x0, 0x0, 0x0 };
        
        while((trigger_pin)==1 && (arm_pin)==1)
           {
            const int up=10;
        rev_sec=up-(millis()/1000);
       
         while(rev_sec!=0)
          {
          rev_sec=up-(millis()/1000);
          
          Serial.println(rev_sec);
          display.setSegments(data);
         display.showNumberDec(rev_sec);                                  
    
           
              }
//                if(digitalRead(trigger_pin) == 0);
//                break;
                
                Serial.println(i);
                const char *msg = "1";
    
    vw_send((uint8_t *)msg, strlen(msg));
    vw_wait_tx(); // Wait until the whole message is gone
    Serial.print("SENDING :");
    Serial.println(msg);
               
                
           }

    }




















  
//    void loop()
//    {
//      
//        display.setBrightness(0x0f);
//        uint8_t data[] = { 0x0, 0x0, 0x0, 0x0 };
//        const int up=10;
//        rev_sec=up-(millis()/1000);
//        Serial.print("Time elapsed in seconds:");
//         while(rev_sec!=0)
//          {
//          rev_sec=up-(millis()/1000);
//          Serial.println(rev_sec);
//          display.setSegments(data);
//          display.showNumberDec(rev_sec);                                  
//    
//          }   
//   // Serial.println(rev_sec);
//    display.showNumberDec(rev_sec);                               
//    digitalWrite(10,HIGH);
////    delay(300);
//    digitalWrite(10,LOW);
//    const char *msg = "1";
//   // digitalWrite(13, HIGH); // Flash a light to show transmitting
//    vw_send((uint8_t *)msg, strlen(msg));
//    vw_wait_tx(); // Wait until the whole message is gone
//    Serial.print("SENDING :");
//    Serial.println(msg);
//    //digitalWrite(13,LOW);
//    //delay(200);
//}




















//display.setBrightness(0x0f);
//
// 
//  display.setSegments(data);
//  display.showNumberDec(23, false, 2,1);
//  delay(TEST_DELAY);
//  
//  display.setSegments(data);
//  display.showNumberDec(153, false, 3, 1);
//  delay(TEST_DELAY);
//
//  display.setSegments(data);
//  for(int i=0; i<=500; i++)
//  {
//    display.showNumberDec(i);
//  }







 /*
  * 
                                            


    
  */
