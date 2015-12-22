//Drew Demechko
//Programming II
//Due:9-4-15
//shellsort.cpp
//This program includes a shell sort algorithm with a test.
#include<iostream>
#include<cstdlib>
using namespace std;

void shellSwap(int arr[], int first, int second)
{
//Swaps elements in the array
  int temp = arr[first];
  arr[first] = arr[second];
  arr[second] = temp;
}

int shellSort(int arr[],int size)
{
  int cost = 0;
  bool swaps = true;
  int gap = size;
  
  while(swaps || (gap > 1))
  {
    swaps = false;
    gap = (gap+1)/2;

    for(int i = 0; i < size - gap; i++)
    {
      cost++;
      if(arr[i+gap] < arr[i])
      {
        swaps = true;
        shellSwap(arr,i,i+gap);
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

cout<<"TESTING SHELL SORT"<<endl;

//Initialize random array values and display for user
cout<<"Original array: "<<endl;

for(int i = 0; i < sizeofarray; i++)
{
  array1[i] = rand()%100;
  cout<<array1[i]<<" ";
}

cout<<endl;

//Sort the array using a shell sort algorithm
cost = shellSort(array1,20);

//Display sorted array
cout<< "Sorted array: "<<endl;

for(int i = 0; i < sizeofarray; i++)
  cout<<array1[i]<<" ";

cout<<endl;

//Display the cost of the algorithm
cout<<"The cost of the shell sort is " <<endl<< cost << endl;
}

#endif
