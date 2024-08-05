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
typedef tuple<int,int,int> tiii;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
/*----------------------*/
bool chk(vector<int> a, vector<int> b){
    rep(i,0,a.size()){
        if(a[i]!=b[i]) return 0;
    }
    return 1;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int tc; cin>>tc;
    while(tc--){
        string a,b; cin>>a>>b;
        vector<int> mask(30,0);
        rep(i,0,b.size()){
            int n = b[i]-'a';
            mask[n]++;
        }
        vector<int> cur(30,0);
        rep(i,0,b.size()){
            int n = a[i]-'a';
            cur[n]++;
        }
        bool flag = 0;
        if(chk(cur,mask)){
            flag = 1;
        }
        for(int i=b.size();i<a.size();i++){
            int front = a[i]-'a';
            int back = a[i-b.size()]-'a';
            cur[front]++;
            cur[back]--;
            if(chk(cur,mask)){
                flag = 1;
                break;
            }
        }

        if(flag) cout<<"YES\n";
        else cout<<"NO\n";

    }

    

}
