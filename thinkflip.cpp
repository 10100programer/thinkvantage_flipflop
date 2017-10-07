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
}

int main()
{
	if(fileExists("state")==false)		//file does not exists
	{
		cout << "Running INIT\n";
		init();							//runs init and creates file
		cout <<"returned 128";
		return 128;						//specal return code
	}
	ifstream readfilestate;				//filestate for reading file
	ofstream filestate;					//filestate for ouput file
	readfilestate.open("state");		//open file
	char * buffer = new char[1];		//buffer one letter
	readfilestate.read(buffer, 1);		//read file and store value in buffer
	readfilestate.close();
	bool state;							//false = 0 true = 1
	cout << "buffer is equal to " << buffer[0];
	cin.ignore();
	if (buffer[0] == '1')			//if buffer =1 then state = true
	{
		state=true;					//Sets state to true
	}
	if (buffer[0] == '0')			//if buffer =0 then state = true
	{
		state=false;				//Sets state to false
	}

	if (state == true)				//for debug
	{								//for debug
		cout << "true";				//for debug
	}								//for debug
	if (state == false)				//for debug
	{								//for debug
		cout << "false";			//for debug
	}								//for debug
	cin.ignore();
	filestate.open("state");		//open file
	if(state == false)				//file at location 0 = 0 do this
	{
		filestate << "1";			//put number 1 into file
		filestate.close();			//closes filestream
		system("redshift -O 2700");	//runs redshift for nighttime
		cout <<"returned 0";		//for debug
		cin.ignore();
		return 0;					//command completed successfully for 0
	}

	if(state == true)				//file at location 0 = 1 do this
	{
		filestate << "0";
		filestate.close();			
		system("redshift -x");		//runs redshift for nighttime
		cout <<"returned 1";		//for debug
		cin.ignore();
		return 1;					//command completed successfully for 1
	}
	cout <<"returned 0x123FF";
	cin.ignore();
	return 0x123FF;					//program has an error most likely because the init failed
}
