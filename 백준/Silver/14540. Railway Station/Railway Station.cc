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
int n;
string sol(vector<int> v){
    int tmp = n;
    stack<int> s;
    rep(i,0,n){
        s.push(v.back()); v.pop_back();
        while(!s.empty() && s.top()==tmp){
            tmp--;
            s.pop();
        }
    }
    return (s.empty()?"Yes\n":"No\n");
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    while(cin>>n){
        vector<int> v(n);
        while(cin>>v[0]){
            if(!v[0]) break;
            rep(i,1,n) cin>>v[i];
            cout<<sol(v);
        }
        cout<<'\n';
    }

}