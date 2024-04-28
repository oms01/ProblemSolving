#include<bits/stdc++.h>
using namespace std;
#define X first 
#define Y second
#define rep(i,x,y) for(int i=x;i<y;i++)
typedef long long ll;
typedef pair<ll,ll> pii;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
/*----------------------*/

int arr[10];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ll n; cin>>n;
    map<ll,ll> m;
    rep(i,0,n){
        string str; cin>>str;
        arr[str[0]-'A'] = 1;
        rep(i,0,str.length()){
            m[str[i]-'A'] += pow(10,str.length()-i-1);
        }
    }
    ll val = 2e15;
    ll mn = 2e15;
    for(auto i=m.begin();i!=m.end();i++){
        if(arr[i->X] || val <= i->Y) continue;
        val = i->Y;
        mn = i->X;
    }
    vector<pii> v;
    for(auto i=m.begin();i!=m.end();i++){
        v.push_back({i->Y,i->X});
    }
    sort(v.rbegin(),v.rend());
    if(v[v.size()-1].Y < m[mn] && v.size()<9){
        mn = v[v.size()-1].X;
    }
    ll idx = 9;
    ll ans = 0;
    rep(i,0,v.size()){
        if(v[i].Y==mn) continue;
        ans+= v[i].X*idx--;
    }
    ans+=m[mn]*idx;
    cout<<ans<<'\n';
}