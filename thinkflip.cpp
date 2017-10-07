/* 
Thinkvantage button fliplop software
This program is designed to be mapped to two commands that run in a filp flop maner
*/
#include 
init() //to be run the first time the program runs in order to setup file structure so the logic works
{

}

main()
{

if()//file does not exists
{
  init();//runs init
  return 1;
}

if()//file at location 0 = 0 do this
{
  system("redshift -O 2700")//runs redshift for nighttime
  return 1;
}

if()//file at location 0 = 1 do this
{
  system("redshift -x")//runs redshift for nighttime
  return 1;
}
  return 0x123FF;//program has an error most likely because the init failed
}
