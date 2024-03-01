#include<bits/stdc++.h>
using namespace std;
#define X first 
#define Y second
#define rep(i,x,y) for(ll i=x;i<y;i++)
typedef long long ll;
typedef pair<int,int> pii;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    map<string,int> ma;
    int n,m; cin>>n>>m;
    while(n--){
        string a; cin>>a;
        if(a.length()<m) continue;
        ma[a]++;
    }
    vector<pair<int,string>> v;
    for(auto iter=ma.begin();iter!=ma.end();iter++){
        v.push_back({iter->second,iter->first});
    }
    sort(v.begin(),v.end(),[](pair<int,string> a, pair<int,string> b){
        if(a.X != b.X) return a>b;
        if(a.Y.length() != b.Y.length()) return a.Y.length() > b.Y.length();
        return a.Y<b.Y;
    });
    for(auto x:v){
        cout<<x.Y<<'\n';
    }
}

