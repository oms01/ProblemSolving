#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define rep(i,x,y) for(int i=x;i<y;i++)
#define all(x) begin(x),end(x)
#define rall(x) rbegin(x),rend(x)
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
/*----------------------*/

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int b; cin>>b;
    unordered_set<string> hi,lo;
    rep(i,0,b){
        string str; cin>>str;
        hi.insert(str);
    }
    rep(i,0,b){
        string str; cin>>str;
        lo.insert(str);
    }

    int n; cin>>n;
    rep(i,0,n){
        string str; cin>>str;
        int ans = 0;
        for(int j=0;j<str.length();j++){
            for(int k=3;k<=50;k++){
                if(j+k>str.length()) break;
                string tmp = str.substr(j,k);
                if(hi.find(tmp)!=hi.end()) ans++;
                if(lo.find(tmp)!=lo.end()) ans--;
            }
        }
        if(ans==0) cout<<"GOOD\n";
        else if(ans<0) cout<<"LOW "<<-ans<<'\n';
        else cout<<"HIGH "<<ans<<'\n';
    }
}