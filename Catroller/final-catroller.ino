//screen /dev/cu.usbmodem47535501 9600
/********************* keystroke parameters *********************/
//Bottom Lvl
#define RT_1 KEY_D
#define LT_2 KEY_A

//Middle Lvl
#define UP_3 KEY_W
#define DWN_4 KEY_S

//Top Lvl
#define ALT_5 KEY_SPACE

/********************* pin parameters daws daw*********************/
//Bottom Lvl
const int PIN_1 = 16; // Pin connected to voltage divider output
const int PIN_2 = 17;

//Middle Lvl
const int PIN_3 = 20;
const int PIN_4 = 22;

//Top Lvl
const int PIN_5 = 23;

//LED Feedback
const int LED_PIN = A0; 


/********************* mapping resistance parameters *********************/
// Measure the voltage at 5V and the actual resistance of your
// 47k resistor, and enter them below:
const float VCC = 5.5; // Measured voltage of Ardunio 5V line
const float R_DIV = 4660.0; // Measured resistance of 3.3k resistor

// This is how you calibrate in different lighting
//Set this to the minimum resistance require to turn an LED on:
const float DARK_THRESHOLD = 900;


/********************* go to deep sleep parameters *********************/
int kill=0; //setting counter for kill switch

#define SMC_PMPROT_AVLLS_MASK   0x2u
#define SMC_PMCTRL_STOPM_MASK   0x7u
#define SCB_SCR_SLEEPDEEP_MASK  0x4u

// see SMC section (e.g. p 339 of K66) 
#define VLLS3 0x3  // RAM retained I/O states held
#define VLLS2 0x2 // RAM partially retained
#define VLLS1 0x1 // I/O states help
#define VLLS0 0x0 // all stop

#define VLLS_MODE VLLS0


void setup() 
{
  Serial.begin(9600);
  
  pinMode(PIN_1, INPUT);
  pinMode(PIN_2, INPUT);
  pinMode(PIN_3, INPUT);
  pinMode(PIN_4, INPUT);
  pinMode(PIN_5, INPUT);
  
  pinMode(LED_PIN, OUTPUT);
  
}

void loop() 
{
  // Read the ADC, and calculate voltage and resistance from it
  int lightADC1 = analogRead(PIN_1);
  int lightADC2 = analogRead(PIN_2);
  int lightADC3 = analogRead(PIN_3);
  int lightADC4 = analogRead(PIN_4);
  int lightADC5 = analogRead(PIN_5);

  //Pin 1 controls
  if (lightADC1 > 0)
  {
    // Use the ADC reading to calculate voltage and resistance 
    float lightV = lightADC1 * VCC / 1023.0;
    float lightR = R_DIV * (VCC / lightV - 1.0);
    Serial.println("Voltage: " + String(lightV) + " V");
    Serial.println("Resistance: " + String(lightR) + " ohms");

    // If resistance of photocell is greater than the dark
    // threshold setting, turn the LED on.
    if (lightR <= DARK_THRESHOLD)
    {
      digitalWrite(LED_PIN, HIGH);
      Keyboard.press(RT_1);
      Keyboard.release(RT_1);
      Serial.println("Right ");
      kill=kill+1;
    }
    else
    {
      digitalWrite(LED_PIN, LOW);
    }
    
    if(kill>=500000) //amount of keystrokes before kill switch (needs to be a very big #)
    {
      gotoSleep();
    }

    Serial.println();
  }
  
  //Pin 2 Controls
  if (lightADC2 > 0)
  {
    // Use the ADC reading to calculate voltage and resistance 
    float lightV = lightADC2 * VCC / 1023.0;
    float lightR = R_DIV * (VCC / lightV - 1.0);
    Serial.println("Voltage: " + String(lightV) + " V");
    Serial.println("Resistance: " + String(lightR) + " ohms");

    // If resistance of photocell is greater than the dark
    // threshold setting, turn the LED on.
    if (lightR <= DARK_THRESHOLD)
    {
      digitalWrite(LED_PIN, HIGH);
      Keyboard.press(LT_2);
      Keyboard.release(LT_2);
      Serial.println("Left ");
      kill=kill+1;
    }
    else
    {
      digitalWrite(LED_PIN, LOW);
    }

    if(kill>=500000) //amount of keystrokes before kill switch (needs to be a very big #)
    {
      gotoSleep();
    }

    Serial.println();
   }

   //Pin 3 Controls
  if (lightADC3 > 0)
  {
    // Use the ADC reading to calculate voltage and resistance 
    float lightV = lightADC3 * VCC / 1023.0;
    float lightR = R_DIV * (VCC / lightV - 1.0);
    Serial.println("Voltage: " + String(lightV) + " V");
    Serial.println("Resistance: " + String(lightR) + " ohms");

    // If resistance of photocell is greater than the dark
    // threshold setting, turn the LED on.
    if (lightR <= DARK_THRESHOLD)
    {
      digitalWrite(LED_PIN, HIGH);
      Keyboard.press(UP_3);
      Keyboard.release(UP_3);
      Serial.println("Up ");
      kill=kill+1;
    }
    else
    {
      digitalWrite(LED_PIN, LOW);
    }

    if(kill>=500000) //amount of keystrokes before kill switch (needs to be a very big #)
    {
      gotoSleep();
    }

    Serial.println();
   }

   //Pin 4 Controls
  if (lightADC4 > 0)
  {
    // Use the ADC reading to calculate voltage and resistance 
    float lightV = lightADC4 * VCC / 1023.0;
    float lightR = R_DIV * (VCC / lightV - 1.0);
    Serial.println("Voltage: " + String(lightV) + " V");
    Serial.println("Resistance: " + String(lightR) + " ohms");

    // If resistance of photocell is greater than the dark
    // threshold setting, turn the LED on.
    if (lightR <= DARK_THRESHOLD)
    {
      digitalWrite(LED_PIN, HIGH);
      Keyboard.press(DWN_4);
      Keyboard.release(DWN_4);
      Serial.println("Down ");
      kill=kill+1;
    }
    else
    {
      digitalWrite(LED_PIN, LOW);
    }

    if(kill>=500000) //amount of keystrokes before kill switch (needs to be a very big #)
    {
      gotoSleep();
    }

    Serial.println();
   } 

   //Pin 5 Controls
  if (lightADC5 > 0)
  {
    // Use the ADC reading to calculate voltage and resistance 
    float lightV = lightADC5 * VCC / 1023.0;
    float lightR = R_DIV * (VCC / lightV - 1.0);
    Serial.println("Voltage: " + String(lightV) + " V");
    Serial.println("Resistance: " + String(lightR) + " ohms");

    // If resistance of photocell is greater than the dark
    // threshold setting, turn the LED on.
    if (lightR <= DARK_THRESHOLD)
    {
      digitalWrite(LED_PIN, HIGH);
      Keyboard.press(ALT_5);
      Keyboard.release(ALT_5);
      Serial.println("Space ");
      kill=kill+1;
    }
    else
    {
      digitalWrite(LED_PIN, LOW);
    }

    if(kill>=500000) //amount of keystrokes before kill switch (needs to be a very big #)
    {
      gotoSleep();
    }

    Serial.println();
   }

   delay(250);
  
}

//Kill program from this thread https://forum.pjrc.com/threads/40745-command-for-shutdown-teensy
void gotoSleep(void)
{  
//  /* Make sure clock monitor is off so we don't get spurious reset */
//   MCG_C6 &= ~MCG_C6_CME0;
   //
   /* Write to PMPROT to allow all possible power modes */
   SMC_PMPROT = SMC_PMPROT_AVLLS_MASK;
   /* Set the STOPM field to 0b100 for VLLSx mode */
   SMC_PMCTRL &= ~SMC_PMCTRL_STOPM_MASK;
   SMC_PMCTRL |= SMC_PMCTRL_STOPM(0x4); // VLLSx

   SMC_VLLSCTRL =  SMC_VLLSCTRL_VLLSM(VLLS_MODE);
   /*wait for write to complete to SMC before stopping core */
   (void) SMC_PMCTRL;

   SYST_CSR &= ~SYST_CSR_TICKINT;      // disable systick timer interrupt
   SCB_SCR |= SCB_SCR_SLEEPDEEP_MASK;  // Set the SLEEPDEEP bit to enable deep sleep mode (STOP)
       asm volatile( "wfi" );  // WFI instruction will start entry into STOP mode
   // will never return, but call ResetHandler() in mk20dx128.c
}
