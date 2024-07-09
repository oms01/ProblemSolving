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

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    int n,m; cin>>n>>m;
    vector<int> a(n),b(m);
    rep(i,0,n) cin>>a[i];
    rep(i,0,m) cin>>b[i];

    rep(i,0,n-1) a.push_back(a[i]);
    rep(i,0,m-1) b.push_back(b[i]);

    vector<int> a_; //a로 만들 수 있는 모든 경우의 수
    int sum = 0;
    rep(i,0,n) sum+=a[i];
    a_.push_back(0);
    a_.push_back(sum);
    rep(i,0,n){
        sum=0;
        rep(j,0,n-1){
            sum+=a[i+j];
            a_.push_back(sum);
        }
    }
    sort(all(a_));

    map<int,int> b_; //b로 만들 수 있는 모든 경우의 수
    sum = 0;
    rep(i,0,m) sum+=b[i];
    b_[0]++;
    b_[sum]++;
    rep(i,0,m){
        sum=0;
        rep(j,0,m-1){
            sum+=b[i+j];
            b_[sum]++;
        }
    }

    int cnt = 0;
    rep(i,0,a_.size()){
        int target = t - a_[i];
        if(b_.find(target)!=b_.end()){
            cnt+=b_[target];
        }
    }
    cout<<cnt<<'\n';

}