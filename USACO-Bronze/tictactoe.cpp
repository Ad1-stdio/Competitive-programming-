#include<iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main()
{
vector<vector<char>> matrix(3);

for(int i=0;i<3;i++){
vector <char> arr;
    for(int j=0;j<3;j++)
    {
        char temp; 
        cin>>temp;
        arr.push_back(temp);
    }
matrix.push_back(arr);
}

for(int i=0;i<matrix.size();i++){
    for(int j=0;j<matrix[i].size();j++)
    {
    cout<<matrix[i][j]<<" ";
    }
}
return 0;
}