#include<bits/stdc++.h>
using namespace std;
#define X first 
#define Y second
#define rep(i,x,y) for(ll i=x;i<y;i++)
typedef long long ll;
typedef pair<int,int> pii;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

int mnX=2e9,mnY=2e9;
int mxX=-2e9,mxY=-2e9;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    vector<int> v(3);
    cin>>v[0]>>v[1]>>v[2];
    sort(v.begin(),v.end());
    v[2] = min(v[2],v[0]+v[1]-1);
    cout<<v[0]+v[1]+v[2];
}