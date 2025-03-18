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

ll add(ll a,ll b){ return (a+b>2e9 ? 2e9 : a+b);}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int n,k; cin>>n>>k;
    vector<int> v(n+1,0);
    REP(i,1,n) cin>>v[i];

    //i로 시작하는 lis최대 길이, i로 시작하는 lis 개수
    vector<ll> lis(n+1), dp(n+1);
    for(int i=n;i>=1;i--){
        lis[i] = dp[i] = 1;
        for(int j=i+1;j<=n;j++){
            if(v[i]<v[j]){
                if(lis[i]<lis[j]+1){
                    lis[i] = lis[j] + 1;
                    dp[i] = 0;
                }
                if(lis[i]==lis[j]+1){
                    dp[i] = add(dp[i],dp[j]);
                    // dp[i]+=dp[j];
                }
            }
        }
    }

    int mx = *max_element(all(lis));
    vector<vector<int>> I(mx+1,vector<int>(0));
    REP(i,1,n) I[lis[i]].push_back(i);
    REP(i,1,mx){
        sort(all(I[i]),[v](int a,int b){
            return v[a]<v[b];
        });
    }

    int sum = 0;
    for(int j:I[mx]) sum = add(sum,dp[j]);
    if(sum<k){
        cout<<-1<<'\n';
        return 0;
    }

    for(int i=mx, prv = 0; i; i--){
        for(int j:I[i]){
            if(prv<j && v[prv]<v[j]){
                if(k>dp[j]) k-=dp[j];
                else{
                    cout<<v[prv=j]<<' ';
                    break;
                }
            }
        }
    }
    cout<<'\n';

}