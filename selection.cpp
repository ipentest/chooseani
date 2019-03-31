#include <iostream>
#include <ctime>
#include <string>
#include <cstdlib>
 
using namespace std;
 
int main(){
short type, subtype, batt, HD, size, natAC, S, Dex, Con, Int, Wis, Cha, bSP ;
string speed, space, NatReach, name, shape, feats ;
bool bfort, bref, bwill ;
// jeszcze ataki, specjalne ataki, umiejetnosci,  atuty, SW i specjalne zdolnosci

// Detailed descr for types
string descr[16][40];
short descr_lines;
//ABERRATION
descr[1][1]="--- Aberration Type ---";
descr[1][2]="An aberration has a bizarre anatomy, strange abilities,";
descr[1][3]="an alien mindset, or any combination of the three.";
descr[1][4]="--- Main Traits ---";
descr[1][5]="Darkvision out to 60 feet.";
descr[1][6]="Aberrations eat, sleep, and breathe.";
descr[1][7]="--- Proficiencies ---";
descr[1][8]="Proficient with its natural weapons. If generally humanoid in form, proficient";
descr[1][9]="with all simple weapons and any weapon it is described as using.";
descr[1][10]="Proficient with whatever type of armor (light,medium,heavy) it is described";
descr[1][11]="as wearing, as well as all lighter types.";
descr[1][12]="Aberrations not indicated as wearing armor are not proficient with armor.";
descr[1][13]="Proficient with shields if they are proficient with any form of armor.";
//ANIMAL
descr[2][1]="--- Animal Type ---";
descr[2][2]="An animal is a living, nonhuman creature, usually a vertebrate with";
descr[2][3]="no magical abilities and no innate capacity for language or culture.";
descr[2][4]="--- Main Traits ---";
descr[2][5]="Low-light vision.";
descr[2][6]="Animals eat, sleep, and breathe.";
descr[2][7]="--- Proficiencies ---";
descr[2][8]="Proficient with its natural weapons only."; 
descr[2][9]="A noncombative herbivore uses its natural weapons as a secondary attack.";
descr[2][10]="Such attacks are made with a -5 penalty on the creature’s attack rolls,";
descr[2][11]="and the animal receives only 1/2 Strength modifier as a damage adjustment.";
descr[2][12]="Proficient with no armor unless trained for war.";
descr[2][13]="--- Other Traits ---";
descr[2][14]="Intelligence score of 1 or 2";
descr[2][15]="(no creature with an Intelligence score of 3 or higher can be an animal).";
descr[2][16]="Alignment: Always neutral.";
descr[2][17]="Treasure: None.";
//CONSTRUCT
descr[3][1]="--- Construct Type ---";
descr[3][2]="A construct is an animated object or artificially constructed creature.";
descr[3][3]="--- Main Traits ---";
descr[3][4]="Low-light vision.";
descr[3][5]="Darkvision out to 60 feet.";
descr[3][6]="Immunity to all mind-affecting effects ";
descr[3][7]="(charms, compulsions, phantasms, patterns, and morale effects).";
descr[3][8]="Immunity to poison, sleep eff, paralysis, stunning, disease, death eff,";
descr[3][9]="and necromancy effects.";
descr[3][10]="Not subject to critical hits, nonlethal damage, ability damage, ability drain,";
descr[3][11]="fatigue, exhaustion, or energy drain.";
descr[3][12]="Immunity to any effect that requires a Fortitude save (unless the effect also";
descr[3][13]="works on objects, or is harmless).";
descr[3][14]="Not at risk of death from massive damage. Immediately destroyed when";
descr[3][15]="reduced to 0 hit points or less.";
descr[3][16]="Constructs do not eat, sleep, or breathe.";
descr[3][17]="--- Proficiencies ---";
descr[3][18]="Proficient with its natural weapons only, unless generally humanoid in form,";
descr[3][19]="in which case proficient with any weapon mentioned in its entry.";
descr[3][20]="Proficient with no armor.";
descr[3][21]="--- Other Traits ---";
descr[3][22]="No Constitution score";
descr[3][23]="It gains bonus hit points based on size";
descr[3][24]="Cannot heal damage on their own, but often can be repaired by exposing";
descr[3][25]="them to a certain kind of effect";
descr[3][26]="(see the creature’s description for details) or through the use of the";
descr[3][27]="Craft Construct feat. ";
descr[3][28]="A construct with the fast healing special quality still benefits from that.";
descr[3][29]="Since it was never alive, a construct cannot be raised or resurrected.";
descr[3][30]="Because its body is a mass of unliving matter, a construct is hard to destroy.";




// CHOOSE TYPE
type = 0;
short type_dec;
bool typetaken; typetaken=0 ;
while (typetaken==0) // PREVIEW TYPE / CHANGE IT

{
system("cls");
cout << "Choose type" << endl; 
cout << "After chosing it, you will see detailed preview and change it if you want to" << endl ;
cout << "1. Aberration HD:8  atk:med. Sv:Will            SP:2+" << endl ;
cout << "2. Animal     HD:8  atk:med. Sv:Fort, Ref (and sometimes Will) SP:2+"	<< endl ;
cout << "3. Construct  HD:10 atk:med. Sv:-	             SP:2+"	<< endl ;
cout << "4. Dragon     HD:12 atk:high Sv:Fort, Ref, Will SP:6+"	<< endl ;
cout << "5. Elemental  HD:8  atk:med. Sv:Ref(Air, Fire)/Fort(Earth, Water) SP:2+"	<< endl ;
cout << "6. Fey        HD:6  atk:low  Sv:Ref, Will       SP:6+"	<< endl ;
cout << "7. Giant      HD:8  atk:med. Sv:Fort            SP:2+"	<< endl ;
cout << "8. Humanoid   HD:8  atk:med. Sv:Varies (any one)   SP:2+"	<< endl ;
cout << "9. Magical beast       HD:10 atk:hgh  Sv:Fort, Ref SP:2+"	<< endl ;
cout << "10.Monstrous humanoid  HD:8  atk:high Sv:Ref, Will SP:2+"	<< endl ;
cout << "11.Ooze       HD:10 atk:med. Sv:-               SP:2+*"	<< endl ;
cout << "12.Outsider   HD:8  atk:high Sv:Fort, Ref, Will SP:8+"	<< endl ;
cout << "13.Plant      HD:8  atk:med. Sv:Fort            SP:2+*"	<< endl ;
cout << "14.Undead     HD:12 atk:low  Sv:Will            SP:4+*"	<< endl ;
cout << "15.Vermin     HD:8  atk:med. Sv:Fort            SP:2+*"	<< endl ;
cout << "16.CONTINUE" << endl ;
cout << "17.EXIT" << endl;

(type==0)? cin >> type_dec:cout << "";

bfort=0, bref=0, bwill=0; //Default save values
if (0<type_dec<16) {type=type_dec;} //Type properities

switch (type)
{
	case 1: descr_lines=14, HD=8, batt=0,75, bwill=1, bSP=2; break;
	case 2: descr_lines=18, HD=8, batt=0,75, bwill=1, bfort=1, bSP=2; break; // SOMETIMES WILL (add a note while final editing)
	case 3: descr_lines=30, HD=10, batt=0,75, bSP=2; break;
	default : break;
}

if (0<type<16) {
cout << "This is your current choice.Pick another type or continue" << endl;
for (int i=1 ; i<descr_lines ; i++)
{
 cout << descr[type][i] << endl;
}
cin >> type_dec;
}
if (type_dec==16){
	typetaken=1;
	}
if (type_dec==17)
{
	return 0;
}
} // while end


 
system("cls");

// CHOOSE SUBTYPE
bool subtypetaken; subtypetaken=0 ;
while (subtypetaken==0)
{
cout << "Choose subtype (if any)" << endl;
cout << "1.  NONE" << endl ; 
cout << "2.  Air" << endl ; 
cout << "3.  Angel" << endl ;
cout << "4.  Aquatic" << endl ;
cout << "5.  Archon" << endl ; 
cout << "6.  Augmented"<< endl ; 
cout << "7.  Chaotic"<< endl ; 
cout << "8.  Cold"<< endl ; 
cout << "9.  Earth"<< endl ; 
cout << "10. Evil"<< endl ; 
cout << "11. Etraplanar"<< endl ; 
cout << "12. Fire"<< endl ; 
cout << "13. Goblinoid"<< endl ; 
cout << "14. Good"<< endl ; 
cout << "15. Incorporeal"<< endl ; 
cout << "16. Lawful"<< endl ; 
cout << "17. Native"<< endl ; 
cout << "18. Reptilian"<< endl ; 
cout << "19. Shapechanger"<< endl ;
cout << "20. Swarm"<< endl ;
cout << "21. Water"<< endl ;
cout << "22. CONTINUE" << endl ;
cout << "23. EXIT" << endl ;

short d_subtype;


cin >> d_subtype;
if (1<d_subtype<22) {subtype=d_subtype ;}

short sub_lines;

//SUBTYPE DESCR
short subtype [24][sub_lines]; sub_lines=0;

system("cls");
}
// CHOOSE SIZE AND DISPLAY SIZE
cout << "Choose Size" << endl;
cout << "1. Fine         Att&AC:+8 SpecAtMod:-16 HideMod:+16"<< endl;
cout << "2. Diminutive   Att&AC:+4 SpecAtMod:-12 HideMod:+12"<< endl;
cout << "3. Tiny         Att&AC:+2 SpecAtMod:-8  HideMod:+8"<< endl;
cout << "4. Small        Att&AC:+1 SpecAtMod:-4  HideMod:+4"<< endl;
cout << "5. Medium       Att&AC:+0 SpecAtMod:0   HideMod:0"<< endl;
cout << "6. Large        Att&AC:-1 SpecAtMod:+4  HideMod:-4"<< endl;
cout << "7. Huge         Att&AC:-2 SpecAtMod:+8  HideMod:-8"<< endl;
cout << "8. Gargantuan   Att&AC:-4 SpecAtMod:+12 HideMod:-12"<< endl;
cout << "9. Colossal     Att&AC:-8 SpecAtMod:+16 HideMod:-16"<< endl;

cin >> size;

// SIZE CONSEQUENCES
string Dsize; // NAME (for Display, not calculations)
string Tsize[9]; // Typpical 1-Str, 2-Dex, 3-Const 4-HD 5-Smash 6-Bite 7-Claws/Sting 8-Butt/Tail for this szie (for Display, not calculations)
short AAC_S, SA_S, HI_S; // AAC_S - Attack and AC mod , Spec Attack mod, Hide mod 
switch (size)
{
case 1: Dsize = "Fine" ; Tsize[1]="1"; Tsize[2]="16-27"; Tsize[3]="2-11"; Tsize [4]="max 2"; Tsize[5]="0"; Tsize[6]="1"; Tsize[7]="0"; Tsize[8]="0"; AAC_S=8 ; SA_S=-16 ; HI_S=16 ; break; 
case 2: Dsize = "Diminutive"; Tsize[1]="1"; Tsize[2]="14-26"; Tsize[3]="4-13"; Tsize [4]="max 4"; Tsize[5]="1"; Tsize[6]="1d2"; Tsize[7]="1"; Tsize[8]="1"; AAC_S=4 ; SA_S=-12 ; HI_S=12 ;  break;
case 3: Dsize = "Tiny"; Tsize[1]="2-5"; Tsize[2]="14-23"; Tsize[3]="4-15"; Tsize [4]="max 6"; Tsize[5]="1"; Tsize[6]="1d3"; Tsize[7]="1d2"; Tsize[8]="1d2"; AAC_S=2 ; SA_S=-8 ; HI_S=8 ;  break;
case 4: Dsize = "Small"; Tsize[1]="4-11"; Tsize[2]="10-21"; Tsize[3]="6-17"; Tsize [4]="min 1/2"; Tsize[5]="1d3"; Tsize[6]="1d5"; Tsize[7]="1d3"; Tsize[8]="1d4"; AAC_S=1 ; SA_S=-4 ; HI_S=4 ;  break;
case 5: Dsize = "Medium"; Tsize[1]="8-19"; Tsize[2]="8-19"; Tsize[3]="8-19"; Tsize [4]="min 1"; Tsize[5]="1d4"; Tsize[6]="1d6"; Tsize[7]="1d4"; Tsize[8]="1d6"; AAC_S=0 ; SA_S=0 ; HI_S=0 ;  break;
case 6: Dsize = "Large"; Tsize[1]="18-27"; Tsize[2]="6-17"; Tsize[3]="10-23"; Tsize [4]="min 2"; Tsize[5]="1d6"; Tsize[6]="1d8"; Tsize[7]="1d6"; Tsize[8]="1d8"; AAC_S=-1 ; SA_S=4 ; HI_S=-4 ;  break;
case 7: Dsize = "Huge"; Tsize[1]="24-33"; Tsize[2]="4-15"; Tsize[3]="12-27"; Tsize [4]="min 4"; Tsize[5]="1d8"; Tsize[6]="2d6"; Tsize[7]="1d8"; Tsize[8]="2d6"; AAC_S=-2 ; SA_S=8 ; HI_S=-8 ;  break;
case 8: Dsize = "Gargantuan"; Tsize[1]="30-41"; Tsize[2]="4-13"; Tsize[3]="14-31"; Tsize [4]="min 12"; Tsize[5]="2d6"; Tsize[6]="2d8"; Tsize[7]="2d6"; Tsize[8]="2d8"; AAC_S=-4 ; SA_S=12 ; HI_S=-12 ;  break;
case 9: Dsize = "Colossal"; Tsize[1]="36-49"; Tsize[2]="2-11"; Tsize[3]="18-39"; Tsize [4]="min 24"; Tsize[5]="2d8"; Tsize[6]="4d6"; Tsize[7]="2d8"; Tsize[8]="4d6"; AAC_S=-8 ; SA_S=16 ; HI_S=-16 ;  break;
default : cout << "Wrong size! Insert only numbers from 1 to 9"; return 0;
}

// CHOOSE HD
cout << "How much Hit Dices?" << endl;
cout << "Due to chosen size, it should be " << Tsize[4] << endl;
cin >> HD;
system("cls");

// CHOOSE NATURAL AC
cout << "Insert natural Armor Class (only the value)" << endl;
cout << "Examples of typpical natural AC and their values:" << endl << endl;
cout << "Thick skin/Hide/Fur :     1-3    (1-baboon, 2-black bear, 3-shark)" << endl;
cout << "Hard skin :               4-7    (4-crocodile, 5-white bear, 6-boar, 7-rhino)" << endl;
cout << "Scales :                  5-10+  (various-dragons)" << endl;
cout << "Exokeleton :              2-11+  (2-gigantic bee, 10-chuul, 11-remorhaz" << endl;
cout << "Crust,Shell or simmilar : 10-12+ (10-troyanid child, 12-bulette)" << endl;
cout << "Very hard skin :          8-15+  (8-othyug, 13-kraken, 15-ravid)" << endl;

cin >> natAC;
system("cls");

// CHOOSE ATTRIBUTES
cout << "Instert strenght " << endl;
cout << "Typpical S for " << Dsize << " size is " << Tsize[1] << endl;
cin >> S;

cout << "Insert dexterity" << endl;
cout << "Typpical Dex for " << Dsize << " size is " << Tsize[2] << endl;
cin >> Dex;

cout << "Insert condition" << endl;
cout << "Typpical Con for " << Dsize << " size is " << Tsize[3] << endl;
cin >> Con;

cout << "Insert inteligence" << endl;
cin >> Int;

cout << "Insert wisdom" << endl;
cin >> Wis;

cout << "Insert Charisma" << endl;
cin >> Cha;
system("cls");

// EDIT ATRIBUTES
bool loop; loop =1;
short decyzja;
	while (loop)
	{
		(type==14 && Con>0)? cout << "Undeads can't possess Con attribute" << endl:cout << "";
		(type==2 && Int>2)? cout << "Animals can't possess Int 3 or higher" << endl:cout << "";
		(type==3 && Con>0)? cout << "Constructs can't possess Con attribute" << endl:cout << "";
		(type==3 && Int>0)? cout << "Constructs usually does not possess Int attribute" << endl:cout << "";
		(type==11 && Int>0)? cout << "Oozes usually does not posses Int attribute" << endl:cout << "";
		(type==13 && Int>0)? cout << "Plants usually does not posses Int attribute" << endl:cout << "";
		(type==14 && Int>0)? cout << "Undeads usually does not posses Int attribute" << endl:cout << "";
		(type==15 && Int>0)? cout << "Vermins usually does not posses Int attribute" << endl:cout << "";
		cout << "Edit attributes" << endl;
		cout << "1. Continue (Save attributes)" << endl;
		cout << "2. S" << endl;
		cout << "3. Dex" << endl;
		cout << "4. Con" << endl;
		cout << "5. Int" << endl;
		cout << "6. Wis" << endl;
		cout << "7. Cha" << endl;
		cout << "S" << S << " Dex" << Dex << " Con" << Con << " Int" << Int << " Wis" << Wis << " Cha" << Cha << endl;
		
		cin >> decyzja;
		
		switch (decyzja)
		{
			case 1: loop=0; system("cls"); break;
case 2: cout << "New S:"; cin >> S; system("cls"); break;
case 3: cout << "New Dex:"; cin >> Dex; system("cls"); break;
case 4: cout << "New Con:";cin >> Con; system("cls"); break;
case 5: cout << "New Int:";cin >> Int; system("cls"); break;
case 6: cout << "New Wis:";cin >> Wis; system("cls"); break;
case 7: cout << "New Cha:";cin >> Cha; system("cls"); break;
 default: cout << "Insert number (1-7)!"; break;

// ATTACKS ! podać wartości dla tego rozmiaru, oraz przy podbiciu atutem


// Multiattack feat?
// Foccus on attack feat(s)?
// Primary or Secondary
// How much attacks?
// Non-combative herbivore? (-5 att all, 1/2 str everywhere)



// SKILLS ! 

 
 
}
}

return 0;
}
