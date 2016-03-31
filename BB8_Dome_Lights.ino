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
int direction = 1;

// Variable holding the LastUpdate value so far. One for each "LastUpdate"
unsigned long greenLEDLastUpdate;
unsigned long yellowLEDLastUpdate;
unsigned long blueLEDLastUpdate;
unsigned long holoLEDLastUpdate;
unsigned long psiLEDLastUpdate;

void setup () 
  {
 for (int thisPin = 0; thisPin < sizeof(ledPins); thisPin++) {
  pinMode(ledPins[thisPin], OUTPUT);
  pinMode (greenLED, OUTPUT);
  pinMode (yellowLED, OUTPUT);
  pinMode (blueLED, OUTPUT);
  pinMode (holoLED, OUTPUT);
  pinMode (psiLED, OUTPUT);
  greenLEDLastUpdate = millis ();
  yellowLEDLastUpdate = millis ();
  blueLEDLastUpdate = millis ();
  holoLEDLastUpdate = millis ();
  psiLEDLastUpdate = millis ();
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
  greenLEDLastUpdate = millis ();  
  }  // end of toggleGreenLED

void toggleyellowLED ()
  {
   if (digitalRead (yellowLED) == LOW)
      digitalWrite (yellowLED, HIGH);
   else
      digitalWrite (yellowLED, LOW);

  // remember when we toggled it
  yellowLEDLastUpdate = millis ();  
  }  // end of toggleyellowLED

void toggleblueLED ()
  {
   if (digitalRead (blueLED) == LOW)
      digitalWrite (blueLED, HIGH);
   else
      digitalWrite (blueLED, LOW);

  // remember when we toggled it
  blueLEDLastUpdate = millis ();  
  }  // end of toggleblueLED

void toggleholoLED ()
  {
   if (digitalRead (holoLED) == LOW)
      digitalWrite (holoLED, HIGH);
   else
      digitalWrite (holoLED, LOW);

  // remember when we toggled it
  holoLEDLastUpdate = millis ();  
  }  // end of toggleholoLED

  void togglepsiLED ()
  {
   if (digitalRead (psiLED) == LOW)
      digitalWrite (psiLED, HIGH);
   else
      digitalWrite (psiLED, LOW);

  // remember when we toggled it
  psiLEDLastUpdate = millis ();  
  }  // end of togglepsiLED
  
void loop ()
  {

  // Handling the blink of Green LED.
  if ( (millis () - greenLEDLastUpdate) >= greenLEDinterval)
     toggleGreenLED ();

  // The Yellow LED is controlled the same way as above. 
  if ( (millis () - yellowLEDLastUpdate) >= yellowLEDinterval) 
    toggleyellowLED ();

  // The Blue LED is controlled the same way as above.
  if ( (millis () - blueLEDLastUpdate) >= blueLEDinterval) 
    toggleblueLED ();

    // The Hololens LED is controlled the same way as above.
  if ( (millis () - holoLEDLastUpdate) >= holoLEDinterval)
     toggleholoLED ();

     // The PSI LED is controlled the same way as above. 
  if ( (millis () - psiLEDLastUpdate) >= psiLEDinterval)
     togglepsiLED ();

  if (millis() - previousMillis > interval) {
    previousMillis = millis();
    
    for(int n = 0; n < sizeof(ledPins); n++ ){  //turns off all sweeper leds
      digitalWrite(ledPins[n], LOW);
    }

    digitalWrite(ledPins[i], HIGH);
    
    if (i == sizeof(ledPins) - 1) {
      direction = -1;
    } 

    if (i == 0) {
      direction = 1;
    }

    i += direction;

/* Other code that needs to execute goes here.
   It will be called many thousand times per second because the above code
   does not wait for the LED blink interval to finish. */

  }
}  // end of loop
