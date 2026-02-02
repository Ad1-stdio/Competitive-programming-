#include<iostream>
using namespace std;

int main(){
int x;int y;int m;
if(!(cin>>x>>y>>m)) return 0;
int high=0;
for(int i=0;i<i*x<=m;i++){
for(int j=0;j*y+i*x<=m;j++)
{
int curr=i*x+j*y;
high = max(high,curr);
}
}
cout<<high;
return 0;
}