#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 100'007
string str;
int l;
bool cmp(int s1,int s2,int len){
    for(int i=0;i<len;i++){
        if(str[s1+i]!=str[s2+i]) return false;
    }
    return true;
}
bool chk(int len){
    ll hash = 0;
    ll pwr = 1;
    vector<vector<int>> v(500'001);
    for(int i=len-1;i>=0;i--){ //처음부터 len까지의 문자열의 해시값
        hash += (str[i]-'a')*pwr % MOD;
        if(i!=0) pwr = pwr * 5 % MOD;
    }
    hash%=MOD;
    v[hash].push_back(0);

    for(int i=len;i<l;i++){
        hash -= pwr*(str[i-len]-'a');
        if(hash<0) hash+=MOD;
        hash %= MOD;
        hash *= 5;
        if(hash<0) hash+=MOD;
        hash %= MOD; 
        hash += str[i]-'a';
        if(hash<0) hash+=MOD;
        hash %= MOD;

        if(v[hash].size()){
            for(int idx : v[hash]){
                if(cmp(idx,i-len+1,len)){
                    return true;
                }
            }
        }

        v[hash].push_back(i-len+1);
    }
    return false;
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin>>l;
    cin>>str;
    int ans = 0;
    //문자열 길이
    int st = 0, en = l;

    while(st<en){
        int mid = (st+en)/2;
        //cout<<mid<<'\n';
        if(chk(mid)){ //두번 이상 등장한 부분 문자열 존재 -> mid 커져야
            ans = max(ans,mid);
            st = mid + 1;
        }
        else{ //mid 작아져야
            en = mid;
        }
        //cout<<'\n';
    }
    cout<<ans<<'\n';
}

