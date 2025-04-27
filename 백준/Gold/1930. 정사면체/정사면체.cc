#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define rep(i,x,y) for(int i=x;i<y;i++)
#define REP(i,x,y) for(int i=x;i<=y;i++)
#define all(x) begin(x),end(x)
#define rall(x) rbegin(x),rend(x)
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef tuple<int,int,int> tiii;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
/*----------------------*/

void solve(){
    vector<int> a(4); rep(i,0,4) cin>>a[i];
    vector<int> b(4); rep(i,0,4) cin>>b[i];

    vector<int> A;
    rep(i,1,4) A.push_back(a[i]);
    rep(i,1,4) A.push_back(a[i]);
    
    rep(idx,0,4){
        if(a[0]!=b[idx]) continue;

        vector<int> B;
        if(idx==0){
            B.push_back(b[1]); B.push_back(b[2]); B.push_back(b[3]);
        }
        else if(idx==1){
            B.push_back(b[0]); B.push_back(b[3]); B.push_back(b[2]);
        }
        else if(idx==2){
            B.push_back(b[0]); B.push_back(b[1]); B.push_back(b[3]);
        }
        else if(idx==3){
            B.push_back(b[0]); B.push_back(b[2]); B.push_back(b[1]);
        }

        REP(i,0,3){
            bool flag = 1;
            rep(j,0,3){
                if(A[i+j]!=B[j]) flag = 0;
            }
            if(flag){
                cout<<1<<'\n';
                return;
            }
        }
    }

    cout<<0<<'\n';
    return;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--) solve();
}