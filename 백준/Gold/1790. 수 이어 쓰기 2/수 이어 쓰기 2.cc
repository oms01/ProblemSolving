#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n,k;
    cin>>n>>k;


    int m = 10; //자릿수
    int c = 1; //추가될 길이 1 : 1, 10~99 : 2, 100~999 : 3
    int ans = -1;
    int s = 0; //전체 문자열 길이
    for(int i=1;i<=n;i++){
        if(i%m==0){
            m*=10;
            c++;
        }
        s+=c;
        if(s>=k){
            s-=k;
            string tmp = to_string(i);
            reverse(tmp.begin(),tmp.end());
            ans = tmp[s]-'0';
            break;
        }
    }
    cout<<ans<<'\n';
}


