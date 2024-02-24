// #include <Arduino_FreeRTOS.h> // For Arduino Nano
#include <STM32FreeRTOS.h>

void TaskBlink(void *params);

void setup() {
  // put your setup code here, to run once:
  pinMode(LED_BUILTIN, OUTPUT);
  
  xTaskCreate(TaskBlink, "Blink", 128, NULL, 2, NULL);
  vTaskStartScheduler();
}

void loop() {
  // put your main code here, to run repeatedly:

}

void TaskBlink(void *params) {
  for(;;) {
    digitalWrite(LED_BUILTIN, HIGH);
    vTaskDelay(250 / portTICK_PERIOD_MS);
    digitalWrite(LED_BUILTIN, LOW);
    vTaskDelay(250 / portTICK_PERIOD_MS); 
  }
}
