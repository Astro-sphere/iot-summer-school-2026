// Ultra Duel - ESP32 sketch (ultrasonic + IR, no button)
// Uploads to the ESP32 via the Arduino IDE.
// Prints one line the laptop game reads:  D,<distance>,<fire>

const int TRIG   = 32;   // HC-SR04 Trig
const int ECHO   = 33;   // HC-SR04 Echo
const int IR_PIN = 25;   // IR sensor OUT

// --- median filter buffer (smooths the jumpy ultrasonic) ---
const int N = 5;
long samples[N];
int idx = 0;

long readDistanceCM() {
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);
  long dur = pulseIn(ECHO, HIGH, 30000); // wait up to 30 ms for the echo
  if (dur == 0) return -1;               // no echo received
  return dur / 58;                       // microseconds -> centimetres
}

long medianOf(long *a, int n) {
  long b[N];
  for (int i = 0; i < n; i++) b[i] = a[i];
  for (int i = 0; i < n - 1; i++)
    for (int j = i + 1; j < n; j++)
      if (b[j] < b[i]) { long t = b[i]; b[i] = b[j]; b[j] = t; }
  return b[n / 2];
}

void setup() {
  Serial.begin(115200);
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
  pinMode(IR_PIN, INPUT);
  for (int i = 0; i < N; i++) samples[i] = 0;
  delay(300);
}

void loop() {
  long raw = readDistanceCM();
  if (raw > 0) { samples[idx] = raw; idx = (idx + 1) % N; }
  long filtered = medianOf(samples, N);

  // Most IR sensors read LOW when they detect something.
  // If FIRE is stuck at 1, change LOW to HIGH below.
  bool fire = (digitalRead(IR_PIN) == LOW);

  // one clean line for the laptop game:  D,<distance>,<fire>
  Serial.print("D,");
  Serial.print(filtered);
  Serial.print(",");
  Serial.println(fire ? 1 : 0);

  delay(60);   // HC-SR04 needs ~60 ms between reads
}