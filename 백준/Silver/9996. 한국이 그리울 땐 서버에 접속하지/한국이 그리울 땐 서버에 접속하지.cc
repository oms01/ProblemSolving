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

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    string pat; cin>>pat;

    int idx = 0;
    while(pat[idx]!='*') idx++;

    string l = pat.substr(0,idx);
    string r = pat.substr(idx+1,pat.length());


    while(t--){
        string str; cin>>str;
        if(str.length() < pat.length()-1){
            cout<<"NE\n";
            continue;
        }
        
        bool flag = 0;
        for(int i=0;i<l.length();i++){
            if(str[i]!=l[i]){
                flag = 1;
                break;
            }
        }
        
        for(int i=0;i<r.length();i++){
            if(str[str.length()-1-i]!=r[r.length()-1-i]){
                flag = 1;
                break;
            }
        }

        cout<<(flag?"NE\n":"DA\n");
    }
}