#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; 

int main ()
{
    int LOR = 100 ;
    int max_l = 0 ;
//m is the road segment 
    int m ;
    cin>>m;

    int current_start_index = 0;

    vector <int> sl(LOR);

    vector <int> bs(LOR); 

    for ( int i = 0 ; i < m ; i ++)
    {
        int length ; 
        int speed ; 

        cin >> length >> speed ; 
        auto start_it = sl.begin() + current_start_index;
        auto end_it = sl.begin() + current_start_index + length ; 

        fill(start_it,end_it,speed);

    current_start_index += length ;
    }

    current_start_index = 0;
    for ( int i = 0 ; i < m ; i ++ )
    {
        int length ; 
        int speed ; 

        cin>> length >> speed ; 
        auto start_it = bs.begin() + current_start_index;
        auto end_it = bs.begin() + current_start_index + length ; 

        fill (start_it,end_it,speed);
        
        
    current_start_index +=length ;
    }

    for ( int i = 0 ; i < LOR ; i++)
    {
        int difference = bs[i] - sl[i];

        if ( difference > 0)
        {
            max_l = std::max(max_l,difference);
        }
    }

    cout<<max_l ;

return 0;
}