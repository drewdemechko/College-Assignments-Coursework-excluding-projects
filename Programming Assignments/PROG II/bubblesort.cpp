//Drew Demechko
//Programming II
//Due:9-4-15
//bubblesort.cpp
//This program includes a bubble sort algorithm with a test.
#include<iostream>
#include<cstdlib>
using namespace std;

void bubbleSwap(int arr[], int first, int second)
{
//Swaps elements in the array
  int temp = arr[first];
  arr[first] = arr[second];
  arr[second] = temp;
}

int bubbleSort(int arr[])
{
  int cost = 0;
  bool swaps = true;

  while(swaps){
    swaps = false;
    for(int j = 0; j < 20-1; j++)
	{
	  //Increment a cost by 1 for every compare
	  cost++;
	  if(arr[j] > arr[j+1])
	  {
	    swaps = true;
            bubbleSwap(arr, j , j+1);
	  //Increment a cost by 6 for every swap
	    cost+= 6;
	  }
	}
    }
  return cost;
}
#if __INCLUDE_LEVEL__ < 1
int main()
{
int cost;
srand((unsigned)time(0));
int array1[20];
int sizeofarray = 20;

cout<<"TESTING BUBBLE SORT"<<endl;
//Initialize random array values and display for user
cout<<"Original array: "<<endl;

for(int i = 0; i < sizeofarray; i++)
{
  array1[i] = rand()%100;
  cout<<array1[i]<< " ";
}

cout<<endl;

//Sort the array using a bubble sort algorithm
cost = bubbleSort(array1);

//Display sorted array
cout<< "Sorted array: "<<endl;

for(int i = 0; i < sizeofarray; i++)
  cout<<array1[i]<<" ";

cout<<endl;

//Display the cost of the algorithm
cout<<"The cost of the bubble sort is " <<endl<< cost << endl;
}

#endif
