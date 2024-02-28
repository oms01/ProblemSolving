#include<bits/stdc++.h>
using namespace std;
#define X first 
#define Y second
#define rep(i,x,y) for(ll i=x;i<y;i++)
typedef long long ll;
typedef pair<int,int> pii;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
bool isPrime(ll n){
    if(n==1) return 0;
    for(ll i=2;i*i<=n;i++){
        if(n%i==0) return 0;
    }
    return 1;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--){
        ll n; cin>>n;
        if(n<3){
            cout<<"2\n";
            continue;
        }
        while(!isPrime(n)) n++;
        cout<<n<<'\n';
    }
}

