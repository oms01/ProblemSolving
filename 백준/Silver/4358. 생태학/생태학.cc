#include<bits/stdc++.h>
using namespace std;
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
typedef tuple<int,int,int> tiii;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
/*----------------------*/

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    map<string,ld> ma;
    string s;
    ld sum = 0;
    while(getline(cin,s)){
        sum++;
        ma[s]++;
    }

    for(auto [a,b]: ma){
        cout<<fixed;
        cout.precision(4);
        cout<<a<<' '<<b*100/sum<<'\n';
    }
}