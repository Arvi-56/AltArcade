/********************* keystroke parameters *********************/
#define buton_key KEY_Q
#define slider_key KEY_SPACE
#define dial_key1 KEY_A
#define dial_key2 KEY_S
#define dial_key3 KEY_D
#define dial_key4 KEY_F
#define dial_key5 KEY_G
#define dial_key6 KEY_H
#define dial_key7 KEY_J
#define dial_key8 KEY_K
#define dial_key9 KEY_L

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
  val = (dial_input+56)*9/1000;
  uint8_t idx = val % 10;       

  //Serial.println(button_input);
  Serial.println(val);
  //Serial.println(idx); 
  
  //Serial.println(); 
  //Serial.println(slider_input);
  //Serial.println();
  //Serial.println(dial_input);
  //Serial.println();          

  if (button_input <  20)
    {
      Keyboard.press(buton_key);
      //Serial.println("Button Press");
      
    }
    else
    {
      Keyboard.release(buton_key);
    }

    if (slider_input <  20)
    {
      Keyboard.press(slider_key);
      //Serial.println("Button Press");
      
    }
    else
    {
      Keyboard.release(slider_key);
    }

    //Dial setting 1

    if (val == 1)
    {
      Keyboard.press(dial_key1);
      //Serial.println("Button Press");
      
    }
    else
    {
      Keyboard.release(dial_key1);
    }

    //Dial setting 2

    if (val == 2)
    {
      Keyboard.press(dial_key2);
      //Serial.println("Button Press");
      
    }
    else
    {
      Keyboard.release(dial_key2);
    }

    //Dial setting 3

    if (val == 3)
    {
      Keyboard.press(dial_key3);
      //Serial.println("Button Press");
      
    }
    else
    {
      Keyboard.release(dial_key3);
    }

    //Dial setting 4

    if (val == 4)
    {
      Keyboard.press(dial_key4);
      //Serial.println("Button Press");
      
    }
    else
    {
      Keyboard.release(dial_key4);
    }

    //Dial setting 5

    if (val == 5)
    {
      Keyboard.press(dial_key5);
      //Serial.println("Button Press");
      
    }
    else
    {
      Keyboard.release(dial_key5);
    }

    //Dial setting 6

    if (val == 6)
    {
      Keyboard.press(dial_key6);
      //Serial.println("Button Press");
      
    }
    else
    {
      Keyboard.release(dial_key6);
    }

    //Dial setting 7

    if (val == 7)
    {
      Keyboard.press(dial_key7);
      //Serial.println("Button Press");
      
    }
    else
    {
      Keyboard.release(dial_key7);
    }

    //Dial setting 8

    if (val == 8)
    {
      Keyboard.press(dial_key8);
      //Serial.println("Button Press");
      
    }
    else
    {
      Keyboard.release(dial_key8);
    }

    //Dial setting 9

    if (val == 9)
    {
      Keyboard.press(dial_key9);
      //Serial.println("Button Press");
      
    }
    else
    {
      Keyboard.release(dial_key9);
    }
}
//screen /dev/cu.usbmodem84591101 9600
