// Pin assignments //
const int buzzer = 8;
const int toggle_switch = 7;
const int photocell = A0;

// Initialize values //
int freq;
int min_freq = 100;
int max_freq = 10000;
int min_light = 0;
int max_light = 1000;
int light_val = 0;
int switch_state = 0;

void setup() {
  // Pin mode assignment //
  pinMode(buzzer, OUTPUT);
  pinMode(toggle_switch, INPUT);
  Serial.begin(9600);
}

void loop() {
  // Get switch state //
  switch_state = digitalRead(toggle_switch);

  // Get photoresistor value //
  light_val = analogRead(photocell);

  // Calculate output frequency //
  freq = map(light_val, min_light, max_light, min_freq, max_freq);

  if(switch_state == HIGH){
    // Update buzzer pitch //
    tone(buzzer, freq);
  }

  // If switch is off, turn off buzzer //
  else{
    noTone(buzzer);
  }

//  Serial.print("Photocell: ");
//  Serial.print(light_val);
//  Serial.print(", Frequency: ");
//  Serial.print(freq);
//  Serial.print("\n");
//
  delay(100);
}
