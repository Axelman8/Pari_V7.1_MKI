#pragma once

/*=========================================================================================================================*/
/*=========================================================================================================================*/

                            /* ==========================================================
                               ====                                                 =====
                               ====           here are all the presetnames          =====
                               ====                                                 =====
                               ====                 from 0 - 511                    =====
                               ====                                                 =====
                               ====     Paste the info from the Excel page here     =====
                               ====                                                 =====
                               ==========================================================*/  
/*=========================================================================================================================*/
/*=========================================================================================================================*/

void preset_Names(void)
{
  debugln(); debug(" -> Preset names are beeing read from presets.ini.h");
  switch (PresetNumb)
  {

// Delete all below: 
// -> set the cursor in front of case 0 and select (CTRL+SHIFT+END) and then DEL 
// PASTE HERE UNDER your presetnames from the excel file
    
case 0: 
strcpy(PresetName0,("Petrucci REC"));
strcpy(PresetName1,("Petrucci Rig 2020"));
strcpy(PresetName2,("Boogie IIC++"));
strcpy(PresetName3,("JP2C Best Rig"));
strcpy(PresetName4,("JP2C+"));
strcpy(PresetName5,("JohnP MarkIIC+"));
strcpy(PresetName6,("JP's IIC+ v12"));
strcpy(PresetName7,("Mesa MarkIV"));
strcpy(PresetName8,("Mesa TriAxess"));
strcpy(PresetName9,("VidarAus JP2C Rigv5"));

break;

case 10: 
strcpy(PresetName0,("MESA TRIAXIS"));
strcpy(PresetName1,("Mark's Recto TNT"));
strcpy(PresetName2,("Mark's Recto 2"));
strcpy(PresetName3,("Mark Journey Set"));
strcpy(PresetName4,("L.O.G."));
strcpy(PresetName5,("L.O.G. To Rest"));
strcpy(PresetName6,("L.O.G 11th Hour"));
strcpy(PresetName7,("L.O.G 11th Hour"));
strcpy(PresetName8,("Mark Morton Mesa"));
strcpy(PresetName9,("MarkIV_NKD"));

break;

case 20: 
strcpy(PresetName0,("Evailution 1"));
strcpy(PresetName1,("Evailution 2"));
strcpy(PresetName2,("Legator Ninja (Fishman Modern)"));
strcpy(PresetName3,("Legator Ninja (Fishman Modern)"));
strcpy(PresetName4,("Sacrament"));
strcpy(PresetName5,("LAMB OF GOD"));
strcpy(PresetName6,("LAMB OF GOD"));
strcpy(PresetName7,("LAMB OF GOD"));
strcpy(PresetName8,("Instant Room Cab - CCFF#19"));
strcpy(PresetName9,("Lonestar rig"));

break;

case 30: 
strcpy(PresetName0,("TM Lukather"));
strcpy(PresetName1,("Farfegnugen"));
strcpy(PresetName2,("Zakk's Marshall #34"));
strcpy(PresetName3,("Two Amps"));
strcpy(PresetName4,("LAMB OF GOD"));
strcpy(PresetName5,("DiG"));
strcpy(PresetName6,("LT MK IV Cygnus"));
strcpy(PresetName7,("LT Rack Delays (Filth)"));
strcpy(PresetName8,("LT Rack Delays (Clean)"));
strcpy(PresetName9,("F.A.R.K"));

break;

case 40: 
strcpy(PresetName0,("LT Crunch"));
strcpy(PresetName1,("LT Chunk"));
strcpy(PresetName2,("MCU"));
strcpy(PresetName3,("Rockbone! (mas bueno)"));
strcpy(PresetName4,("Skull Crusher"));
strcpy(PresetName5,("Powerball ENGL AX3 -c"));
strcpy(PresetName6,("NKP Dream Theater"));
strcpy(PresetName7,("NKP metallica"));
strcpy(PresetName8,("NKP malmsteen"));
strcpy(PresetName9,("NKP muse (plug in baby)"));

break;

case 50: 
strcpy(PresetName0,("NKP meshuggah"));
strcpy(PresetName1,("NKP hendrix"));
strcpy(PresetName2,("NKP nirvana"));
strcpy(PresetName3,("NKP guns N roses"));
strcpy(PresetName4,("NKP Slayer"));
strcpy(PresetName5,("NKP AC DC"));
strcpy(PresetName6,("DJENT La Tempesta"));
strcpy(PresetName7,("Bag Pipes drone"));
strcpy(PresetName8,("<EMPTY>"));
strcpy(PresetName9,("<EMPTY>"));

break;

case 60: 
strcpy(PresetName0,("8 String Djent"));
strcpy(PresetName1,("FAS Me!"));
strcpy(PresetName2,("Ambient Djentymist"));
strcpy(PresetName3,("6160 Rhythm"));
strcpy(PresetName4,("GHoffman's Djent Scenes"));
strcpy(PresetName5,("GOJIRA"));
strcpy(PresetName6,("<EMPTY>"));
strcpy(PresetName7,("<EMPTY>"));
strcpy(PresetName8,("<EMPTY>"));
strcpy(PresetName9,("<EMPTY>"));

break;

case 70: 
strcpy(PresetName0,("<EMPTY>"));
strcpy(PresetName1,("<EMPTY>"));
strcpy(PresetName2,("<EMPTY>"));
strcpy(PresetName3,("<EMPTY>"));
strcpy(PresetName4,("<EMPTY>"));
strcpy(PresetName5,("<EMPTY>"));
strcpy(PresetName6,("<EMPTY>"));
strcpy(PresetName7,("<EMPTY>"));
strcpy(PresetName8,("<EMPTY>"));
strcpy(PresetName9,("<EMPTY>"));

break;

case 80: 
strcpy(PresetName0,("<EMPTY>"));
strcpy(PresetName1,("<EMPTY>"));
strcpy(PresetName2,("<EMPTY>"));
strcpy(PresetName3,("<EMPTY>"));
strcpy(PresetName4,("<EMPTY>"));
strcpy(PresetName5,("<EMPTY>"));
strcpy(PresetName6,("<EMPTY>"));
strcpy(PresetName7,("<EMPTY>"));
strcpy(PresetName8,("<EMPTY>"));
strcpy(PresetName9,("<EMPTY>"));

break;

case 90: 
strcpy(PresetName0,("<EMPTY>"));
strcpy(PresetName1,("<EMPTY>"));
strcpy(PresetName2,("<EMPTY>"));
strcpy(PresetName3,("<EMPTY>"));
strcpy(PresetName4,("<EMPTY>"));
strcpy(PresetName5,("<EMPTY>"));
strcpy(PresetName6,("<EMPTY>"));
strcpy(PresetName7,("<EMPTY>"));
strcpy(PresetName8,("<EMPTY>"));
strcpy(PresetName9,("<EMPTY>"));

break;

case 100: 
strcpy(PresetName0,("Rockin' Train"));
strcpy(PresetName1,("Dr Z's blues"));
strcpy(PresetName2,("Carol-Ann OD2 lead 1"));
strcpy(PresetName3,("Carol-Ann OD2 lead 2"));
strcpy(PresetName4,("Carol-Ann OD2 lead 3"));
strcpy(PresetName5,("Fat Buddah"));
strcpy(PresetName6,("Bright Buddah"));
strcpy(PresetName7,("Bludojai Lead 1"));
strcpy(PresetName8,("Bludojai Lead 2"));
strcpy(PresetName9,("Two Rock to rock"));

break;

case 110: 
strcpy(PresetName0,("Two Rock to rock II"));
strcpy(PresetName1,("Zen Wreck"));
strcpy(PresetName2,("FAS Wreck"));
strcpy(PresetName3,("What the Fuchs is goin'"));
strcpy(PresetName4,("ODS-100 Lead 1"));
strcpy(PresetName5,("ODS-100 Lead 2"));
strcpy(PresetName6,("ODS-100 Lead 3"));
strcpy(PresetName7,("ODS-100 Lead 4 Joe B"));
strcpy(PresetName8,("ODS-100 HRM Mid lead"));
strcpy(PresetName9,("ODS-100 Ford lead 1"));

break;

case 120: 
strcpy(PresetName0,("ODS-100 Ford lead 2"));
strcpy(PresetName1,("ODS-100 Ford lead 3"));
strcpy(PresetName2,("Dumble and Dumbler"));
strcpy(PresetName3,("Fat ODS-100"));
strcpy(PresetName4,("Fat lead"));
strcpy(PresetName5,("Komet Concorde 1"));
strcpy(PresetName6,("Komet Concorde 2"));
strcpy(PresetName7,("Komet Concorde 3"));
strcpy(PresetName8,("Tucana blues 1"));
strcpy(PresetName9,("Tucana blues 2"));

break;

case 130: 
strcpy(PresetName0,("Hook blues"));
strcpy(PresetName1,("Warm BogFish lead"));
strcpy(PresetName2,("5F1 Tweed EC"));
strcpy(PresetName3,("Blues Jr Fat"));
strcpy(PresetName4,("Texas Blues - Lonestar"));
strcpy(PresetName5,("Texas Blues - Vibroking"));
strcpy(PresetName6,("Texas Blues - VibratoVerb"));
strcpy(PresetName7,("Texas Blues - Bandmaster"));
strcpy(PresetName8,("Texas Blues - Super Reverb"));
strcpy(PresetName9,("Texas Blues - Princeton"));

break;

case 140: 
strcpy(PresetName0,("Texas Blues - Dr Z"));
strcpy(PresetName1,("Texas Blues - Bassman"));
strcpy(PresetName2,("Dirty tweed"));
strcpy(PresetName3,("Andy Little Wing"));
strcpy(PresetName4,("Just one night"));
strcpy(PresetName5,("AC20 crunch"));
strcpy(PresetName6,("AC20 crunch 2"));
strcpy(PresetName7,("AC20 fusion 1"));
strcpy(PresetName8,("AC20 fusion 2"));
strcpy(PresetName9,("AC20 fusion 3"));

break;

case 150: 
strcpy(PresetName0,("Crunchy D30"));
strcpy(PresetName1,("Div/13 crunch"));
strcpy(PresetName2,("J. Mayer I"));
strcpy(PresetName3,("J. Mayer II"));
strcpy(PresetName4,("<EMPTY>"));
strcpy(PresetName5,("<EMPTY>"));
strcpy(PresetName6,("<EMPTY>"));
strcpy(PresetName7,("<EMPTY>"));
strcpy(PresetName8,("<EMPTY>"));
strcpy(PresetName9,("<EMPTY>"));

break;

case 160: 
strcpy(PresetName0,("<EMPTY>"));
strcpy(PresetName1,("<EMPTY>"));
strcpy(PresetName2,("<EMPTY>"));
strcpy(PresetName3,("<EMPTY>"));
strcpy(PresetName4,("<EMPTY>"));
strcpy(PresetName5,("<EMPTY>"));
strcpy(PresetName6,("<EMPTY>"));
strcpy(PresetName7,("<EMPTY>"));
strcpy(PresetName8,("<EMPTY>"));
strcpy(PresetName9,("<EMPTY>"));

break;

case 170: 
strcpy(PresetName0,("<EMPTY>"));
strcpy(PresetName1,("<EMPTY>"));
strcpy(PresetName2,("<EMPTY>"));
strcpy(PresetName3,("<EMPTY>"));
strcpy(PresetName4,("<EMPTY>"));
strcpy(PresetName5,("<EMPTY>"));
strcpy(PresetName6,("<EMPTY>"));
strcpy(PresetName7,("<EMPTY>"));
strcpy(PresetName8,("<EMPTY>"));
strcpy(PresetName9,("<EMPTY>"));

break;

case 180: 
strcpy(PresetName0,("<EMPTY>"));
strcpy(PresetName1,("<EMPTY>"));
strcpy(PresetName2,("<EMPTY>"));
strcpy(PresetName3,("<EMPTY>"));
strcpy(PresetName4,("<EMPTY>"));
strcpy(PresetName5,("<EMPTY>"));
strcpy(PresetName6,("<EMPTY>"));
strcpy(PresetName7,("<EMPTY>"));
strcpy(PresetName8,("<EMPTY>"));
strcpy(PresetName9,("<EMPTY>"));

break;

case 190: 
strcpy(PresetName0,("<EMPTY>"));
strcpy(PresetName1,("<EMPTY>"));
strcpy(PresetName2,("<EMPTY>"));
strcpy(PresetName3,("<EMPTY>"));
strcpy(PresetName4,("<EMPTY>"));
strcpy(PresetName5,("<EMPTY>"));
strcpy(PresetName6,("<EMPTY>"));
strcpy(PresetName7,("<EMPTY>"));
strcpy(PresetName8,("<EMPTY>"));
strcpy(PresetName9,("<EMPTY>"));

break;

case 200: 
strcpy(PresetName0,("<EMPTY>"));
strcpy(PresetName1,("<EMPTY>"));
strcpy(PresetName2,("<EMPTY>"));
strcpy(PresetName3,("<EMPTY>"));
strcpy(PresetName4,("<EMPTY>"));
strcpy(PresetName5,("<EMPTY>"));
strcpy(PresetName6,("<EMPTY>"));
strcpy(PresetName7,("<EMPTY>"));
strcpy(PresetName8,("<EMPTY>"));
strcpy(PresetName9,("<EMPTY>"));

break;

case 210: 
strcpy(PresetName0,("<EMPTY>"));
strcpy(PresetName1,("<EMPTY>"));
strcpy(PresetName2,("<EMPTY>"));
strcpy(PresetName3,("<EMPTY>"));
strcpy(PresetName4,("<EMPTY>"));
strcpy(PresetName5,("<EMPTY>"));
strcpy(PresetName6,("<EMPTY>"));
strcpy(PresetName7,("<EMPTY>"));
strcpy(PresetName8,("<EMPTY>"));
strcpy(PresetName9,("<EMPTY>"));

break;

case 220: 
strcpy(PresetName0,("<EMPTY>"));
strcpy(PresetName1,("<EMPTY>"));
strcpy(PresetName2,("<EMPTY>"));
strcpy(PresetName3,("<EMPTY>"));
strcpy(PresetName4,("<EMPTY>"));
strcpy(PresetName5,("<EMPTY>"));
strcpy(PresetName6,("<EMPTY>"));
strcpy(PresetName7,("<EMPTY>"));
strcpy(PresetName8,("<EMPTY>"));
strcpy(PresetName9,("<EMPTY>"));

break;

case 230: 
strcpy(PresetName0,("<EMPTY>"));
strcpy(PresetName1,("<EMPTY>"));
strcpy(PresetName2,("<EMPTY>"));
strcpy(PresetName3,("<EMPTY>"));
strcpy(PresetName4,("<EMPTY>"));
strcpy(PresetName5,("<EMPTY>"));
strcpy(PresetName6,("<EMPTY>"));
strcpy(PresetName7,("<EMPTY>"));
strcpy(PresetName8,("<EMPTY>"));
strcpy(PresetName9,("<EMPTY>"));

break;

case 240: 
strcpy(PresetName0,("<EMPTY>"));
strcpy(PresetName1,("<EMPTY>"));
strcpy(PresetName2,("<EMPTY>"));
strcpy(PresetName3,("<EMPTY>"));
strcpy(PresetName4,("<EMPTY>"));
strcpy(PresetName5,("<EMPTY>"));
strcpy(PresetName6,("<EMPTY>"));
strcpy(PresetName7,("<EMPTY>"));
strcpy(PresetName8,("<EMPTY>"));
strcpy(PresetName9,("<EMPTY>"));

break;

case 250: 
strcpy(PresetName0,("<EMPTY>"));
strcpy(PresetName1,("<EMPTY>"));
strcpy(PresetName2,("<EMPTY>"));
strcpy(PresetName3,("<EMPTY>"));
strcpy(PresetName4,("<EMPTY>"));
strcpy(PresetName5,("<EMPTY>"));
strcpy(PresetName6,("<EMPTY>"));
strcpy(PresetName7,("<EMPTY>"));
strcpy(PresetName8,("<EMPTY>"));
strcpy(PresetName9,("<EMPTY>"));

break;

case 260: 
strcpy(PresetName0,("<EMPTY>"));
strcpy(PresetName1,("<EMPTY>"));
strcpy(PresetName2,("<EMPTY>"));
strcpy(PresetName3,("<EMPTY>"));
strcpy(PresetName4,("<EMPTY>"));
strcpy(PresetName5,("<EMPTY>"));
strcpy(PresetName6,("<EMPTY>"));
strcpy(PresetName7,("<EMPTY>"));
strcpy(PresetName8,("<EMPTY>"));
strcpy(PresetName9,("<EMPTY>"));

break;

case 270: 
strcpy(PresetName0,("<EMPTY>"));
strcpy(PresetName1,("<EMPTY>"));
strcpy(PresetName2,("<EMPTY>"));
strcpy(PresetName3,("<EMPTY>"));
strcpy(PresetName4,("<EMPTY>"));
strcpy(PresetName5,("<EMPTY>"));
strcpy(PresetName6,("<EMPTY>"));
strcpy(PresetName7,("<EMPTY>"));
strcpy(PresetName8,("<EMPTY>"));
strcpy(PresetName9,("<EMPTY>"));

break;

case 280: 
strcpy(PresetName0,("<EMPTY>"));
strcpy(PresetName1,("<EMPTY>"));
strcpy(PresetName2,("<EMPTY>"));
strcpy(PresetName3,("<EMPTY>"));
strcpy(PresetName4,("<EMPTY>"));
strcpy(PresetName5,("<EMPTY>"));
strcpy(PresetName6,("<EMPTY>"));
strcpy(PresetName7,("<EMPTY>"));
strcpy(PresetName8,("<EMPTY>"));
strcpy(PresetName9,("<EMPTY>"));

break;

case 290: 
strcpy(PresetName0,("<EMPTY>"));
strcpy(PresetName1,("<EMPTY>"));
strcpy(PresetName2,("<EMPTY>"));
strcpy(PresetName3,("<EMPTY>"));
strcpy(PresetName4,("<EMPTY>"));
strcpy(PresetName5,("<EMPTY>"));
strcpy(PresetName6,("<EMPTY>"));
strcpy(PresetName7,("<EMPTY>"));
strcpy(PresetName8,("<EMPTY>"));
strcpy(PresetName9,("<EMPTY>"));

break;

case 300: 
strcpy(PresetName0,("<EMPTY>"));
strcpy(PresetName1,("<EMPTY>"));
strcpy(PresetName2,("<EMPTY>"));
strcpy(PresetName3,("<EMPTY>"));
strcpy(PresetName4,("<EMPTY>"));
strcpy(PresetName5,("<EMPTY>"));
strcpy(PresetName6,("<EMPTY>"));
strcpy(PresetName7,("<EMPTY>"));
strcpy(PresetName8,("<EMPTY>"));
strcpy(PresetName9,("<EMPTY>"));

break;

case 310: 
strcpy(PresetName0,("<EMPTY>"));
strcpy(PresetName1,("<EMPTY>"));
strcpy(PresetName2,("<EMPTY>"));
strcpy(PresetName3,("<EMPTY>"));
strcpy(PresetName4,("<EMPTY>"));
strcpy(PresetName5,("<EMPTY>"));
strcpy(PresetName6,("<EMPTY>"));
strcpy(PresetName7,("<EMPTY>"));
strcpy(PresetName8,("<EMPTY>"));
strcpy(PresetName9,("<EMPTY>"));

break;

case 320: 
strcpy(PresetName0,("<EMPTY>"));
strcpy(PresetName1,("<EMPTY>"));
strcpy(PresetName2,("<EMPTY>"));
strcpy(PresetName3,("<EMPTY>"));
strcpy(PresetName4,("<EMPTY>"));
strcpy(PresetName5,("<EMPTY>"));
strcpy(PresetName6,("<EMPTY>"));
strcpy(PresetName7,("<EMPTY>"));
strcpy(PresetName8,("<EMPTY>"));
strcpy(PresetName9,("<EMPTY>"));

break;

case 330: 
strcpy(PresetName0,("<EMPTY>"));
strcpy(PresetName1,("<EMPTY>"));
strcpy(PresetName2,("<EMPTY>"));
strcpy(PresetName3,("<EMPTY>"));
strcpy(PresetName4,("<EMPTY>"));
strcpy(PresetName5,("<EMPTY>"));
strcpy(PresetName6,("<EMPTY>"));
strcpy(PresetName7,("<EMPTY>"));
strcpy(PresetName8,("<EMPTY>"));
strcpy(PresetName9,("<EMPTY>"));

break;

case 340: 
strcpy(PresetName0,("<EMPTY>"));
strcpy(PresetName1,("<EMPTY>"));
strcpy(PresetName2,("<EMPTY>"));
strcpy(PresetName3,("<EMPTY>"));
strcpy(PresetName4,("<EMPTY>"));
strcpy(PresetName5,("<EMPTY>"));
strcpy(PresetName6,("<EMPTY>"));
strcpy(PresetName7,("<EMPTY>"));
strcpy(PresetName8,("<EMPTY>"));
strcpy(PresetName9,("<EMPTY>"));

break;

case 350: 
strcpy(PresetName0,("<EMPTY>"));
strcpy(PresetName1,("<EMPTY>"));
strcpy(PresetName2,("<EMPTY>"));
strcpy(PresetName3,("<EMPTY>"));
strcpy(PresetName4,("<EMPTY>"));
strcpy(PresetName5,("<EMPTY>"));
strcpy(PresetName6,("<EMPTY>"));
strcpy(PresetName7,("<EMPTY>"));
strcpy(PresetName8,("<EMPTY>"));
strcpy(PresetName9,("<EMPTY>"));

break;

case 360: 
strcpy(PresetName0,("<EMPTY>"));
strcpy(PresetName1,("<EMPTY>"));
strcpy(PresetName2,("<EMPTY>"));
strcpy(PresetName3,("<EMPTY>"));
strcpy(PresetName4,("<EMPTY>"));
strcpy(PresetName5,("<EMPTY>"));
strcpy(PresetName6,("<EMPTY>"));
strcpy(PresetName7,("<EMPTY>"));
strcpy(PresetName8,("<EMPTY>"));
strcpy(PresetName9,("<EMPTY>"));

break;

case 370: 
strcpy(PresetName0,("<EMPTY>"));
strcpy(PresetName1,("<EMPTY>"));
strcpy(PresetName2,("<EMPTY>"));
strcpy(PresetName3,("<EMPTY>"));
strcpy(PresetName4,("<EMPTY>"));
strcpy(PresetName5,("<EMPTY>"));
strcpy(PresetName6,("<EMPTY>"));
strcpy(PresetName7,("<EMPTY>"));
strcpy(PresetName8,("<EMPTY>"));
strcpy(PresetName9,("<EMPTY>"));

break;

case 380: 
strcpy(PresetName0,("<EMPTY>"));
strcpy(PresetName1,("<EMPTY>"));
strcpy(PresetName2,("<EMPTY>"));
strcpy(PresetName3,("<EMPTY>"));
strcpy(PresetName4,("<EMPTY>"));
strcpy(PresetName5,("<EMPTY>"));
strcpy(PresetName6,("<EMPTY>"));
strcpy(PresetName7,("<EMPTY>"));
strcpy(PresetName8,("<EMPTY>"));
strcpy(PresetName9,("<EMPTY>"));

break;

case 390: 
strcpy(PresetName0,("<EMPTY>"));
strcpy(PresetName1,("<EMPTY>"));
strcpy(PresetName2,("<EMPTY>"));
strcpy(PresetName3,("<EMPTY>"));
strcpy(PresetName4,("<EMPTY>"));
strcpy(PresetName5,("<EMPTY>"));
strcpy(PresetName6,("<EMPTY>"));
strcpy(PresetName7,("<EMPTY>"));
strcpy(PresetName8,("<EMPTY>"));
strcpy(PresetName9,("<EMPTY>"));

break;

case 400: 
strcpy(PresetName0,("<EMPTY>"));
strcpy(PresetName1,("<EMPTY>"));
strcpy(PresetName2,("<EMPTY>"));
strcpy(PresetName3,("<EMPTY>"));
strcpy(PresetName4,("<EMPTY>"));
strcpy(PresetName5,("<EMPTY>"));
strcpy(PresetName6,("<EMPTY>"));
strcpy(PresetName7,("<EMPTY>"));
strcpy(PresetName8,("<EMPTY>"));
strcpy(PresetName9,("<EMPTY>"));

break;

case 410: 
strcpy(PresetName0,("<EMPTY>"));
strcpy(PresetName1,("<EMPTY>"));
strcpy(PresetName2,("<EMPTY>"));
strcpy(PresetName3,("<EMPTY>"));
strcpy(PresetName4,("<EMPTY>"));
strcpy(PresetName5,("<EMPTY>"));
strcpy(PresetName6,("<EMPTY>"));
strcpy(PresetName7,("<EMPTY>"));
strcpy(PresetName8,("<EMPTY>"));
strcpy(PresetName9,("<EMPTY>"));

break;

case 420: 
strcpy(PresetName0,("<EMPTY>"));
strcpy(PresetName1,("<EMPTY>"));
strcpy(PresetName2,("<EMPTY>"));
strcpy(PresetName3,("<EMPTY>"));
strcpy(PresetName4,("<EMPTY>"));
strcpy(PresetName5,("<EMPTY>"));
strcpy(PresetName6,("<EMPTY>"));
strcpy(PresetName7,("<EMPTY>"));
strcpy(PresetName8,("<EMPTY>"));
strcpy(PresetName9,("<EMPTY>"));

break;

case 430: 
strcpy(PresetName0,("<EMPTY>"));
strcpy(PresetName1,("<EMPTY>"));
strcpy(PresetName2,("<EMPTY>"));
strcpy(PresetName3,("<EMPTY>"));
strcpy(PresetName4,("<EMPTY>"));
strcpy(PresetName5,("<EMPTY>"));
strcpy(PresetName6,("<EMPTY>"));
strcpy(PresetName7,("<EMPTY>"));
strcpy(PresetName8,("<EMPTY>"));
strcpy(PresetName9,("<EMPTY>"));

break;

case 440: 
strcpy(PresetName0,("<EMPTY>"));
strcpy(PresetName1,("<EMPTY>"));
strcpy(PresetName2,("<EMPTY>"));
strcpy(PresetName3,("<EMPTY>"));
strcpy(PresetName4,("<EMPTY>"));
strcpy(PresetName5,("<EMPTY>"));
strcpy(PresetName6,("<EMPTY>"));
strcpy(PresetName7,("<EMPTY>"));
strcpy(PresetName8,("<EMPTY>"));
strcpy(PresetName9,("<EMPTY>"));

break;

case 450: 
strcpy(PresetName0,("<EMPTY>"));
strcpy(PresetName1,("<EMPTY>"));
strcpy(PresetName2,("<EMPTY>"));
strcpy(PresetName3,("<EMPTY>"));
strcpy(PresetName4,("<EMPTY>"));
strcpy(PresetName5,("<EMPTY>"));
strcpy(PresetName6,("<EMPTY>"));
strcpy(PresetName7,("<EMPTY>"));
strcpy(PresetName8,("<EMPTY>"));
strcpy(PresetName9,("<EMPTY>"));

break;

case 460: 
strcpy(PresetName0,("<EMPTY>"));
strcpy(PresetName1,("<EMPTY>"));
strcpy(PresetName2,("<EMPTY>"));
strcpy(PresetName3,("<EMPTY>"));
strcpy(PresetName4,("<EMPTY>"));
strcpy(PresetName5,("<EMPTY>"));
strcpy(PresetName6,("<EMPTY>"));
strcpy(PresetName7,("<EMPTY>"));
strcpy(PresetName8,("<EMPTY>"));
strcpy(PresetName9,("Ping-Pong Pong-Ping"));

break;

case 470: 
strcpy(PresetName0,("8-Voice Chorus"));
strcpy(PresetName1,("Dual Clean"));
strcpy(PresetName2,("New Country"));
strcpy(PresetName3,("In a Fixx"));
strcpy(PresetName4,("L.A. Session Clean"));
strcpy(PresetName5,("Yngwie!"));
strcpy(PresetName6,("Mr.Gilmour Lead"));
strcpy(PresetName7,("Plate Collection"));
strcpy(PresetName8,("Chugnuts"));
strcpy(PresetName9,("Ned Beatty"));

break;

case 480: 
strcpy(PresetName0,("A Kind of Dream"));
strcpy(PresetName1,("Spandex & Hairspray"));
strcpy(PresetName2,("Avant Jazz"));
strcpy(PresetName3,("Stone in Love"));
strcpy(PresetName4,("Fifth Tribe"));
strcpy(PresetName5,("Ambient Guitar"));
strcpy(PresetName6,("Eruption"));
strcpy(PresetName7,("Thrilling Chilling"));
strcpy(PresetName8,("Mr.Floyd"));
strcpy(PresetName9,("Barracuda"));

break;

case 490: 
strcpy(PresetName0,("Solar Eclipses"));
strcpy(PresetName1,("Comb Delays"));
strcpy(PresetName2,("Blitz III"));
strcpy(PresetName3,("Pitch Follower"));
strcpy(PresetName4,("The Infield"));
strcpy(PresetName5,("Polychromatic Shifter"));
strcpy(PresetName6,("1987 Clean"));
strcpy(PresetName7,("Sultans"));
strcpy(PresetName8,("RockMeOn CLN2"));
strcpy(PresetName9,("Jeff Gets Ready"));

break;

case 500: 
strcpy(PresetName0,("Diamonique Rain"));
strcpy(PresetName1,("Pete-a-Palooza"));
strcpy(PresetName2,("Larry Mitchell NY Steak"));
strcpy(PresetName3,("Mark's Day's Recto Cygnus"));
strcpy(PresetName4,("Fremen's Drones of Arrakis"));
strcpy(PresetName5,("Brett's Party Pack"));
strcpy(PresetName6,("Brett's Party Pack 2"));
strcpy(PresetName7,("AustinBuddy's XTCs"));
strcpy(PresetName8,("Leon's Live"));
strcpy(PresetName9,("Out1:FOH Out2:Cab"));

break;

case 510: 
strcpy(PresetName0,("Amp Match Template"));
strcpy(PresetName1,("BYPASS"));
strcpy(PresetName2,("NOT AVAILABLE"));
strcpy(PresetName3,("NOT AVAILABLE"));
strcpy(PresetName4,("NOT AVAILABLE"));
strcpy(PresetName5,("NOT AVAILABLE"));
strcpy(PresetName6,("NOT AVAILABLE"));
strcpy(PresetName7,("NOT AVAILABLE"));
strcpy(PresetName8,("NOT AVAILABLE"));
strcpy(PresetName9,("NOT AVAILABLE"));

break;

 }
}
