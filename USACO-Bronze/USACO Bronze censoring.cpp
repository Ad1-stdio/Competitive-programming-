#include <iostream>
#include <string>

using namespace std;

void RemoveSubString(string& str1,string& str2){
size_t pos;
while((pos=str1.find(str2))!=string::npos){
str1.erase(pos,str2.length());
}
}
int main(){
string str1;string str2;
if(!(cin>>str1)) return 0;
if(!(cin>>str2))return 0;

RemoveSubString(str1,str2);
cout<<str1;
return 0;
}