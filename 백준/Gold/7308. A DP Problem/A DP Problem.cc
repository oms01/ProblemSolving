#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define rep(i,x,y) for(int i=x;i<y;i++)
#define all(x) begin(x),end(x)
#define rall(x) rbegin(x),rend(x)
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
/*----------------------*/

pll f(string str){
    //{(상수,계수) 여부 , 값}
    return {str[str.length()-1]=='x', (str[str.length()-1]!='x' ? stoll(str) :
        str=="x" ? 1 : stoll(str.substr(0,str.length()-1)))};
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    ll t; cin>>t;
    while(t--){
        string str; cin>>str;

        ll c=0, x=0;//상수 합계, 계수 합계
        bool rev = 0; // = 이전 0, 이후 1
        bool flag = 1; // 0이면 음수, 1이면 양수
        string cur = "";
        rep(i,0,str.length()){

            //항의 첫 시작이 부호인 경우
            if((i==0||str[i-1]=='=')&&(str[i]=='-'||str[i]=='+')){
                flag = (str[i]!='-');
            }

            else if(str[i]=='+' || str[i]=='-' || str[i]=='='){
                pll ret = f(cur);
                ll n = (flag ? ret.Y : -1*ret.Y) * (rev ? -1 : 1);
                ret.X ? x+=n : c+=n;
                flag = (str[i]!='-');
                rev = (rev||str[i]=='=');
                cur="";
            }
            else cur+=str[i];


        }
        pll ret = f(cur);
        ll n = (flag ? ret.Y : -1*ret.Y) * (rev ? -1 : 1);
        ret.X ? x+=n : c+=n;

        if(x==0) cout<<(c!=0 ? "IMPOSSIBLE\n" : "IDENTITY\n");
        else cout<<-1*c/x - (c%x!=0 && -1*c/x<0)<<'\n';
    }
    
}