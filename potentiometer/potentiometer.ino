const int redLED = 5;
const int greenLED = 3;
const int blueLED = 6;
int colorMode, red, green, blue;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(8,INPUT);
  pinMode(redLED,OUTPUT);
  pinMode(greenLED,OUTPUT);
  pinMode(blueLED,OUTPUT);
  colorMode = redLED;
  red = 0;
  green = 0;
  blue = 0;
  }

void loop() {
  // put your main code here, to run repeatedly:
  int value = analogRead(0);
  value = map(value, 0, 1023, 0, 255);
  if (colorMode == redLED){
    red = value;
  } else if (colorMode == greenLED){
    green = value;
  } else if (colorMode == blueLED) {
    blue = value;
  } else {
    //nothing happens here
  }
  shine(red, green, blue);
  Serial.println(value);
  if (digitalRead(8)==HIGH) {
    colorMode = changeColor(colorMode);
  }
  delay(20);
}

int changeColor(int colorMode) {
  if (colorMode==redLED){
    colorMode=greenLED;
    blink(0, 255, 0);  
  } else if (colorMode==greenLED){
    colorMode=blueLED;
    blink(0, 0, 255);
  } else if (colorMode == blueLED){
    colorMode=0;
    blink(255, 255, 255);
  } else {
    colorMode=redLED;
    blink(255, 0, 0);
  }
  delay(500);
  return colorMode;
}

void blink(int red, int green, int blue) {
  shine(red, green, blue);
  delay(500);
  shine(0, 0, 0);
  delay(500);
  shine(red, green, blue);
  return;
}

void shine(int red, int green, int blue){
  analogWrite(redLED, red);
  analogWrite(greenLED, green);
  analogWrite(blueLED, blue);
  return;
}
