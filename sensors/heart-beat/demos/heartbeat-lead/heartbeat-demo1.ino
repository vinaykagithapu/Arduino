// Ultra-stable heartbeat detector for KY-039 (low signal sensors)

int pulsePin = A0;
int ledPin = 9;

float filtered = 0;
float alpha = 0.90;        // Smooth but responsive
float baseline = 0;
float baselineAlpha = 0.999;   // VERY slow-moving baseline

unsigned long lastBeat = 0;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);

  // Initial baseline from first reading
  baseline = analogRead(pulsePin);
  filtered = baseline;
}

void loop() {

  int raw = analogRead(pulsePin);

  // Smooth reading (EMA)
  filtered = (alpha * filtered) + ((1 - alpha) * raw);

  // Baseline follows finger slowly
  baseline = (baselineAlpha * baseline) + ((1 - baselineAlpha) * filtered);

  // Calculate deviation from baseline
  float deviation = filtered - baseline;

  // Heartbeat = small bump above baseline (+1.2)
  if (deviation > 1.2) {
    unsigned long now = millis();

    // Ignore noise after recent beat
    if (now - lastBeat > 300) {
      lastBeat = now;

      // LED blink
      digitalWrite(ledPin, HIGH);
      delay(50);
      digitalWrite(ledPin, LOW);

      Serial.println("Beat detected!");
    }
  }

  // Debug output
  Serial.print("Raw: ");
  Serial.print(raw);
  Serial.print(" | Filtered: ");
  Serial.print(filtered);
  Serial.print(" | Baseline: ");
  Serial.print(baseline);
  Serial.print(" | Deviation: ");
  Serial.println(deviation);

  delay(5);
}
