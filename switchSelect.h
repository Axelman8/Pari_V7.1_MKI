#pragma once


/*===========================================   -  Include library's  -  ================================================*/

#include <AxeFxControl.h>


#include "Screenstyle.h"
#include "axe_handler.h"
#include "Preset_range.h"
#include "screenSetup.h"


/*================================================================================================================================*/
/*   +++++    SCREEN SELECT      +++++     DO NOT EDIT THESE CODES   +++++     
/*================================================================================================================================*/

void scenePage_selection()
{
  debugln(); debug(" -> Pressed Switch = "); debug(currentSwitch + 1);  
  debugln(); debugln(); debug(" * function scenePage_selection started on switchSelect.h");

  auditionMode = false;
  debugln();debug(" -> auditionmode set to: ");debug(auditionMode);
  currentEffect = 0;
  Counter = 0;
  getScenes = true;
  effectCycle = true;
  debugln(); debug(" -> effectcycle set to: ");  debug(effectCycle);
  debugln(); debug(" -> getScenes set to: "); debug(getScenes);  
  if (strcmp(page, "effect") == 0)
  {
    if (RESET_EFFECT == true)  // when going to scenepage, reset effects true or false? 
    {
      reset_effectbypass_state = true;
      Axe.refresh();  
      }
  }
  if (auditionMode == true)
  {exit_auditionmodeTopscreens();}
  else
  {sceneTopscreens();}
  ini_scenes();
  delay(20);
}

/*==================   OR  ========================*/
void presetPage_selection()
{
  debugln(); debug(" -> Pressed Switch = "); debug(currentSwitch + 1);  
  debugln(); debugln(); debug(" * function presetPage_selection started on switchSelect.h");
 
  presetTopscreens();
  auditionMode = false;
  debugln(); debug (" -> auditionmode set to: ");  debug(auditionMode);
  getScenes = false;
  effectCycle = true;
  debugln(); debug(" -> effectcycle set to: "); debug(effectCycle);
  debugln(); debug(" -> getScenes set to: ");   debug(getScenes); 
  presetRange();
  ini_preset();
  delay(20);
}


/*==================   OR  ========================*/
void looperPage_selection() 
{
  debugln(); debug(" -> Pressed Switch = "); debug(currentSwitch + 1);  
  debugln(); debugln(); debug(" * function looperPage_selection started on switchSelect.h"); 
  
  looperTopscreens();
  ini_looper();
  delay(20);
}

/*==================   OR  ========================*/
void numberPage_selection() 
{
  debugln(); debug(" -> Pressed Switch = "); debug(currentSwitch + 1); 
  debugln();debugln();  debug(" * function numberPage_selection started on switchSelect.h");   

  if (auditionMode != true)
  {numberTopscreens();}  
  Counter = 0;
  ini_numbers();
  delay(20);
 }

/*==================   OR  ========================*/

void ampabcdPage_selection() 
{
  if (auditionMode == true)  // On auditionMode there is tunerscreen change on screen 12 and Flash change screen 14
  {
    if (tunerScreen8_Circle == false)
    {tunerScreen8_Circle = true;
     tuner_pyramidSelection();    
    }
    else
    {
      tunerScreen8_Circle = false;
      tuner_circleSelection();      
      }
  }
  else
  {
  select_AMP_start = true;  // show amp names of AMP1 on buildup of the AMP_ABCD screens
  preset_amp();
  debugln(); debug(" -> Pressed Switch = "); debug(currentSwitch + 1); 
  debugln(); debugln(); debug(" * function ampabcdPage_selection started on switchSelect.h");
  
  CS1L; CS2L;  CS3L;  CS4L;  CS5L; 
  CS6L; CS7L;  CS8L;  CS9L;  CS10L;  
  tft.fillScreen(TFT_BLACK);
  CS1H; CS2H;  CS3H;  CS4H;  CS5H;  
  CS6H; CS7H;  CS8H;  CS9H;  CS10H;  

    if (strcmp(page,"AMP_effect") !=0)  
    {abcdTopscreens();}
    getScenes = false;
    effectCycle = true;
    debugln(); debug(" -> getScenes set to: "); debug(getScenes);
    debugln(); debug(" -> effectcycle set to: ");  debug(effectCycle);
    delay(20);
    currentEffect = 0;
    debugln(); debug(" currenteffect = 0");
    AxePreset preset = (Axe.getCurrentPreset());
    presetName_setting(preset);
    AMP_ABCD();
    Axe.refresh(); 
  }
}

/*==================   OR  ========================*/
void effectPage_selection() 
{
  debugln(); debug(" -> Pressed Switch = "); debug(currentSwitch + 1); 
  debugln(); debugln(); debug(" * function effectPage_selection started on switchSelect.h");
  
  effectTopscreens();
  getScenes = false;
  debugln(); debug(" -> getScenes set to: "); debug(getScenes);
  effectCycle = true;
  debugln(); debug(" -> effectcycle set to: ");  debug(effectCycle);
  auditionMode = false;
  debugln(); debug(" -> auditionmode set to: ");debug(auditionMode);
  ini_effect();
  Axe.refresh();

}

/*==================   OR  ========================*/
void taptempoPage_selection() 
{
  debugln(); debug(" -> Pressed Switch = "); debug(currentSwitch + 1);  
  debugln(); debugln(); debugln(" * function taptempoPage_selection started on switchSelect.h");   

 
 if (auditionMode != true)
 {
  if (tapSwitch == false) 
  {
    tempoflash_bar == false;
    Axe.sendTap();
    tapSwitch = true;
    CS14L;
    tapTempo_selectionScreen();
    CS14H;
  }
  else
  {
    Axe.sendTap();
    tapSwitch = false;
    CS14L;
    tapTempo_screen();
    CS14H;
    tempoflash_bar == true;
  }
    }
      if (auditionMode == true)
    {
  if (tempoflash_bar == false)
    {
    tempoflash_bar = true;
    }
      else
      {
      tempoflash_bar = false;
      }
  tempoflash.deleteSprite();
  tapTempo_flash_selection_screen();
  }
}


/*==================   OR  ========================*/

void tunerPage_selection()
{
  debugln(); debug(" -> Pressed Switch = "); debug(currentSwitch + 1); 
  debugln(); debugln(); debug(" * function tunerPage_selection started on switchSelect.h");
  debugln(); debug(" -> TUNER started");

  if (tunerScreen8 == true)
  {
    tuner_startScreens();
  }
  Axe.toggleTuner();
}

/*================================================================================================================================*/
/*   Build-up SCENE selection Screen  
/*================================================================================================================================*/
void sceneSelection()
{
  switch (currentSwitch) {
    case 0: CS = CS1; sceneNumber = 1; SWITCH = SWITCH1; break;
    case 1: CS = CS2; sceneNumber = 2; SWITCH = SWITCH2; break;
    case 2: CS = CS3; sceneNumber = 3; SWITCH = SWITCH3; break;
    case 3: CS = CS4; sceneNumber = 4; SWITCH = SWITCH4; break;
    case 5: CS = CS6; sceneNumber = 5; SWITCH = SWITCH6; break;
    case 6: CS = CS7; sceneNumber = 6; SWITCH = SWITCH7; break;
    case 7: CS = CS8; sceneNumber = 7; SWITCH = SWITCH8; break;
    case 8: CS = CS9; sceneNumber = 8; SWITCH = SWITCH9; break;
  }

  MIDI.sendControlChange(SceneSelect_CC, sceneNumber - 1, MIDICHAN);

  debugln(); debug(" -> Pressed Switch = "); debug(currentSwitch + 1); debug(" | Buttonpin = "); debug(SWITCH);
  debugln(); debug(" -> Screenpin = "); debug(CS);
  debugln(); debug(" -> Active sceneNumber = "); debug(sceneNumber);;

  digitalWrite (CS, LOW);
  activesceneStyle1();
  tft.println(sceneNumber);
  scene_ACTIVEbezel();
  digitalWrite (CS, HIGH);
}

/*================================================================================================================================*/
/*   Build-up PRESET selection Screens  
/*================================================================================================================================*/

void presetSelection()
{
   if (auditionMode == true)
          {
          CurPreset = (PresetNumb + currentSwitch);
          debugln(); debug(" While Auditionmode ON CurPreset = "); debug(CurPreset);
          if (CurPreset > maxPreset) 
            {
              CurPreset = 0;
              PresetNumb = 0;
            debugln(); debug(" While Auditionmode ON CurPreset = "); debug(CurPreset);
            debugln(); debug(" While Auditionmode ON PresetNumb = "); debug(PresetNumb);
            }
          effectCycle = true;
          getScenes = true;
          debugln(); debug(" -> effectcycle set to: "); debug(effectCycle);
          debugln(); debug(" -> getScenes set to: "); debug(getScenes);        
          Axe.sendPresetChange(CurPreset);
          presetRange();
          debugln(); debug(" -> Pressed Switch = "); debug(currentSwitch + 1);
          }
            else
              {
              CurPreset = (PresetNumb + currentSwitch);
              debugln(); debug(" PresetSelection CurPreset = "); debug(CurPreset);
              if (CurPreset > maxPreset)
                {
                CurPreset = currentSwitch;
                debugln(); debug(" PresetSelection CurPreset = "); debug(CurPreset);    
                  } 
              debugln(); debug(" PresetSelection CurPreset = "); debug(CurPreset);            
              sceneTopscreens();
              getScenes = true;
              effectCycle = true;
              debugln(); debug(" -> getScenes set to: "); debug(getScenes);
              debugln(); debug(" -> effectcycle set to: ");  debug(effectCycle);
              Axe.sendPresetChange(CurPreset);
              debugln(); debug(" -> Pressed Switch = "); debug(currentSwitch + 1);
              }
}

void auditionmodeEnd_Selection()
{
            sceneTopscreens();
            getScenes = true;
            effectCycle = true;
            debugln(); debug(" -> getScenes set to: "); debug(getScenes);
            debugln(); debug(" -> effectcycle set to:"); debug(effectCycle);
            //Axe.sendPresetChange(active_Preset);
            CurPreset = (active_Preset);
            ini_scenes();            
            debugln(); debug(" Auditionmode OFF CurPreset = "); debug(CurPreset);            
            debugln(); debug(" -> Pressed Switch = "); debug(currentSwitch + 1);
}

/*================================================================================================================================*/
/*   Build-up EFFECT selection Screens 
/*================================================================================================================================*/
void effectSelection()
{
  switch (currentSwitch) {
    case 0: CS = CS1; thisEffect = effect0; break;
    case 1: CS = CS2; thisEffect = effect1; break;
    case 2: CS = CS3; thisEffect = effect2; break;
    case 3: CS = CS4; thisEffect = effect3; break;
    case 4: CS = CS5; thisEffect = effect4; break;
    case 5: CS = CS6; thisEffect = effect5; break;    
    case 6: CS = CS7; thisEffect = effect6; break;
    case 7: CS = CS8; thisEffect = effect7; break;
    case 8: CS = CS9; thisEffect = effect8; break;
    case 9: CS = CS10; thisEffect = effect9; break;
  }            
            
    debugln(); debug(" -> Pressed Switch = "); debug(currentSwitch + 1);
    AxeEffect *effect = Axe.getCurrentPreset().getEffectById(thisEffect);
    if (thisEffect > 0)
    {
    effect->toggle();
    digitalWrite (CS, LOW);
      if (effect->isBypassed()) {
          effectStyle1();     //on axe_handler.h
          effect->printEffectName(tft);
          }
           else {
              effectStyle2(); //on axe_handler.h
              effect->printEffectName(tft);
               }
    digitalWrite (CS, HIGH);
    }
}

/*================================================================================================================================*/
/*   +++++++     END SCREEN SELECT     +++++++++        
/*================================================================================================================================*/

void bankDown_selection()
{ 
  if (presetBank != 1)
  {
  if (strcmp(page, "preset") != 0)  // -->>  NOT on presetpage
        { 
          PresetNumb = (PresetNumb - 10);
        Serial.println(""); Serial.print("presetNumb - 10 = "); Serial.print(PresetNumb); 
          if (PresetNumb < 0) 
          {
            PresetNumb = (510 + PresetNumb);  // 520 is first passible number in the next bank, but doesnt exist
            } 
          CurPreset = PresetNumb;
          debugln(); debug(" preset bankDown CurPreset = "); debug(CurPreset);          
          bankDown_LCD_text();
          getScenes = true;
          effectCycle = true;
          Axe.sendPresetChange(CurPreset);
          
          debugln(); debug(" -> getScenes set to: "); debug(getScenes);
          debugln(); debug(" -> effectcycle set to: ");  debug(effectCycle);
          debugln(); debug(" -> Pressed Switch = "); debug(currentSwitch - 10);  
        }
          else // -->> ON presetpage
        {  
         { 
           PresetNumb = (PresetNumb - 10);
        Serial.println(""); Serial.print("presetNumb - 10 = "); Serial.print(PresetNumb); 
          if (PresetNumb < 0) 
          {
            PresetNumb = (500 + currentSwitch);  // 520 is first passible number in the next bank, but doesnt exist
            } 
           if (auditionMode == true)
          {
          CurPreset = PresetNumb;          
          debugln(); debug(" preset bankDown CurPreset = "); debug(CurPreset);   
          auditionmode_LCD_text();
          }
          else
            {
          CurPreset = PresetNumb;
          debugln(); debug(" preset bankDown CurPreset = "); debug(CurPreset);          
          bankDown_LCD_text();
          debugln(); debugln(" Switch-6");
          presetRange();
            }
          ini_preset();
        }
     }    
   }
}  
/*==================   OR  ========================*/   //  +10 

void bankUp_selection()
{
    if (presetBank != 1)
        {
        
         if (strcmp(page, "preset") != 0) // NOT on presetpage
          {
            PresetNumb = (PresetNumb + 10);  
          if (PresetNumb > 511) 
          {
            PresetNumb = (PresetNumb - 510); // 520 is first passible number in the next bank, but doesnt exist
            } 
          CurPreset = PresetNumb;
          debugln(); debug(" preset bankUp CurPreset = "); debug(CurPreset); 
          bankUp_LCD_text();
          getScenes = true;
          effectCycle = true;
          Axe.sendPresetChange(PresetNumb);
          
          debugln(); debug(" -> getScenes set to: "); debug(getScenes);
          debugln(); debug(" -> effectcycle set to: ");  debug(effectCycle);
          debugln(); debug(" -> Pressed Switch = "); debug(currentSwitch + 10);
          }
          else  // ON presetpage
          {
            PresetNumb = (PresetNumb + 10);  
          if (PresetNumb > 511) 
          {
            PresetNumb = (PresetNumb - (520)); // 520 is first passible number in the next bank, but doesnt exist
            }   
          if (auditionMode == true)
          {
          CurPreset = PresetNumb;
          debugln(); debug(" preset bankUp CurPreset = "); debug(CurPreset);  
          auditionmode_LCD_text();
            }
          else
          {
          CurPreset = PresetNumb;
          debugln(); debug(" preset bankUp CurPreset = "); debug(CurPreset); 
          bankUp_LCD_text();
          debugln(); debug(" Switch-12 ");
          presetRange();
            }
          ini_preset();
          }
    } 
}

/*==================   OR  ========================*/   //  -1
void presetDown_selection()
{
          if (CurPreset == 0)
          {
            CurPreset = 511;
            debugln(); debug(" presetDown CurPreset = "); debug(CurPreset);             
            PresetNumb = 511;
          }
          else 
           {
            PresetNumb = PresetNumb - 1;
          }
          getScenes = true;
          debugln(); debug(" -> getScenes set to: "); debug(getScenes);
          effectCycle = true;
          auditionMode = false;
          debugln(); debug(" -> effectcycle set to: "); debug(effectCycle);
          scene_LCD_text();
          debugln(); debug(" -> Pressed Switch = "); debug(currentSwitch + 1);
          Axe.sendPresetChange(PresetNumb);
}

/*==================   OR  ========================*/   //  +1
void presetUp_selection()
{
          if (CurPreset == 511)
          {
          CurPreset = 0;
          debugln(); debug(" presetUp CurPreset = "); debug(CurPreset); 
          PresetNumb = 0;
          }
          else 
          {
            PresetNumb = PresetNumb + 1;
          }
          getScenes = true;
          debugln(); debug(" -> getScenes set to: "); debug(getScenes);
          effectCycle = true;
          auditionMode = false;
          debugln(); debug(" -> effectcycle set to: "); debug(effectCycle);
          scene_LCD_text();
          debugln(); debug(" -> Pressed Switch = "); debug(currentSwitch + 1);
          Axe.sendPresetChange(PresetNumb);
}

void auditionmodePage_selection()
{
  if (auditionMode == false)
          {
            auditionMode = true;
            debugln(); debug (" -> auditionmode set to: "); debug(auditionMode);
            auditionmode_LCD_text();
            effectCycle = true;
            debugln(); debug(" -> effectcycle set to: "); debug(effectCycle);            
            auditionMode_ON_screen();
            auditionmodeTopscreens();
          }
                    else
          {
           auditionMode = false;
           auditionmodeEnd_Selection();
          }
}

void auditionmodePage_tuner_OFF_selection()
          {
            debugln(); debug (" -> auditionmode set to: ");debug(auditionMode);
            auditionmodeTopscreens();
            ini_preset();
            auditionmode_LCD_text();
            effectCycle = true;
            debugln(); debug(" -> effectcycle set to: "); debug(effectCycle);            
            auditionMode_ON_screen();
          }

/*===================================================================================*/
/*Axelman8*/
