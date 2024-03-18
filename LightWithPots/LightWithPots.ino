#define RED 22
#define GREEN 21
#define BLUE 19
#define WHITE 17
#define BRIGHTNESS 34
#define SATURATION 39
#define COLOR 36
void setup() {
  Serial.begin(115200);
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
  pinMode(WHITE, OUTPUT);

}

void loop() {
    float brightness_value = (float) analogRead(BRIGHTNESS) / 4095;
    brightness_value = 1 - brightness_value;
    float saturation_value = (float) analogRead(SATURATION) / 4095;
    saturation_value = 1 - saturation_value;
    float color_value = (float) (4095 - analogRead(COLOR)) / 652;

    uint8_t r = uint8_t(127.5 * (cos(color_value) + 1));
    uint8_t g = uint8_t(127.5 * (sin(color_value) + 1));
    uint8_t b = uint8_t(255 - (r + g) / 2);

    analogWrite(RED, (float) saturation_value * brightness_value * r * 0.5);
    analogWrite(GREEN, (float) saturation_value * brightness_value * g);
    analogWrite(BLUE, (float) saturation_value * brightness_value * b * 0.5);
    analogWrite(WHITE, (float) 255 * brightness_value * (1 - saturation_value));
    delay(10);
    Serial.print("BRIGHTNESS: ");
    Serial.print(brightness_value);
    Serial.print(", SATURATION: ");
    Serial.print(saturation_value);
    Serial.print(", COLOR: ");
    Serial.println(color_value);
}
