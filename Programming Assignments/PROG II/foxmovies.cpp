//Drew Demechko
//Programming II
//Due:September 11, 2015
//foxmovies.cpp
//This program stores an array of movies and sorts by the name of the movie
//and sorts the movies by gross profit.
#include<iostream>
#include<cstdlib>
#include<fstream>
#include<string.h>
#include<iomanip>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

class movie{
private: string name;
private: string date;
private: string cost;
private: string gross;

//Takes name,date of release, production costs, and gross profit
public: movie(string d, string n, string c, string g)
{
  date = d;
  name = n;
  cost = c;
  gross = g;
}
  
  public: string getName()
  {
    return name;
  }

  public: string getDate()
  {
    return date;
  }

  public: string getCost()
  {
    return cost;
  }

  public: long convertGross()
  {  
  //converts gross profit to an integer so that it can be sorted correctly
  string temp;
  int i = 0;
  while(gross[i] != 0)
  {
  if(gross[i] != ',' && gross[i] != '$')
  temp+=gross[i++];
  else
  i++;
  }
  const char * c = temp.c_str();
  long num = atol(c);
  return num;
  }

  public: string getGross()
  {
    return gross;
  }

//Displays movie information to the user
public: void displayInfo()
{
  cout<<"Date: "<<date<<" "<<"Name: "<<name<<"Production Cost: "<<
  cost<<"Gross: "<<gross<<endl;
}
};

movie m[99] = movie("","","","");

void swap(int left, int right)
{
  movie temp = m[left];
  m[left] = m[right];
  m[right] = temp;
}

void sortByName(movie mo[])
{
bool swaps;

//Sort the movies by Movie Name and display list
cout<<"---Movies sorted by Movie Name---"<<endl;
cout<<left<<setw(50)<<"Name"<<left<<setw(40)<<"Release Date"<<left<<setw(40)<<"Production Cost"<<left<<setw(40)<<"Gross Profit"<<endl;
  for(int i = 0; i < 99; i++)
  {
    bool swaps = false;
    for(int j = 0; j < 98; j++)
      {
        if(mo[j].getName() > mo[j+1].getName())
        {
        swap(j,j+1);
        swaps = true;
        }
      }
  }
  
}

void sortByGross(movie mo[])
{
bool swaps;

//Sort the movies by Gross Profit and display list
cout<<"---Movies sorted by Gross Profit---"<<endl;
cout<<left<<setw(50)<<"Name"<<left<<setw(40)<<"Production Cost"<<left<<setw(40)<<"Gross Profit"<<left<<setw(40)<<"Release Date"<<endl;
  for(int i = 0; i < 99; i++)
  {
    bool swaps = false;
    for(int j = 0; j < 98; j++)
    {
      if(mo[j].convertGross() < mo[j+1].convertGross())
      {
        if(mo[j].convertGross() == 2185372302)
        cout<<"HIT"<<endl;
        swap(j,j+1);
        swaps = true;
      }
    }
  }
}

int main()
{
string tempvalue;
ifstream movies("movies.txt");
string tempmovie[4];
//movie m[99]= movie("","","","");
int i = 0;
int moviecount = 0;

//Read text in from the movies text file
if(movies.is_open())
{
   while(getline(movies,tempvalue,'|'))
   {
    //Store movie data in the movies class array
    tempmovie[i++] = tempvalue;
    if(i == 4)
    {
    m[moviecount++]=movie(tempmovie[0],tempmovie[1],tempmovie[2],tempmovie[3]);
    i = 0;
    }
   }
   movies.close();
}

//Sort the movies first by name then by gross profit
sortByName(m);

for(int i = 0; i < 99; i++)
  cout<<left<<setw(50)<<m[i].getName()<<left<<setw(40)<<m[i].getDate()<<left<<setw(40)<<m[i].getCost()<<left<<setw(40)<<m[i].getGross()<<endl;

}
