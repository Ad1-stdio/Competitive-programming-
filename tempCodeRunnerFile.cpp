#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std; 

int main ()
{
int n ;
cin >> n ; 

vector <string> type(n);
vector <int> low(n);
vector <int> high(n);

for( int i = 0 ; i < n ; i ++)
{
    cin >> type[i]>>low[i]>>high[i];
}


int L = 0;
int H = 1000;


for ( int i = 0 ; i < n ; i++)
{ 
    if ( type[i] == "none")

    {
        L = max(L,low[i]);
        H = min(H,high[i]);
    }

    else if(type[i] == "on")
    {
        L += low[i] ;
        H += high[i] ;
    }

    else if(type[i] == "off")
    {
        L -= high[i] ;
        H -= low[i] ;
        L = max(0,L);
    }
}

int FinalH = H ;
int FinalL = L ;

L = 0;
H = 1000;

for ( int i = n-1 ; i>=0 ; i--)
{ 
    if ( type[i]== "none")

    {
        L = max(L,low[i]);
        H = min(H,high[i]);
    }

    else if(type[i] == "on")
    {
        L -= high[i] ;
        H -= low[i] ;
        L = max(0,L);
    }

    else if(type[i] == "off")
    {
        L += low[i] ;
        H += high[i] ;
    }
}



cout <<L<<" "<<H<<endl;
cout << FinalL<< " " << FinalH<<endl;

return 0;
}