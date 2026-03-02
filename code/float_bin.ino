#define BLYNK_TEMPLATE_ID "YourTemplateID"
#define BLYNK_TEMPLATE_NAME "FloatBin"
#define BLYNK_AUTH_TOKEN "YourAuthToken"

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// WiFi credentials
char ssid[] = "YourWiFiName";
char pass[] = "YourWiFiPassword";

// Relay pin (connected to D1)
#define RELAY_PIN D1

void setup()
{
  Serial.begin(9600);

  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, HIGH);   // Relay OFF (active LOW relay)

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
}

// Blynk Button Widget (Virtual Pin V0)
BLYNK_WRITE(V0)
{
  int buttonState = param.asInt();

  if (buttonState == 1)
  {
    digitalWrite(RELAY_PIN, LOW);   // Turn pump ON
    Serial.println("Pump ON");
  }
  else
  {
    digitalWrite(RELAY_PIN, HIGH);  // Turn pump OFF
    Serial.println("Pump OFF");
  }
}

void loop()
{
  Blynk.run();
}
