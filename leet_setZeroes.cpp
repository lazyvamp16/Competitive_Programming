#include<iostream>
#include<set>
#include<vector>
using namespace std;

//Set Matrix Zeroes

void setZeroes(vector<vector<int>>& matrix)
{
    set<int> l1,l2;
    int n= matrix.size();
    int m= matrix[0].size();
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m;j++)
        {
            cout << matrix[i][j] << " ";
            if ((matrix[i][j]) == 0) 
            {
                l1.insert(i);
                l2.insert(j);
            }
        }
        cout << endl;
    }

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m;j++)
        {
            if (l1.find(i)!=l1.end()|| l2.find(j)!=l2.end()) matrix[i][j]=0;
        }
    }

    cout << endl;
    cout << "after fucntion call" << endl << endl;

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m;j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

}

int main()
{
    vector<vector<int>> matrix{{1,1,1},{1,0,1},{1,1,1}};
    setZeroes(matrix);
}