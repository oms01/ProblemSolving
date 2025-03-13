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
ll dist(pll a, pll b){
    return (a.X-b.X)*(a.X-b.X) + (a.Y-b.Y)*(a.Y-b.Y);
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    pll a,b,c;
    cin>>a.X>>a.Y>>b.X>>b.Y>>c.X>>c.Y;

    if((a.Y-b.Y)*(b.X-c.X)==(a.X-b.X)*(b.Y-c.Y)){
        cout<<"X\n";
        return 0;
    }

    vector<ll> v(3); //변의 길이
    v[0] = dist(a,b);
    v[1] = dist(b,c);
    v[2] = dist(c,a);

    if(v[0]==v[1] && v[1]==v[2]){
        cout<<"JungTriangle\n";
        return 0;
    }
    
    sort(all(v));
    
    if(v[0] + v[1] < v[2]){
        cout<<"Dunkak";
    }
    else if(v[0] + v[1] == v[2]){
        cout<<"Jikkak";
    }
    else{
        cout<<"Yeahkak";
    }
    
    if(v[0]==v[1] || v[1] == v[2] || v[2]==v[0]){
        cout<<"2";
    }
    cout<<"Triangle\n";



}