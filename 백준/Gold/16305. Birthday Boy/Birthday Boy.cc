#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define rep(i,x,y) for(ll i=x;i<y;i++)
#define all(x) begin(x),end(x)
#define rall(x) rbegin(x),rend(x)
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef tuple<int,int,int> tiii;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
/*----------------------*/

int a[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
int s[13] = {0,};
int conv(string date){
    int m = stoi(date.substr(0,2));
    int d = stoi(date.substr(3,2));
    return s[m-1] + d;
}
string conv2(int date){
    int m = 0;
    int d = 0;
    rep(i,1,13){
        if(s[i] >= date){
            m = i;
            d = date-s[i-1];
            break;
        }
    }
    string a = (m<10 ? "0": "") + to_string(m);
    string b = (d<10 ? "0": "") + to_string(d);
    return a+"-"+b;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    rep(i,1,13) s[i] = s[i-1] + a[i];

    int n; cin>>n;
    vector<int> v;
    int cur = conv("10-27");
    

    rep(i,0,n){
        string name,date; cin>>name>>date;
        v.push_back(conv(date));
    }

    if(n==1){
        if(v[0]==1) v[0]+=s[12];
        cout<<conv2(v[0]-1)<<'\n';
        return 0;
    }
    
    sort(all(v));
    v.push_back(v[0]+s[12]);

    //최대 차이 찾기
    int mx = -1;
    rep(i,1,v.size()){
        mx = max(mx,v[i]-v[i-1]);
    }


    //정답 후보 찾기
    vector<int> tmp;
    rep(i,1,v.size()){
        if(v[i]-v[i-1]==mx){
            if(v[i]==1) v[i] += s[12];
            tmp.push_back(v[i]-1);
        }
    }

    //정답이 단 하나
    if(tmp.size()==1){
        if(tmp[0]>s[12]) tmp[0]-=s[12];
        cout<<conv2(tmp[0])<<'\n';
        return 0;
    }

    //무승부 처리
    rep(i,0,tmp.size()){
        if(tmp[i]<=cur) continue;

        if(tmp[i]>s[12]) tmp[i]-=s[12];
        cout<<conv2(tmp[i])<<'\n';
        return 0;
    }

    
}