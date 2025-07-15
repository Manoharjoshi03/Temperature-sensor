const int analogPin = 35;
const int samples = 10;
const float offset = 8.0; // Calibration offset

void setup() {
  Serial.begin(115200);
  analogReadResolution(12); // 12-bit resolution (0–4095)
}

void loop() {
  long totalADC = 0;

  // Read multiple samples
  for (int i = 0; i < samples; i++) {
    totalADC += analogRead(analogPin);
    delay(10); // Small delay between readings
  }

  // Calculate average ADC value
  float avgADC = totalADC / (float)samples;

  // Convert ADC to voltage
  float voltage = (3.3 / 4095.0) * avgADC;

  // Calculate temperature in °C with offset
  float temperatureC = (voltage * 100.0) + offset;

  // Print values
  Serial.print("Avg ADC: ");
  Serial.print(avgADC);
  Serial.print(" | Voltage: ");
  Serial.print(voltage, 3);
  Serial.print(" V | Temp: ");
  Serial.print(temperatureC, 2);
  Serial.println(" °C");

  delay(1000); // 1-second update
}
