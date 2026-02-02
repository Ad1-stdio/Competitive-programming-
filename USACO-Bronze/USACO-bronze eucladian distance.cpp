#include<iostream>
#include<cmath>
#include <vector>
using namespace std; 
int main(){
int n;
vector<int> x;
vector<int> y;
if(!(cin>>n))return 0;
int high;
for(int i=0;i<n;i++){
int temp;
cin>>temp;
x.push_back(temp);}
for(int i=0;i<n;i++){
int temp;
cin>>temp;
y.push_back(temp);}

for(int i=0;i<n;i++){
for(int j=i+1;j<n;j++){
int dx = x[i]-x[i+1];
int dy =y[i]-y[i+1];
high = max(high,dx*dx+dy*dy);
}
}
cout<<high;
return 0;
}