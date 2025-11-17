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
typedef pair<ld,ld> pldld;
typedef tuple<int,int,int> ti3;
typedef tuple<ll,ll,ll> tl3;
typedef tuple<int,int,int,int> ti4;
int dx[] = {-1,0,0,1};
int dy[] = {0,-1,1,0};
/*----------------------*/
vector<pair<pii, vector<pair<string,int>>>> v; //{최소, 최대}, 방인원
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n,m; cin>>n>>m;
    rep(i,0,n){
        int val; string str; cin>>val>>str;
        bool flag = 0;
        for(auto& [a,b]: v){
            auto [mn,mx] = a;
            if(b.size()==m) continue;
            if(mn <= val && val <= mx){
                b.push_back({str,val});
                flag = 1;
                break;
            }
        }

        if(flag) continue;
        vector<pair<string,int>> tmp;
        tmp.push_back({str,val});
        v.push_back({{val-10,val+10}, tmp});

    }

    for(auto& [a,b]: v){
        if(b.size()==m){
            cout<<"Started!\n";
        }
        else{
            cout<<"Waiting!\n";
        }
        sort(all(b));
        for(auto [x,y]:b){
            cout<<y<<' '<<x<<'\n';
        }
    }

}