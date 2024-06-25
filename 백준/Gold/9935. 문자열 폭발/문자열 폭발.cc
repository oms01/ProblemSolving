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

    string str,pat; cin>>str>>pat;
    vector<char> v;
    rep(i,0,str.length()){
        v.push_back(str[i]);
        if(v.size() >= pat.size() && str[i]==pat[pat.size()-1]){
            bool flag = 0;
            rep(j,0,pat.size()) flag += (v[v.size()-j-1]!=pat[pat.size()-1-j]);

            if(!flag){
                rep(i,0,pat.size()) v.pop_back();
            }
        }
    }
    if(v.empty()) cout<<"FRULA\n";
    rep(i,0,v.size()) cout<<v[i];

}