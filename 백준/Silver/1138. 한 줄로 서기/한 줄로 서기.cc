#include<bits/stdc++.h>
using namespace std;
#define X first 
#define Y second
typedef long long ll;
typedef pair<int,int> pii;
int n;
int arr[10];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<int> v;
    for(int i=1;i<=n;i++) v.push_back(i);

    do{
        bool flag = 1;
        for(int i=0;i<n;i++){
            int cnt = 0; // 왼쪽에 키 큰 사람 수
            for(int j=0;j<i;j++){
                if(v[i] < v[j]) cnt++;
            }
            if(arr[v[i]-1]!=cnt){
                flag = 0;
            }
        }
        if(flag){
            for(int i=0;i<n;i++){
                cout<<v[i]<<' ';
            }
            cout<<'\n';
            break;
        }
        
    }while(next_permutation(v.begin(),v.end()));
}