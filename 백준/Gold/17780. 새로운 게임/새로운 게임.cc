#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
typedef long long ll;
typedef pair<int,int> pii;
int dx[] = {0,0,-1,1}; //우 좌 상 하
int dy[] = {1,-1,0,0};
int input[15][15]; // 0:흰, 1:빨, 2:파
vector<pii> board[15][15];
int n,k;
int ans;
//이동하려는 칸이 흰색이면 이동 
//이동하려는 칸이 빨간색이면 말이 쌓인 순서 reverse
//이동하려는 칸이 파란색/범위밖이면 이동방향 반대로 + 한칸 이동
	//방향바꿔 이동하려는 칸이 파란색이면 이동 X
//말이 4개 이상 쌓이면 종료
void print(){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<board[i][j].size()<<' ';
		}
		cout<<'\n';
	}
}
pii getPos(int idx){ //idx번 말의 위치 return
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			for(int k=0;k<board[i][j].size();k++){
				if(board[i][j][k].X==idx){
					return {i,j};
				}
			}
		}
	}
	return {-1,-1};
}
vector<pii> group(pii pos, int idx){ //idx와 같이 움직일 말의 번호, 방향 return
	vector<pii> ret;
	vector<pii> cur = board[pos.X][pos.Y];
	bool flag = 0;
	for(int i=0;i<cur.size();i++){
		if(cur[i].X==idx){
			flag = 1;
		}
		if(flag){
			ret.push_back(cur[i]);
		}
	}

	return ret;
}
void whiteMove(int x, int y, int nx, int ny, vector<pii> s){
	for(int i=0;i<s.size();i++){
		board[nx][ny].push_back(s[i]);
		board[x][y].pop_back();
	}
	return;
}
void redMove(int x, int y, int nx, int ny, vector<pii> s){
	reverse(s.begin(),s.end());
	whiteMove(x,y,nx,ny,s);
	return;
}
void blueMove(int x, int y, int dir, vector<pii> s){
	if(dir==0) dir = 1;
	else if(dir==1) dir = 0;
	else if(dir==2) dir = 3;
	else if(dir==3) dir = 2;

	s[0].Y = dir;
	board[x][y][board[x][y].size() - s.size()].Y = dir;

	int nx = x + dx[dir];
	int ny = y + dy[dir];

	if(nx<0||nx>=n||ny<0||ny>=n){//파랑
		return;
	} 
	else if(input[nx][ny]==0){//하양
		whiteMove(x,y,nx,ny,s);
	}
	else if(input[nx][ny]==1){//빨강
		redMove(x,y,nx,ny,s);
	}
	return;

}
bool isDone(){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(board[i][j].size()>=4){
				return true;
			}
		}
	}
	return false;
}

bool func(){
	bool flag = 0;
	for(int i=1;i<=k;i++){
		// print();
		// cout<<'\n';
		pii pos = getPos(i);
		vector<pii> s = group(pos, i);
		if(board[pos.X][pos.Y].size() != s.size()) continue;
		if(s.size()>=4) break;
		int dir = s[0].Y;
		int nx = pos.X + dx[dir];
		int ny = pos.Y + dy[dir];
		// cout<<s[0].X<<"("<<dir<<","<<s.size()<<")"<<' '<<"{"<<pos.X<<' '<<pos.Y<<"} -> {"<<nx<<' '<<ny<<"} : ";
		if(nx<0||nx>=n||ny<0||ny>=n){ //파란색
			blueMove(pos.X,pos.Y,dir,s);
		}
		else if(input[nx][ny]==2){ //파랑
			blueMove(pos.X,pos.Y,dir,s);
		}
		else if(input[nx][ny]==0){ //흰색
			whiteMove(pos.X,pos.Y,nx,ny,s);
		}
		else if(input[nx][ny]==1){ //빨간색
			redMove(pos.X,pos.Y,nx,ny,s);
		}

		if(isDone()){
			flag = 1;
			break;
		}
	}
	return flag;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	cin>>n>>k;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++) cin>>input[i][j];
	}
	for(int i=1;i<=k;i++){
		int x,y,d;
		cin>>x>>y>>d;
		board[x-1][y-1].push_back({i,d-1});
	}

	while(1){
		ans++;
		if(func()){
			break;
		}
		if(ans > 1000){
			ans=-1;
			break;
		}
	}
	cout<<ans<<'\n';




}