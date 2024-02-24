#include <Arduino_FreeRTOS.h>

void TaskBlink(void *params);

void setup() {
  // put your setup code here, to run once:
  pinMode(13, OUTPUT);
  
  xTaskCreate(TaskBlink, "Blink", 128, NULL, 2, NULL);
}

void loop() {
  // put your main code here, to run repeatedly:

}

void TaskBlink(void *params) {
  for(;;) {
    digitalWrite(13, HIGH);
    vTaskDelay(1000 / portTICK_PERIOD_MS);
    digitalWrite(13, LOW);
    vTaskDelay(1000 / portTICK_PERIOD_MS); 
  }
}
