// Pin assignments //
const int buzzer = 8;
const int toggle_switch = 7
const int photocell = A0;

// Initialize values //
int freq = 1000;
int light_val = 0;
int switch_state = 0;

void setup() {
  // Pin mode assignment //
  pinMode(buzzer, OUTPUT);
  pinMode(toggle_switch, INPUT);
}

void loop() {
  // Get switch state //
  switch_state = digitalRead(toggle_switch);

  // Get photoresistor value //
  light_val = analogRead(photocell);

  // Calculate output frequency //
  freq = 200 + light_val / 4;

  if(switch_state == HIGH){
    // Update buzzer pitch //
    tone(buzzer, freq);
  }

  // If switch is off, turn off buzzer //
  else{
    noTone(buzzer);
  }
}
