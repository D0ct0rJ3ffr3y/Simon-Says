#include <wiringPi.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

int LED = 1;   //initialize LED to pin 1
int LED2 = 4;  //initialize LED2 to pin 4
int LED3 = 5;  //initialize LED3 to pin 5
int LED4 = 0;  //initialize LED4 to pin 0
int LED5 = 2;  //initialize LED5 to pin 2
int PushB = 6; //initialize PushB to pin 6
int PushB2 = 28;  //initialize PushB2 to pin 28
int PushB3 = 29;  //initialize PushB3 to pin 29
int PushB4 = 27;  //initialize PushB4 to pin 27;
int x;            //initialize variable x for PushB
int y;            //initialize variable y for PushB2
int z;            //initialize variable z for PushB3
int a;            //initialize variable a for PushB4

int randomNum;          //variable used for a random number
int LEDPattern[4];      //array used for LED sequence
int USERLedPattern[4]={0,0,0, 0};   //array used for user input


void randomLED()       //function to create random number
{
    int upper = 4;     //upper bound of LED sequence
    int lower = 1;     //lower bound of LED sequence

    for(int a = 0; a < 4; a++)   //loops 4 times, loops through elements of array LEDPattern
     {
         randomNum = (rand() % (upper - lower + 1)) + lower;   //creates a random number between 1 and 4

         if(randomNum == 1)
         LEDPattern[a] = randomNum;    //if randomNum = 1, randomNum is stored in element 'a' of LEDPattern
         else if(randomNum == 2)
         LEDPattern[a] = randomNum;   //if randomNum = 2, randomNum is stored in element 'a' of LEDPattern
         else if(randomNum == 3)
         LEDPattern[a] = randomNum;   //if randomNum = 3, randomNum is stored in element 'a' of LEDPattern
         else if(randomNum == 4)
         LEDPattern[a] = randomNum;   //if randomNum = 4, randomNum is stored in element 'a' of LEDPattern
    }
}

void playLED()        //function to play LED according to array LEDPattern
{
    for(int play = 0; play < 4; play++) //loops 4 times, loops through elements of array LEDPattern
    {
       if(LEDPattern[play] == 1)
       {
           digitalWrite(LED, HIGH);     //turns on LED if element 'play' is 1
           delay(1000);                 //wait 1000 milliseconds
           digitalWrite(LED, LOW);      //turns on LED if element 'play' is 1
       }
       else if(LEDPattern[play] == 2)
       {
           digitalWrite(LED2, HIGH);    //turns on LED if element 'play' is 2
           delay(1000);                 //wait 000 milliseconds
           digitalWrite(LED2, LOW);     //turns on LED if element 'play' is 2
       }
       else if(LEDPattern[play] == 3)
       {
           digitalWrite(LED3, HIGH);    //turns on LED if element 'play' is 3
           delay(1000);                 //wait 1000 milliseconds
           digitalWrite(LED3, LOW);     //turns on LED if element 'play' is 3
       }
       else if(LEDPattern[play] == 4)
       {
              digitalWrite(LED5, HIGH); //turns on LED if element 'play' is 4
              delay(1000);              //wait 1000 milliseconds
              digitalWrite(LED5, LOW);  //turns on LED if element 'play' is 4
       }
    }
}

void showArrays()        //function to display arrays USERLedPattern and LEDPattern
{
       printf("You entered: ");   //print statement "You entered: "

       for(int i=0; i<4; i++)    //loops 4 times, loops through elements of USERLedPattern
       {
          printf("%d ", USERLedPattern[i]);   //prints elements of USERLedPattern
       }

       printf("\n");       //next line

       printf("Random array is: ");    //print statement "Random array is: "
          
       for(int i=0; i<4; i++)   //loops 4 times, loops through elements of LEDPattern
       {
          printf("%d ", LEDPattern[i]);   //prints elements of LEDPattern
       }
}

void queue(int num)    //function to create a delay when obtaining user input, with initialized variable 'num'
{
     int s0;     //initialize variable s0
     int s1;     //initialize variable s1
     int s2;     //initialize variable s2

     for(int i = 0; i<4; i++)   //loop 4 times, loops through elements of USERLEDPattern
     {
         if(USERLedPattern[i] == 0)    //if element i of USERLedPattern is equal to 0
         {
            USERLedPattern[i] = num;   //number 'num' is stored in element i of USERLedPattern
            if(USERLedPattern[i] == 1||2||3||4)     //if element i of USERLedPattern is equal to 1 or 2 or 3 or 4
            {
                  i=4;                //variable i is set to 4
            }
         }
  
         if(i==3)               //if variable i is equal to 3
         {
              s2 = USERLedPattern[0];   //variable s0 is equal to element 0 of USERLedPattern
              s1 = USERLedPattern[1];   //variable s1 is equal to element 1 of USERLedPattern
              s0 = USERLedPattern[2];   //variable s2 is equal to element 2 of USERLedPattern
              
              USERLedPattern[1] = s2;   //element 1 of USERLedPattern is equal to variable s2
              USERLedPattern[2] = s1;   //element 2 of USERLedPattern is equal to variable s1
              USERLedPattern[3] = s0;   //element 3 of USERLedPattern is equal to variable s0
              USERLedPattern[0] = num;  //element 0 of USERLedPattern is equal to variable num
         }
     }
}

char compareLED(int user[], int gen[])   //function to compare array 'user' and array 'gen'
{
    for(int i=0; i<4; i++)     //loops 4 times, loops through elements of 'user' and 'gen'
    {
        if(user[i] != gen[i])   //if element i of 'user' is not equal to element i of 'gen'

       return 0;           //return 0
    }
    
    return 1;     //return 1
}

void algorithm()
{
       while(1)                              //creates loop
       {
              x = digitalRead(PushB);        //sets 'x' as 0 or 1 based on PushB
              if (x == 0)                    //if 'x' is equal to 0
              {
                 digitalWrite(LED, HIGH);    //turns on LED
                 delay(1000);                //wait 1000 milliseconds
                 queue(1);                   //starts function queue() with value 1
                 showArrays();               //starts function showArrays()
              }
              else                           //if 'y' is not equal to 0
              digitalWrite(LED, LOW);        //turns off LED

              y = digitalRead(PushB2);       //sets 'y' as 0 or 1 based on PushB2
              if (y == 0)                    //if 'y' is equal to 0
              {
                 digitalWrite(LED2, HIGH);   //turns on LED2
                 delay(1000);                //wait 1000 milliseconds
                 queue(2);                   //starts function queue() with value 2
                 showArrays();               //starts function showArrays()
              }
              else                           //if 'y' is not equal to 0
              digitalWrite(LED2, LOW);       //turn off LED2

              z = digitalRead(PushB3);       //set 'z' as 0 or 1 based on PushB3
              if (z == 0)                    //if 'z' is equal to 0
              {
                 digitalWrite(LED3, HIGH);   //turns on LED3
                 delay(1000);                //wait 1000 milliseconds
                 queue(3);                   //starts function queue() with value 3
                 showArrays();               //starts function showArrays()
              }
              else                           //if 'z' is not equal to 0
              digitalWrite(LED3, LOW);       //turn off LED3

              a = digitalRead(PushB4);       //set 'a' as 0 or 1 based on PushB4
              if (a == 0)                    //if 'a' is equal to 0
              {
                 digitalWrite(LED5, HIGH);   //turns on LED5
                 delay(1000);                //wait 1000 milliseconds
                 queue(4);                   //starts function queue() with value 4
                 showArrays();               //starts function showArrays()
              }
              else                           //if 'a' is not equal to 1
              digitalWrite(LED5, LOW);       //turn off LED5
              
              if(compareLED(USERLedPattern, LEDPattern))   //if array USERLedPattern is equal to array LEDPattern
              {
                     for(int i = 0; i < 3; i++)       //loops 3 times
                     {
                         digitalWrite(LED4, HIGH);    //turns on LED4
                         delay(1000);                 //wait 1000 milliseconds
                         digitalWrite(LED4, LOW);     //turns off LED4
                         delay(1000);                 //wait 1000 milliseconds
                     }
                     
                     digitalWrite(LED, LOW);         //turns off LED
                     digitalWrite(LED2, LOW);        //turns off LED2
                     digitalWrite(LED3, LOW);        //turns off LED3
                     digitalWrite(LED5, LOW);        //turns off LED5
                     break;                          //exits out of while loop
              }
       }
}

int main()
{
       wiringPiSetup();      //wiringPi setup
       pinMode(LED, OUTPUT);     //sets LED as output
       pinMode(LED2, OUTPUT);    //sets LED2 as output
       pinMode(LED3, OUTPUT);    //sets LED3 as output
       pinMode(LED4, OUTPUT);     //sets LED4 as output
       pinMode(LED5, OUTPUT);     //sets LED5 as output
       pinMode(PushB, INPUT);    //sets PushB as input
       pinMode(PushB2, INPUT);   //sets PushB2 as input
       pinMode(PushB3, INPUT);   //sets PushB3 as input
       pinMode(PushB4, INPUT);   //sets PushB4 as input

       srand(time(0));       //uses current time as seed for random generator

       randomLED();       //start function randomLED()
       playLED();         //start function playLED()
       showArrays();      //start function showArrays()
       
       algorithm();       //start function algorithm()
       
       return 0;          //exit program
}
