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

    int n; cin>>n;
    deque<char> dq;
    stack<int> s; //1: back, 2: front
    while(n--){
        int q; cin>>q;
        if(q==1){
            char c; cin>>c;
            s.push(q);
            dq.push_back(c);
        }
        else if(q==2){
            char c; cin>>c;
            s.push(q);
            dq.push_front(c);
        }
        else{
            if(s.empty()) continue;
            int t = s.top(); s.pop();
            if(t==1){
                dq.pop_back();
            }
            else{
                dq.pop_front();
            }
        }
    }

    string str = "";
    while(!dq.empty()){
        str+=dq.front(); dq.pop_front();
    }
    if(str.empty()) str="0";
    cout<<str<<'\n';
}


