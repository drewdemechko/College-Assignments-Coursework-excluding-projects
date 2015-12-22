//Drew Demechko
//Programming II
//Due:November 11, 2015
//tickets.cpp
//This program reads in a group of tickets and calculates the total
//cost for a basketball game.

#include<iostream>
#include<iomanip>
#include<fstream>
#include<stdlib.h>

using namespace std;

int findSeatCost(char c)
{
  switch(c)
  {
    case 'a':
    case 'h':
    case 'i':
    case 'p':
      return 5;
    case 'b':
    case 'g':
    case 'j':
    case 'o':
      return 3;
    case 'c':
    case 'f':
    case 'k':
    case 'n':
      return 6;
    case 'd':
    case 'e':
    case 'l':
    case 'm':
      return 9;
    default:
      return 0;
  }
}

int calculateCost(string line)
{
  //Calculates the cost of each line of input
  int count = 0;
  int cost = 0;
  int tempnum = 0;

  while(line[count] != 'A' && line[count] != 0)//end of useful info
  {
    if(isdigit(line[count]))
    {
      if(isdigit(line[count+1]))
      {
        tempnum = (line[count++] - 48) * 10;
        tempnum += line[count++] - 48;
      }
      else
      {
        tempnum = line[count++] - 48;
      }
    }
    else if(isalpha(line[count]))
    {
      cost += findSeatCost(line[count++]) * tempnum;
    }
    else
    {
      count++;
    }
  }
  cout<<setw(20)<<line<<"  ";
  cout<<"The amount due for this group is  "<<setprecision(2)<<fixed
  <<float(cost)<<endl;
  return cost;  
}

int main()
{
  cout<<setw(20)<<"echo input"<<setw(40)<<"cost"<<endl;

  ifstream idata;
  string temp = "";
  int total = 0;

  idata.open("tickets.dat");

  while(getline(idata,temp))
  {
    total += calculateCost(temp);
  }
  cout<<setw(56)<<"The grand total is  "
  <<setprecision(2)<<fixed<<float(total)<<endl;
  idata.close();
}

