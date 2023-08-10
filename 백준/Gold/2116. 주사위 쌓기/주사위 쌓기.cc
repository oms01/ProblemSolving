#include <bits/stdc++.h>
using namespace std;
int arr[10001][10];
int FindOpposite(int n,int opp){ //n번째 주사위에 대해서 opp의 반대편 숫자 구하기
    int idx = find(arr[n],arr[n]+6,opp)-arr[n]; //opp의 인덱스 가져옴
    if(idx==0) return arr[n][5];
    else if(idx==1) return arr[n][3];
    else if(idx==2) return arr[n][4];
    else if(idx==3) return arr[n][1];
    else if(idx==4) return arr[n][2];
    else return arr[n][0];
}
int findNearMax(int n, int a, int b){ //n번째 주사위에서 a,b를 제외한 나머지 원소들 중 가장 큰 값
    int aidx = find(arr[n],arr[n]+6,a)-arr[n];
    int bidx = find(arr[n],arr[n]+6,b)-arr[n];
    int ret = 0;
    for(int i=0;i<6;i++){
        if(i==aidx || i==bidx) continue;
        ret = max(ret,arr[n][i]);
    }
    return ret;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<6;j++){
            cin>>arr[i][j];
        }
    }
    int ans = 0;
    for(int i=0;i<6;i++){
        int sum = 0;
        int a,b;
        for(int j=0;j<n;j++){
            a = (j==0) ? arr[j][i] : b; // j번째 주사위의 아래
            b = FindOpposite(j,a); //j번째 주사위의 위
            sum += findNearMax(j,a,b);
        }
        ans = max(ans,sum);
    }
    cout<<ans<<'\n';
}


