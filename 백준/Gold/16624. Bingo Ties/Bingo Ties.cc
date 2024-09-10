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
    int n; cin>>n;
    vector<vector<int>> loc(n,vector<int>(3001,-1));
    vector<vector<int>> board(n);
    rep(i,0,n){
        rep(j,0,25){
            int x; cin>>x;
            board[i].push_back(x);
            loc[i][x] = j/5;

        }
    }

    rep(i,0,n) rep(j,i+1,n){
        rep(idx,0,25){
            if(loc[i][board[j][idx]]==-1) continue;
            //값 board[j][idx]가 중복
            //i에서 중복값의 행은 loc[i][board[j][idx]]
            //j에서 중복값의 행은 idx/5;

            set<int> s;
            int i_col = loc[i][board[j][idx]];
            int j_col = idx/5;
            // cout<<board[j][idx]<<'\n';
            rep(x,0,5){
                s.insert(board[i][i_col*5+x]);
                s.insert(board[j][j_col*5+x]);
            }
            s.erase(board[j][idx]);
            // for(auto x: s) cout<<x<<' '; cout<<'\n';

            bool f = 0;
            //i와 j를 제외한 다른 보드에서 set만으로 빙고가 만들어지는지 check
            rep(I,0,n){
                if(I==i||I==j) continue;
                rep(r,0,5){
                    int cnt = 0;
                    rep(c,0,5){
                        cnt += (s.find(board[I][r*5+c])!=s.end());
                    }
                    if(cnt==5){
                        f = 1;
                        break;
                    }
                }
                if(f) break;
            }
            if(!f){
                cout<<i+1<<' '<<j+1<<'\n';
                return 0;
            }

        }
    }
    cout<<"no ties\n";
}