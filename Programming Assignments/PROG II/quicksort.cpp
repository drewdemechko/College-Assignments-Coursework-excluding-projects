//Drew Demechko
//Programming II
//Due:9-4-15
//quicksort.cpp
//This program includes a quick sort algorithm with a test.
#include<iostream>
#include<cstdlib>
using namespace std;

void quickSwap(int arr[], int first, int second)
{
//Swaps elements in the array
  int temp = arr[first];
  arr[first] = arr[second];
  arr[second] = temp;
}

int quickSort(int arr[], int left, int right)
{
  int i = left;
  int j = right;
  int pivot = arr[(left+right)/2];
  int cost = 0;

  //Partition
  while(i <= j)
  {
    //Increment the cost by 1 for every compare
    cost++;
    while(arr[i]<pivot)
      i++;
    while(arr[j]>pivot)
      j--;
    if(i<=j)
    {
      //Increment the cost by 6 for every swap
      quickSwap(arr,i,j);
      cost+=6;
      i++;
      j--;
    }
  }

  if(left<j)
    quickSort(arr,left,j);
  if(i<right)
    quickSort(arr,i,right);

return cost;
}

#if __INCLUDE_LEVEL__ < 1
int main()
{
int cost;
srand((unsigned)time(0));
int array1[20];
int sizeofarray = 20;

cout<<"TESTING QUICK SORT"<<endl;

//Initialize random array values and display for user
cout<<"Original array: "<<endl;

for(int i = 0; i < sizeofarray; i++)
{
  array1[i] = rand()%100;
  cout<<array1[i]<<" ";
}

cout<<endl;

//Sort the array using a quick sort algorithm
cost = quickSort(array1,0,19);

//Display sorted array
cout<<"Sorted array: "<<endl;

for(int i = 0; i < sizeofarray; i++)
  cout<<array1[i]<<" ";

cout<<endl;

//Display the cost of the algorithm
cout<<"The cost of the quick sort is "<<endl<<cost<<endl;
}

#endif
