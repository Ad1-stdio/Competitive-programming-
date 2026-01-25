#include <iostream>
using namespace std;
#include <map>

int main()
{
int x = 0;int y=0;int t=0;int n;
char direction;int steps;int ans =1001;

if(!(cin>>n)) return 0;

map<pair<int,int>,int>loc;
loc[{0,0}]=0;

for(int i=0;i<n;i++){
cin>>direction>>steps;

for(int i=0;i<steps;i++){
t++;

if(direction=='N')y++;
else if(direction=='S')y--;
else if(direction=='W')x--;
else if(direction=='E')x++;

if(loc.count({x,y})){
int gap = t - loc[{x,y}];
ans = min(ans,gap);
}
loc[{x,y}]=t;
}
}
if(ans==1001){
cout<<-1<<endl;
}
else cout<<ans<<endl;

return 0;
}