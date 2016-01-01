// ALICE

/* N= prime1 * prime2

phi_n = (prime1 -1) * (prime2 -1);

public_key(e) such that gcd(phi_n, e) = 1

private_key(d) :
for(int n = 0 ;; n++)
{   
    if(1 + n * phi_n)% e ==0)
        d = (1 +n phi_n) / e
            break;
}

*/

//PUBLIC KEYS are N and e
//PRIVATE KEYS are N and d

#include<iostream>
#include<cmath>
#include <cstdio>
#include <fstream>
#include <cstdlib>

using namespace std;

void getprime(long long *primes);
long long generate_d(long long ,int);
int gcd(long long a, int b );

class key
{
    public:
    long long N;
    int public_key;
   
    
    key()
    {
        N = 1 * 1;
        public_key = 2;
    }
    long long return_N()
    {
        return N;
    }
    int retpublic_key()
    {
        return public_key;
    }
}; 
    
    
    
    
int main()
{
    long long primes[2];
    getprime(primes);
    key A;
    //primes[0] = 76207;
    //primes[1] = 70313;
    cout<<primes[0]<<endl<<primes[1]<<endl;
    A.N = primes[0] * primes[1];
    long long phi_N = (primes[0] - 1) * (primes[1] - 1);
    while (gcd(phi_N, A.public_key) != 1)
        A.public_key++;
    long d = generate_d(phi_N, A.retpublic_key());
    cout<<"your private key: "<<d<<endl<<"Product of Primes: "<<A.N<<endl;
    //send
    ofstream fout;
    fout.open("Public_key.txt");
    fout<<A.N<<endl<<A.public_key;  
    fout.close();
    return 0;
}    

long long generate_d( long long m, int e)
{    
    long long d = -1;
    int n = 0;
    while(d < 0)
    {   
        if((1 + n * m) % e == 0)
        {
            d = (1 +n * m) / e;
            
        }
        //cout<<d;
        n++;
    }
    
    //cout<<d<<endl;
    return d;
}


void getprime(long long *primes)
{
  int tempnum;
  int count = 0;

  srand (time(NULL)); // random seed
  // get 2 random indices which are distinct
  int ind1 = rand() % 2000 + 1 ; // get a random number b/w 1 and 10000
  int ind2 = ind1;
  while(ind1 == ind2)
    {
      ind2 = rand() % 2000 + 1;
    }
  
  // arrange the random indices in increasing order
  if(ind2 < ind1)
    {
      int temp = ind1;
      ind1 = ind2;
      ind2 = temp;
    }
  
  
  std::fstream file("primenumbers.txt", std::ios_base::in);
  while (count <= ind2)
    {
      count++;
      file >> tempnum;
      if (count == ind1)
	primes[0] = tempnum;
      else if (count == ind2)
	primes[1] = tempnum;
    }
  
  file.close();
}

int gcd(long long a, int b )
{
  long c;
  while ( a != 0 ) 
  {
     c = a; 
     a = b%a;  
     b = c;
  }
  return b;
}

           