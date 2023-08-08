#include <bits/stdc++.h>
using namespace std;
int arr[500][500];
void rotate(int idx, int n, int m){ 
    int tmp = arr[idx][idx];

    for(int i=idx;i<m-1;i++){
        arr[idx][i] = arr[idx][i+1];
    }
    for(int i=idx;i<n-1;i++){
        arr[i][m-1] = arr[i+1][m-1];
    }
    for(int i=m-1;i>idx;i--){
        arr[n-1][i] = arr[n-1][i-1];
    }
    for(int i=n-1;i>idx;i--){
        arr[i][idx] = arr[i-1][idx];
    }
    arr[idx+1][idx] = tmp;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n,m,r;
    cin>>n>>m>>r;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }

    int cnt = min(n/2,m/2);
    // int x = n;
    // int y = m;
    // rotate(0,x--,y--);
    // rotate(1,x--,y--);

    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         cout<<arr[i][j]<<' ';
    //     }
    //     cout<<'\n';
    // }
    while(r--){
        int x = n;
        int y = m;
        for(int i=0;i<cnt;i++){
            rotate(i,x--,y--);
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<arr[i][j]<<' ';
        }
        cout<<'\n';
    }
}


