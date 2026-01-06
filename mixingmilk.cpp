#include <iostream>
using namespace std;
#include <algorithm>

int main()
{

    int C[3];
    int M[3];

    for (int i=0;i<3;i++)
    {
        cin>>C[i]>>M[i];
    }
    for(int j=0;j<100;j++)
        {
            int from = j%3;
            int to = (j+1)%3;

            int space = C[to] - M[to];
            int to_pour = min(M[from],space);

            M[from]-= to_pour;
            M[to]+= to_pour;
        }
    
    for(int i = 0;i<3;i++)
    {
        cout<<M[i]<<endl;
    }
    return 0;
}
