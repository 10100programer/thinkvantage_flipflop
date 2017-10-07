/* 
Thinkvantage button fliplop software
This program is designed to be mapped to two commands that run in a filp flop maner
*/
#include <iostream>
#include <string>
#include <fstream>

using namespace std;
bool fileExists(const char *fileName)
{
    ifstream infile(fileName);
    return infile.good();
}
void init() //to be run the first time the program runs in order to setup file structure so the logic works
{
  ofstream initfile;
  initfile.open ("state");//make state file
  initfile << "0"; //writes zero to file
  initfile.close(); //closes the file
//create
}

main()
{
if(fileExists("state")==false)//file does not exists
{
cout << "Running INIT\n";
  init();//runs init and creates file
cout <<"returned 128";
  return 128;//specal return code
}

fstream filestate;
filestate.open("state");

//string conversion area
char file;
filestate.read(file,1);
bool state = false;//false = 0 true = 1
if (file[0] == 1)
{
state=true;
}
if (file[0] == 0)
{
state=false;
}

//state = filestate; //check to see if this will work
//cout >> file
if(state == true)
	cout << "true";

if(state == false)
	cout << "false";


if(state == false)//file at location 0 = 0 do this
{
filestate << "1";
filestate.close();
  system("redshift -O 2700");//runs redshift for nighttime

cout <<"returned 1";
  return 1;//command completed successfully
}

if(state == true)//file at location 0 = 1 do this
{
  system("redshift -x");//runs redshift for nighttime
cout <<"returned 1";
  return 1;//command completed successfully
}
cout <<"returned 0x123FF";
  return 0x123FF;//program has an error most likely because the init failed
}
