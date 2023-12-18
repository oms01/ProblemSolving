#include<bits/stdc++.h>
using namespace std;
#define X first 
#define Y second
typedef long long ll;
typedef pair<int,int> pii;
int n,m;
int cnt[100'001];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n>>m;
    vector<bool> state(100'001,true);
    state[0]=false;
    state[1]=false;
    for(int i=2;i<=100'000;i++){
        if(!state[i]) continue;
        for(int j=i*2;j<=100'000;j+=i){
            state[j]=false;
            int tmp = j;
            while(tmp%i==0){
                tmp/=i;
                cnt[j]++;
            }
        }
    }
    int ans = 0;
    for(int i=n;i<=m;i++){
        if(state[cnt[i]]) ans++;
    }
    cout<<ans<<'\n';
}