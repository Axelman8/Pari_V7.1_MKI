#pragma once


/*===========================================   -  Include library's  -  ================================================*/
#include <SD_ini.h>
#include "preset_range.h"


/*========================================================================================================================*/

/*=========================================================
    Serial monitor text: RAM MEMORY CALCULATION   
  =========================================================*/

void serialprint_memory_info() //Serial monitor text: RAM MEMORY CALCULATION 
{
  debugln();debugln(); 
  debugln(" =======================");
  debug(F(" -->> Free RAM = "));   //F function does the same and is now a built in library, in IDE > 1.0.0
  debugln(freeMemory());
  debugln(" =======================");  // print how much RAM is available in bytes.
}

/*=========================================================
    16*2 LCD text: RAM MEMORY CALCULATION   
  =========================================================*/
void availablememory()
{
    lcd.setCursor(0, 1); lcd.print("Free RAM: "); lcd.print(freeMemory()); lcd.print(" ");
}


void digitalClockDisplay()
{
  // digital clock display of the time
  if (millis() - lastMillis >= 1 * 1 * 1000UL)
  {
    lastMillis = millis();  //get ready for the next iteration
    lcd.setCursor(0, 0); lcd.print("    ");  lcd.print(rtc.getTimeStr()); lcd.print("     ");     
    if (strcmp(page, "numbers") != 0)
    {
    availablememory();
    }
  }
}

/*=========================================================
  BUTTONPRESS TIMER for ?   maby usefull in the future
  =========================================================*/

void buttonpressed()
{ currentMillis = millis();}   //for ?


/*==========================================================================================================================
     Helper for better view of SCENE and PRESET names
  ==========================================================================================================================*/

void SceneName_helper(const char *name)
{
  stringScene = name;
  stringScene.trim();
  row1 = stringScene.indexOf(' ');  //frows location of first ,
  str1 = stringScene.substring(0, row1);   //captures first data String
  row2 = stringScene.indexOf(' ', row1 + 1 ); //frows location of second ,
  str2 = stringScene.substring(row1 + 1, row2 + 1); //captures second data String
  row3 = stringScene.indexOf(' ', row2 + 1 );
  str3 = stringScene.substring(row2 + 1, row3 + 1);
}

void PresetName_helper()
{
  stringPreset = active_PresetName;
  stringPreset.trim();
  prow1 = stringPreset.indexOf(' ');  //frows location of first ,
  pre1 = stringPreset.substring(0, prow1);   //captures first data String
  prow2 = stringPreset.indexOf(' ', prow1 + 1 ); //frows location of second ,
  pre2 = stringPreset.substring(prow1 + 1, prow2 + 1); //captures second data String
  prow3 = stringPreset.indexOf(' ', prow2 + 1 );
  pre3 = stringPreset.substring(prow2 + 1, prow3 + 1);

  P11 = pre1.length(); P12 = pre2.length(); P13 = pre3.length();
  pre1.toCharArray(PRE11, P11 + 1); pre2.toCharArray(PRE12, P12 + 1); pre3.toCharArray(PRE13, P13 + 1);
}

void presetNames_buildup()
{
    if (P11 > 10)
    {  tft.setCursor(1, 10); }
    else
    { tft.setCursor((80 - ((P11 * 9) - 6)), 10); }
      tft.setTextSize(3);
      tft.setTextColor(presetNameStyle1_txt1_color);
      tft.println(PRE11);

    //row 2
    if (P12 > 10)
    { tft.setCursor(1, 39); }
    else
    { tft.setCursor((80 - ((P12 * 9) - 6)), 39); }
      tft.setTextSize(3);
      tft.setTextColor(presetNameStyle1_txt1_color);
      tft.println(PRE12);

    //row 3
    if (P13 > 10)
    { tft.setCursor(1, 68); }    
    else
    { tft.setCursor((80 - ((P13 * 9) - 6)), 68); }
      tft.setTextSize(3);
      tft.setTextColor(presetNameStyle1_txt1_color);
      tft.println(PRE13);
} 

void active_presetNames_buildup()
{
    if (P11 > 10)
    {  tft.setCursor(1, 10); }
    else
    { tft.setCursor((80 - ((P11 * 9) - 6)), 10); }
      tft.setTextSize(3);
      tft.setTextColor(presetNameStyle2_txt1_color);
      tft.println(PRE11);

    //row 2
    if (P12 > 10)
    { tft.setCursor(1, 39); }
    else
    { tft.setCursor((80 - ((P12 * 9) - 6)), 39); }
      tft.setTextSize(3);
      tft.setTextColor(presetNameStyle2_txt1_color);
      tft.println(PRE12);

    //row 3
    if (P13 > 10)
    { tft.setCursor(1, 68); }    
    else
    { tft.setCursor((80 - ((P13 * 9) - 6)), 68); }
      tft.setTextSize(3);
      tft.setTextColor(presetNameStyle2_txt1_color);
      tft.println(PRE13);
} 

void preset_UP_DOWN_Names_buildup()
{
    if (P11 > 10)
    {  tft.setCursor(1, 50); }
    else
    { tft.setCursor((80 - ((P11 * 9) - 6)), 50); }
      tft.setTextSize(3);
      tft.setTextColor(presetUpDown_screen_txt2_color,presetUpDown_screen_txt2_BGcolor);
      tft.println(PRE11);

    //row 2
    if (P12 > 10)
    { tft.setCursor(1, 39); }
    else
    { tft.setCursor((80 - ((P12 * 9) - 6)), 78); }
      tft.setTextSize(3);
      tft.setTextColor(presetUpDown_screen_txt2_color,presetUpDown_screen_txt2_BGcolor);
      tft.println(PRE12);

    //row 3
    if (P13 > 10)
    { tft.setCursor(1, 68); }    
    else
    { tft.setCursor((80 - ((P13 * 9) - 6)), 106); }
      tft.setTextSize(3);
      tft.setTextColor(presetUpDown_screen_txt2_color,presetUpDown_screen_txt2_BGcolor);
      tft.println(PRE13);
} 


/*===========================================================================================================================
     16*2 LCD BUILT TEXT on screen         
  ===========================================================================================================================*/

void scene_LCD_text()
{
  //lcd.clear();   //lcd.begin(16, 2);  lcd.setCursor(0, 0); lcd.print("ACT PRESET: "); lcd.print(active_Preset);
  availablememory(); digitalClockDisplay();
  }
  
void preset_LCD_text()
{
  //lcd.clear(); //lcd.begin(16, 2);  lcd.setCursor(0, 0); lcd.print("ACT PRESET: "); lcd.print(CurPreset);
  availablememory(); digitalClockDisplay();  
  }
  
void effect_LCD_text()
{
  //lcd.clear(); 
  availablememory(); digitalClockDisplay();
  }
  
void ampabcd_LCD_text()
{
  //lcd.clear(); //lcd.setCursor(0, 0); lcd.print("Sel. AMP/CAB 1st");
  availablememory(); digitalClockDisplay();
  }


void bankDown_LCD_text()
{ 
  //lcd.clear(); //lcd.setCursor(0, 0); lcd.print("Sel BANK: "); lcd.print(PresetNumb); lcd.print("-"); lcd.print(PresetNumb - 10);
  availablememory(); digitalClockDisplay();
}


void bankUp_LCD_text()
{ 
  //lcd.clear(); //lcd.setCursor(0, 0); lcd.print("Sel BANK: "); lcd.print(PresetNumb); lcd.print("-"); lcd.print(PresetNumb + 10);
  availablememory(); digitalClockDisplay();
}

void auditionmode_LCD_text()
{
  //lcd.clear(); //lcd.clear(); lcd.setCursor(0, 0); lcd.print("AUDITION MODE ON");
  availablememory(); digitalClockDisplay();
  }


/*================================================================================================================================
      SCREEN TEXT and COLOR styling settings 
  ================================================================================================================================*/

void bootupStyle1()
{
  tft.fillScreen(bootupStyle1_fillscreen);
  tft.setTextColor(bootupStyle1_txt1_color, bootupStyle1_fillscreen);
  tft.setTextSize(20);  tft.setCursor(60, 40);
  }
void bootupStyle2()
{
  tft.fillScreen(bootupStyle2_fillscreen);
  tft.setTextColor(bootupStyle2_txt1_color, bootupStyle2_fillscreen);
  tft.setTextSize(20);  tft.setCursor(60, 40);
}

void bootupStyle3()
{
  tft.fillScreen(bootupStyle3_fillscreen);
  tft.setTextColor(bootupStyle3_txt1_color, bootupStyle3_fillscreen);
  tft.setTextSize(20);  tft.setCursor(60, 40);
}

void bootupStyle4()
{
  tft.fillScreen(bootupStyle4_fillscreen);
  tft.setTextColor(bootupStyle4_txt1_color, bootupStyle4_fillscreen);
  tft.setTextSize(20);  tft.setCursor(60, 40);
}

void bootupStyle5()
{
  tft.fillScreen(bootupStyle5_fillscreen);
  tft.setTextColor(bootupStyle5_txt1_color, bootupStyle5_fillscreen);
  tft.setTextSize(8);  tft.setCursor(40, 40);
}

void tunerscreenStyle1()
{
tft.fillScreen(TFT_ORANGE);
tft.setTextColor(TFT_BLACK);  
tft.setTextSize(20);  tft.setCursor(60, 40);  
}

/*===========================================================================================================================
    SCENE STYLE
  ===========================================================================================================================*/ 

void scene_ACTIVEbezel()  // for scenes
{
   tft.drawLine(0, 99, 160, 99, sceneStyle_ACTIVEbezel);  // draw single line looks nice
   tft.drawRect(0, 0, 160, 128, sceneStyle_ACTIVEbezel);  // Draw bezel line
}

void scene_notACTIVEbezel()  // for scenes
{
   tft.drawLine(0, 99, 160, 99, sceneStyle_notACTIVEbezel); // draw single line looks nice
   tft.drawRect(0, 0, 160, 128, sceneStyle_notACTIVEbezel); // Draw bezel line
}



void sceneText() // this one holds space for text...  There whas "SCENES" here
{ tft.println("        "); }

void sceneCursor1()
{ tft.setTextSize(4); tft.setCursor(139, 100); }  

void sceneCursor2()
{ tft.setTextSize(4); tft.setCursor(1, 100); }  


void activesceneStyle1() // ACTIVE scene screen buildup 
{ tft.setTextColor(activesceneStyle1_txt1_color, activesceneStyle1_txt1_BGcolor);  sceneCursor2();  sceneText();  sceneCursor1(); }


void sceneStyle0() // ALL scene screen buildup
{ tft.setTextWrap(false); tft.fillScreen(sceneStyle0_fillscreen); scene_notACTIVEbezel(); 
  tft.setTextColor(sceneStyle4_txt1_color,sceneStyle_notACTIVEbezel); sceneCursor2(); sceneText();}


void sceneStyle1() // scenenumber buildup ALL screens
{ sceneCursor1(); 
  tft.setTextColor(sceneStyle1_txt1_color, sceneStyle1_txt1_BGcolor);
  tft.setTextColor(sceneStyle1_txt2_color, sceneStyle1_txt2_BGcolor);}  

void sceneStyle2()
{ tft.setTextSize(3); tft.setCursor(5, 10); 
  tft.setTextColor(sceneStyle2_txt1_color, sceneStyle2_txt1_BGcolor);
  tft.setTextColor(sceneStyle2_txt2_color, sceneStyle2_txt2_BGcolor);} 

void sceneStyle3()
{ tft.setTextSize(3); tft.setTextColor(sceneStyle3_txt1_color, sceneStyle3_txt1_BGcolor);}       
  
void sceneStyle4() // buildup scenes for all screens from switch_PageSettings.h
{ scene_notACTIVEbezel(); tft.setTextColor(sceneStyle4_txt1_color,sceneStyle_notACTIVEbezel); sceneCursor2(); sceneText();}   


void screen13Style()
{
  tft.fillScreen(screen13Style_fillscreen);
  tft.setTextColor(screen13Style_txt1_color,screen13Style_fillscreen);
  tft.setTextSize(6); tft.setCursor(Cursor, 0);
  tft.println("         ");
  tft.setTextSize(6); tft.setCursor(Cursor, 0);
  tft.setTextColor(screen13Style_txt1_color,screen13Style_fillscreen); 
  }

/*===========================================================================================================================
    PRESET UP/DOWN STYLE
  ===========================================================================================================================*/ 
void presetDown_Style()
{
  tft.fillScreen(presetUpDown_screen_fillscreen);
  tft.setTextColor(presetUpDown_screen_txt1_color,presetUpDown_screen_txt1_BGcolor);
  if (previousPreset < 10)
  { Cursor = 65;  }
  else if ((previousPreset >= 10) && (previousPreset < 100))
  { Cursor = 50;  }
  else if ((previousPreset >= 100) && (previousPreset < 1000))
  { Cursor = 29;  } 
  tft.setTextSize(6); tft.setCursor(Cursor, 2);
}

void presetUp_Style()
{
  tft.fillScreen(presetUpDown_screen_fillscreen);
  tft.setTextColor(presetUpDown_screen_txt1_color,presetUpDown_screen_txt1_BGcolor);
  if (nextPreset < 10)
  { Cursor = 65;  }
  else if ((nextPreset >= 10) && (nextPreset < 100))
  { Cursor = 50;  }
  else if ((nextPreset >= 100) && (nextPreset < 1000))
  { Cursor = 29;  } 
  tft.setTextSize(6); tft.setCursor(Cursor, 2);
}


void presetUpDown_Style1()
{ tft.setTextSize(2);  tft.setCursor(2, 65); tft.setTextColor(presetUpDown_screen_txt2_color,presetUpDown_screen_txt2_BGcolor);} 




/*===========================================================================================================================
    PRESET STYLE
  ===========================================================================================================================*/ 

void preset_ACTIVEbezel()  // for preset
{
   tft.drawRect(0, 0, 160, 128, presetStyle_ACTIVEbezel); // Draw bezel line
   tft.drawRect(1, 1, 158, 126, presetStyle_ACTIVEbezel); // Draw bezel line
   tft.drawRect(0, 95, 160, 128, presetStyle_ACTIVEbezel);  // Draw bezel line 
   tft.fillRect(0, 95, 160, 128, presetStyle_ACTIVEbezel);  // Draw bezel line
}

void preset_auditionMode_ACTIVEbezel()  // for preset
{
   tft.drawRect(0, 0, 160, 128, presetStyle_auditionMode_ACTIVEbezel); // Draw bezel line
   tft.drawRect(1, 1, 158, 126, presetStyle_auditionMode_ACTIVEbezel); // Draw bezel line
   tft.drawRect(0, 95, 160, 128, presetStyle_auditionMode_ACTIVEbezel);  // Draw bezel line 
   tft.fillRect(0, 95, 160, 128, presetStyle_auditionMode_ACTIVEbezel);  // Draw bezel line
}

void preset_notACTIVEbezel()  // for preset
{
   tft.drawRect(0, 0, 160, 128, presetStyle_notACTIVEbezel); // Draw bezel line
   tft.drawRect(1, 1, 158, 126, presetStyle_notACTIVEbezel); // Draw bezel line
   tft.drawRect(0, 95, 160, 128, presetStyle_notACTIVEbezel);  // Draw bezel line 
   tft.fillRect(0, 95, 160, 128, presetStyle_notACTIVEbezel);  // Draw bezel line
}

void presetStyle1()   // is not used at the moment
{ tft.setTextColor(presetStyle1_txt1_color, presetStyle1_txt1_BGcolor);
  tft.setTextSize(3); tft.setCursor(30, 30);
  tft.println("PRESET");
  tft.setTextSize(3); tft.setCursor(45, 70);
}

void presetNumberStyle1() 
{ preset_notACTIVEbezel(); tft.setTextSize(3);
  tft.setCursor(PNtxtWidth, PNtxtHeight); tft.setTextColor(presetNumberStyle1_txt1_color, presetNumberStyle1_txt1_BGcolor);}

void presetNameStyle1()  //Not active preset settings
{  tft.setTextSize(3);  tft.setCursor(3, 10); tft.setTextColor(presetNameStyle1_txt1_color, presetNameStyle1_txt1_BGcolor);}

void presetNumberStyle2()
{
if (auditionMode == true)
 {preset_auditionMode_ACTIVEbezel(); tft.setTextSize(3);
  tft.setCursor(PNtxtWidth, PNtxtHeight); tft.setTextColor(presetNumberStyle2_txt1_auditionMode_color, presetNumberStyle2_txt1_auditionMode_BGcolor);
  }
 else
{ preset_ACTIVEbezel(); tft.setTextSize(3);
  tft.setCursor(PNtxtWidth, PNtxtHeight); tft.setTextColor(presetNumberStyle2_txt1_color, presetNumberStyle2_txt1_BGcolor);
  }
}

void presetNameStyle2()
{ tft.setTextSize(3);  tft.setCursor(3, 10); tft.setTextColor(presetNameStyle2_txt1_color, presetNameStyle2_txt1_BGcolor);}


/*===========================================================================================================================
    EFFECT STYLE
  ===========================================================================================================================*/ 
void effectStyle1() { //BYPASS
  tft.fillScreen(effectStyle1_fillscreen);
  tft.setTextSize(4); tft.setCursor(2, 50);
  tft.setTextColor(effectStyle1_txt1_color, effectStyle1_txt1_BGcolor);
}

void effectStyle2() { //ACTIVE
  tft.fillScreen(effectStyle2_fillscreen);
  tft.setTextSize(4);  tft.setCursor(2, 50);
  tft.setTextColor(effectStyle2_txt1_color, effectStyle2_txt1_BGcolor);
}

/*===========================================================================================================================
    AMP_ABCD STYLE
  ===========================================================================================================================*/ 

void amp_abcd_GREENbezel() // for amp_abcd settings
{
   tft.drawRect(0, 0, 160, 128, ST7735_GREEN);    // Draw bezel line
   tft.drawRect(0, 0, 160, 33, ST7735_GREEN);     // Draw bezel line 
   tft.fillRect(0, 0, 160, 33, ST7735_GREEN);     // Draw bezel line
}

void amp_abcd_REDbezel()    // for amp_abcd settings
{
   tft.drawRect(0, 0, 160, 128, ST7735_RED);    // Draw bezel line
   tft.drawRect(0, 0, 160, 33, ST7735_RED);     // Draw bezel line 
   tft.fillRect(0, 0, 160, 33, ST7735_RED);     // Draw bezel line
}

void ampabcdStyle_blackBezelLine()
{
  tft.drawRect(0, 1, 160, 3, TFT_BLACK);
  tft.fillRect(0, 1, 160, 3, TFT_BLACK);
  tft.drawRect(0, 125, 160, 127, TFT_BLACK);
  tft.fillRect(0, 125, 160, 127, TFT_BLACK);
  tft.drawRect(0, 0, 160, 128, TFT_BLACK); // Draw bezel line
  tft.drawRect(1, 1, 158, 126, TFT_BLACK); // Draw bezel line
}

void ampabcdStyle_greenBezelLine()
{
  tft.drawRect(0, 1, 160, 3, TFT_GREEN);
  tft.fillRect(0, 1, 160, 3, TFT_GREEN);
  tft.drawRect(0, 125, 160, 127, TFT_GREEN);
  tft.fillRect(0, 125, 160, 127, TFT_GREEN);
  tft.drawRect(0, 0, 160, 128, TFT_GREEN); // Draw bezel line
  tft.drawRect(1, 1, 158, 126, TFT_GREEN); // Draw bezel line
}



void ampabcdStyle2()
{
  amp_abcd_GREENbezel();
  tft.setTextColor(ampabcd_screen_style2_color);
  tft.setTextSize(4); tft.setCursor(3,3); tft.println("      ");
  tft.setTextSize(4); tft.setCursor(0,3);  

}

void ampabcdStyle3()
{
  amp_abcd_REDbezel();
  tft.setTextColor(ampabcd_screen_style3_color);
  tft.setTextSize(4); tft.setCursor(3,3); tft.println("      ");
  tft.setTextSize(4); tft.setCursor(0,3);
}

void ampabcdStyle4()  //clear AMP text in the AMP A-B-C-D screens
{
  tft.drawRect(0, 34, 160, 128, ST7735_BLACK);     // Draw bezel line 
  tft.fillRect(0, 34, 160, 128, ST7735_BLACK);     // Draw bezel line   
}

void ampabcdStyle5()
{
  tft.setTextWrap(false);
  tft.setTextColor(ampabcd_screen_style5_color, ampabcd_style5_BGcolor );
  tft.setTextSize(3); 
}


/*===========================================================================================================================
    EFFECT CHANNEL SWITCH STYLE
  ===========================================================================================================================*/ 
void effectchannelswitchStyle0()
{
   tft.setTextSize(6); tft.setCursor(70, 10);
   tft.setTextColor(TFT_CYAN, TFT_BLACK);
  }  

void effectchannelswitchStyle1()
{
   tft.setTextSize(6); tft.setCursor(70, 10);
   tft.setTextColor(TFT_CYAN, TFT_BLACK);
   tft.println(channel);
  }

void effectchannelswitchStyle2()
{  
  tft.setCursor(40, 70);
  tft.setTextSize(4);
  tft.setTextColor(TFT_RED, TFT_BLACK);
  }

void effectchannelswitchStyle3()
{ 
  tft.setCursor(40, 70);
  tft.setTextSize(4);
  tft.setTextColor(TFT_GREEN, TFT_BLACK);
}

/*===========================================================================================================================
    LOOPER STYLE
  ===========================================================================================================================*/ 
void looperStyle1()
{
  tft.setTextColor(looper_screen_txt1_color, looper_screen_txt1_BGcolor);
  tft.setTextSize(3); tft.setCursor(30, 35);
  tft.println("LOOPER");
  tft.setTextSize(3); tft.setCursor(30, 70); 
  }  
void looperStyle2()
{
  tft.setTextColor(looper_screen_txt2_color, looper_screen_txt2_BGcolor);
  tft.setTextSize(3);  tft.setCursor(30, 35);
  tft.println("LOOPER");
  tft.setTextSize(3);  tft.setCursor(30, 70);  
  } 



/*===========================================================================================================================
    NUMBER STYLE
  ===========================================================================================================================*/ 

void numbersStyle1()
{
  tft.setTextSize(20);  tft.setCursor(65, 40);
  tft.setTextColor(numberSelect_screen_txt1_color, numberSelect_screen_fillscreen);
  }

/*===========================================================================================================================
     PRESET SCREENS BUILT UP         
  ===========================================================================================================================*/

void preset_screen()
{
  tft.fillScreen(preset_screen_fillscreen);
  tft.setTextColor(preset_screen_txt1_color, preset_screen_txt1_BGcolor);
  tft.setTextSize(3);  tft.setCursor(35, 35);
  tft.println("PRESET");
  tft.setTextColor(preset_screen_txt2_color, preset_screen_txt2_BGcolor);
  tft.setTextSize(3); tft.setCursor(45, 70);
  tft.println("PAGE");
}

void presetNameNumber_screen()
{ 
  tft.fillScreen(presetNameNumber_screen_fillscreen);
  tft.setTextColor(presetNameNumber_screen_txt1_color, presetNameNumber_screen_txt1_BGcolor);
  tft.setTextSize(4);  tft.setCursor(65, 20);  tft.println("NO");
  tft.setTextColor(presetNameNumber_screen_txt2_color, presetNameNumber_screen_txt2_BGcolor);  
  tft.setTextSize(4);  tft.setCursor(35, 70);  tft.println("INFO");
}

/*===========================================================================================================================
    PRESET UP SCREEN BUILD-UP 
  ===========================================================================================================================*/  

void presetDown_handler()
{
    if ((previousPreset) != maxPreset)
      {    
    PresetNumb = active_Preset;
    if ((previousPreset % 10) == 9)
    {PresetNumb = (PresetNumb - 10);}
      }
    else
        {
      PresetNumb = maxPreset;
        }
}

//================================================

void presetUp_handler()
{
    if ((nextPreset) != 0)
      {
       PresetNumb = active_Preset; 
        if ((nextPresetnr % 10) == 0)
        {PresetNumb = (active_Preset + 10);}
      }
    else
    {
      PresetNumb = 0; 
        }
  }

//================================================


void presetUp_screen()
{
  if (strcmp(page, "scene") == 0)
  {
    nextPresetnr = (nextPreset % 10);
    presetUp_handler();
    presetRange(); delay(10); 
    preset_Names(); delay(10);
    
  switch (nextPresetnr)
  {
  case 0:  strcpy(active_PresetName, PresetName0); debugln(); debug(" nextPresetName = "); debug(PresetName0); break;
  case 1:  strcpy(active_PresetName, PresetName1); debugln(); debug(" nextPresetName = "); debug(PresetName1); break;
  case 2:  strcpy(active_PresetName, PresetName2); debugln(); debug(" nextPresetName = "); debug(PresetName2); break;
  case 3:  strcpy(active_PresetName, PresetName3); debugln(); debug(" nextPresetName = "); debug(PresetName3); break;
  case 4:  strcpy(active_PresetName, PresetName4); debugln(); debug(" nextPresetName = "); debug(PresetName4); break;
  case 5:  strcpy(active_PresetName, PresetName5); debugln(); debug(" nextPresetName = "); debug(PresetName5); break;
  case 6:  strcpy(active_PresetName, PresetName6); debugln(); debug(" nextPresetName = "); debug(PresetName6); break;
  case 7:  strcpy(active_PresetName, PresetName7); debugln(); debug(" nextPresetName = "); debug(PresetName7); break;
  case 8:  strcpy(active_PresetName, PresetName8); debugln(); debug(" nextPresetName = "); debug(PresetName8); break;
  case 9:  strcpy(active_PresetName, PresetName9); debugln(); debug(" nextPresetName = "); debug(PresetName9); break;
  }
    debugln(); debug(" nextPresetnr = "); debug(nextPreset);  
    debugln(); debug(" Nextpreset PresetNumb = "); debug(PresetNumb);
      

    presetUp_Style();  tft.println(nextPreset);
    presetUpDown_Style1();
    PresetName_helper();
    preset_UP_DOWN_Names_buildup(); 
    PresetNumb = active_Preset;
  }
}

/*===========================================================================================================================
    PRESET DOWN SCREEN BUILD-UP 
  ===========================================================================================================================*/ 
void presetDown_screen()
{
  if (strcmp(page, "scene") == 0)
  {
  previousPresetnr = (previousPreset % 10); 
    presetDown_handler();
    presetRange(); delay(10);
    preset_Names(); delay(10);
        
  switch (previousPresetnr)
  {
  case 0:  strcpy(active_PresetName, PresetName0); debugln(); debug(" previousPresetName = "); debug(PresetName0); break;
  case 1:  strcpy(active_PresetName, PresetName1); debugln(); debug(" previousPresetName = "); debug(PresetName1); break;
  case 2:  strcpy(active_PresetName, PresetName2); debugln(); debug(" previousPresetName = "); debug(PresetName2); break;
  case 3:  strcpy(active_PresetName, PresetName3); debugln(); debug(" previousPresetName = "); debug(PresetName3); break;
  case 4:  strcpy(active_PresetName, PresetName4); debugln(); debug(" previousPresetName = "); debug(PresetName4); break;
  case 5:  strcpy(active_PresetName, PresetName5); debugln(); debug(" previousPresetName = "); debug(PresetName5); break;
  case 6:  strcpy(active_PresetName, PresetName6); debugln(); debug(" previousPresetName = "); debug(PresetName6); break;
  case 7:  strcpy(active_PresetName, PresetName7); debugln(); debug(" previousPresetName = "); debug(PresetName7); break;
  case 8:  strcpy(active_PresetName, PresetName8); debugln(); debug(" previousPresetName = "); debug(PresetName8); break;
  case 9:  strcpy(active_PresetName, PresetName9); debugln(); debug(" previousPresetName = "); debug(PresetName9); break;
  }
    debugln(); debug(" previousPresetnr = "); debug(previousPreset);
    debugln(); debug(" PreviousPreset PresetNumb = "); debug(PresetNumb); 

    presetDown_Style();  tft.println(previousPreset);
    presetUpDown_Style1();
    PresetName_helper();
    preset_UP_DOWN_Names_buildup();     
    PresetNumb = active_Preset;
  }
}

/*===========================================================================================================================
    EFFECT SCREEN BUILD-UP 
  ===========================================================================================================================*/ 
void effect_screen()
{
  tft.fillScreen(effect_screen_fillscreen);
  tft.setTextColor(effect_screen_txt1_color, effect_screen_txt1_BGcolor);
  tft.setTextSize(3); tft.setCursor(35, 35);
  tft.println("EFFECT");
  tft.setTextColor(effect_screen_txt2_color, effect_screen_txt2_BGcolor);
  tft.setTextSize(3); tft.setCursor(45, 70);
  tft.println("PAGE");
  }

void ampABCD_screen()
{
  tft.fillScreen(ampABCD_screen_fillscreen);
  tft.setTextColor(ampABCD_screen_txt1_color, ampABCD_screen_txt1_BGcolor);
  tft.setTextSize(3); tft.setCursor(0, 35);
  tft.println(" AMP/CAB ");
  tft.setTextColor(ampABCD_screen_txt2_color, ampABCD_screen_txt2_BGcolor);
  tft.setTextSize(3); tft.setCursor(45, 70);  
  tft.println("ABCD");  
  }

/*=========================================================================================================================
     WAH SCREEN BUILD-UP 
  ========================================================================================================================*/
  
void NOWAH_screen()
{
  tft.setTextColor(NOWAH_screen_txt1_color, NOWAH_screen_txt1_BGcolor);
  tft.setTextSize(2); tft.setCursor(0, 0);
  tft.println("NO WAH ACTIVE");
  }

void YESWAH_screen()
{  
  tft.setTextColor(YESWAH_screen_txt1_color, YESWAH_screen_txt1_BGcolor);
  tft.setTextSize(2); tft.setCursor(0, 0);
  tft.println("WAH AVAILABLE");
  }


/*=========================================================================================================================
      LOOPER SCREEN BUILD-UP 
  ========================================================================================================================*/

void looper_screen()
{
  tft.fillScreen(looper_screen_fillscreen);
  tft.setTextColor(looper_screen_txt1_color, looper_screen_txt1_BGcolor);
  tft.setTextSize(3); tft.setCursor(30, 50); 
  tft.println("LOOPER");
  }

void NOLOOPER_screen()
{
  tft.setTextColor(NOLOOPER_screen_txt1_color, NOLOOPER_screen_txt1_BGcolor);
  tft.setTextSize(2); tft.setCursor(0, 0);
  tft.println("  NO LOOPER  ");
  }

void YESLOOPER_screen()
{
  tft.setTextColor(YESLOOPER_screen_txt1_color, YESLOOPER_screen_txt1_BGcolor);
  tft.setTextSize(2); tft.setCursor(0, 0);
  tft.println("LOOPER ACTIVE");
  }

/*=========================================================================================================================
      NUMBER SCREEN BUILD-UP 
  ========================================================================================================================*/

void numberSelect_screen()
{
  tft.fillScreen(number_screen_fillscreen);
  tft.setTextColor(number_screen_txt1_color, number_screen_txt1_BGcolor);
  tft.setTextSize(3); tft.setCursor(10, 0);
  tft.println("Axelman8");
  tft.setTextSize(3); tft.setCursor(30, 50);
  tft.setTextColor(number_screen_txt2_color, number_screen_txt2_color);
  tft.println("NUMBER");
  tft.setTextSize(3); tft.setCursor(30, 85);
  tft.setTextColor(number_screen_txt3_color, number_screen_txt3_color);  
  tft.println("SELECT");  
  }

void reset_numberSelect_screen()
{
  lcd.clear(); lcd.setCursor(0, 0); lcd.print("Selected =      ");
  delay(200);
  Counter = 0;
}


/*=========================================================================================================================
      AUDITIONMODE SCREEN BUILD-UP 
  ========================================================================================================================*/

void auditionMode_screen()
{
    tft.fillScreen(auditionMode_screen_fillscreen);
    tft.setTextColor(auditionMode_screen_txt1_color, auditionMode_screen_txt1_BGcolor);
    tft.setTextSize(3); tft.setCursor(10, 30);
    tft.println("AUDITION");
    tft.setTextColor(auditionMode_screen_txt2_color, auditionMode_screen_txt2_BGcolor);
    tft.setTextSize(3); tft.setCursor(40, 70);
    tft.println("MODE");
    tft.drawRect(0, 0, 160, 128, auditionMode_screen_txt1_color); // Draw bezel line
    auditionMode = false;
  }

void auditionMode_ON_screen() 
{
            CS13L;
            tft.fillScreen(TFT_BLACK);
            tft.setTextColor(TFT_RED);
            tft.setTextSize(3); tft.setCursor(10, 30);
            tft.println("AUDITION");
            tft.setTextSize(4); tft.setCursor(60, 80);
            tft.println("ON");
            tft.drawRect(0, 0, 160, 128, TFT_RED); // Draw bezel line
            CS13H;
          delay(50);
  }

/*=========================================================================================================================
      TUNER SCREEN SELECTION BUILD-UP 
  ========================================================================================================================*/

void tuner_selectionScreen()
{
    CS12L;
    tft.fillScreen(tuner_screen_fillscreen);
    tft.setTextColor(tuner_screen_txt1_color, tuner_screen_txt1_BGcolor);
    tft.setTextSize(3); tft.setCursor(5, 25);
    tft.println(" TAP FOR");
    tft.setTextColor(tuner_screen_txt1_color, tuner_screen_txt1_BGcolor);
    tft.setTextSize(3); tft.setCursor(15, 60);
    tft.println(" TUNER ");
    tft.setTextColor(tuner_screen_txt2_color, tuner_screen_txt2_BGcolor);
    tft.setTextSize(3); tft.setCursor(5, 95);
    tft.println(tuner_type);
    CS12H;
  }

void tuner_circleSelection()
{
    strcpy(tuner_type, " CIRCLE ");
    tuner_selectionScreen();
  delay(200);    
} 

void tuner_pyramidSelection()
{
    strcpy(tuner_type, " PYRAMID");
    tuner_selectionScreen();
  delay(200); 
} 


/*=========================================================================================================================
      TAP TEMPO SCREEN BUILD-UP 
  ========================================================================================================================*/
void tapTempo_screen()
{
  if (flashScreen14 != true)
  {flashhight_tempo_Text = 15;}
  else
  {flashhight_tempo_Text = 40;}
  
    CS14L;
    Axe.requestTempo();
    tft.fillScreen(tapTempo_screen_fillscreen);
    tft.setTextColor(tapTempo_screen_txt1_color, tapTempo_screen_txt1_BGcolor);
    tft.setTextSize(5); tft.setCursor(5, flashhight_tempo_Text);
    tft.println("TEMPO");
    tft.setTextColor(tapTempo_screen_txt2_color, tapTempo_screen_txt2_BGcolor);
    tft.setTextSize(4); tft.setCursor(53, 90);
    tft.println(Axe.getTempo());  
    CS14H;
}

/* ========== IN AUDITIONMODE - CHANGE FLASH IN SCREEN 14 ===============*/

void tapTempo_flash_selection_screen()
{
    CS14L;
    Axe.requestTempo();
    tft.fillScreen(tapTempo_screen_fillscreen);
    tft.setTextColor(tapTempo_screen_txt1_color, tapTempo_screen_txt1_BGcolor);
    tft.setTextSize(3); tft.setCursor(5, 30);
    tft.println(" TAP FOR");
    tft.setTextColor(tapTempo_screen_txt1_color, tapTempo_screen_txt1_BGcolor);
    tft.setTextSize(3); tft.setCursor(5, 60);
    tft.println("  OTHER ");
    tft.setTextColor(tapTempo_screen_txt2_color, tapTempo_screen_txt2_BGcolor);
    tft.setTextSize(3); tft.setCursor(5, 95);
    tft.println("  FLASH ");  
    CS14H; 
  }

void tapTempo_selectionScreen()
{
  if (flashScreen14 != true)
  {flashhight_tempo_Text = 15;}
  else
  {flashhight_tempo_Text = 30;}
  if (auditionMode == true)
  {tapTempo_flash_selection_screen();}
  else
  {
    CS14L;
    tft.fillScreen(tapTempo_selectionScreen_fillscreen);
    tft.setTextColor(tapTempo_selectionScreen_txt1_color, tapTempo_selectionScreen_txt1_BGcolor);
    tft.setTextSize(5); tft.setCursor(5, flashhight_tempo_Text);
    tft.println("TEMPO");
    tft.setTextColor(tapTempo_selectionScreen_txt2_color, tapTempo_selectionScreen_txt2_BGcolor);
    tft.setTextSize(4); tft.setCursor(53, 80);
    tft.println(Axe.getTempo());
    CS14H;
  }
}


TFT_eSprite tempoflash = TFT_eSprite(&tft);  // Declare Sprite object "spr" with pointer to "tft" object


void tapTempo_sprite() 
{ 
  if (tempoflash_bar == true)
  {
  tempoflash.setColorDepth(1); // 1 = brightest.   choose 8 for 16 colours (all color variations)
  tempoflash.createSprite(160, 20);

  }
  else
  {
  tempoflash.setColorDepth(1); // 1 = brightest.   choose 8 for 16 colours (all color variations)
  tempoflash.createSprite(160, 20);

    }
}

void tapTempo_flash_ON() 
{  
  if (tempoflash_bar == true)
  {
    //(x,y,w,h,lenth,radius)
  tempoflash.drawRoundRect(35, 0, 90, 20, 6, tapTempo_screen_sprite_color);
  tempoflash.fillRoundRect(37, 2, 86, 16, 6, tapTempo_screen_flash_color);
  CS14L;
  tempoflash.pushSprite(0, 0);
  CS14H;
    }
  else
  {
  tempoflash.drawRoundRect(0, 0, 30, 20, 6, tapTempo_screen_sprite_color);
  tempoflash.drawRoundRect(43, 0, 30, 20, 6, tapTempo_screen_sprite_color);
  tempoflash.drawRoundRect(86, 0, 30, 20, 6, tapTempo_screen_sprite_color);
  tempoflash.drawRoundRect(129, 0, 30, 20, 6, tapTempo_screen_sprite_color);
    
    switch (tempo_Counter)
    {
  case 1:
  tempoflash.fillRoundRect(2, 2, 26, 16, 6, tapTempo_screen_flash_color);
  break;

  case 2:  
  tempoflash.fillRoundRect(45, 2, 26, 16, 6, tapTempo_screen_flash_color);
  break;
  
  case 3:
  tempoflash.fillRoundRect(88, 2, 26, 16, 6, tapTempo_screen_flash_color);
  break;
  
  case 4:
  tempoflash.fillRoundRect(131, 2, 26, 16, 6, tapTempo_screen_flash_color);  
  break;
    }
  CS14L;
  tempoflash.pushSprite(0, 0);
  CS14H;   
  }
}


void tapTempo_flash_OFF()
{
  if (tempoflash_bar == true)
  {  
  tempoflash.drawRoundRect(35, 0, 90, 20, 6, tapTempo_screen_sprite_color);
  tempoflash.fillRoundRect(37, 2, 86, 16, 6, tapTempo_screen_fillscreen);
  CS14L;
  tempoflash.pushSprite(0, 0);
  CS14H;
  }
  else
  {
  tempoflash.fillRoundRect(2, 2, 26, 16, 6, tapTempo_screen_fillscreen);
  tempoflash.fillRoundRect(45, 2, 26, 16, 6, tapTempo_screen_fillscreen);
  tempoflash.fillRoundRect(88, 2, 26, 16, 6, tapTempo_screen_fillscreen);
  tempoflash.fillRoundRect(131, 2, 26, 16, 6, tapTempo_screen_fillscreen);  
  }
  CS14L;
  tempoflash.pushSprite(0, 0);
  CS14H;      
}


/*===========================================================================================================================
     PRESET |  ADDITIONAL PAGE'S         
  ===========================================================================================================================*/

void presetMin100_screen()
{ CS11L;  presetStyle1();  tft.println("-100");  CS11H;}
    
void presetMin50_screen()
{ CS12L;  presetStyle1();  tft.println("-50");   CS12H;}
   
void presetPlus50_screen()
{ CS14L;  presetStyle1(); tft.println("+50");    CS14H;}
      
void presetPlus100_screen()
{ CS15L;  presetStyle1(); tft.println("+100");   CS15H;}

void presetUpDownscreens()
{
    CS5L;  sceneScreen_5;   CS5H;
    CS10L; sceneScreen_10;  CS10H;
  }

/*===========================================================================================================================
     TUNER SCREEN | SCREEN 8 BUILT UP        
  ===========================================================================================================================*/

void tuner_startScreens()
{   CS1L, CS2L, CS3L, CS4L, CS5L,CS8L, CS11L, CS12L, CS14L, CS15L;
    tft.fillScreen(TFT_BLACK); 
    CS1H, CS2H, CS3H, CS4H, CS5H,CS8H, CS11H, CS12H, CS14H, CS15H;
  
    CS6L; tunerscreenStyle1(); tft.println("T"); CS6H;
    CS7L; tunerscreenStyle1(); tft.println("U"); CS7H;
    CS9L; tunerscreenStyle1(); tft.println("N"); CS9H;
    CS10L; tunerscreenStyle1(); tft.println("E"); CS10H;

}
/*===========================================================================================================================
     TOPSCREENS BUILT UP | ALL SEPARATE PAGE'S         
  ===========================================================================================================================*/

void sceneTopscreens()
{
    strcpy(page, "scene");
    debugln(); debug(" * PAGE is set to: "); debug(page);
  if (scene_Topscreen11 == true){ CS11L; sceneScreen_11;  CS11H;}
  if (scene_Topscreen12 == true){ CS12L; sceneScreen_12;  CS12H;}
  if (scene_Topscreen14 == true){ CS14L; sceneScreen_14;  CS14H;}
  if (scene_Topscreen15 == true){ CS15L; sceneScreen_15;  CS15H;}
  }


void auditionmodeTopscreens()
{
  strcpy(page, "preset");
  debugln(); debug(" * PAGE is set to -> ");  debug(page); debug(" <- while in auditionMode");
  CS11L; presetScreen_11; CS11H;
  CS15L; presetScreen_15; CS15H; 
  tapTempo_flash_selection_screen();
  tuner_selectionScreen();   

}

void exit_auditionmodeTopscreens()
{
  auditionMode = false;
  strcpy(page, "scene");
  debugln(); debug(" * PAGE is set to ->  "); debug(page); debug(" <- after exiting auditionMode");
}


void presetTopscreens()  
{
//Set the page to PRESET.  If we do not set it to preset, then the presetpage will not function conrrectly with a preset selection.  
    strcpy(page, "preset"); 
    debugln(); debug(" * PAGE is set to: "); debug(page);       

if (preset_Topscreen11 == true){ CS11L; presetScreen_11; CS11H;}
if (preset_Topscreen12 == true){ CS12L; presetScreen_12; CS12H;}

    CS13L;  auditionMode_screen(); CS13H;
    
if (preset_Topscreen14 == true){ CS14L; presetScreen_14; CS14H;}
if (preset_Topscreen15 == true){ CS15L; presetScreen_15; CS15H;}

  }


void effectTopscreens()
{
    strcpy(page, "effect");
    debugln(); debug(" * PAGE is set to: ");debug(page);
if (effect_Topscreen11 == true){ CS11L; effectScreen_11;  CS11H;}
if (effect_Topscreen12 == true){ CS12L; effectScreen_12;  CS12H;}
if (effect_Topscreen14 == true){ CS14L; effectScreen_14;  CS14H;}
if (effect_Topscreen15 == true){ CS15L; effectScreen_15;  CS15H;}
  }


void abcdTopscreens()
{
    strcpy(page, "AMP_effect");
    debugln(); debug(" * PAGE is set to: "); debug(page);
if (AMP_ABCD_Topscreen11 == true){ CS11L; AMP_effectScreen_11;  CS11H;}
if (AMP_ABCD_Topscreen12 == true){ CS12L; AMP_effectScreen_12;  CS12H;}
if (AMP_ABCD_Topscreen14 == true){ CS14L; AMP_effectScreen_14;  CS14H;}
if (AMP_ABCD_Topscreen15 == true){ CS15L; AMP_effectScreen_15;  CS15H;}
  }
  

//    tft.fillScreen(TFT_BLACK); // additional not used screens goto black
void looperTopscreens()
{
    strcpy(page, "looper");
    debugln(); debug(" * PAGE is set to: ");debug(page);
if (looper_Topscreen11 == true){ CS11L; looperScreen_11; CS11H;}
if (looper_Topscreen12 == true){ CS12L; looperScreen_12; CS12H;}
if (looper_Topscreen14 == true){ CS14L; looperScreen_14; CS14H;}
if (looper_Topscreen15 == true){ CS15L; looperScreen_15; CS15H;}
  }


void numberTopscreens()
{
    strcpy(page, "numbers");
    debugln(); debug(" * PAGE is set to: "); debug(page);
if (number_Topscreen11 == true){ CS11L; numberScreen_11; CS11H;}
if (number_Topscreen12 == true){ CS12L; numberScreen_12; CS12H;}
if (number_Topscreen14 == true){ CS14L; numberScreen_14; CS14H;}
if (number_Topscreen15 == true){ CS15L; numberScreen_15; CS15H;}
 } 
  
/*===================================================================================*/
/*Axelman8*/  
