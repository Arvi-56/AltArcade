
const int LIGHT_PIN = A0; // Pin connected to voltage divider output
const int LED_PIN = 17; // Use built-in LED as dark indicator

// Measure the voltage at 5V and the actual resistance of your
// 47k resistor, and enter them below:
const float VCC = 5.5; // Measured voltage of Ardunio 5V line
const float R_DIV = 4660.0; // Measured resistance of 3.3k resistor

// Set this to the minimum resistance require to turn an LED on:
const float DARK_THRESHOLD = 15000.0;

int kill=0; //setting counter for kill switch
/********************* go to deep sleep parameters *********************/
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
  pinMode(LIGHT_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
  
}

void loop() 
{
  // Read the ADC, and calculate voltage and resistance from it
  int lightADC = analogRead(LIGHT_PIN);
  if (lightADC >= 0)
  {
    // Use the ADC reading to calculate voltage and resistance
    float lightV = lightADC * VCC / 1023.0;
    float lightR = R_DIV * (VCC / lightV - 1.0);
    Serial.println("Voltage: " + String(lightV) + " V");
    Serial.println("Resistance: " + String(lightR) + " ohms");

    // If resistance of photocell is greater than the dark
    // threshold setting, turn the LED on.
    if (lightR <= DARK_THRESHOLD)
   {
      digitalWrite(LED_PIN, HIGH);
      Keyboard.press(KEY_A);
      Keyboard.release(KEY_A);
      kill=kill+1;
      
   }
    else
    {
      digitalWrite(LED_PIN, LOW);
    }

    if(kill>=100000) //amount of keystrokes before kill switch (needs to be a very big #)
    {
      gotoSleep();
    }

    Serial.println();
    delay(250);
  }
}

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
