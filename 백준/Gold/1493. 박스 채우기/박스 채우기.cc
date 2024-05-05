#include<bits/stdc++.h>
using namespace std;
#define X first 
#define Y second
#define rep(i,x,y) for(int i=x;i<y;i++)
#define all(x) begin(x),end(x)
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
/*------------------------------*/

int arr[21];
ll ans;
void func(int len, int wid, int hei){
    if(len==0 || wid==0 || hei==0) return;

    //넣을 수 있는 가장 큰 큐브 찾기
    int tmp = log2(min({len,wid,hei}));
    bool flag = 0;
    for(tmp;tmp>=0;tmp--){
        if(arr[tmp]>0){
            flag = 1;
            break;
        }
    }

    if(!flag){
        cout<<-1<<'\n';
        exit(0);
    }
    // cout<<len<<' '<<wid<<' '<<hei<<" : "<<val<<'\n';
    // cout<<val<<' ';
    arr[tmp]--;
    ans++;
    tmp = 1<<tmp;

    func(len-tmp, wid, hei);
    func(tmp, wid, hei-tmp);
    func(tmp, wid-tmp, tmp);

}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int l,w,h; cin>>l>>w>>h;
    int n; cin>>n;
    rep(i,0,n){
        int a,b; cin>>a>>b;
        arr[a] = b;
    }
    func(l,w,h);
    cout<<ans<<'\n';
}