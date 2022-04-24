#pragma once

/*======================================================================================================================*/

//ON THIS TAB ALL THE SCREENS ARE INSTATIATED.

// 1 = *BOOTUP SCREEN AXE FX III
// 2 = *BUILD UP the 5 SCREENS on the top (CS 11,12,13,14,15)
// 3 = *SCENES  -> nope, these are now on axe_handler.h
// 4 = *PRESETS -> nope, these are now on axe_handler.h
// 5 = *PRESETNUMBERS
// 6 = *EFFECTS & AMP ABCD


/*===========================================   -  Include library's  -  ================================================*/

#include <AxeFxControl.h>
#include <SD_ini.h>


#include "axe_handler.h"
#include "Screenstyle.h"
#include "Preset_range.h"


/*=========================================================================================================================
      BOOT SCREENS 
  ========================================================================================================================*/

void bootscreen_setup()  // This shows the AXE FX III on the bootup
{
  debug(" ====================    BOOTUP   ===================");  
  debugln(); debug(" * function boot_screensetup started on screenSetup.h");

 //one FLASHled,  going to activate it now:
 // pinMode(29, OUTPUT);

  //setup the 15 LCD screens
  pinMode(CS1, OUTPUT),  pinMode(CS2, OUTPUT),  pinMode(CS3, OUTPUT),  pinMode(CS4, OUTPUT), pinMode(CS5, OUTPUT),  
  pinMode(CS6, OUTPUT),  pinMode(CS7, OUTPUT), pinMode(CS8, OUTPUT),  pinMode(CS9, OUTPUT), pinMode(CS10,OUTPUT),  
  pinMode(CS11,OUTPUT),  pinMode(CS12,OUTPUT),  pinMode(CS13,OUTPUT),  pinMode(CS14,OUTPUT), pinMode(CS15,OUTPUT);
  tft.begin();
  tft.setRotation(1);         //screen is rotated to width 160 x  hight 128 (landscape)

  CS1L; CS2L; CS3L; CS4L; CS5L; CS6L; CS7L; CS8L; CS9L; CS10L; CS11L; CS12L; CS13L; CS14L; CS15L;
  
  tft.fillScreen(TFT_BLACK);  // screen is all black
  tft.setTextWrap(false);     // text is not wrapped on multi lines, but goes straight on.  That is correct, as the code will optimize the text in the screens

  CS1H, CS2H, CS3H, CS4H, CS5H, CS6H, CS7H, CS8H, CS9H, CS10H, CS11H, CS12H, CS13H, CS14H, CS15H;
   


  CS12L; bootupStyle1();tft.println("A"); CS12H;
  CS13L; bootupStyle1();tft.println("X"); CS13H; 
  CS14L; bootupStyle1();tft.println("E"); CS14H;


                                CS8L;
                                bootupStyle5();
                                tft.println("FX");
                                CS8H;



  CS2L; bootupStyle2();tft.println("I"); CS2H; 
  CS3L; bootupStyle3();tft.println("I"); CS3H; 
  CS4L; bootupStyle4();tft.println("I"); CS4H; 
  delay(1500);
}


/*=========================================================================================================================
      First start initializing screens
  ========================================================================================================================*/

void ini_screens()  //clear all screens after 1st boot

{ 
  debugln();  debugln();  debug(" * function ini_screens started on screenSetup.h");
  CS1L; CS2L; CS3L; CS4L; CS5L; CS6L; CS7L; CS8L; CS9L; CS10L; CS11L; CS12L; CS13L; CS14L; CS15L;

  tft.fillScreen(TFT_BLACK);
  
  CS1H, CS2H, CS3H, CS4H, CS5H, CS6H, CS7H, CS8H, CS9H, CS10H, CS11H, CS12H, CS13H, CS14H, CS15H;

// First initial setup screen 13 "NO INFO" text
  CS11L; sceneScreen_11;  CS11H;
  CS12L; sceneScreen_12;  CS12H;
  CS13L; sceneScreen_13;  CS13H;
  CS14L; sceneScreen_14;  CS14H;
  CS15L; sceneScreen_15;  CS15H; 
}


/*=========================================================================================================================
      PRESET initializing screens
  ========================================================================================================================*/

void ini_preset()
{
  debugln();  debugln();  debug(" * function ini_preset started on screenSetup.h");

    if (auditionMode == true)
    {
    presetBank_settings(); // go to the page Axe_handler.h for building the preset screens
    auditionmode_LCD_text();
    }
    else
      {
      presetBank_settings(); // go to the page Axe_handler.h for building the preset screens
      preset_LCD_text();
      }
      debugln();debug(" -> ini_preset has succesfully loaded");
}


/*=========================================================================================================================
     LOOPER 
  ========================================================================================================================*/

void ini_looper()
{

  debugln(); debugln();   debug(" * function ini_looper started on screenSetup.h");  

  CS1L,  CS2L,  CS3L,  CS4L,  CS5L, CS6L,  CS7L,  CS8L,  CS9L,  CS10L,
  tft.fillScreen(looper_screen_fillscreen);
  CS1H,  CS2H,  CS3H,  CS4H,  CS5H, CS6H,  CS7H,  CS8H,  CS9H,  CS10H,

  CS1L;  looperStyle1();  tft.println("RECORD");  CS1H;
  CS3L;  looperStyle1();  tft.println("PLAY");    CS3H;
  CS5L;  looperStyle1();  tft.println("UNDO");    CS5H;
  CS6L;  looperStyle1();  tft.println("ONCE");    CS6H;
  CS8L;  looperStyle1();  tft.println("REVERSE"); CS8H;
  CS10L;  looperStyle1();  tft.println("HALFSPD"); CS10H;

}


/*=========================================================================================================================
     NUMBERS SETTINGS
  ========================================================================================================================*/

void ini_numbers()
{

  debugln();debugln();  debug(" * function ini_numbers started on screenSetup.h");
  lcd.setCursor(0, 1); lcd.print(" Number =        ");

  CS1L,  CS2L,  CS3L,  CS4L,  CS5L,  CS6L, CS7L,  CS8L,  CS9L,  CS10L;  
  tft.fillScreen(numberSelect_screen_fillscreen);
  CS1H,  CS2H,  CS3H,  CS4H,  CS5H,  CS6H, CS7H,  CS8H,  CS9H,  CS10H;  
  
  CS1L;  numbersStyle1();  tft.println("0");  CS1H;
  CS2L;  numbersStyle1();  tft.println("1");  CS2H;
  CS3L;  numbersStyle1();  tft.println("2");  CS3H;
  CS4L;  numbersStyle1();  tft.println("3");  CS4H;
  CS5L;  numbersStyle1();  tft.println("4");  CS5H;
  CS6L;  numbersStyle1();  tft.println("5");  CS6H;
  CS7L;  numbersStyle1();  tft.println("6");  CS7H;
  CS8L;  numbersStyle1();  tft.println("7");  CS8H;
  CS9L;  numbersStyle1();  tft.println("8");  CS9H;
  CS10L; numbersStyle1();  tft.println("9"); CS10H;
}

/*=========================================================================================================================
      Build-up EFFECT Screens 
  ========================================================================================================================*/
void effectSettings()
{
  AxeEffect *effect = Axe.getCurrentPreset().getEffectById(effectindex);
  
 if (effectindex ==0)
 {  //this gets rid of the useless effect that crashes the peddleboard :) 
 switch (effectindex) {
    case 1: CS = CS1; thisEffect = effect1; break;
    case 2: CS = CS2; thisEffect = effect2; break;
    case 3: CS = CS3; thisEffect = effect3; break;
    case 4: CS = CS4; thisEffect = effect4; break;
    case 5: CS = CS5; thisEffect = effect5; break;
    case 6: CS = CS6; thisEffect = effect6; break;    
    case 7: CS = CS7; thisEffect = effect7; break;
    case 8: CS = CS8; thisEffect = effect8; break;
    case 9: CS = CS9; thisEffect = effect9; break;
    case 10: CS = CS10; thisEffect = effect10; break;
  }           
      digitalWrite (CS, LOW);
      thisEffect = (effect->getEffectId());
      if (effect->isBypassed()) 
      {effectStyle1(); effect->printEffectName(tft);}
      else 
      {effectStyle2(); effect->printEffectName(tft);}
      digitalWrite (CS, HIGH);   
  }
  
}

/*=========================================================================================================================
       EFFECT initializing screens 
  ========================================================================================================================*/

void ini_effect()

{

  //================== EFFECTS ===========================
  CS1L,  CS2L,  CS3L,  CS4L,  CS5L,  CS6L, CS7L,  CS8L,  CS9L,  CS10L;  
  tft.fillScreen(TFT_BLACK);
  CS1H,  CS2H,  CS3H,  CS4H,  CS5H,  CS6H, CS7H,  CS8H,  CS9H,  CS10H; 
  
  switch (effectindex)
  {
    case 1:      effectSettings();      break; // = effect1
    case 2:      effectSettings();      break; // = effect2
    case 3:      effectSettings();      break; // = effect3
    case 4:      effectSettings();      break; // = effect4
    case 5:      effectSettings();      break; // = effect5
    case 6:      effectSettings();      break; // = effect6
    case 7:      effectSettings();      break; // = effect7
    case 8:      effectSettings();      break; // = effect8
    case 9:      effectSettings();      break; // = effect9
    case 10:     effectSettings();      break; // = effect10
  }
  effect_LCD_text();
}


/*=========================================================================================================================
       AMP1 and AMP2 NAME HELPER
  ========================================================================================================================*/

void ampName_helper(const char *Amp)
{
  stringAmp = Amp;
  stringAmp.trim();
  Arow1 = stringAmp.indexOf(' ');  //frows location of first ,
  amp_1 = stringAmp.substring(0, Arow1);   //captures first data String
  Arow2 = stringAmp.indexOf(' ', Arow1 + 1 ); //frows location of second ,
  amp_2 = stringAmp.substring(Arow1 + 1, Arow2 + 1); //captures second data String
  Arow3 = stringAmp.indexOf(' ', Arow2 + 1 );
  amp_3 = stringAmp.substring(Arow2 + 1, Arow3 + 1);
}

void ampName_buildup()
{
      debugln(); debug("AMPnumber 1 = "); debug(AMPnumber);  
      
      switch (AMPnumber) {

      case 1: ampName_helper(Amp); A_11 = amp_1.length(); A_12 = amp_2.length(); A_13 = amp_3.length(); amp_1.toCharArray(amp11, A_11 + 1); amp_2.toCharArray(amp12, A_12 + 1); amp_3.toCharArray(amp13, A_13 + 1); 
              debugln(); debug("AMP11 = "); debug(amp11); debug(", ");debug("AMP12 = "); debug(amp12); debug(", ");debug("AMP13 = "); debug(amp13); break;
      case 2: ampName_helper(Amp); A_21 = amp_1.length(); A_22 = amp_2.length(); A_23 = amp_3.length(); amp_1.toCharArray(amp21, A_21 + 1); amp_2.toCharArray(amp22, A_22 + 1); amp_3.toCharArray(amp23, A_23 + 1); break;
              debugln(); debug("AMP21 = "); debug(amp21); debug(", ");debug("AMP22 = "); debug(amp22); debug(", ");debug("AMP23 = "); debug(amp23); break;
      case 3: ampName_helper(Amp); A_31 = amp_1.length(); A_32 = amp_2.length(); A_33 = amp_3.length(); amp_1.toCharArray(amp31, A_31 + 1); amp_2.toCharArray(amp32, A_32 + 1); amp_3.toCharArray(amp33, A_33 + 1); break;
              debugln(); debug("AMP31 = "); debug(amp31); debug(", ");debug("AMP32 = "); debug(amp32); debug(", ");debug("AMP33 = "); debug(amp33); break;
      case 4: ampName_helper(Amp); A_41 = amp_1.length(); A_42 = amp_2.length(); A_43 = amp_3.length(); amp_1.toCharArray(amp41, A_41 + 1); amp_2.toCharArray(amp42, A_42 + 1); amp_3.toCharArray(amp43, A_43 + 1); break;
              debugln(); debug("AMP41 = "); debug(amp41); debug(", ");debug("AMP42 = "); debug(amp42); debug(", ");debug("AMP43 = "); debug(amp43); break;
    }
}

/*=========================================================================================================================
       AMP / CAB ABCD SETTINGS
  ========================================================================================================================*/

void AMP_ABCD()
{
    
	  if (select_AMP_1 == false || select_AMP_2 == false )
  {
  debugln();debugln();  debug(" * function AMP ABCD started on screenSetup.h");
  
  CS1L,  CS2L,  CS6L,  CS7L;
  ampabcdStyle_blackBezelLine();
  CS1H,  CS2H,  CS6H,  CS7H;

  CS9L; ampabcdStyle4(); ampabcdStyle3(); tft.println("   A   ");  CS9H;
  CS10L; ampabcdStyle4(); ampabcdStyle3(); tft.println("   B   "); CS10H;
  CS4L; ampabcdStyle4(); ampabcdStyle3(); tft.println("   C   ");  CS4H;
  CS5L; ampabcdStyle4(); ampabcdStyle3(); tft.println("   D   ");  CS5H;
  ampabcdStyle4();
   }

  
  if ((select_AMP_start == true) || (select_AMP_1 == true))
  { 

//  -->> AMP 1
    strcpy (Amp, AMP1_A); 
    AMPnumber = 1;
    ampName_buildup();
          CS9L; 
          if (A_11 >= 9){ ampabcdStyle5(); tft.println(amp11);}
          else
          {ampabcdStyle5(); tft.setCursor(80 - ((A_11 * 9) - 5), 40); tft.println(amp11);}
          tft.setCursor(80 - ((A_12 * 9) - 5), 70); tft.println(amp12); tft.setCursor(80 - ((A_13 * 9) - 5), 100); tft.println(amp13);  
          CS9H;

//  -->> AMP 2      
    strcpy (Amp, AMP1_B); 
    AMPnumber = 2;
    ampName_buildup();
          CS10L;
          if 
          (A_21 >= 9){ ampabcdStyle5(); tft.println(amp21);}
          else
          {ampabcdStyle5(); tft.setCursor(80 - ((A_21 * 9) - 5), 40); tft.println(amp21);}
          tft.setCursor(80 - ((A_22 * 9) - 5), 70); tft.println(amp22); tft.setCursor(80 - ((A_23 * 9) - 5), 100); tft.println(amp23);  
          CS10H;
  
//  -->> AMP 3
    strcpy (Amp, AMP1_C); 
    AMPnumber = 3;
    ampName_buildup();  
         CS4L;
          if 
          (A_11 >= 9){ ampabcdStyle5(); tft.println(amp31);}
          else
          {ampabcdStyle5(); tft.setCursor(80 - ((A_31 * 9) - 5), 40); tft.println(amp31);}
          tft.setCursor(80 - ((A_32 * 9) - 5), 70); tft.println(amp32); tft.setCursor(80 - ((A_33 * 9) - 5), 100); tft.println(amp33);   
         CS4H;

//  -->> AMP 4
    strcpy (Amp, AMP1_D); 
    AMPnumber = 4;
    ampName_buildup();
        CS5L;
          if 
          (A_11 >= 9){ ampabcdStyle5(); tft.println(amp41);}
          else
          {ampabcdStyle5(); tft.setCursor(80 - ((A_41 * 9) - 5), 40); tft.println(amp41);}
            tft.setCursor(80 - ((A_42 * 9) - 5), 70); tft.println(amp42); tft.setCursor(80 - ((A_43 * 9) - 5), 100); tft.println(amp43);   
        CS5H;
  select_AMP_start = false;
  select_AMP_1 = false;
  }


//==========================================================================================================================================

  if (select_AMP_2 == true)
  {
//  -->> AMP 1
    strcpy (Amp, AMP2_A); 
    AMPnumber = 1;
    ampName_buildup();
          CS9L;
          if (A_11 >= 9){ ampabcdStyle5(); tft.println(amp11);}
          else
          {ampabcdStyle5(); tft.setCursor(80 - ((A_11 * 9) - 5), 40); tft.println(amp11);}
          tft.setCursor(80 - ((A_12 * 9) - 5), 70); tft.println(amp12); tft.setCursor(80 - ((A_13 * 9) - 5), 100); tft.println(amp13);  
          CS9H;

//  -->> AMP 2      
    strcpy (Amp, AMP2_B); 
    AMPnumber = 2;
    ampName_buildup();
          CS10L;
          if 
          (A_21 >= 9){ ampabcdStyle5(); tft.println(amp21);}
          else
          {ampabcdStyle5(); tft.setCursor(80 - ((A_21 * 9) - 5), 40); tft.println(amp21);}
          tft.setCursor(80 - ((A_22 * 9) - 5), 70); tft.println(amp22); tft.setCursor(80 - ((A_23 * 9) - 5), 100); tft.println(amp23);  
          CS10H;
  
//  -->> AMP 3
    strcpy (Amp, AMP2_C); 
    AMPnumber = 3;
    ampName_buildup();  
         CS4L;
          if 
          (A_11 >= 9){ ampabcdStyle5(); tft.println(amp31);}
          else
          {ampabcdStyle5(); tft.setCursor(80 - ((A_31 * 9) - 5), 40); tft.println(amp31);}
          tft.setCursor(80 - ((A_32 * 9) - 5), 70); tft.println(amp32); tft.setCursor(80 - ((A_33 * 9) - 5), 100); tft.println(amp33);   
         CS4H;

//  -->> AMP 4
    strcpy (Amp, AMP2_D); 
    AMPnumber = 4;
    ampName_buildup();
        CS5L;
          if 
          (A_11 >= 9){ ampabcdStyle5(); tft.println(amp41);}
          else
          {ampabcdStyle5(); tft.setCursor(80 - ((A_41 * 9) - 5), 40); tft.println(amp41);}
            tft.setCursor(80 - ((A_42 * 9) - 5), 70); tft.println(amp42); tft.setCursor(80 - ((A_43 * 9) - 5), 100); tft.println(amp43);   
        CS5H;
  select_AMP_2 = false;
  }
  
  ampabcd_LCD_text();
}

/*=========================================================================================================================
     ABCD selection updating in screens 
  ========================================================================================================================*/

void channelSwitch()
{
  debugln();  debugln();  debug(" * function channelSwitch started on screenSetup.h");
  switch (changeCurrentEffect)
  {
    case 58: {CS1L; effectchannelswitchStyle1(); CS1H;} break;
    case 17: {CS2L; effectchannelswitchStyle1(); CS2H;} break;
    case 18: {CS6L; effectchannelswitchStyle1(); CS6H;} break;
    case 19: {CS7L; effectchannelswitchStyle1(); CS7H;} break;
  }
}

/*===================================================================================*/
/*Axelman8*/
