#include<bits/stdc++.h>
using namespace std;
#define X first 
#define Y second
typedef long long ll;
typedef pair<ll,ll> pii;
int n,m,st;
int arr[51];
int ans = -1;
set<pii> s;
void func(int v,int i){
    if(v<0 || v>m) return;
    if(!s.empty() && s.find({v,i})!=s.end()) return;
    if(i==n){
        ans = max(ans,v);
        return;
    }

    s.insert({v,i});
    func(v+arr[i],i+1);
    func(v-arr[i],i+1);

}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n>>st>>m; //곡 리스트, 시작, 최대
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    func(st,0);
    cout<<ans<<'\n';

}