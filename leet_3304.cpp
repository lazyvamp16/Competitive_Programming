#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>
#include <algorithm>
#include <set>
using namespace std;

// Leetcode 3304. Find the K-th Character in String Game I

int main()
{
    //char a = 'a';
    //cout << char(a+1);
    int k = 5;
    string s = "a";
    while(s.length()<k){
        for(char i : s){
            if(i=='z') s.push_back('a');
            else s.push_back(char(i+1));
        }
    }
    cout << s[k-1];
}