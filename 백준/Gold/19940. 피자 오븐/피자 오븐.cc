#include<bits/stdc++.h>
using namespace std;
#define X first 
#define Y second
#define rep(i,x,y) for(ll i=x;i<y;i++)
typedef long long ll;
typedef pair<int,int> pii;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
/*------------------------------*/
int ans[5];
void func(int n){
    bool flag = 0; //0: 줄여야, 1: 늘려야
    //ADDH
    int a = n/60;
    int b = n/60+1;
    ans[0]+=n/60;
    n%=60;
    if(n>35){ //줄여야
        ans[0]++;
        n = abs(n-60);
        if(n%10 > 5){ //줄여야
            ans[2] = n/10+1;
            ans[3] = 10-(n%10);
        }
        else{ //늘려야
            ans[2] = n/10;
            ans[4] = n%10;
        }
    }
    else{ //늘려야
        if(n%10 > 5){ //줄여야
            ans[1] = n/10 + 1;
            ans[4] = 10 - (n%10);
        }
        else{ //늘려야
            ans[1] = n/10;
            ans[3] = n%10;
        }
    }

}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        fill(ans,ans+5,0);
        func(n);
        rep(i,0,5) cout<<ans[i]<<' ';
        cout<<'\n';
    }

}
/*
ADDH +60
ADDT +10
MINT -10
ADDO +1
MINO -1
*/