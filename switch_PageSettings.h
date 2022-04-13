#pragma once

/*=======================================================================================================================
  ON THIS TAB ALL THE BUTTONS ARE INSTATIATED.

  // * Scenes setting buttons and Screens
  // * PRESET Setting buttons and Screens
  // * EFFECT Setting buttons and Screens
  // * AMP and CAB switching A-B-C-D
  // * LOOPER Setting buttons and Screens
  // * NUMBER setting

/*===========================================   -  Include library's  -  ================================================*/

#include <SD_ini.h>
#include <preset_amp_ini.h>

#include "Screenstyle.h"
#include "axe_handler.h"
#include "Preset_range.h"
#include "screenSetup.h"
#include "switchSelect.h"


/*================================================================================================================================*/
/*   SCENES BUTTONS   
/*================================================================================================================================*/
void scenes_settings()
{
  for ( currentSwitch = 0; currentSwitch < 18; currentSwitch++ ) {
    if ((digitalRead(switches[currentSwitch]) != switchState[currentSwitch] ) && (switchState[currentSwitch] == HIGH)) {

      digitalWrite(CS1, LOW), digitalWrite(CS2, LOW), digitalWrite(CS3, LOW), digitalWrite(CS4, LOW),
      digitalWrite(CS6, LOW), digitalWrite(CS7, LOW), digitalWrite(CS8, LOW), digitalWrite(CS9, LOW);

      sceneStyle4();

      digitalWrite(CS1, HIGH), digitalWrite(CS2, HIGH), digitalWrite(CS3, HIGH), digitalWrite(CS4, HIGH),
      digitalWrite(CS6, HIGH), digitalWrite(CS7, HIGH), digitalWrite(CS8, HIGH), digitalWrite(CS9, HIGH);

      digitalWrite(CS1, LOW); sceneStyle1(); tft.println("1"); digitalWrite(CS1, HIGH);
      digitalWrite(CS2, LOW); sceneStyle1(); tft.println("2"); digitalWrite(CS2, HIGH);
      digitalWrite(CS3, LOW); sceneStyle1(); tft.println("3"); digitalWrite(CS3, HIGH);
      digitalWrite(CS4, LOW); sceneStyle1(); tft.println("4"); digitalWrite(CS4, HIGH);
      digitalWrite(CS6, LOW); sceneStyle1(); tft.println("5"); digitalWrite(CS6, HIGH);
      digitalWrite(CS7, LOW); sceneStyle1(); tft.println("6"); digitalWrite(CS7, HIGH);
      digitalWrite(CS8, LOW); sceneStyle1(); tft.println("7"); digitalWrite(CS8, HIGH);
      digitalWrite(CS9, LOW); sceneStyle1(); tft.println("8"); digitalWrite(CS9, HIGH);

        switch (currentSwitch) {
        
        case 0: sceneSelection(); delay(200);  break; // Switch 1.  Scene 1
        case 1: sceneSelection(); delay(200);  break; // Switch 2.  Scene 2
        case 2: sceneSelection(); delay(200);  break; // Switch 3.  Scene 3
        case 3: sceneSelection(); delay(200);  break; // Switch 4.  Scene 4
        case 4: sceneswitch_5;    delay(200);  break; // Switch 5.  
        case 5: sceneSelection(); delay(200);  break; // Switch 6.  Scene 5
        case 6: sceneSelection(); delay(200);  break; // Switch 7.  Scene 6
        case 7: sceneSelection(); delay(200);  break; // Switch 8.  Scene 7
        case 8: sceneSelection(); delay(200);  break; // Switch 10. Scene 8
        case 9: sceneswitch_10;  delay(200);   break; // Switch 11. 
        case 10: sceneswitch_11; delay(200);   break; // Switch 13. 
        case 11: sceneswitch_12; delay(200);   break; // Switch 14. 
        case 12: sceneswitch_13; delay(200);   break; // Switch 15. 
        case 13: sceneswitch_14; break; // Switch 16. 
        case 14: sceneswitch_15; delay(200);   break; // Switch 17. 
        case 15: sceneswitch_16; delay(50);   break; // Switch 16. /*strcpy(page, "scene");*/ 
        case 16: sceneswitch_17; delay(50);   break; // Switch 17. /*strcpy(page, "scene");*/
        case 17: sceneswitch_18; delay(200);   break; // Switch 18. TUNER
        }
      }
    switchState[currentSwitch] = digitalRead( switches[currentSwitch]);
    }
}


/*================================================================================================================================*/
/*   PRESET BUTTONS
/*================================================================================================================================*/
void preset_settings()
{
  for ( currentSwitch = 0; currentSwitch < 18; currentSwitch++ ) {
    if ((digitalRead(switches[currentSwitch]) != switchState[currentSwitch] ) && (switchState[currentSwitch] == HIGH)) {
      switch ( currentSwitch ) {

        case 0:  presetSelection(); delay(200);  break; // Switch 1. preset 1
        case 1:  presetSelection(); delay(200);  break; // Switch 2. preset 2
        case 2:  presetSelection(); delay(200);  break; // Switch 3. preset 3
        case 3:  presetSelection(); delay(200);  break; // Switch 4. preset 4
        case 4:  presetSelection(); delay(200);  break; // Switch 5. Preset 5
        case 5:  presetSelection(); delay(200);  break; // Switch 7. preset 6
        case 6:  presetSelection(); delay(200);  break; // Switch 8. preset 7
        case 7:  presetSelection(); delay(200);  break; // Switch 9. preset 8
        case 8:  presetSelection(); delay(200);  break; // Switch 10.preset 9
        case 9:  presetSelection(); delay(200);  break; // Switch 11.preset 10
        case 10: presetswitch_11; delay(200);   break;  // Switch 13. 
        case 11: presetswitch_12; delay(200);   break;  // Switch 14. 
        case 12: presetswitch_13; delay(200);   break;  // Switch 15. 
        case 13: presetswitch_14; break;  // Switch 16. 
        case 14: presetswitch_15; delay(200);   break;  // Switch 17. 
        case 15: presetswitch_16; delay(50);   break;  // Switch 16. /*strcpy(page, "preset");*/
        case 16: presetswitch_17; delay(50);   break;  // Switch 17. /*strcpy(page, "preset");*/
        case 17: presetswitch_18; delay(200);  break;  // Switch 18. TUNER
    }
    switchState[currentSwitch] = digitalRead( switches[currentSwitch] );
   }
  }
}


/*================================================================================================================================*/
/*   AMP and CAB switching A-B-C-D   BUTTONS
/*================================================================================================================================*/
void AMP_effect_settings()
{
  for ( currentSwitch = 0; currentSwitch < 18; currentSwitch++ ) {
    if ((digitalRead(switches[currentSwitch]) != switchState[currentSwitch] ) && (switchState[currentSwitch] == HIGH)) {
      switch ( currentSwitch ) {

        
        case 0: // Switch 1.  =AMP 1
          {
            select_AMP_1 = true;
            preset_amp();
            AMP_ABCD();  //reset the state of the amp ABCD settings
            AxeEffect *effect = Axe.getCurrentPreset().getEffectById(58);
            digitalWrite (CS1, LOW);


            /* is AMP-CAB selected? if yes, Toggle and bypass  */
            if (currentEffect == 58)
            {
              effect->toggle();

              if (effect->isBypassed())
              {
              effectchannelswitchStyle2();
                tft.println("AMP1");
              }
              else
              {
              effectchannelswitchStyle3();
                tft.println("AMP1");
              }
              effectchannelswitchStyle0();
              tft.println(effect->getChannelChar());
              //draw line and bezel to show its selected
            ampabcdStyle_greenBezelLine();
            }

            /* if AMP-CAB is not active then set currentEffect */
            else if (currentEffect != 58)
            {
              currentEffect = 58;
              changeCurrentEffect = 58;
              debugln(); debug(" currenteffect = 58");
              effectchannelswitchStyle0();
              tft.println(effect->getChannelChar());
              //draw line and bezel to show its selected
            ampabcdStyle_greenBezelLine();
            }
          }
          digitalWrite (CS1, HIGH);
          delay(200);
          break;


        case 1:       // Switch 2  =AMP 2
          {
            select_AMP_2 = true;
            AMP_ABCD();
            AxeEffect *effect = Axe.getCurrentPreset().getEffectById(effect17);
  
            digitalWrite (CS2, LOW);
            /* is AMP-CAB selected? if yes, Toggle and bypass  */
            if (currentEffect == effect17)
            {
              effect->toggle();

              if (effect->isBypassed())
              {
                  tft.setCursor(40, 70);
                  tft.setTextSize(4);
                  tft.setTextColor(TFT_RED, TFT_BLACK);
                  effect->printEffectName(tft);
                }
                else
                {
                  tft.setCursor(40, 70);
                  tft.setTextSize(4);
                  tft.setTextColor(TFT_GREEN, TFT_BLACK);
                  effect->printEffectName(tft);
                        
                }
              effectchannelswitchStyle0();
              tft.println(effect->getChannelChar());
              //draw line and bezel to show its selected
            ampabcdStyle_greenBezelLine() ;            
              }
              /* if AMP-CAB is not active then set currentEffect */
              else if (currentEffect != effect17)
              {
                currentEffect = effect17;
                changeCurrentEffect = 17;
              debugln(); debug(" currenteffect = 17");
              effectchannelswitchStyle0();
              tft.println(effect->getChannelChar());
              //draw line and bezel to show its selected
            ampabcdStyle_greenBezelLine();
              }

            }
            digitalWrite (CS2, HIGH);
            delay(200);
            break;

          case 3: // Switch 4 = C
            {
              if (currentEffect != 0)
              {
                AxeEffect *effect = Axe.getCurrentPreset().getEffectById(currentEffect);
                channel = "C";                
                effect->switchChannel(2);

                digitalWrite(CS4, LOW); ampabcdStyle2(); tft.println(" AMP C "); digitalWrite(CS4, HIGH);
                digitalWrite(CS5, LOW); ampabcdStyle3(); tft.println(" AMP D "); digitalWrite(CS5, HIGH);
                digitalWrite(CS9, LOW); ampabcdStyle3(); tft.println(" AMP A "); digitalWrite(CS9, HIGH);
                digitalWrite(CS10, LOW);ampabcdStyle3(); tft.println(" AMP B "); digitalWrite(CS10, HIGH);
                channelSwitch();
              }

            }
            break;

          case 4: // Switch 5  = D
            {
              if (currentEffect != 0)
              {
                AxeEffect *effect = Axe.getCurrentPreset().getEffectById(currentEffect);
                channel = "D";
                effect->switchChannel(3);
                digitalWrite(CS5, LOW); ampabcdStyle2(); tft.println(" AMP D "); digitalWrite(CS5, HIGH);
                digitalWrite(CS4, LOW); ampabcdStyle3(); tft.println(" AMP C "); digitalWrite(CS4, HIGH);
                digitalWrite(CS9, LOW); ampabcdStyle3(); tft.println(" AMP A "); digitalWrite(CS9, HIGH);
                digitalWrite(CS10, LOW);ampabcdStyle3(); tft.println(" AMP B "); digitalWrite(CS10, HIGH);
                channelSwitch();
              }

            }
            break;



          case 5:       //Switch 6  = CAB 1/2  
            {
              AMP_ABCD();
              AxeEffect *effect = Axe.getCurrentPreset().getEffectById(effect18);

              digitalWrite (CS6, LOW);
              /* is AMP-CAB selected? if yes, Toggle and bypass  */
              if (currentEffect == effect18)
              {
                effect->toggle();
                if (effect->isBypassed())
                {
                 tft.setCursor(40, 70);
                  tft.setTextSize(4);
                  tft.setTextColor(TFT_RED, TFT_BLACK);
                  effect->printEffectName(tft);
                }
                else
                {
                  tft.setCursor(40, 70);
                  tft.setTextSize(4);
                  tft.setTextColor(TFT_GREEN, TFT_BLACK);
                  effect->printEffectName(tft);
                }
              effectchannelswitchStyle0();
                tft.println(effect->getChannelChar());
              //draw line and bezel to show its selected
            ampabcdStyle_greenBezelLine() ;            
              }
              /* if AMP-CAB is not active then set currentEffect */
              else if (currentEffect != effect18)
              {
                currentEffect = effect18;
                changeCurrentEffect = 18;
              debugln(); debug(" currenteffect = 18");
              effectchannelswitchStyle0();
              tft.println(effect->getChannelChar());
              //draw line and bezel to show its selected
            ampabcdStyle_greenBezelLine();
              }
            }
            digitalWrite (CS6, HIGH);
            delay(200);
            break;



          case 6:   //Switch 7 = CAB 2  
            {
              AMP_ABCD();
              AxeEffect *effect = Axe.getCurrentPreset().getEffectById(effect19);
              digitalWrite (CS7, LOW);

              /* is AMP-CAB selected? if yes, Toggle and bypass  */
              if (currentEffect == effect19)
              {
                effect->toggle();
                if (effect->isBypassed())
                {
                 tft.setCursor(40, 70);
                  tft.setTextSize(4);
                  tft.setTextColor(TFT_RED, TFT_BLACK);
                  effect->printEffectName(tft);
                }
                else
                {
                  tft.setCursor(40, 70);
                  tft.setTextSize(4);
                  tft.setTextColor(TFT_GREEN, TFT_BLACK);
                  effect->printEffectName(tft);
                }
              effectchannelswitchStyle0();
              tft.println(effect->getChannelChar());
              //draw line and bezel to show its selected
            ampabcdStyle_greenBezelLine();
              }
              /* if AMP-CAB is not active then set currentEffect */
              else if (currentEffect != effect19)
              {
              currentEffect = effect19;
              changeCurrentEffect = 19;
              debugln(); debug(" currenteffect = 19");
              effectchannelswitchStyle0();
              tft.println(effect->getChannelChar());
              //draw line and bezel to show its selected
            ampabcdStyle_greenBezelLine();
              }
            }
            digitalWrite (CS7, HIGH);
            delay(200);
            break;


          case 8:  //Switch 9  = A
            {
              if (currentEffect != 0)
              {
                AxeEffect *effect = Axe.getCurrentPreset().getEffectById(currentEffect);
                channel = "A";
                effect->switchChannel(0);
                digitalWrite(CS9, LOW); ampabcdStyle2(); tft.println(" AMP A "); digitalWrite(CS9, HIGH);
                digitalWrite(CS5, LOW); ampabcdStyle3(); tft.println(" AMP D "); digitalWrite(CS5, HIGH);
                digitalWrite(CS4, LOW); ampabcdStyle3(); tft.println(" AMP C "); digitalWrite(CS4, HIGH);
                digitalWrite(CS10, LOW);ampabcdStyle3(); tft.println(" AMP B "); digitalWrite(CS10, HIGH);
                channelSwitch(); 
              }
            }
            break;

          case 9: //Switch 10  = B
            {
              if (currentEffect != 0)
              {
                AxeEffect *effect = Axe.getCurrentPreset().getEffectById(currentEffect);
                channel = "B";
                effect->switchChannel(1);
                digitalWrite(CS10, LOW);ampabcdStyle2(); tft.println(" AMP B "); digitalWrite(CS10, HIGH);
                digitalWrite(CS5, LOW); ampabcdStyle3(); tft.println(" AMP D "); digitalWrite(CS5, HIGH);
                digitalWrite(CS9, LOW); ampabcdStyle3(); tft.println(" AMP A "); digitalWrite(CS9, HIGH);
                digitalWrite(CS4, LOW); ampabcdStyle3(); tft.println(" AMP C "); digitalWrite(CS4, HIGH);
                channelSwitch(); 
              }
            }
            break;

        case 10:  AMP_effectswitch_11; delay(200);    break;     // Switch 11. 
        case 11:  AMP_effectswitch_12; delay(200);    break;     // Switch 12.        
        case 12:  AMP_effectswitch_13; delay(200);    break;     // Switch 13. 
        case 13:  AMP_effectswitch_14; break;     // Switch 14. 
        case 14:  AMP_effectswitch_15; delay(200);    break;     // Switch 15.  
        case 15:  AMP_effectswitch_16; delay(50);  /*strcpy(page, "scene"); */break; // Switch 16. BANK DOWN
        case 16:  AMP_effectswitch_17; delay(50);  /*strcpy(page, "scene");*/ break; // Switch 17. BANK UP
        case 17:  AMP_effectswitch_18; delay(200);    break;     // Switch 18. TUNER
      }
      break;
    }
    switchState[currentSwitch] = digitalRead( switches[currentSwitch] );
  }
}


/*================================================================================================================================*/
/*   EFFECT  BUTTONS
/*================================================================================================================================*/
void effect_settings()
{
  for ( currentSwitch = 0; currentSwitch < 18; currentSwitch++ ) {
    if ((digitalRead(switches[currentSwitch]) != switchState[currentSwitch] ) && (switchState[currentSwitch] == HIGH)) {
      switch ( currentSwitch ) {
    
    // NOTES: Currently the issue is we get a copy of effect so modifying it doesn't update state, we need to modify the actual state of the preset;

        case 0: {effectSelection(); delay(200); break;}     // Switch 1. Effect 1
        case 1: {effectSelection(); delay(200); break;}     // Switch 2. Effect 2
        case 2: {effectSelection(); delay(200); break;}     // Switch 3. Effect 3
        case 3: {effectSelection(); delay(200); break;}     // Switch 4. Effect 4
        case 4: {effectSelection(); delay(200); break;}     // Switch 5. Effect 5
        case 5: {effectSelection(); delay(200); break;}     // Switch 7. Effect 6
        case 6: {effectSelection(); delay(200); break;}     // Switch 8. Effect 7
        case 7: {effectSelection(); delay(200); break;}     // Switch 9. Effect 8
        case 8: {effectSelection(); delay(200); break;}     // Switch 10. Effect 9
        case 9: {effectSelection(); delay(200); break;}     // Switch 11. Effect 10
        case 10: effectswitch_11;   delay(200); break;      // Switch 13. 
        case 11: effectswitch_12;   delay(200); break;      // Switch 14. 
        case 12: effectswitch_13;   delay(200); break;      // Switch 15. 
        case 13: effectswitch_14;   break;      // Switch 16. 
        case 14: effectswitch_15;   delay(200); break;      // Switch 17. 
        case 15: effectswitch_16; delay(50); break;  /*strcpy(page, "scene");*/ 
        case 16: effectswitch_17; delay(50); break;  /*strcpy(page, "scene");*/
        case 17: effectswitch_18;   delay(200); break;      // Switch 18. TUNER
      }
      break;
    }
    switchState[currentSwitch] = digitalRead( switches[currentSwitch] );
 }
}



/*================================================================================================================================*/
/*   LOOPER  BUTTONS
/*================================================================================================================================*/
void looper_settings()
{
  for ( currentSwitch = 0; currentSwitch < 18; currentSwitch++ ) {
    if ((digitalRead(switches[currentSwitch]) != switchState[currentSwitch] ) && (switchState[currentSwitch] == HIGH)) {
      switch ( currentSwitch ) {

        case 0:
          {
            debugln(); debug(" record");
            Axe.getLooper().record();
            ini_looper();
            digitalWrite (CS1, LOW); looperStyle2(); tft.println("RECORD"); digitalWrite (CS1, HIGH);
          }
          delay(200);
          break;

        case 2:
          {
            debugln(); debug(" play");
            Axe.getLooper().play();
            ini_looper();
            digitalWrite (CS3, LOW); looperStyle2(); tft.println("PLAY"); digitalWrite (CS3, HIGH);
          }
          delay(200);
          break;

        case 4: {

            debugln(); debug(" undo");
            Axe.getLooper().undo();
            ini_looper();
            digitalWrite(CS5, LOW); looperStyle2(); tft.println("UNDO"); digitalWrite(CS5, HIGH);
          }
          delay(200);
          break;

        case 5:
          {
            debugln(); debug(" once");
            Axe.getLooper().once();
            ini_looper();
            digitalWrite(CS6, LOW); looperStyle2(); tft.println("ONCE"); digitalWrite(CS6, HIGH);
          }
          delay(200);
          break;

        case 7:
          {
            debugln(); debug(" reverse");
            Axe.getLooper().reverse();
            ini_looper();
            digitalWrite(CS8, LOW); looperStyle2(); tft.println("REVERSE"); digitalWrite(CS8, HIGH);
          }
          delay(200);
          break;


        case 9:
          {
            debugln(); debug(" halfSpeed");
            Axe.getLooper().halfSpeed();
            ini_looper();
            digitalWrite(CS10, LOW); looperStyle2(); tft.println("HALFSPD"); digitalWrite(CS10, HIGH);
          }
          delay(200);
          break;

        case 10: looperswitch_11; delay(200);  break;    // Switch 11.
        case 11: looperswitch_12; delay(200);  break;    // Switch 12. 
        case 12: looperswitch_13; delay(200);  break;    // Switch 13. 
        case 13: looperswitch_14; break;    // Switch 14. 
        case 14: looperswitch_15; delay(200);  break;    // Switch 15. 
        case 15: looperswitch_16; delay(50);  break;    // Switch 16. 
        case 16: looperswitch_17; delay(50);  break;    // Switch 17. 
        case 17: looperswitch_18; delay(200);  break;    // Switch 18.TUNER
      }
    }
    switchState[currentSwitch] = digitalRead( switches[currentSwitch] );
  }
}



/*================================================================================================================================*/
/*    NUMBERS  BUTTONS           
/*================================================================================================================================*/
void numbers_settings()
{
  for ( currentSwitch = 0; currentSwitch < 18; currentSwitch++ ) {
    if ((digitalRead(switches[currentSwitch]) != switchState[currentSwitch] ) && (switchState[currentSwitch] == HIGH)) {
      switch ( currentSwitch ) {

        //Switch 1-10
        case 0:
          {
            Counter = Counter + 1;
            inputNumber = 0;
            debugln(); debug (" Counter = ");  debug( Counter);
            debugln(); debug (" Inputnumber = ");  debug( inputNumber);
            if ( Counter == 1)      {
              n1 = inputNumber;
              debugln(); debug (" N1 = ");  debug(n1);
              lcd.setCursor(0, 1); lcd.print(" Number = "); lcd.print(n1);
            }
            else if ( Counter == 2) {
              n2 = ((n1 * 10) + inputNumber);
              debugln(); debug (" N2 = ");  debug(n2);
              lcd.setCursor(0, 1); lcd.print(" Number = "); lcd.print(n2);
            }
            else if ( Counter == 3) {
              n3 = ((n2 * 10) + inputNumber);
              debugln(); debug (" N3 = ");  debug(n3);
              lcd.setCursor(0, 1); lcd.print(" Number = "); lcd.print(n3);
            }
          }
          delay(200);
          break;


        case 1:
          {
            Counter = Counter + 1;
            inputNumber = 1;
            debugln(); debug (" Counter = ");  debug( Counter);
            debugln(); debug (" Inputnumber = ");  debug( inputNumber);
            if ( Counter == 1)      {
              n1 = inputNumber;
              debugln(); debug (" N1 = ");  debug(n1);
              lcd.setCursor(0, 1); lcd.print(" Number = "); lcd.print(n1);
            }
            else if ( Counter == 2) {
              n2 = ((n1 * 10) + inputNumber);
              debugln(); debug (" N2 = ");  debug(n2);
              lcd.setCursor(0, 1); lcd.print(" Number = "); lcd.print(n2);
            }
            else if ( Counter == 3) {
              n3 = ((n2 * 10) + inputNumber);
              debugln(); debug (" N3 = ");  debug(n3);
              lcd.setCursor(0, 1); lcd.print(" Number = "); lcd.print(n3);
            }
           } 
          delay(200);
           break;

        case 2:
          {
            Counter = Counter + 1;
            inputNumber = 2;
            debugln(); debug (" Counter = ");  debug( Counter);
            debugln(); debug (" Inputnumber = ");  debug( inputNumber);
            if ( Counter == 1)      {
              n1 = inputNumber;
              debugln(); debug (" N1 = ");  debug(n1);
              lcd.setCursor(0, 1); lcd.print(" Number = "); lcd.print(n1);
            }
            else if ( Counter == 2) {
              n2 = ((n1 * 10) + inputNumber);
              debugln(); debug (" N2 = ");  debug(n2);
              lcd.setCursor(0, 1); lcd.print(" Number = "); lcd.print(n2);
            }
            else if ( Counter == 3) {
              n3 = ((n2 * 10) + inputNumber);
              debugln(); debug (" N3 = ");  debug(n3);
              lcd.setCursor(0, 1); lcd.print(" Number = "); lcd.print(n3);
            }
          }
          delay(200);
          break;

        case 3:
          {
            Counter = Counter + 1;
            inputNumber = 3;
            debugln(); debug (" Counter = ");  debug( Counter);
            debugln(); debug (" Inputnumber = ");  debug( inputNumber);
            if ( Counter == 1)      {
              n1 = inputNumber;
              debugln(); debug (" N1 = ");  debug(n1);
              lcd.setCursor(0, 1); lcd.print(" Number = "); lcd.print(n1);
            }
            else if ( Counter == 2) {
              n2 = ((n1 * 10) + inputNumber);
              debugln(); debug (" N2 = ");  debug(n2);
              lcd.setCursor(0, 1); lcd.print(" Number = "); lcd.print(n2);
            }
            else if ( Counter == 3) {
              n3 = ((n2 * 10) + inputNumber);
              debugln(); debug (" N3 = ");  debug(n3);
              lcd.setCursor(0, 1); lcd.print(" Number = "); lcd.print(n3);
            }
          }
          delay(200);
          break;

        case 4:
          {
            Counter = Counter + 1;
            inputNumber = 4;
            debugln(); debug (" Counter = ");  debug( Counter);
            debugln(); debug (" Inputnumber = ");  debug( inputNumber);
            if ( Counter == 1)      {
              n1 = inputNumber;
              debugln(); debug (" N1 = ");  debug(n1);
              lcd.setCursor(0, 1); lcd.print(" Number = "); lcd.print(n1);
            }
            else if ( Counter == 2) {
              n2 = ((n1 * 10) + inputNumber);
              debugln(); debug (" N2 = ");  debug(n2);
              lcd.setCursor(0, 1); lcd.print(" Number = "); lcd.print(n2);
            }
            else if ( Counter == 3) {
              n3 = ((n2 * 10) + inputNumber);
              debugln(); debug (" N3 = ");  debug(n3);
              lcd.setCursor(0, 1); lcd.print(" Number = "); lcd.print(n3);
            }
          }
          delay(200);
          break;

      
        case 5:
          {
            Counter = Counter + 1;
            inputNumber = 5;
            debugln(); debug (" Counter = ");  debug( Counter);
            debugln(); debug (" Inputnumber = ");  debug( inputNumber);
            if ( Counter == 1)      {
              n1 = inputNumber;
              debugln(); debug (" N1 = ");  debug(n1);
              lcd.setCursor(0, 1); lcd.print(" Number = "); lcd.print(n1);
            }
            else if ( Counter == 2) {
              n2 = ((n1 * 10) + inputNumber);
              debugln(); debug (" N2 = ");  debug(n2);
              lcd.setCursor(0, 1); lcd.print(" Number = "); lcd.print(n2);
            }
            else if ( Counter == 3) {
              n3 = ((n2 * 10) + inputNumber);
              debugln(); debug (" N3 = ");  debug(n3);
              lcd.setCursor(0, 1); lcd.print(" Number = "); lcd.print(n3);
            }
          }
          delay(200);
          break;

        case 6:
          {
            Counter = Counter + 1;
            inputNumber = 6;
            debugln(); debug (" Counter = ");  debug( Counter);
            debugln(); debug (" Inputnumber = ");  debug( inputNumber);
            if ( Counter == 1)      {
              n1 = inputNumber;
              debugln(); debug (" N1 = ");  debug(n1);
              lcd.setCursor(0, 1); lcd.print(" Number = "); lcd.print(n1);
            }
            else if ( Counter == 2) {
              n2 = ((n1 * 10) + inputNumber);
              debugln(); debug (" N2 = ");  debug(n2);
              lcd.setCursor(0, 1); lcd.print(" Number = "); lcd.print(n2);
            }
            else if ( Counter == 3) {
              n3 = ((n2 * 10) + inputNumber);
              debugln(); debug (" N3 = ");  debug(n3);
              lcd.setCursor(0, 1); lcd.print(" Number = "); lcd.print(n3);
            }
          }
          delay(200);
          break;

        case 7:
          {
            Counter = Counter + 1;
            inputNumber = 7;
            debugln(); debug (" Counter = ");  debug( Counter);
            debugln(); debug (" Inputnumber = ");  debug( inputNumber);
            if ( Counter == 1)      {
              n1 = inputNumber;
              debugln(); debug (" N1 = ");  debug(n1);
              lcd.setCursor(0, 1); lcd.print(" Number = "); lcd.print(n1);
            }
            else if ( Counter == 2) {
              n2 = ((n1 * 10) + inputNumber);
              debugln(); debug (" N2 = ");  debug(n2);
              lcd.setCursor(0, 1); lcd.print(" Number = "); lcd.print(n2);
            }
            else if ( Counter == 3) {
              n3 = ((n2 * 10) + inputNumber);
              debugln(); debug (" N3 = ");  debug(n3);
              lcd.setCursor(0, 1); lcd.print(" Number = "); lcd.print(n3);
            }
          }
          delay(200);
          break;

        case 8:
          {
            Counter = Counter + 1;
            inputNumber = 8;
            debugln(); debug (" Counter = ");  debug( Counter);
            debugln(); debug (" Inputnumber = ");  debug( inputNumber);
            if ( Counter == 1)      {
              n1 = inputNumber;
              debugln(); debug (" N1 = ");  debug(n1);
              lcd.setCursor(0, 1); lcd.print(" Number = "); lcd.print(n1);
            }
            else if ( Counter == 2) {
              n2 = ((n1 * 10) + inputNumber);
              debugln(); debug (" N2 = ");  debug(n2);
              lcd.setCursor(0, 1); lcd.print(" Number = "); lcd.print(n2);
            }
            else if ( Counter == 3) {
              n3 = ((n2 * 10) + inputNumber);
              debugln(); debug (" N3 = ");  debug(n3);
              lcd.setCursor(0, 1); lcd.print(" Number = "); lcd.print(n3);
            }
          }
          delay(200);
          break;


        case 9:
          {
            Counter = Counter + 1;
            inputNumber = 9;
            debugln(); debug (" Counter = ");  debug( Counter);
            debugln(); debug (" Inputnumber = ");  debug( inputNumber);
            if ( Counter == 1)      {
              n1 = inputNumber;
              debugln(); debug (" N1 = ");  debug(n1);
              lcd.setCursor(0, 1); lcd.print(" Number = "); lcd.print(n1);
            }
            else if ( Counter == 2) {
              n2 = ((n1 * 10) + inputNumber);
              debugln(); debug (" N2 = ");  debug(n2);
              lcd.setCursor(0, 1); lcd.print(" Number = "); lcd.print(n2);
            }
            else if ( Counter == 3) {
              n3 = ((n2 * 10) + inputNumber);
              debugln(); debug (" N3 = ");  debug(n3);
              lcd.setCursor(0, 1); lcd.print(" Number = "); lcd.print(n3);
            }
          }
          delay(200);
          break;

        case 10: numberswitch_11; delay(200);  break;    // Switch 11. EFFECT Page
        case 11: numberswitch_12; delay(200); break;   // Switch 12. AMP ABCD Page
        case 12: numberswitch_13; delay(200);  break;     // Switch 13. Active Preset / select Scene or Preset page
        case 13: // Switch 14.  TAP tempo  !! Set TAP tempo manual with number buttons    
          {
            debugln(); debug(" -> Pressed Switch = "); debug(currentSwitch + 1);
            switch (Counter)
            {
              case 1: Axe.setTempo(n1); delay(200); Counter = 0; tapTempo = n1; tapTempo_screen(); break;
                lcd.clear(); lcd.setCursor(0, 1); lcd.print("Tempo = "); lcd.print(n1);
                debugln(); debug (" Tempo = ");  debug(n1);
              case 2: Axe.setTempo(n2); delay(200); Counter = 0; tapTempo = n2; tapTempo_screen(); break;
                lcd.clear(); lcd.setCursor(0, 1); lcd.print("Tempo = "); lcd.print(n2);
                debugln(); debug (" Tempo = ");  debug(n2);
              case 3:
                if (n3 >= 251)
                { n3 = 250;}
                Axe.setTempo(n3); delay(200); Counter = 0; tapTempo = n3; tapTempo_screen(); break;
                lcd.clear(); lcd.setCursor(0, 1); lcd.print("Tempo = "); lcd.print(n3);
                debugln(); debug (" Tempo = ");  debug(n3);

            }
            lcd.setCursor(0, 1); lcd.print("Number =        ");
            Axe.fetchEffects(true);
            Axe.refresh();
            Counter = 0;
          }
          delay(200);
          break;


        case 14:  // Switch 15 Select a preset with the numbers entered
          {
            debugln(); debug(" -> Pressed Switch = "); debug(currentSwitch + 1);

                                  
            switch (Counter)
            {
              case 1: getScenes = true; effectCycle = true; Axe.sendPresetChange(n1); delay(200); Counter = 0; break;
                lcd.clear(); lcd.setCursor(0, 1); lcd.print("Selected = "); lcd.print(n1);
                debugln(); debug(" -> effectcycle set to: "); debug(effectCycle);
                debugln(); debug (" Selected number = ");  debug(n1);
              case 2: getScenes = true; effectCycle = true;  Axe.sendPresetChange(n2); delay(200); Counter = 0; break;
                lcd.clear(); lcd.setCursor(0, 1); lcd.print("Selected = "); lcd.print(n2);
                debugln(); debug(" -> effectcycle set to: "); debug(effectCycle);
                debugln(); debug (" Selected number = ");  debug(n2);
              case 3: getScenes = true; effectCycle = true; Axe.sendPresetChange(n3); delay(200); Counter = 0; break;
                lcd.clear(); lcd.setCursor(0, 1); lcd.print("Selected = "); lcd.print(n3);
                debugln(); debug(" -> effectcycle set to: "); debug(effectCycle);
                debugln(); debug (" Selected number = ");  debug(n3);
               }
            //Axe.fetchEffects(true);
            if (auditionMode == true) 
            {auditionmodeTopscreens();}
            else {sceneTopscreens();}
            Axe.refresh();
            Counter = 0;
          }
          delay(200);
          break;

        case 15: numberswitch_16;  delay(50);  break;        // Switch 16. Bank Down
        case 16: numberswitch_17;  delay(50);  break;        // Switch 17. BANK UP
        case 17: numberswitch_18; delay(200);  break;        // Switch 18. This is not the tuner, but here you deselect input to input again
      }
    }
    switchState[currentSwitch] = digitalRead( switches[currentSwitch] );
  }
}
/*===================================================================================*/
/*Axelman8*/
