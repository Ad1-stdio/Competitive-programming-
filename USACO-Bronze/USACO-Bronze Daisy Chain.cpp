#include<iostream>
#include<vector>
using namespace std;

int main(){
int n;
if(!(cin>>n))return 0;
vector<int> P(n);
int temp=0,sum=0;
for(int i=0;i<n;i++){cin>>P[i];}

for(int i=0;i<n;i++){
    for(int j=i;j<n;j++){
        sum=0;
        for(int k=i;k<=j;k++){
            sum+=P[k];
        }
    
    if(sum%(j-i+1)==0){
        int avg=sum/(j-i+1);
        for(int k=i;k<=j;k++){
            if(P[k]==avg){
            temp++;
            break;
            }
        }
    }
    }
}
cout<<temp;
return 0;
}