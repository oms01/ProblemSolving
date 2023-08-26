#include <bits/stdc++.h>
using namespace std;
int board[101][101];
int mn = 2e9;
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>board[i][j];
        }
    }
    vector<int> p;
    for(int i=0;i<n/2;i++) p.push_back(0);
    for(int i=0;i<n/2;i++) p.push_back(1);
    do{
        vector<int> a,b;
        for(int i=0;i<n;i++){
            if(p[i]) a.push_back(i);
            else b.push_back(i);
        }
        int s1=0,s2=0;
        for(int i=0;i<a.size();i++){
            for(int j=i;j<a.size();j++){
                s1+=board[a[i]][a[j]];
                s1+=board[a[j]][a[i]];
            }
        }
        for(int i=0;i<b.size();i++){
            for(int j=i;j<b.size();j++){
                s2+=board[b[i]][b[j]];
                s2+=board[b[j]][b[i]];
            }
        }
        mn = min(mn,abs(s1-s2));

    }while(next_permutation(p.begin(),p.end()));
    cout<<mn<<'\n';
}