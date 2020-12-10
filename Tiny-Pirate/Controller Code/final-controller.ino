/********************* keystroke parameters *********************/

#define button_key KEY_Q
#define slider_key KEY_SPACE
#define dial_key1 KEY_L
#define dial_key2 KEY_K
#define dial_key3 KEY_J
#define dial_key4 KEY_H
#define dial_key5 KEY_G
#define dial_key6 KEY_F
#define dial_key7 KEY_D
#define dial_key8 KEY_S
#define dial_key9 KEY_A

boolean buttonToggle;
boolean sliderToggle;

boolean dialToggle1;
boolean dialToggle2;
boolean dialToggle3;
boolean dialToggle4;
boolean dialToggle5;
boolean dialToggle6;
boolean dialToggle7;
boolean dialToggle8;
boolean dialToggle9;

/********************* pin parameters *********************/
//Bottom Lvl                                                                
const int button_pin = 20;
const int slider_pin = 18;
const int dial_pin = 16;


/********************* executed code *********************/
void setup() 
{
  // put your setup code here, to run once:
  Serial.begin(9600);

  //Controller Inputs  
  pinMode(button_pin, INPUT);
  pinMode(slider_pin, INPUT);
  pinMode(dial_pin, INPUT);

  buttonToggle = true;
  sliderToggle = true;
  
  dialToggle1 = true;
  dialToggle2 = true;
  dialToggle3 = true;
  dialToggle4 = true;
  dialToggle5 = true;
  dialToggle6 = true;
  dialToggle7 = true;
  dialToggle8 = true;
  dialToggle9 = true;
}

void loop() 
{
  // put your main code here, to run repeatedly:
  //read the inputs
  //button inputs 
  uint16_t val;
  uint16_t button_input;
  button_input = analogRead(button_pin);
  //slide pot input          
  uint16_t slider_input;
  slider_input = analogRead(slider_pin);
  //dial input
  uint16_t dial_input;
  dial_input = analogRead(dial_pin);
  val = (dial_input)/100;
  //val = (dial_input+56)*9/1017;
 
  Serial.println(button_input);
  //Serial.println(val); 
  
  //Serial.println(); 
  //Serial.println(slider_input);
  //Serial.println();
  //Serial.println(dial_input);
  //Serial.println();

  //Serial.println(buttonToggle);
//  Serial.println(sliderToggle);
//  Serial.println(dialToggle1);
//  Serial.println(dialToggle2);
//  Serial.println(dialToggle3);
//  Serial.println(dialToggle4);
//  Serial.println(dialToggle5);
//  Serial.println(dialToggle6);
//  Serial.println(dialToggle7); qq
//qqqqqqqq
  if (button_input < 190)
    {
      Keyboard.press(button_key);
      Serial.println("Button Press");
      sliderToggle = true;
    }
    else
    { 
      Keyboard.release(button_key);
      //Serial.println("Button Release");
    }

    if (slider_input <  50 && sliderToggle == true)
    {
      Keyboard.press(slider_key);
      Serial.println("Slider Shoot");
      sliderToggle = false;
    }
    else
    {
      Keyboard.release(slider_key);
      
    }

    //Dial setting 1

    if (val == 2 && dialToggle1 == true)
    {
      Keyboard.press(dial_key1);
      Keyboard.release(dial_key1);
      //Serial.println("Angle 9");
      dialToggle1 = false;
      dialToggle2 = true;
      dialToggle3 = true;
      dialToggle4 = true;
      dialToggle5 = true;
      dialToggle6 = true;
      dialToggle7 = true;
      dialToggle8 = true;
      dialToggle9 = true;
    }

    //Dial setting 2

    else if (val == 3 && dialToggle2 == true)
    {
      Keyboard.press(dial_key2);
      Keyboard.release(dial_key2);
      //Serial.println("Angle 8");
      dialToggle1 = true;
      dialToggle2 = false;
      dialToggle3 = true;
      dialToggle4 = true;
      dialToggle5 = true;
      dialToggle6 = true;
      dialToggle7 = true;
      dialToggle8 = true;
      dialToggle9 = true;
    }

    //Dial setting 3

    else if (val == 4 && dialToggle3 == true)
    {
      Keyboard.press(dial_key3);
      Keyboard.release(dial_key3);
      //Serial.println("Angle 7");
      dialToggle1 = true;
      dialToggle2 = true;
      dialToggle3 = false;
      dialToggle4 = true;
      dialToggle5 = true;
      dialToggle6 = true;
      dialToggle7 = true;
      dialToggle8 = true;
      dialToggle9 = true; 
    }

    //Dial setting 4

    else if (val == 5 && dialToggle4 == true)
    {
      Keyboard.press(dial_key4);
      Keyboard.release(dial_key4);
      //Serial.println("Angle 6"); 
      dialToggle1 = true;
      dialToggle2 = true;
      dialToggle3 = true;
      dialToggle4 = false;
      dialToggle5 = true;
      dialToggle6 = true;
      dialToggle7 = true;
      dialToggle8 = true;
      dialToggle9 = true;
    }

    //Dial setting 5

    else if (val == 6 && dialToggle5 == true)
    {
      Keyboard.press(dial_key5);
      Keyboard.release(dial_key5);
      //Serial.println("Angle 5");
      dialToggle1 = true;
      dialToggle2 = true;
      dialToggle3 = true;
      dialToggle4 = true;
      dialToggle5 = false;
      dialToggle6 = true;
      dialToggle7 = true;
      dialToggle8 = true;
      dialToggle9 = true;
    }

    //Dial setting 6

    else if (val == 7 && dialToggle6 == true)
    {
      Keyboard.press(dial_key6);
      Keyboard.release(dial_key6);
      //Serial.println("Angle 4");
      dialToggle1 = true;
      dialToggle2 = true;
      dialToggle3 = true;
      dialToggle4 = true;
      dialToggle5 = true;
      dialToggle6 = false;
      dialToggle7 = true;
      dialToggle8 = true;
      dialToggle9 = true; 
    }

    //Dial setting 7

    else if (val == 8 && dialToggle7 == true)
    {
      Keyboard.press(dial_key7);
      Keyboard.release(dial_key7);
      //Serial.println("Angle 3");
      dialToggle1 = true;
      dialToggle2 = true;
      dialToggle3 = true;
      dialToggle4 = true;
      dialToggle5 = true;
      dialToggle6 = true;
      dialToggle7 = false;
      dialToggle8 = true;
      dialToggle9 = true; 
    }

    //Dial setting 8
    
    else if (val == 9 && dialToggle8 == true)
    {
      Keyboard.press(dial_key8);
      Keyboard.release(dial_key8);
      //Serial.println("Angle 2");
      dialToggle1 = true;
      dialToggle2 = true;
      dialToggle3 = true;
      dialToggle4 = true;
      dialToggle5 = true;
      dialToggle6 = true;
      dialToggle7 = true;
      dialToggle8 = false;
      dialToggle9 = true;
    }

    //Dial setting 9
    //
    
    else if (val == 10 && dialToggle9 == true)
    {
      Keyboard.press(dial_key9);
      Keyboard.release(dial_key9);
      //Serial.println("Angle 1");
      dialToggle1 = true;
      dialToggle2 = true;
      dialToggle3 = true;
      dialToggle4 = true;
      dialToggle5 = true;
      dialToggle6 = true;
      dialToggle7 = true;
      dialToggle8 = true;
      dialToggle9 = false;
    }

   else
    {
      
    }
}
//screen /dev/cu.usbmodem84591101 9600
//
