#pragma once


/*===========================================   -  Include library's  -  ================================================*/

#include <presets_ini.h>

/*=============================================================================================================================*/
/* presetRange is to determen which bank you are in.  then it will display all 0-9 presets in that bank with page "preset-names"*/
/*=============================================================================================================================*/

void presetRange()
{
  debugln(); debugln(); debug(" * function presetRange started on Preset_range.h"); 
if ((PresetNumb >=0) && (PresetNumb<10)) {PresetNumb = 0;}
if ((PresetNumb >=10) && (PresetNumb<20)) {PresetNumb = 10;}
if ((PresetNumb >=20) && (PresetNumb<30)) {PresetNumb = 20;}
if ((PresetNumb >=30) && (PresetNumb<40)) {PresetNumb = 30;}
if ((PresetNumb >=40) && (PresetNumb<50)) {PresetNumb = 40;}
if ((PresetNumb >=50) && (PresetNumb<60)) {PresetNumb = 50;}
if ((PresetNumb >=60) && (PresetNumb<70)) {PresetNumb = 60;}
if ((PresetNumb >=70) && (PresetNumb<80)) {PresetNumb = 70;}
if ((PresetNumb >=80) && (PresetNumb<90)) {PresetNumb = 80;}
if ((PresetNumb >=90) && (PresetNumb<100)) {PresetNumb = 90;}
if ((PresetNumb >=100) && (PresetNumb<110)) {PresetNumb = 100;}
if ((PresetNumb >=110) && (PresetNumb<120)) {PresetNumb = 110;}
if ((PresetNumb >=120) && (PresetNumb<130)) {PresetNumb = 120;}
if ((PresetNumb >=130) && (PresetNumb<140)) {PresetNumb = 130;}
if ((PresetNumb >=140) && (PresetNumb<150)) {PresetNumb = 140;}
if ((PresetNumb >=150) && (PresetNumb<160)) {PresetNumb = 150;}
if ((PresetNumb >=160) && (PresetNumb<170)) {PresetNumb = 160;}
if ((PresetNumb >=170) && (PresetNumb<180)) {PresetNumb = 170;}
if ((PresetNumb >=180) && (PresetNumb<190)) {PresetNumb = 180;}
if ((PresetNumb >=190) && (PresetNumb<200)) {PresetNumb = 190;}
if ((PresetNumb >=200) && (PresetNumb<210)) {PresetNumb = 200;}
if ((PresetNumb >=210) && (PresetNumb<220)) {PresetNumb = 210;}
if ((PresetNumb >=220) && (PresetNumb<230)) {PresetNumb = 220;}
if ((PresetNumb >=230) && (PresetNumb<240)) {PresetNumb = 230;}
if ((PresetNumb >=240) && (PresetNumb<250)) {PresetNumb = 240;}
if ((PresetNumb >=250) && (PresetNumb<260)) {PresetNumb = 250;}
if ((PresetNumb >=260) && (PresetNumb<270)) {PresetNumb = 260;}
if ((PresetNumb >=270) && (PresetNumb<280)) {PresetNumb = 270;}
if ((PresetNumb >=280) && (PresetNumb<290)) {PresetNumb = 280;}
if ((PresetNumb >=290) && (PresetNumb<300)) {PresetNumb = 290;}
if ((PresetNumb >=300) && (PresetNumb<310)) {PresetNumb = 300;}
if ((PresetNumb >=310) && (PresetNumb<320)) {PresetNumb = 310;}
if ((PresetNumb >=320) && (PresetNumb<330)) {PresetNumb = 320;}
if ((PresetNumb >=330) && (PresetNumb<340)) {PresetNumb = 330;}
if ((PresetNumb >=340) && (PresetNumb<350)) {PresetNumb = 340;}
if ((PresetNumb >=350) && (PresetNumb<360)) {PresetNumb = 350;}
if ((PresetNumb >=360) && (PresetNumb<370)) {PresetNumb = 360;}
if ((PresetNumb >=370) && (PresetNumb<380)) {PresetNumb = 370;}
if ((PresetNumb >=380) && (PresetNumb<390)) {PresetNumb = 380;}
if ((PresetNumb >=390) && (PresetNumb<400)) {PresetNumb = 390;}
if ((PresetNumb >=400) && (PresetNumb<410)) {PresetNumb = 400;}
if ((PresetNumb >=410) && (PresetNumb<420)) {PresetNumb = 410;}
if ((PresetNumb >=420) && (PresetNumb<430)) {PresetNumb = 420;}
if ((PresetNumb >=430) && (PresetNumb<440)) {PresetNumb = 430;}
if ((PresetNumb >=440) && (PresetNumb<450)) {PresetNumb = 440;}
if ((PresetNumb >=450) && (PresetNumb<460)) {PresetNumb = 450;}
if ((PresetNumb >=460) && (PresetNumb<470)) {PresetNumb = 460;}
if ((PresetNumb >=470) && (PresetNumb<480)) {PresetNumb = 470;}
if ((PresetNumb >=480) && (PresetNumb<490)) {PresetNumb = 480;}
if ((PresetNumb >=490) && (PresetNumb<500)) {PresetNumb = 490;}
if ((PresetNumb >=500) && (PresetNumb<510)) {PresetNumb = 500;}
if ((PresetNumb >=510) && (PresetNumb<520)) {PresetNumb = 510;}
 
 if (strcmp(page, "preset") == 0)
 {
   debugln(); debugln();   debug(" * function preset_Names called on preset_range.h");
    preset_Names();

 }
}
