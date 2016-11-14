int setCycles;

void set(int cycles)
{
  char oldSREG;
  int dtyCycle = cycles * o.5;
  if (dutyCycle < 6)
  {
    dutyCycle = 6;
  }
  if (cycles < 50)
  {
    cycles = 50;
  }
  oldSREG = SREG;
  cli ();
  ICR1 = cycles;
  OCR1A = dutyCycle;
  SREG = oldSREG;
}

void setup() {
  TCCR1A = 0;
  TCCR1B = _BV(WGM13);
  TCCR1B &= ~(_BV(CS10) | _BV(CS12));
  TCCR1B |= _BV(CS10);
  DDRB |= _BV(PORTB1);
  TCCR1A |= _BV(COM1A1);
  // put your setup code here, to run once:

}

void loop() {
  int temp _cycles = analogRead(A0);
  if (temp_cycles != setCycles)
  {
    setCycles = temp_cycles;
    set(setCycles);
  }
  // put your main code here, to run repeatedly:

}
