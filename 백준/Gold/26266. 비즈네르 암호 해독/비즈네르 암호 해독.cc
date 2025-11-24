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

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    string a,b; cin>>a>>b;

    int len = a.length();
    vector<int> v(len);
    rep(i,0,len){
        v[i] = b[i] - a[i];
        if(v[i]<1) v[i]+=26;
    }

    int l = len;
    REP(i,1,len){
        if(len%i) continue;
        bool flag = 1;
        for(int j=0;j+i<len;j++){
            if(v[j]!=v[j+i]) flag = 0;
        }
        if(flag){
            l = i;
            break;
        }
    }
    rep(i,0,l){
        cout<<(char)(v[i]+'A'-1);
    }

}