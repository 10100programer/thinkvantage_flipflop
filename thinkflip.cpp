/* 
Thinkvantage button fliplop software
This program is designed to be mapped to two commands that run in a filp flop maner
*/
#include <iostream>
#include <string>
#include <fstream>

bool fileExists(const char *fileName)
{
    ifstream infile(fileName);
    return infile.good();
}
init() //to be run the first time the program runs in order to setup file structure so the logic works
{
  ofstream initfile;
  initfile.open ("/var/lib/thinkflip/state");//make state file
  initfile << "0"; //writes zero to file
  initfile.close(); //closes the file
//create
}

main()
{
fstream filestate;
filestate.open("/var/lib/thinkflip/state");

bool state = false;//false = 0 true = 1
filestate >> state; //check to see if this will work

if(fileExists("/var/lib/thinkflip/state"))//file does not exists
{
  init();//runs init and creates file
  return 128;//specal return code
}

if(state)//file at location 0 = 0 do this
{
  system("redshift -O 2700")//runs redshift for nighttime
  return 1;//command completed successfully
}

if(state)//file at location 0 = 1 do this
{
  system("redshift -x")//runs redshift for nighttime
  return 1;//command completed successfully
}
  return 0x123FF;//program has an error most likely because the init failed
}
