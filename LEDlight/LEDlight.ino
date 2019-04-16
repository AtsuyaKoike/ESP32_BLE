#define BLYNK_PRINT Serial
#define BLYNK_USE_DIRECT_CONNECT
#include <BlynkSimpleEsp32_BLE.h>
#include <BLEDevice.h>
#include <BLEServer.h>

const uint8_t LED_pin = 5;
const uint8_t LED_pin2 = 21;
char auth[]= "";

void setup()
{
  // Debug console
  Serial.begin(9600);
  Serial.println("Waiting for connections...");
  sigmaDeltaSetup(0, 312500);
  sigmaDeltaAttachPin(LED_pin, 0);
  sigmaDeltaAttachPin(LED_pin2, 1);
  sigmaDeltaWrite(0, 0);
  
  Blynk.begin(auth);
}

BLYNK_WRITE(V0){
  int LED_level = param[0].asInt();
  sigmaDeltaWrite(0, LED_level);
 
  Serial.printf("LEDpin#%d = %d\r\n", LED_pin, LED_level);
}
BLYNK_WRITE(V1){
  int LED_level = param[0].asInt();
  if ( LED_level == 1 ) LED_level = 255; 
  sigmaDeltaWrite(1, LED_level);
 
  Serial.printf("LEDpin#%d = %d\r\n", LED_pin2, LED_level);
}

void loop()
{
  Blynk.run();
}
