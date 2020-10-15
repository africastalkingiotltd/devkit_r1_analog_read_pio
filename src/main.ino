// #include <Arduino.h> only  needed if this is a cpp file

#define LDR_PIN PB1
#define LED_PIN PC13

char buffer[100];

void setup()
{
    Serial.begin(115200);
    delay(100);
    while(!Serial)
    {
        ;
    }
    pinMode(LDR_PIN, INPUT_ANALOG);
    pinMode(LED_PIN, OUTPUT);
}

void loop()
{
    int intensity = analogRead(LDR_PIN);
    snprintf(buffer, sizeof(buffer), "Light intensity: %i", intensity);
    Serial.println(buffer);
    analogWrite(LED_PIN, intensity / 4);
    delay(2000);
}