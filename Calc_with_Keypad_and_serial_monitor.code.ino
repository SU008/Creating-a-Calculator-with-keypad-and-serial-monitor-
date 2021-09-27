#include <stdio.h>
// include the library code:
#include <Keypad.h>
#include <LiquidCrystal.h>

float Addition(float num1);
float Subtraction(float num1);
float muliplication(float num1);
float Division(float num1);
float num1;
float Ans;
char  key;       //not used in codebolcks code
//float symbol;

 // initialize the library with the numbers of the interface pins
  LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
  



                                                                                   // Keypad Setup
  const byte ROWS = 4;                                                                //four rows
  const byte COLS = 3;                                                               //three columns
  char keys[ROWS][COLS] = {
                         {'1','2','3'},
                         {'4','5','6'},
                         {'7','8','9'},
                         {'#','0','*'}
                          };
  //byte rowPins[ROWS] = {1, 14, 15, 16}; //connect to the row pinouts of the keypad
  //byte colPins[COLS] = {17, 18, 19}; //connect to the column pinouts of the keypad
  byte rowPins[ROWS] = { 12, 10 ,11,9 };
  byte colPins[COLS] = { 8, 7, 6 }; 

  Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );          //keypad setup end


//////////////////setupENDS///////////////////////////////////////////////////////////////
void setup()
{
  Serial.begin(9600);
  lcd.begin(16, 2);              // set up the LCD's number of columns and rows:
  Serial.println("Hello\n");          // Print a message to the LCD only once.

  //pinMode(1,  OUTPUT);
 // pinMode(14, OUTPUT);
 // pinMode(15, OUTPUT);
 // pinMode(16, OUTPUT);
 // pinMode(17, OUTPUT);
 // pinMode(18, OUTPUT);
 // pinMode(19, OUTPUT);
}



void loop()
{

 // lcd.setCursor(0, 1); // set the cursor to column 0, line 1
 
lcd.printSerial.print("Enter first number --------> ");          //get first number
  do{
    key = keypad.getKey();                 // scanf("%f",&num1);                       
  }while( key == NO_KEY );
  num1 = key - 48;    // ***convert ASCII value to number
 Serial.println(num1);
 Serial.println("");
 Serial.println("press a sign");                  //get symbol
 Serial.println("where,(1= +) (2= -) (3= *) (4= /)\n");
  

  do{
   key = keypad.getKey();  
  }while( key == NO_KEY );
  
   if (key == '1')
   {
      Addition(num1);             //Ans=     //go to + function, pass down num1, save to ans
   }

   else if (key == '2')
   {
      Subtraction(num1);              //go to - function, pass down num1, save to ans
   }

   else if (key == '3')
   {
      muliplication(num1);                //go to function, pass down num1, save ans
   }

   else if  (key == '4')
   {
      Division(num1);                 //go to function, pass down num1, save ans
   }

   else
   {
    //lcd.setCursor(0, 1);                                           // set the cursor to column 0, line 1
    Serial.println("Error you did not press => 1,2,3 or 4\n");                 // ask user to press a sign, not number
    //lcd.setCursor(0, 2);
    Serial.println("Try Again next time\n");
   }



}


//---------------------------------------------------------functions start-------------------------------------------------------
float Addition(float num1)              //addition function
{
  float num2;
  float result;
  Serial.print("Enter second number -------> ");

  //-----------------------------
  do{
    key = keypad.getKey();              //scanf("%f",&num2);
  }while( key == NO_KEY );
  num2 = key - 48;
  //------------------------------
  Serial.println(num2);
  result = num1 + num2;
  Serial.print("\n");
  Serial.print(num1);
  Serial.print(" + ");
  Serial.print(num2);
  Serial.print(" = ");
  Serial.println(result);  //display answer
  Serial.print("\n");
  
  //return result;
}
float Subtraction(float num1)        //subtraction function
{
  float num2;
  float result;
  Serial.print("Enter second number -------> ");
  
do{
    key = keypad.getKey();              //scanf("%f",&num2);
  }while( key == NO_KEY );             //scanf("%f",&num2);
  num2 = key -48;

  Serial.println(num2);
  result = num1 - num2;
  Serial.print("\n");
  Serial.print(num1);
  Serial.print(" - ");
  Serial.print(num2);
  Serial.print(" = ");
  Serial.println(result);
  Serial.print("\n");   
  //return result;
}
float muliplication(float num1)            //multiplication function
{
  float num2;
  float result;
  Serial.print("Enter second number -------> ");
  
  do{
    key = keypad.getKey();              //scanf("%f",&num2);
  }while( key == NO_KEY );        //scanf("%f",&num2);          keypad.getkey();
  num2 = key -48;
  
  ln(num2);
  result = num1 * num2;
  ("\n");
  Serial.print(num1);
  Serial.print(" * ");
  Serial.print(num2);
  Serial.print(" = ");
  Serial.println(result);
  Serial.print("\n");   
}
float Division(float num1)              //division function
{
  float num2;
  float result;
  ("Enter second number -------> ");
  
do{
    key = keypad.getKey();              //scanf("%f",&num2);
  }while( key == NO_KEY );        
  num2 = key -48;   //keypad.getkey();            scanf("%f",&num2);
  
  ln(num2);
  result = num1 / num2;
  ("\n");
  (num1);
  (" / ");
  (num2);
  (" = ");
  ln(result);
  ("\n");   
}




