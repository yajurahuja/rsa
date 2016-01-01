//BOB
#include <fstream>
#include <iostream>
#include <cmath>
#include<ctype.h>
#include <cstring>

using namespace std;

long remainder(long dividend, long exponent, long divisor);
long dectobinary(long decimalnumber,int A[]);
void convert(long A[], char B[], int size, int e, int N);
class key
{
    public:
    long long N;
    int public_key;
    
    key()
    {
        N = 1 * 1;
        public_key = 3;
    }
    /*long long N()
    {
        return N;
    }
    int public_key()
    {
        return public_key;
    }*/
}; 


long remainder(long dividend, long exponent, long divisor)
{
    int Binary[200]; long pr[200]; int remainder; long long product = 1;

    int size = dectobinary(exponent, Binary);

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
    //cout<<"Remainder :"<<remainder<<endl;
    return remainder;
}
        
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
void convert(long A[], char B[], int size, int e, int N)
{
    for(int i = 0; i < size; i++)
    {
        A[i] = remainder(int(B[i]), e, N);
    }
}
      
int main()
{
    ifstream fin;
    fin.open("Public_key.txt");
    key B;
    fin>>B.N;
    fin>>B.public_key;
    char message[100];
    cout<<"Enter your message(100 characters max): ";
    gets(message);
    int size = strlen(message);
    long message1[100];
    convert(message1, message, size, B.public_key, B.N);
    ofstream fout;
    fout.open("Message.txt");
    for(int k = 0; k < size; k++)
        fout<<message1[k]<<" ";
    fout.close();
    return 0;
}
    
    