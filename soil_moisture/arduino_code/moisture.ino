const int dry = 436;
const int wet = 251;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // // put your main code here, to run repeatedly:
  int sensorVal = analogRead(A0);

  int percentageHumidity = map(sensorVal, wet, dry, 100, 0);


  Serial.print(percentageHumidity);
  Serial.println("%");

  delay(100);
}