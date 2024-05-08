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
/*------------------------------*/

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    
    int n; cin>>n;
    stack<int> s;
    vector<char> ans;
    int cur = 1;
    rep(i,0,n){
        int x; cin>>x;
        while(1){
            if(cur>n+1){
                cout<<"NO\n";
                return 0;
            }
            if(!s.empty() && s.top()==x){
                s.pop();
                ans.push_back('-');
                break;
            }
            s.push(cur++);
            ans.push_back('+');
        }
    }
    rep(i,0,ans.size()){
        cout<<ans[i]<<'\n';
    }

}