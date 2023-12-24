#include<bits/stdc++.h>
using namespace std;
#define X first 
#define Y second
typedef long long ll;
typedef pair<ll,ll> pii;
vector<ll> ans;
void func(string str, int n){ //str의 뒤를 이어붙일 수 있는 n자리 감소하는 수
    if(n==0){
        ans.push_back(stoll(str));
        return;
    }
    int back = str[str.length()-1]-'0';
    for(int i=0;i<back;i++){
        string tmp = str + to_string(i);
        for(int j=0;j<n;j++){
            func(tmp,j);
        }
    }
    return;

}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    for(int i=0;i<=9;i++){
        ans.push_back(i);
        func(to_string(i),9);
    }
    sort(ans.begin(),ans.end());
    ans.erase(unique(ans.begin(),ans.end()),ans.end());
    ans.size() > n ? cout<<ans[n] : cout<<-1;
}