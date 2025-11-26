#include<bits/stdc++.h>
using namespace std;
using namespace std::chrono;
#define X first
#define Y second
#define rep(i,x,y) for(int i=x;i<y;i++)
#define REP(i,x,y) for(int i=x;i<=y;i++)
#define all(x) begin(x),end(x)
#define rall(x) rbegin(x),rend(x)
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pldld;
typedef tuple<int,int,int> ti3;
typedef tuple<ll,ll,ll> tl3;
typedef tuple<ll,ll,ll,ll> tl4;
typedef tuple<int,int,int,int> ti4;
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};
/*----------------------*/

bool f(int y){
    if(y%400==0) return 1;
    if(y%100==0) return 0;
    if(y%4==0) return 1;
    return 0;
}
int day[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    
    int n; cin>>n;
    int y = 2014, m = 4, d = 2;
    while(--n){
        d++;

        int tmp = day[m];
        if(m==2 && f(y)) tmp = 29;

        if(d>tmp){
            d = 1;
            m++;
            if(m>12){
                m = 1;
                y++;
            }
        }
    }

    cout<<setw(4)<<setfill('0')<<y<<'-';
    cout<<setw(2)<<setfill('0')<<m<<'-';
    cout<<setw(2)<<setfill('0')<<d;
}
