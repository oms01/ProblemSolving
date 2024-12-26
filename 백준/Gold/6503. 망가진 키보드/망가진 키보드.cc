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

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    
    int n; string str;
    while(1){
        cin>>n;
        if(n==0) break;
        cin.ignore();
        getline(cin,str);

        map<int,int> m;
        
        int st = 0;
        int en = 0;
        while(m.size()<n && en<str.length()){
            m[str[en++]]++;
        }

        int ans = en-st;
        for(;en<str.length();en++){
            m[str[en]]++;
            
            if(m.size()>n){
                m[str[st++]]--;
                if(m[str[st-1]]==0) m.erase(str[st-1]);
            }
            ans = max(ans,en-st+1);
        }

        cout<<ans<<'\n';
    }
}
