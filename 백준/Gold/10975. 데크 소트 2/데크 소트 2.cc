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

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    vector<int> v(n);
    rep(i,0,n) cin>>v[i];

    vector<pii> dq;
    rep(i,0,n){
        int cur = v[i];
        bool flag = 1;
        for(auto& [st,en]:dq){
            if(cur<st){
                bool f = 1;
                rep(j,i+1,n){
                    if(cur<v[j]&&v[j]<st){
                        f = 0;
                    }
                }
                if(f){
                    flag = 0;
                    st = cur;
                    break;
                }

            }
            else{
                bool f = 1;
                rep(j,i+1,n){
                    if(en<v[j]&&v[j]<cur){
                        f = 0;
                    }
                }
                if(f){
                    flag = 0;
                    en = cur;
                    break;
                }

            }
        }

        if(flag){
            dq.push_back({cur,cur});
        }
    }
    cout<<dq.size()<<'\n';
}