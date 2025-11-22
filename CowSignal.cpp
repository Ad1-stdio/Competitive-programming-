#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main ()
{
int m ;
int n ; 
int k ; 
cin >> m >> n >> k ;

vector<string> grid(m) ; 

for ( int i = 0 ; i < m ; i ++ )
{

    cin >> grid[i];
}

for ( int i = 0 ; i < m*k;i++ )
{
    for ( int j = 0 ; j < n*k ; ++j )
    {
    cout<<grid[i/k][j/k];
    }
    cout << endl;
}
return 0;
}