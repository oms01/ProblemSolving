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

    string a,b; cin>>a>>b;
    if(a.length() > b.length()) swap(a,b);
    int alen = a.length();
    int blen = b.length();

    string padding = "";
    rep(i,0,a.length()) padding+="1";

    b = padding + b + padding;

    int mn = alen+blen;
    for(int i=0;i<b.length()-a.length()+1;i++){

        string tmp = b;
        for(int j=0;j<a.length();j++){
            tmp[i+j] += a[j]-'0';
        }
        int mx = *max_element(all(tmp))-'0';
        
        int len = alen+blen;
        if(mx<=3){
            if(i<alen) len = alen+blen-i;
            else if(i<blen) len = blen;
            else len = i;
        }
        // cout<<tmp<<": "<<len<<'\n';
        mn = min(mn, len);
    }
    cout<<mn<<'\n';
}