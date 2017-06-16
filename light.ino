#include <Adafruit_NeoPixel.h>

#define LIGHT_PIN       8

#define BRIGHTNESS_PIN  A0
#define SOUND_PIN       A2

#define BRIGHTNESS_THRESHOLD  100
#define VOLUME_THRESHOLD      400

#define LIGHT_ON_TIME         5000

Adafruit_NeoPixel Light =
    Adafruit_NeoPixel(1, LIGHT_PIN, NEO_GRB + NEO_KHZ800);

void setup()
{
    Light.begin();
    pinMode(BRIGHTNESS_PIN, INPUT);
    pinMode(SOUND_PIN, INPUT);
}

void loop()
{
    int brightness = analogRead(BRIGHTNESS_PIN);
    int volume     = analogRead(SOUND_PIN);

    if (brightness < BRIGHTNESS_THRESHOLD &&
            volume > VOLUME_THRESHOLD) {
        Light.setPixelColor(0, Light.Color(255, 255, 255));
        Light.show();
        delay(LIGHT_ON_TIME); // Keep on for given time
    } else {
        Light.setPixelColor(0, Light.Color(0, 0, 0));
        Light.show();
    }
}
