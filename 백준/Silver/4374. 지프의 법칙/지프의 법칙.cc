#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define rep(i,x,y) for(ll i=x;i<y;i++)
#define REP(i,x,y) for(ll i=x;i<=y;i++)
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

vector<string> parse(string s){
    for(auto& x: s){
        if('A'<=x&&x<='Z'){
            x = x-'A'+'a';
        }
    }
    
    vector<string> ret;
    string tmp = "";
    for(auto x: s){
        if(!('a'<=x&&x<='z')){
            if(tmp=="") continue;
            ret.push_back(tmp);
            tmp="";
        }
        else{
            tmp+=x;
        }
    }

    if(tmp!="") ret.push_back(tmp);
    return ret;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    while(cin>>n){
        map<string,int> m;
        string s;
        while(cin>>s){
            if(s=="EndOfText") break;
            for(auto x: parse(s)){
                m[x]++;
            }
        }
        vector<string> ans;
        for(auto [a,b]:m){
            if(b==n) ans.push_back(a);
        }

        if(ans.empty()){
            cout<<"There is no such word.\n";
        }
        else{
            sort(all(ans));
            for(auto x: ans) cout<<x<<'\n';
        }
        cout<<'\n';

    }

}