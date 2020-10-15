#define LDR_PIN PB1

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
}

void loop()
{
    int intensity = analogRead(LDR_PIN);
    snprintf(buffer, sizeof(buffer), "Light intensity: %i", intensity);
    Serial.println(buffer);
    delay(2000);
}