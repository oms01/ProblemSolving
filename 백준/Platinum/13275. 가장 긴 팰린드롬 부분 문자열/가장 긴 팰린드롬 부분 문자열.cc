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
typedef tuple<int,int,int> tiii;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
/*----------------------*/

int A[500'001];
void manachers(string str){
    int r = 0, c = 0;
    rep(i,0,str.length()){

        A[i] = (i<=r ? min(A[2*c-i],r-i) : 0);

        while(i-A[i]-1>=0 && i+A[i]+1<str.length() && str[i-A[i]-1]==str[i+A[i]+1]){
            A[i]++;
        }
        if(r<i+A[i]){
            r = i + A[i];
            c = i;
        }
    }
}   
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    string input; cin>>input;
    string str="";
    rep(i,0,input.size()){
        str+='#';
        str+=input[i];
    }
    str+='#';

    manachers(str);

    cout<<*max_element(A,A+str.length())<<'\n';
}
