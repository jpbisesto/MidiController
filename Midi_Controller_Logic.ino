#include <MIDI.h>


int noteSensor1 = A0;                 // analog pin used to connect the sharp sensor
int noteSensor2 = A1; 
int noteSensor3 = A2; 
int noteSensor4 = A3; 
int noteSensor5 = A4; 
int noteSensor6 = A5; 

int air1 = 0;                 // variable to store the values from sensor(initially zero)
int air2 = 0;                 // variable to store the values from sensor(initially zero)
int air3 = 0;                 // variable to store the values from sensor(initially zero)
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
      MIDI.begin();          // Launch MIDI 
    Serial.begin(115200);
}
 
void loop()
{

  
 
sensorTest();
 
 /*
  air1 = analogRead(noteSensor1);     
  air2 = analogRead(noteSensor2); 
  
   if(air1 > 200 && air1<300 ){
   MIDI.sendNoteOn(c4,127,1); //play C
     delay(1000); 
     MIDI.sendNoteOff(c4,0,1); 
   }
   if(air1>350 ){
      MIDI.sendNoteOn(d4,127,1); //play d
     delay(1000); 
     MIDI.sendNoteOff(d4,0,1); 
   }
      if(air2 > 200 && air2<300 ){
   MIDI.sendNoteOn(e4,127,1); //play C
     delay(1000); 
     MIDI.sendNoteOff(e4,0,1); 
   }
   if(air2>350 ){
      MIDI.sendNoteOn(f4,127,1); //play d
     delay(1000); 
     MIDI.sendNoteOff(f4,0,1); 
   }
   
   
   delay(10);

*/

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
 
   
   
}//end of minor chord mode
 
 
 //to test the value being read by the sharp sensors 
 //NOTE: wont work through Hairless-MIDI for testing of sensors only
 void sensorTest(){
  air1 = analogRead(noteSensor1);       // reads the value of the sharp sensor in A0
  air2 = analogRead(noteSensor2); 
  air3 = analogRead(noteSensor3); 
  air4 = analogRead(noteSensor4); 
  air5 = analogRead(noteSensor5); 
  air6 = analogRead(noteSensor6); 
  
  Serial.println("Sensor 1 value: "); 
  Serial.println(air1); //value of air1 
  delay(2000); //wait 2 seconds
   
   
 }
  
