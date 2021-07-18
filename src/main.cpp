#include <Arduino.h>

TaskHandle_t Core0;

// LED pins
const int led1 = 2;
const int led2 = 4;

void LoopCore0( void * pvParameters );

void setup() {
  Serial.begin(115200); 
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);

  //create a task that will be executed in the Task1code() function, with priority 1 and executed on core 0
  xTaskCreatePinnedToCore(
                    LoopCore0,   /* Task function. */
                    "Core0",     /* name of task. */
                    10000,       /* Stack size of task */
                    NULL,        /* parameter of the task */
                    1,           /* priority of the task */
                    &Core0,      /* Task handle to keep track of created task */
                    0);          /* pin task to core 0 */                  
  delay(500); 
}

//Task1code: blinks an LED every 1000 ms
void LoopCore0(void * pvParameters ){
  Serial.print("Task on Core ");
  Serial.println(xPortGetCoreID());

  for(;;){
    Serial.println("Task loop " + xPortGetCoreID());  
    digitalWrite(led1, HIGH);
    delay(800);
    digitalWrite(led1, LOW);
    delay(800);
  } 
}

void loop() {
  
Serial.print("Task on Core ");
  Serial.println(xPortGetCoreID());

  for(;;){
    Serial.println(" Main loop " + xPortGetCoreID());  
    digitalWrite(led1, HIGH);
    delay(1000);
    digitalWrite(led1, LOW);
    delay(1000);
  }

}