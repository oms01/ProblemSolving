#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int arr[] = {0,9,9,90,90,900,900,9000,9000,90000,90000};
int ans;
ll n;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    int len = to_string(n).length();
    for(int i=0;i<len;i++){
        ans+=arr[i];
    }
    
    if(len == 1){
        cout<<n<<'\n';
        return 0;
    }

    int half = (len+1)/2;
    int N=1;
    for(int i=0;i<half-1;i++){
        N*=10;
    }
    if(len%2){ //홀수
        while(1){
            string front = to_string(N);
            string back = to_string(N/10);
            reverse(back.begin(),back.end());
            front+=back;
            if(stoll(front) > n) break;
            ans++;
            N++;
        }
    }
    else{ //짝수
        while(1){
            string front = to_string(N);
            string back = to_string(N);
            reverse(back.begin(),back.end());
            front+=back;
            if(stoll(front) > n) break;
            ans++;
            N++;
        }
    }
    cout<<ans<<'\n';
    return 0;
}