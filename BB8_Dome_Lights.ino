/*
 * BB8 Dome Lights
 * RADAR Eye - Chase Sequence
 * PSI, Hololens and Dome Logic Lights on odd time interval, faking a random blink pattern.
 */

// Which pins are connected to which LED
const byte greenLED = 2;  // Green Dome Logic Light
const byte yellowLED = 3; // Yellow Dome Logic Light
const byte blueLED = 4; // Blue Dome Logic Light
const byte holoLED = 5; // Hololens
const byte psiLED = 6; // PSI
byte ledPins[] = { 8, 9, 10, 11, 12, 13}; //Radar Eye Array 

// Time periods of blinks in milliseconds (1000 to a second).
const unsigned long greenLEDinterval = 666;
const unsigned long yellowLEDinterval = 999;
const unsigned long blueLEDinterval = 444;
const unsigned long holoLEDinterval = 4381;
const unsigned long psiLEDinterval = 2563;
long previousMillis ;
long interval = 150;
byte i = 0;

// Variable holding the timer value so far. One for each "Timer"
unsigned long greenLEDtimer;
unsigned long yellowLEDtimer;
unsigned long blueLEDtimer;
unsigned long holoLEDtimer;
unsigned long psiLEDtimer;

void setup () 
  {
 for (int thisPin = 0; thisPin < sizeof(ledPins); thisPin++) {
  pinMode(ledPins[thisPin], OUTPUT);
  pinMode (greenLED, OUTPUT);
  pinMode (yellowLED, OUTPUT);
  pinMode (blueLED, OUTPUT);
  pinMode (holoLED, OUTPUT);
  pinMode (psiLED, OUTPUT);
  greenLEDtimer = millis ();
  yellowLEDtimer = millis ();
  blueLEDtimer = millis ();
  holoLEDtimer = millis ();
  psiLEDtimer = millis ();
  }  // end of setup
  
 previousMillis = millis();
  }

void toggleGreenLED ()
  {
   if (digitalRead (greenLED) == LOW)
      digitalWrite (greenLED, HIGH);
   else
      digitalWrite (greenLED, LOW);

  // remember when we toggled it
  greenLEDtimer = millis ();  
  }  // end of toggleGreenLED

void toggleyellowLED ()
  {
   if (digitalRead (yellowLED) == LOW)
      digitalWrite (yellowLED, HIGH);
   else
      digitalWrite (yellowLED, LOW);

  // remember when we toggled it
  yellowLEDtimer = millis ();  
  }  // end of toggleyellowLED

void toggleblueLED ()
  {
   if (digitalRead (blueLED) == LOW)
      digitalWrite (blueLED, HIGH);
   else
      digitalWrite (blueLED, LOW);

  // remember when we toggled it
  blueLEDtimer = millis ();  
  }  // end of toggleblueLED

void toggleholoLED ()
  {
   if (digitalRead (holoLED) == LOW)
      digitalWrite (holoLED, HIGH);
   else
      digitalWrite (holoLED, LOW);

  // remember when we toggled it
  holoLEDtimer = millis ();  
  }  // end of toggleholoLED

  void togglepsiLED ()
  {
   if (digitalRead (psiLED) == LOW)
      digitalWrite (psiLED, HIGH);
   else
      digitalWrite (psiLED, LOW);

  // remember when we toggled it
  psiLEDtimer = millis ();  
  }  // end of togglepsiLED
  
void loop ()
  {

  // Handling the blink of Green LED.
  if ( (millis () - greenLEDtimer) >= greenLEDinterval)
     toggleGreenLED ();

  // The Yellow LED is controlled the same way as above. 
  if ( (millis () - yellowLEDtimer) >= yellowLEDinterval) 
    toggleyellowLED ();

  // The Blue LED is controlled the same way as above.
  if ( (millis () - blueLEDtimer) >= blueLEDinterval) 
    toggleblueLED ();

    // The Hololens LED is controlled the same way as above.
  if ( (millis () - holoLEDtimer) >= holoLEDinterval)
     toggleholoLED ();

     // The PSI LED is controlled the same way as above. 
  if ( (millis () - psiLEDtimer) >= psiLEDinterval)
     togglepsiLED ();

    if (millis() - previousMillis > interval) {
    previousMillis = millis();

    if ( i < sizeof(ledPins) - 1 ) {
      // Turn off the previous LED
      digitalWrite(ledPins[i], LOW);

      // Turn on the next LED
      digitalWrite(ledPins[++i ], HIGH);
    }

    else if  (i == sizeof(ledPins) - 1 )   {
      // Last event
      i = 0;
      previousMillis = millis();
      digitalWrite(ledPins[i ], HIGH);
      digitalWrite(ledPins[ sizeof(ledPins) - 1 ], LOW);
    }

/* Other code that needs to execute goes here.
   It will be called many thousand times per second because the above code
   does not wait for the LED blink interval to finish. */

    }}  // end of loop
