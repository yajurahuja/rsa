// ALICE 2
#include <fstream>
#include <iostream>
#include <cmath>

using namespace std;
long dectobinary(long decimalnumber,int A[])
{ 
    int i = 0; int temp;
    long quotient = decimalnumber;
    while(quotient !=0)
    {
        A[i++] = quotient % 2;
        quotient = quotient / 2;
    }
   /* int end = i -1;
    for(int j = 0; j< i/2; j++,end--)
     {
        temp = A[j];
        A[j] = A[end];
        A[end] = temp;
    }*/    
    return i;
}
  
long remainder(long dividend, long exponent, long divisor)
{
    int Binary[200]; long pr[200]; int remainder; long long product = 1;

    long size = dectobinary(exponent, Binary);

    for(int i = 0; i < size; i++)
    {       
        if(i == 0)
            pr[i] = (long)pow(dividend, pow(2, i))%divisor;
        else
            pr[i] = (long)pow(pr[i-1], 2) % divisor;
        //cout<<pr[i]<<" "<<Binary[i]<<endl;
        if(Binary[i] == 1)
            product *= pr[i];
            product = product % divisor;
            
    }
    remainder = product % divisor;
    //cout<<"Remainder :"<<(char)remainder<<endl;
    return remainder;
}
        
    

  
int main()
{
    long d;
    long long N;
    cout<<"Enter the private key: ";
    cin>>d;
    ifstream fin;
    fin.open("Public_key.txt");
    fin>>N;
    fin.close();
    
    long message[100];
    int count = 0;
    //input the data from the text file and store it in message
    
    fin.open("Message.txt");
    while(!fin.eof())
    {
        fin>>message[count];
        count++;
    }
    cout<<(count - 1)<<endl;
    
    for(int i = 0; i < count - 1; i++)
    {
        cout<<(char)remainder(message[i], d, N);
    }
    cout<<endl;
    return 0;
}
    