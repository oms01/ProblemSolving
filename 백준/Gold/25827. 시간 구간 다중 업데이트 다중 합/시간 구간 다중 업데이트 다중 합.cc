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

const int MX = 100'000;
ll arr[MX+1];
int conv(string str){
    int h = stoi(str.substr(0,2));
    int m = stoi(str.substr(3,2));
    int s = stoi(str.substr(6,2));
    return h*60*60 + m*60 + s;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    bool flag = 0;
    while(n--){
        ll a; string st, en;
        cin>>a>>st>>en;
        if(a==1){
            arr[conv(st)+1]++;
            arr[conv(en)+1]--;
        }
        else{
            if(!flag){
                flag = 1;
                rep(i,1,MX) arr[i] += arr[i-1];
                rep(i,1,MX) arr[i] += arr[i-1];
            }

            cout<<arr[conv(en)]-arr[conv(st)]<<'\n';
        }
    }
}