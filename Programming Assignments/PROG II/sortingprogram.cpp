//Drew Demechko
//Programming II
//Due: 9-4-15
//sortingprogram.cpp
//Main program that includes 3 classes for different sorting algorithms such as
//Algorithms include bubble sort, shell sort, and a quick sort.

//Include programs that hold sorting algorithms
#include "bubblesort.cpp"
#include "shellsort.cpp"
#include "quicksort.cpp"

#if __INCLUDE_LEVEL__ < 1
#include<iostream>
#include<cstdlib>
using namespace std;
int main()
{
  srand((unsigned)time(0));
  int originalarray[20];
  
  //Initialize a randomized array that holds 10 values
    //and print out the numbers
  for(int i = 0; i < 20; i++)
  {
    originalarray[i] = rand()%100;
  }

  //Copy each of the random values in an individual array for each
    // sorting algorithm
  int bubblearray[20];
  int shellarray[20];
  int quickarray[20];

  for(int i = 0; i < 20; i++)
  {
  bubblearray[i] = originalarray[i];
  shellarray[i] = originalarray[i];
  quickarray[i] = originalarray[i];
  }

  cout<<"--------------------"<<endl;
  //Print the cost of each algorithm and the sorted array
  cout<<"Original array values: "<<endl;
  for(int i = 0; i < 20; i++)
  cout<<originalarray[i]<<" ";
  cout<<endl;
  int bubblecost = bubbleSort(bubblearray);
  cout<<"Array values after bubble sort algorithm: "<<endl;
  for(int i = 0; i < 20; i++)
  cout<<bubblearray[i]<<" ";
  cout<<endl;
  cout<<"The cost of  the bubble sort: "<<endl;
  cout<<bubblecost<<endl;
  cout<<"--------------------"<<endl;
  
  cout<<"Original array values: "<<endl;
  for(int i = 0; i < 20; i++)
  cout<<originalarray[i]<<" ";
  cout<<endl;
  int shellcost = shellSort(shellarray,20);
  cout<<"Array values after shell sort algorithm: "<<endl;
  for(int i = 0; i < 20; i++)
  cout<<shellarray[i]<<" ";
  cout<<endl;
  cout<<"The cost of the shell sort: "<<endl;
  cout<<shellcost<<endl;
  cout<<"--------------------"<<endl;

  cout<<"Original array values: "<<endl;
  for(int i = 0; i < 20; i++)
  cout<<originalarray[i]<<" ";
  cout<<endl;
  int quickcost = quickSort(quickarray,0,19);
  cout<<"Array values after quick sort algorithm: "<<endl;
  for(int i = 0; i < 20; i++)
  cout<<quickarray[i]<<" ";
  cout<<endl;
  cout<<"The cost of the quick sort: "<<endl;
  cout<<quickcost<<endl;
  cout<<"--------------------"<<endl;
}
#endif
