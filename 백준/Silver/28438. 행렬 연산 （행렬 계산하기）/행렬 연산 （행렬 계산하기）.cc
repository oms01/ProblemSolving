#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<vector<int>> v;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n,m,t;
    cin>>n>>m>>t;
    v.resize(n+1,vector<int>(m+1,0));
    
    for(int i=0;i<t;i++){
        int a,b,c;
        cin>>a>>b>>c;
        if(a==1){
            v[b-1][m]+=c;
        }   
        else{
            v[n][b-1]+=c;
        }
    }
    // for(int i=0;i<n+1;i++){
    //     for(int j=0;j<m+1;j++){
    //         cout<<v[i][j]<<' ';
    //     }
    //     cout<<'\n';
    // }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            v[i][j] = v[n][j] + v[i][m];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<v[i][j]<<' ';
        }
        cout<<'\n';
    }

}


