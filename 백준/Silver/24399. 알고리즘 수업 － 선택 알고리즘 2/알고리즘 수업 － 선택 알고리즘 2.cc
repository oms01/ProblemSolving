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

int N,Q,K;
int arr[10'001];
int cnt;
int partition(int s, int e){
    int x = arr[e];
    int i = s-1;

    for(int j = s;j<e;j++){
        if(arr[j]<=x){
            swap(arr[++i],arr[j]);
            cnt++;
            if(cnt==K){
                rep(I,0,N) cout<<arr[I]<<' ';
                exit(0);
            }
        }
    }
    if(i+1!=e){
        swap(arr[i+1],arr[e]);
        cnt++;
        if(cnt==K){
            rep(I,0,N) cout<<arr[I]<<' ';
            exit(0);
        }
    }
    return i+1;
}
int select(int s,int e, int q){
    if(s==e) return arr[s];
    int t = partition(s,e);
    int k = t-s+1;
    if(q<k) return select(s,t-1,q);
    else if(q==k) return arr[t];
    return select(t+1,e,q-k);
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>N>>Q>>K;
    rep(i,0,N) cin>>arr[i];
    select(0,N-1,Q);
    cout<<-1<<'\n';
}


