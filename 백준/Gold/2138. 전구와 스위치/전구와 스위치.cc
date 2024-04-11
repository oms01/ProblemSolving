#include<bits/stdc++.h>
using namespace std;
#define X first 
#define Y second
#define rep(i,x,y) for(ll i=x;i<y;i++)
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
/*------------------------------*/


int n;
string bef,aft;
void toggle(int i){
    if(i<0 || i>=n) return;
    bef[i] = "10"[bef[i]-'0'];
}
int func(){
    string tmp = bef;
    int cnt = 0;
    for(int i=0;i<n-1;i++){
        if(bef[i]!=aft[i]){
            cnt++;
            toggle(i); toggle(i+1); toggle(i+2);
        }
    }
    swap(tmp,bef);
    if(tmp!=aft) return -1e9;
    return cnt;

}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n>>bef>>aft;

    int a = func();
    toggle(0); toggle(1);
    int b = func()+1;
    if(a+b < -1e9) cout<<-1<<'\n';
    else if(a+b<0) cout<<max(a,b)<<'\n';
    else cout<<min(a,b)<<'\n';

}
