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

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n,k; cin>>n>>k;
    vector<int> v(n);
    rep(i,0,n) cin>>v[i];

    // 가장 작은 제거가능한 숫자 = 최소값
    map<int,int> freq;
    for(auto x: v) freq[x]++;
    
    int mnMex = 0;
    for(;;mnMex++){
        if(freq[mnMex]<=k){
            break;
        }
    }
    
    
    //최대화하려면 무조건 정수 추가
    v.push_back(-1); v.push_back(2e9);
    sort(all(v));
    int cnt = k;
    int mxMex = 0;
    rep(i,0,v.size()-1){
        int need = v[i+1] - v[i] - 1;
        if(need<1) continue;

        //갭을 매꿀 수 없는 경우
        if(cnt<need){
            mxMex = v[i]+cnt+1;
            break;
        }
        //갭을 매꿀 수 있는 경우
        else{
            cnt-=need;
            mxMex = v[i+1]+1;
        }
    }

    cout<<mnMex<<'\n'<<mxMex<<'\n';


}