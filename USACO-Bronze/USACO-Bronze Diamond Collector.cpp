/*🏛️ The Problem: Diamond Collector
Bessie has N diamonds of various sizes. She wants to put some of them in a display case. However, she must follow
one rule: the difference between the size of the largest diamond and the smallest diamond in the case cannot be 
greater than K.

Your Goal: Find the maximum number of diamonds she can put in the case.
Input:
N (Number of diamonds) and K (The maximum size difference).
The sizes of the N diamonds.
Constraints: N≤1000,K≤10,000.
*/
#include<iostream>
using namespace std;
int main(){
    int c , k;
    vector<int> n(c);
    if(!(cin>>c>>k))return 0;

    for(int i=0;i<c;++i){
        cin>>n[i];
    }
    int ans=0,temp=0;

    for(int i=0;i<c;i++)
    {
    temp=0;
        for(int j=0;j<c;j++)
        {
            if(n[i]<=n[j]&&n[j]<=n[i]+k){temp++;}
        }
    ans=max(ans,temp);
    }

    cout<<ans;
    return 0;
}