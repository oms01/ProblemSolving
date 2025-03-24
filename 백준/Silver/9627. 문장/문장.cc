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
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef tuple<int,int,int> tiii;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
/*----------------------*/
vector<string> numbers;
void init(){
    vector<string> one = {"","one","two","three","four","five","six","seven", "eight","nine"};
    vector<string> teen = {"ten","eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen"};
    vector<string> ty = {"twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
    
    for(int I=0;I<=9;I++){
        string hun = "";
        if(I!=0) hun = numbers[I]+"hundred";
        for(auto x: one){
            numbers.push_back(hun + x);
        }
        for(auto x: teen){
            numbers.push_back(hun + x);
        }
        for(auto x: ty){
            for(int i=0;i<=9;i++){
                string s = x+numbers[i];
                numbers.push_back(hun + s);
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    init();


    int n; cin>>n;
    int sum = 0;
    int idx = -1;
    vector<string> v(n);
    rep(i,0,n){
        cin>>v[i];
        if(v[i]=="$"){
            idx = i;
            continue;
        }
        sum += v[i].length();
    }

    REP(i,1,numbers.size()){
        if(numbers[i].length() + sum == i){
            rep(j,0,n){
                if(j==idx) cout<<numbers[i]<<' ';
                else cout<<v[j]<<' ';
            }
            return 0;
        }
    }    


}