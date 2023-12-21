#include<bits/stdc++.h>
using namespace std;
#define X first 
#define Y second
typedef long long ll;
typedef pair<int,int> pii;
int dx[] = {-1,-1,-1,0,0,1,1,1};
int dy[] = {-1,0,1,-1,1,-1,0,1};
string board[11];
int n,m;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n>>m;
    for(int i=0;i<n;i++) cin>>board[i];
    int ans = -1;
    for(int i=0;i<n;i++){ //기준점
        for(int j=0;j<m;j++){ //기준점

            for(int k=-10;k<=10;k++){ //열 공차
                for(int l=-10;l<=10;l++){ //행 공차

                    for(int dir=0;dir<8;dir++){ //방향
                        string s="";
                        for(int cnt=0;cnt<9;cnt++){ //글자수
                            int nx = i + dx[dir]*k*cnt;
                            int ny = j + dy[dir]*l*cnt;
                            if(nx<0||nx>=n||ny<0||ny>=m) break;
                            s+=board[nx][ny];
                            int a = stoi(s);
                            if((int)sqrt(a)*(int)sqrt(a)==a) ans = max(ans,a);
                            // else continue;
                            // cout<<a<<' ';
                        }
                    }

                }
            }
        }
    }
    cout<<ans<<'\n';

}