#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
typedef long long ll;
typedef pair<int,int> pii;
int n;
ll node[1'000'001];
ll tree[1'000'001];
ll arr[1'000'001];
void update(ll i, ll diff){
    while(i<=n){
        tree[i]+=diff;
        i+=(i&-i);
    }
}
ll query(ll i){
    ll sum = 0;
    while(i>0){
        sum+=tree[i];
        i-=(i&-i);
    }
    return sum;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    for(int i=1;i<=n;i++){
        int a; cin>>a;
        node[a] = i;
    }
    ll ans = 0;
    for(int i=1;i<=n;i++){
        update(node[arr[i]],1);
        ans += i-query(node[arr[i]]);
    }
    cout<<ans<<'\n';
}