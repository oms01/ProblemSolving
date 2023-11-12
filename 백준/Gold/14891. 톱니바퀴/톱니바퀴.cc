#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<string> v(4);
void spin(int idx,int dir){ //dir=-1: 반시계, dir=1: 시계
    if(dir==-1){
        char tmp = v[idx][0];
        for(int i=1;i<8;i++) v[idx][i-1] = v[idx][i];
        v[idx][7] = tmp;
    }
    else{
        char tmp = v[idx][7];
        for(int i=7;i>0;i--) v[idx][i] = v[idx][i-1];
        v[idx][0] = tmp;
    }
    return;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    for(int i=0;i<4;i++) cin>>v[i];
    int k;
    cin>>k;
    while(k--){
        int a,b;
        cin>>a>>b;
        a--;
        vector<int> arr(4,0);
        arr[a] = b;

        //right
        int cur = a;
        int nxt = a+1;
        while(nxt < 4){
            if(v[cur][2] == v[nxt][6]) break;
            arr[nxt] = (arr[cur]==-1 ? 1 : -1);
            nxt++; cur++;
        }
        //left
        cur = a;
        nxt = a-1;
        while(nxt >= 0){
            if(v[cur][6] == v[nxt][2]) break;
            arr[nxt] = (arr[cur]==-1 ? 1 : -1);
            nxt--; cur--;
        }
        for(int i=0;i<4;i++){
            if(arr[i]==0) continue;
            spin(i,arr[i]);
        }
        // for(auto x:arr){
        //     cout<<x<<' ';
        // }
        // cout<<'\n';
    }


    int ans = 0;
    for(int i=0;i<4;i++){
        if(v[i][0]=='0') continue;
        ans+=(1<<i);
    }
    cout<<ans<<'\n';
}