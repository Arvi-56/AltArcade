#define LEDPIN 17        //LED brightness (PWM) writing
#define LIGHTSENSORPIN A0 //Ambient light sensor reading
#define keystroke "Meow "

void setup() 
{
  pinMode(LIGHTSENSORPIN,  INPUT);  
  pinMode(LEDPIN, OUTPUT);  
}

void loop() 
{
  float reading = analogRead(LIGHTSENSORPIN); //Read light level
  float square_ratio = reading / 1023.0;      //Get percent of maximum value (1023)
  square_ratio = pow(square_ratio, 2.0);      //Square to make response more obvious
  float inverse = 1/(255.0 * square_ratio);   //inverse so low light makes a high number
  
  if (inverse > 10)
  {
    analogWrite(LEDPIN, 255);
    Keyboard.print(keystroke);
  }
  
//build counter and keyswitch, make crimped jst polarized connector, solder perfboars with headers
  
  else
  {
    analogWrite(LEDPIN, 0);
  }
}
