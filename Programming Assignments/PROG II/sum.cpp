#include<iostream>
using namespace std;

int main()
{
int sum = 0;
int i = 0;
while(i<1000)
{
if((i%5==0 && i%3==0)||(i%3==0)||(i%5==0))
sum+=i;
i++;
}

cout<<"sum = " << sum<<endl;
}
