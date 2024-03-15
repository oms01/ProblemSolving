#include<bits/stdc++.h>
using namespace std;
#define X first 
#define Y second
#define rep(i,x,y) for(ll i=x;i<y;i++)
typedef long long ll;
typedef pair<int,int> pii;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
/* -------------------- */


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    set<ll> s;
    s.insert(0);
    ll sum=0;
    int x=0;
    while(t--){
        int a; cin>>a;
        if(a==1){
            int n; cin>>n;
            s.insert(n);
            sum+=n;
            x^=n;
        }
        else if(a==2){
            int n; cin>>n;
            s.erase(n);
            sum-=n;
            x^=n;
        }
        else if(a==3){
            cout<<sum<<'\n';
        }
        else{
            cout<<x<<'\n';
        }
    }
}