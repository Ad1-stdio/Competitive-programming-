#include<iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main()
{
    vector<vector<int>> matrix(3);

    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            int val;
            cin>>val;
            matrix[i].push_back(val);
        }
    }

    for(int i=0;i<matrix.size();i++){
        for(int j=0;j<matrix[i].size();j++){
            cout << matrix[i][j]<<" ";
        }
    }
    return 0;
}