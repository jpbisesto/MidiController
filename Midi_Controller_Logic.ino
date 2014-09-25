#include <MIDI.h>

// this program is for the Embark v1.1 MAK-6 Airboard controller
// it will run the airboard to play MIDI values through a DAW. 
// A DAW such as Logic or Ableton or Garageband is required to 
// function the MIDI Airboard device. Also required is the software 
// "Hairless-MIDI" to bridge the signals from the Serial Monitor to 
//the DAW 

//Code and Hardware design by Joe Bisesto, May 2014

//connect all sensors for music play to analog pins in order to read value


int noteSensor1 = A0;                 
int noteSensor2 = A1; 
int noteSensor3 = A2; 
int noteSensor4 = A3; 
int noteSensor5 = A4; 
int noteSensor6 = A5; 

//buttons to select a mode 
const int buttonPinZero = 4 ;     // the number of the pushbutton pin for mode Major Chord 
const int buttonPinOne = 5 ;     // the number of the pushbutton pin for mode Minor Chord
const int buttonPinTwo = 6 ;     // the number of the pushbutton pin for mode note mode
const int buttonPinThree = 7 ;     // the number of the pushbutton pin for mode Arpegiate 

// variables will change:
//these are variable for reading the mode buttons
int zeroState = 0;         
int oneState = 0; 
int twoState = 0; 
int threeState = 0; 

int currentButton = 10; //variable to keep track of the current mode (initially set to 10... which means nothing)

//variables to store the value of the sensors 
int air1 = 0;                 
int air2 = 0;                
int air3 = 0;                 
int air4 = 0; 
int air5 = 0; 
int air6 = 0; 

//all notes for octave 4 

int c4 = 60; 
int csharp4 = 61; 
int d4 = 62; 
int dsharp4 = 63; 
int e4 = 64; 
int f4 = 65; 
int fsharp4 = 66; 
int g4 = 67; 
int gsharp4= 68; 
int a4 = 69; 
int asharp4 = 70; 
int b4 = 71; 

void setup()
{

  // initialize the pushbutton pin as an input:
  pinMode(buttonPinZero, INPUT);     
  pinMode(buttonPinOne, INPUT);  
  pinMode(buttonPinTwo, INPUT);   
  pinMode(buttonPinThree, INPUT);       



  MIDI.begin();          // Launch MIDI 
  Serial.begin(115200); //begin serial monitor
}

void loop()
{


  // read the state of the pushbuttons value in order to select a mode
  zeroState = digitalRead(buttonPinZero);
  oneState = digitalRead(buttonPinOne);
  twoState = digitalRead(buttonPinTwo);
  threeState = digitalRead(buttonPinThree);


  if (zeroState == HIGH) {   //Major chord mode   
    // turn LED on:    
    currentButton = 0; //set current button value to 0
    majorChordMode(); //go to major chord mode 


  } 

  if(oneState == HIGH){

    currentButton = 1; //set current button value to 1 
    minorChordMode(); //go to minor chord mode 

  }

  if(twoState == HIGH){

    currentButton = 2; //set current button value to 2 
    noteMode(); //go to note mode

  }

  if(threeState == HIGH){

    currentButton = 3; //set current button value to 3 
    arpegiateMajor(); //go to arpegiate mode

  }




}


//plays individual notes like a keyboard 
void noteMode(){

  /*
   sensor 1: C     B
   sensor 2: D     D#
   sensor 3: E    
   sensor 4: F     F#
   sensor 5: G     G#
   sensor 6: A     A#
   */
  while(currentButton ==2){ //stay in this function untill current button is changed 


    //check all the states of the buttons 
    zeroState = digitalRead(buttonPinZero);
    oneState = digitalRead(buttonPinOne);
    twoState = digitalRead(buttonPinTwo);
    threeState = digitalRead(buttonPinThree);

    //if any buttons are pressed the currentButton value will change and
    // the while loop will break and go back to the main loop function
    if (zeroState == HIGH) {   //Major chord mode   

      currentButton = 0;



    } 
    else if (oneState == HIGH) {     //minor chord mode 

      currentButton = 1; 


    } 

    else if (twoState == HIGH) {     //note mode

      currentButton = 2; 


    } 

    else if (threeState == HIGH) {     //arp mode

      currentButton = 3; 

    } 


    delay(10); 
    air1 = analogRead(noteSensor1);       // reads the value of the sharp sensor in A0
    air2 = analogRead(noteSensor2); 
    air3 = analogRead(noteSensor3); 
    air4 = analogRead(noteSensor4); 
    air5 = analogRead(noteSensor5); 
    air6 = analogRead(noteSensor6); 

    //air 1 (sensor 1) C C# 
    if(air1 > 200 && air1<300 ){
      MIDI.sendNoteOn(c4,127,1); //play C
      delay(1000); 
      MIDI.sendNoteOff(c4,0,1); 
    }

    if(air1 >= 351){
      MIDI.sendNoteOn(csharp4,127,1); // Middle C# 
      delay(1000); 
      MIDI.sendNoteOff(csharp4,0,1); // Middle C# off 
    }


    //----------


    //sensor 2 D D#
    if(air2 > 200 && air2<300 ){
      MIDI.sendNoteOn(d4,127,1); //play D
      delay(1000); 
      MIDI.sendNoteOff(d4,0,1); 
    }
    if(air2 >= 350){
      MIDI.sendNoteOn(dsharp4,127,1); //D#
      delay(1000); 
      MIDI.sendNoteOff(dsharp4,0,1); //D# off
    }



    //-------

    //sensor 3 E   F

    if(air3 > 200 && air3<300 ){
      MIDI.sendNoteOn(e4,127,1); //play E
      delay(1000); 
      MIDI.sendNoteOff(e4,0,1); 
    }
    if(air3 >= 350){
      MIDI.sendNoteOn(f4,127,1); //F
      delay(1000); 
      MIDI.sendNoteOff(f4,0,1); //F off
    }


    //--------

    //sensor 4 F# G 

    if(air4 > 200 && air4<300 ){
      MIDI.sendNoteOn(fsharp4,127,1); //play F#
      delay(1000); 
      MIDI.sendNoteOff(fsharp4,0,1); 
    }
    if(air4 >= 350){
      MIDI.sendNoteOn(g4,127,1); //G
      delay(1000); 
      MIDI.sendNoteOff(g4,0,1); //G off
    }


    //------

    //sensor 5  G# A 
    if(air5 > 200 && air5<300 ){
      MIDI.sendNoteOn(gsharp4,127,1); //play g#
      delay(1000); 
      MIDI.sendNoteOff(gsharp4,0,1); 
    }
    if(air5 >= 350){
      MIDI.sendNoteOn(a4,127,1); //A
      delay(1000); 
      MIDI.sendNoteOff(a4,0,1); //A off
    }



    //------

    //sensor 6 A# B
    if(air6 > 200 && air6<300 ){
      MIDI.sendNoteOn(asharp4,127,1); //play A#
      delay(1000); 
      MIDI.sendNoteOff(asharp4,0,1); 
    }
    if(air6 >= 350){
      MIDI.sendNoteOn(b4,127,1);//B
      delay(1000); 
      MIDI.sendNoteOff(b4,0,1); //B off 
    }


  }//end of while loop 


} //end note mode


//will play all major chords
void majorChordMode(){

  /* 
   
   sensor 1: C C#
   sensor 2: D D#
   sensor 3: E F
   sensor 4: F# G
   sensor 5: G# A
   sensor 6: A# B
   
   
   */




  while(currentButton ==0){


    zeroState = digitalRead(buttonPinZero);
    oneState = digitalRead(buttonPinOne);
    twoState = digitalRead(buttonPinTwo);
    threeState = digitalRead(buttonPinThree);

    if (zeroState == HIGH) {   //Major chord mode   

      currentButton = 0;



    } 
    else if (oneState == HIGH) {     //minor chord mode 

      currentButton = 1; 


    } 

    else if (twoState == HIGH) {     //note mode
      // turn LED on:    
      currentButton = 2; 


    } 

    else if (threeState == HIGH) {     //arp mode

      currentButton = 3; 

    } 




    delay(10); 
    air1 = analogRead(noteSensor1);       // reads the value of the sharp sensor in A0
    // air2 = analogRead(noteSensor2); 
    air3 = analogRead(noteSensor3); 
    air4 = analogRead(noteSensor4); 
    air5 = analogRead(noteSensor5); 
    air6 = analogRead(noteSensor6); 

    //air 1 (sensor 1) C C#

    if(air1 > 200 && air1<300 ){ //CMajor
      MIDI.sendNoteOn(60,127,1);
      MIDI.sendNoteOn(64,127,1);
      MIDI.sendNoteOn(67,127,1);
      delay(1000); 
      MIDI.sendNoteOff(60,0,1);
      MIDI.sendNoteOff(64,0,1); 
      MIDI.sendNoteOff(67,0,1);  
    }

    if(air1 >= 350){ //C# Major
      MIDI.sendNoteOn(61,127,1);
      MIDI.sendNoteOn(64,127,1);
      MIDI.sendNoteOn(68,127,1);
      delay(1000); 
      MIDI.sendNoteOff(61,0,1);
      MIDI.sendNoteOff(64,0,1); 
      MIDI.sendNoteOff(68,0,1);  
    }



    //---------------

    //air 2(sensor2) D D#

    if(air2 > 200 && air2<300 ){ //Dmajor
      MIDI.sendNoteOn(62,127,1);
      MIDI.sendNoteOn(66,127,1);
      MIDI.sendNoteOn(69,127,1);
      delay(1000); 
      MIDI.sendNoteOff(62,0,1);
      MIDI.sendNoteOff(66,0,1); 
      MIDI.sendNoteOff(69,0,1);  
    }

    if(air2 >= 350){ //D# Major
      MIDI.sendNoteOn(63,127,1);
      MIDI.sendNoteOn(67,127,1);
      MIDI.sendNoteOn(70,127,1);
      delay(1000); 
      MIDI.sendNoteOff(63,0,1);
      MIDI.sendNoteOff(67,0,1); 
      MIDI.sendNoteOff(70,0,1);  
    }

    //---------------

    //air3 (sensor 3) E F  
    if(air3 > 200 && air3<300 ){ //EMajor
      MIDI.sendNoteOn(64,127,1);
      MIDI.sendNoteOn(68,127,1);
      MIDI.sendNoteOn(71,127,1);
      delay(1000); 
      MIDI.sendNoteOff(63,0,1);
      MIDI.sendNoteOff(68,0,1); 
      MIDI.sendNoteOff(71,0,1);  
    }


    if(air3 >= 350){ //F Major
      MIDI.sendNoteOn(65,127,1);
      MIDI.sendNoteOn(69,127,1);
      MIDI.sendNoteOn(72,127,1);
      delay(1000); 
      MIDI.sendNoteOff(65,0,1);
      MIDI.sendNoteOff(69,0,1); 
      MIDI.sendNoteOff(72,0,1);  
    }


    //------------

    //air4 (sensor 4) F#  G

    if(air4 > 200 && air4<300 ){ //F# Major
      MIDI.sendNoteOn(66,127,1);
      MIDI.sendNoteOn(70,127,1);
      MIDI.sendNoteOn(73,127,1);
      delay(1000); 
      MIDI.sendNoteOff(66,0,1);
      MIDI.sendNoteOff(70,0,1); 
      MIDI.sendNoteOff(73,0,1);  
    }

    if(air4 >= 350){ //G Major
      MIDI.sendNoteOn(67,127,1);
      MIDI.sendNoteOn(71,127,1);
      MIDI.sendNoteOn(74,127,1);
      delay(1000); 
      MIDI.sendNoteOff(67,0,1);
      MIDI.sendNoteOff(71,0,1); 
      MIDI.sendNoteOff(74,0,1);  
    }


    //--------

    //air 5 (sensor 5) G# A 
    if(air5 > 200 && air5<300 ){ //G# Major
      MIDI.sendNoteOn(68,127,1);
      MIDI.sendNoteOn(72,127,1);
      MIDI.sendNoteOn(75,127,1);
      delay(1000); 
      MIDI.sendNoteOff(68,0,1);
      MIDI.sendNoteOff(72,0,1); 
      MIDI.sendNoteOff(75,0,1);  
    }
    if(air5 >= 350){  //A Major
      MIDI.sendNoteOn(69,127,1);
      MIDI.sendNoteOn(73,127,1);
      MIDI.sendNoteOn(76,127,1);
      delay(1000); 
      MIDI.sendNoteOff(69,0,1);
      MIDI.sendNoteOff(73,0,1); 
      MIDI.sendNoteOff(76,0,1);  
    } 

    //-------


    //air 6 (sensor 6) A#(Bb)  B


    if(air6 > 200 && air6<300 ){ //A#(Bb)Major
      MIDI.sendNoteOn(70,127,1);
      MIDI.sendNoteOn(72,127,1);
      MIDI.sendNoteOn(77,127,1);
      delay(1000); 
      MIDI.sendNoteOff(70,0,1);
      MIDI.sendNoteOff(72,0,1); 
      MIDI.sendNoteOff(77,0,1);  
    }
    if(air6 >= 350){ //B Major
      MIDI.sendNoteOn(71,127,1);
      MIDI.sendNoteOn(75,127,1);
      MIDI.sendNoteOn(78,127,1);
      delay(1000); 
      MIDI.sendNoteOff(71,0,1);
      MIDI.sendNoteOff(75,0,1); 
      MIDI.sendNoteOff(78,0,1);  
    }

  }//end of while

}//end of Major chord mode




//will play all minor chords
void minorChordMode(){ 

  /* 
   
   sensor 1: C C#
   sensor 2: D D#
   sensor 3: E F
   sensor 4: F# G
   sensor 5: G# A
   sensor 6: A# B
   
   
   
   
   
   */


  while(currentButton ==1){ //stay in this function untill current button is changed 


    //check all the states of the buttons 
    zeroState = digitalRead(buttonPinZero);
    oneState = digitalRead(buttonPinOne);
    twoState = digitalRead(buttonPinTwo);
    threeState = digitalRead(buttonPinThree);

    if (zeroState == HIGH) {   //Major chord mode   

      currentButton = 0;
      majorChordMode(); 


    } 
    else if (oneState == HIGH) {     //minor chord mode 

      currentButton = 1; 

    } 

    else if (twoState == HIGH) {     //note mode

      currentButton = 2; 


    } 

    else if (threeState == HIGH) {     //arp mode

      currentButton = 3; 

    } 

    delay(10); 
    air1 = analogRead(noteSensor1);       // reads the value of the sharp sensor in A0
    air2 = analogRead(noteSensor2); 
    air3 = analogRead(noteSensor3); 
    air4 = analogRead(noteSensor4); 
    air5 = analogRead(noteSensor5); 
    air6 = analogRead(noteSensor6); 

    //air 1 (sensor 1) C C#

    if(air1 > 200 && air1<300 ){ //C minor
      MIDI.sendNoteOn(60,127,1);
      MIDI.sendNoteOn(63,127,1);
      MIDI.sendNoteOn(67,127,1);
      delay(1000); 
      MIDI.sendNoteOff(60,0,1);
      MIDI.sendNoteOff(63,0,1); 
      MIDI.sendNoteOff(67,0,1);  
    }

    if(air1 >= 350){ //C# minor
      MIDI.sendNoteOn(61,127,1);
      MIDI.sendNoteOn(64,127,1);
      MIDI.sendNoteOn(67,127,1);
      delay(1000); 
      MIDI.sendNoteOff(61,0,1);
      MIDI.sendNoteOff(64,0,1); 
      MIDI.sendNoteOff(67,0,1);  
    }



    //---------------

    //air 2(sensor2) D D#

    if(air2 > 200 && air2<300 ){ //D minor
      MIDI.sendNoteOn(62,127,1);
      MIDI.sendNoteOn(65,127,1);
      MIDI.sendNoteOn(69,127,1);
      delay(1000); 
      MIDI.sendNoteOff(62,0,1);
      MIDI.sendNoteOff(65,0,1); 
      MIDI.sendNoteOff(69,0,1);  
    }

    if(air2 >= 350){ //D# Major
      MIDI.sendNoteOn(63,127,1);
      MIDI.sendNoteOn(66,127,1);
      MIDI.sendNoteOn(71,127,1);
      delay(1000); 
      MIDI.sendNoteOff(63,0,1);
      MIDI.sendNoteOff(66,0,1); 
      MIDI.sendNoteOff(71,0,1);  
    }

    //---------------

    //air3 (sensor 3) E F  
    if(air6 > 200 && air6<300 ){ //e minor
      MIDI.sendNoteOn(64,127,1);
      MIDI.sendNoteOn(67,127,1);
      MIDI.sendNoteOn(71,127,1);
      delay(1000); 
      MIDI.sendNoteOff(63,0,1);
      MIDI.sendNoteOff(67,0,1); 
      MIDI.sendNoteOff(71,0,1);  
    }


    if(air3 >= 350){ //F minor
      MIDI.sendNoteOn(65,127,1);
      MIDI.sendNoteOn(68,127,1);
      MIDI.sendNoteOn(71,127,1);
      delay(1000); 
      MIDI.sendNoteOff(65,0,1);
      MIDI.sendNoteOff(68,0,1); 
      MIDI.sendNoteOff(71,0,1);  
    }


    //------------

    //air4 (sensor 4) F#  G

    if(air4 > 200 && air4<300){ //F# minor
      MIDI.sendNoteOn(66,127,1);
      MIDI.sendNoteOn(69,127,1);
      MIDI.sendNoteOn(73,127,1);
      delay(1000); 
      MIDI.sendNoteOff(66,0,1);
      MIDI.sendNoteOff(69,0,1); 
      MIDI.sendNoteOff(73,0,1);  
    }

    if(air4 >= 350){ //G minor
      MIDI.sendNoteOn(67,127,1);
      MIDI.sendNoteOn(70,127,1);
      MIDI.sendNoteOn(74,127,1);
      delay(1000); 
      MIDI.sendNoteOff(67,0,1);
      MIDI.sendNoteOff(70,0,1); 
      MIDI.sendNoteOff(74,0,1);  
    }


    //--------

    //air 5 (sensor 5) G# A 
    if(air5 > 200 && air5<300){ //G# minor
      MIDI.sendNoteOn(68,127,1);
      MIDI.sendNoteOn(71,127,1);
      MIDI.sendNoteOn(75,127,1);
      delay(1000); 
      MIDI.sendNoteOff(68,0,1);
      MIDI.sendNoteOff(71,0,1); 
      MIDI.sendNoteOff(75,0,1);  
    }
    if(air5 >= 350){  //A minor
      MIDI.sendNoteOn(69,127,1);
      MIDI.sendNoteOn(72,127,1);
      MIDI.sendNoteOn(76,127,1);
      delay(1000); 
      MIDI.sendNoteOff(69,0,1);
      MIDI.sendNoteOff(72,0,1); 
      MIDI.sendNoteOff(76,0,1);  
    } 

    //-------


    //air 6 (sensor 6) A#(Bb)  B


    if(air6 > 200 && air6<300 ){ //A#(Bb) minor
      MIDI.sendNoteOn(70,127,1);
      MIDI.sendNoteOn(73,127,1);
      MIDI.sendNoteOn(77,127,1);
      delay(1000); 
      MIDI.sendNoteOff(70,0,1);
      MIDI.sendNoteOff(73,0,1); 
      MIDI.sendNoteOff(77,0,1);  
    }
    if(air6 >= 350){ //B Major
      MIDI.sendNoteOn(71,127,1);
      MIDI.sendNoteOn(74,127,1);
      MIDI.sendNoteOn(78,127,1);
      delay(1000); 
      MIDI.sendNoteOff(71,0,1);
      MIDI.sendNoteOff(74,0,1); 
      MIDI.sendNoteOff(78,0,1);  
    }

  }//end while

}//end of minor chord mode


//play all major chords arpegio 
void arpegiateMajor(){

  /* 
   
   sensor 1: C C#
   sensor 2: D D#
   sensor 3: E F
   sensor 4: F# G
   sensor 5: G# A
   sensor 6: A# B
   
   
   */




  while(currentButton ==3 ){//stay in this function untill current button is changed 


    //check all the states of the buttons 

    zeroState = digitalRead(buttonPinZero);
    oneState = digitalRead(buttonPinOne);
    twoState = digitalRead(buttonPinTwo);
    threeState = digitalRead(buttonPinThree);

    if (zeroState == HIGH) {   //Major chord mode   

      currentButton = 0;



    } 
    else if (oneState == HIGH) {     //minor chord mode 

      currentButton = 1; 


    } 

    else if (twoState == HIGH) {     //note mode

      currentButton = 2; 


    } 

    else if (threeState == HIGH) {     //arp mode

      currentButton = 3; 

    } 

    delay(10); 
    air1 = analogRead(noteSensor1);       // reads the value of the sharp sensor in A0
    air2 = analogRead(noteSensor2); 
    air3 = analogRead(noteSensor3); 
    air4 = analogRead(noteSensor4); 
    air5 = analogRead(noteSensor5); 
    air6 = analogRead(noteSensor6); 

    //air 1 (sensor 1) C C#

    if(air1 > 200 && air1<300 ){ //CMajor
      MIDI.sendNoteOn(60,127,1);
      delay(1000); 
      MIDI.sendNoteOff(60,0,1);
      delay(1000);
      MIDI.sendNoteOn(64,127,1);
      delay(1000); 
      MIDI.sendNoteOff(64,0,1); 
      delay(1000); 
      MIDI.sendNoteOn(67,127,1);
      delay(1000); 
      MIDI.sendNoteOff(67,0,1);  
      delay(1000); 
    }

    if(air1 >= 350){ //C# Major
      MIDI.sendNoteOn(61,127,1);
      delay(1000); 
      MIDI.sendNoteOff(61,0,1);
      delay(1000); 
      MIDI.sendNoteOn(64,127,1);
      delay(1000); 
      MIDI.sendNoteOff(64,0,1); 
      delay(1000); 
      MIDI.sendNoteOn(68,127,1);
      delay(1000);   
      MIDI.sendNoteOff(68,0,1);  
      delay(1000); 
    }

    //---------------

    //air 2(sensor2) D D#

    if(air2 > 200 && air2<300 ){ //Dmajor
      MIDI.sendNoteOn(62,127,1);
      delay(1000); 
      MIDI.sendNoteOff(62,0,1);
      delay(1000); 
      MIDI.sendNoteOn(66,127,1);
      delay(1000); 
      MIDI.sendNoteOff(66,0,1);
      delay(1000); 
      MIDI.sendNoteOn(69,127,1);
      delay(1000); 
      MIDI.sendNoteOff(69,0,1); 
      delay(1000);  
    }

    if(air2 >= 350){ //D# Major
      MIDI.sendNoteOn(63,127,1);
      delay(1000); 
      MIDI.sendNoteOff(63,0,1);
      delay(1000); 
      MIDI.sendNoteOn(67,127,1);
      delay(1000); 
      MIDI.sendNoteOff(67,0,1);
      delay(1000); 
      MIDI.sendNoteOn(70,127,1);
      delay(1000); 


      MIDI.sendNoteOff(70,0,1);  
      delay(1000); 
    }

    //---------------

    //air3 (sensor 3) E F  
    if(air3 > 200 && air3<300 ){ //EMajor
      MIDI.sendNoteOn(64,127,1);
      delay(1000); 
      MIDI.sendNoteOff(64,0,1);
      delay(1000); 
      MIDI.sendNoteOn(68,127,1);
      delay(1000); 
      MIDI.sendNoteOff(68,0,1); 
      delay(1000);
      MIDI.sendNoteOn(71,127,1);
      delay(1000); 
      MIDI.sendNoteOff(71,0,1);  
    }


    if(air3 >= 350){ //F Major
      MIDI.sendNoteOn(65,127,1);
      delay(1000); 
      MIDI.sendNoteOff(65,0,1);
      delay(1000); 
      MIDI.sendNoteOn(69,127,1);
      delay(1000); 
      MIDI.sendNoteOff(69,0,1); 
      delay(1000); 
      MIDI.sendNoteOn(72,127,1);
      delay(1000); 
      MIDI.sendNoteOff(72,0,1);  
      delay(1000); 
    }


    //------------

    //air4 (sensor 4) F#  G

    if(air4 > 200 && air4<300 ){ //F# Major
      MIDI.sendNoteOn(66,127,1);
      delay(1000); 
      MIDI.sendNoteOff(66,0,1);
      delay(1000); 
      MIDI.sendNoteOn(70,127,1);
      delay(1000); 
      MIDI.sendNoteOff(70,0,1);
      delay(1000); 
      MIDI.sendNoteOn(73,127,1);
      delay(1000); 
      MIDI.sendNoteOff(73,0,1);  
      delay(1000); 
    }

    if(air4 >= 350){ //G Major
      MIDI.sendNoteOn(67,127,1);
      delay(1000); 
      MIDI.sendNoteOff(67,0,1);
      delay(1000); 
      MIDI.sendNoteOn(71,127,1);
      delay(1000); 
      MIDI.sendNoteOff(71,0,1); 
      delay(1000); 
      MIDI.sendNoteOn(74,127,1);
      delay(1000); 
      MIDI.sendNoteOff(74,0,1); 
      delay(1000);  
    }


    //--------

    //air 5 (sensor 5) G# A 
    if(air5 > 200 && air5<300 ){ //G# Major
      MIDI.sendNoteOn(68,127,1);
      delay(1000); 
      MIDI.sendNoteOff(68,0,1);
      delay(1000);
      MIDI.sendNoteOn(72,127,1);
      delay(1000); 
      MIDI.sendNoteOff(72,0,1); 
      delay(1000);
      MIDI.sendNoteOn(75,127,1);
      delay(1000); 
      MIDI.sendNoteOff(75,0,1);  
    }
    if(air5 >= 350){  //A Major
      MIDI.sendNoteOn(69,127,1);
      delay(1000); 
      MIDI.sendNoteOff(69,0,1);
      delay(1000); 
      MIDI.sendNoteOn(73,127,1);
      delay(1000); 
      MIDI.sendNoteOff(73,0,1); 
      delay(1000); 
      MIDI.sendNoteOn(76,127,1);
      delay(1000); 


      MIDI.sendNoteOff(76,0,1);  
      delay(1000); 
    } 

    //-------


    //air 6 (sensor 6) A#(Bb)  B


    if(air6 > 200 && air6<300 ){ //A#(Bb)Major
      MIDI.sendNoteOn(70,127,1);
      delay(1000); 
      MIDI.sendNoteOff(70,0,1);
      delay(1000); 
      MIDI.sendNoteOn(72,127,1);
      delay(1000);
      MIDI.sendNoteOff(72,0,1); 
      delay(1000); 
      MIDI.sendNoteOn(77,127,1);
      delay(1000); 


      MIDI.sendNoteOff(77,0,1);  
      delay(1000); 
    }
    if(air6 >= 350){ //B Major
      MIDI.sendNoteOn(71,127,1);
      delay(1000); 
      MIDI.sendNoteOff(71,0,1);
      MIDI.sendNoteOn(75,127,1);
      delay(1000); 
      MIDI.sendNoteOff(75,0,1); 
      delay(1000); 
      MIDI.sendNoteOn(78,127,1);
      delay(1000); 


      MIDI.sendNoteOff(78,0,1);  
      delay(1000); 
    }

  }//end of while

}//end function arp 


//to test the value being read by the sharp sensors 
//NOTE: wont work through Hairless-MIDI for testing of sensors only
void sensorTest(){
  air1 = analogRead(noteSensor1);       // reads the value of the sharp sensor in A0
  // air2 = analogRead(noteSensor2); 
  air3 = analogRead(noteSensor3); 
  air4 = analogRead(noteSensor4); 
  air5 = analogRead(noteSensor5); 
  air6 = analogRead(noteSensor6); 

  Serial.println("Sensor 1 value: "); 
  Serial.println(air1); //value of air1 
  delay(2000); //wait 2 seconds


}
