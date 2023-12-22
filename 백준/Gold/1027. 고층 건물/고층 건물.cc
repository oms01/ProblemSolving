#include<bits/stdc++.h>
using namespace std;
#define X first 
#define Y second
typedef long long ll;
typedef pair<ll,ll> pii;
int n;
int board[51];
int ans[51];
pii arr[51][51]; //기울기 (y증가량 / x증가량)
int cmp(pii a, pii b){
    return a.Y*b.X - a.X*b.Y == 0 ? 0 : a.Y*b.X - a.X*b.Y > 0 ? 1 : -1;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    for(int i=0;i<n;i++){
        int h; cin>>h;
        board[i] = h;
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j) continue;
            arr[i][j] = {board[i]-board[j],i-j};
        }
    }
    for(int i=0;i<n;i++){

        for(int j=i+1;j<n;j++){
            if(i==j) continue;

            bool flag = 1;
            for(int k=i+1;k<j;k++){

                if(cmp(arr[i][k], arr[i][j])!=1){ 
                    flag = 0;
                    break;
                }

                // if(board[i] < board[j]){ //양수 기울기
                //     // cout<<arr[i][k].X<<' '<<arr[i][k].Y<<'\n';
                //     // cout<<arr[i][j].X<<' '<<arr[i][j].Y<<'\n';
                //     // cout<<cmp(arr[i][k], arr[i][j])<<'\n';
                //     if(cmp(arr[i][k], arr[i][j])!=1){ 
                //         flag = 0;
                //         break;
                //     }
                // }
                // if(board[i] > board[j]){ //음수 기울기
                //     swap(i,j);
                //     // cout<<arr[i][k].X<<' '<<arr[i][k].Y<<'\n';
                //     // cout<<arr[i][j].X<<' '<<arr[i][j].Y<<'\n';
                //     // cout<<cmp(arr[i][k], arr[i][j])<<'\n';
                //     if(cmp(arr[i][k],arr[i][j])!=1){
                //         flag = 0;
                //         break;
                //     }
                //     swap(i,j);
                // }
                // else{
                //     cout<<"!";
                // }
            }
            // cout<<i<<' '<<j<<" : "<<flag<<'\n';
            if(flag){
                ans[i]++;
                ans[j]++;
            }
        }
    }
    int mx = 0;
    for(int i=0;i<n;i++){
        // cout<<ans[i]<<' ';
        mx = max(mx,ans[i]);
    }
    // cout<<'\n';
    cout<<mx<<'\n';
    // cout<<max_element(ans,ans+n)-ans;

}