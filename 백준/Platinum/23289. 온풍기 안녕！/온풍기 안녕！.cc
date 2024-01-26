#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
typedef long long ll;
typedef pair<int,int> pii;
int dx[] = {0,0,-1,1}; //오,왼,위,아래
int dy[] = {1,-1,0,0};
vector<pii> d[] = {
	{{-1,1},{0,1},{1,1}}, //오른쪽 0 
	{{-1,-1},{0,-1},{1,-1}}, //왼쪽 1
	{{-1,-1},{-1,0},{-1,1}}, //위 2
	{{1,-1},{1,0},{1,1}}, //아래 3
};
int cnt = 0;
int n,m,k,w;
//0:빈칸, 1:오른쪽, 2:왼쪽, 3:위, 4:아래, 5:조사칸
int input[21][21];
int board[21][21];
int tmp[21][21];
vector<pair<pii,pii>> wall;

void in(){
	cin>>n>>m>>k;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++) cin>>input[i][j];
	}
	cin>>w;
	for(int i=0;i<w;i++){
		int x,y,t; //t=1: 세로 벽, t=0: 가로 벽
		cin>>x>>y>>t;
		x--; y--;
		if(t==0){
			wall.push_back({{x,y},{x-1,y}});
			wall.push_back({{x-1,y},{x,y}});
		}
		else{ //t==1
			wall.push_back({{x,y},{x,y+1}});
			wall.push_back({{x,y+1},{x,y}});
		}
	}
	return;
}

void printBoard(){
	cout<<"--------------\n";
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cout<<board[i][j]<<' ';
		}
		cout<<'\n';
	}
}

bool isMovable(int x,int y,int nx,int ny,int dir){ //1-2. 2-1.
	//좌우위아래
	if(x==nx || y==ny){
		for(int i=0;i<wall.size();i++){
			pii cur = wall[i].X;
			pii nxt = wall[i].Y;
			if(x==cur.X && y==cur.Y && nx==nxt.X && ny==nxt.Y) return false;
		}
		return true;
	}

	//대각선
	pii mid1,mid2;
	if(!(dir/2)){
		mid1 = {x+dx[2], y+dy[2]};
		mid2 = {x+dx[3], y+dy[3]};
	}
	else{
		mid1 = {x+dx[0], y+dy[0]};
		mid2 = {x+dx[1], y+dy[1]};
	}
	if((dir/2)==0 && (mid1.X==nx || mid2.X==nx)){
		pii mid;
		if(mid1.X==nx) mid = mid1;
		else mid = mid2;
		// cout<<"mid1 : "<<mid.X<<' '<<mid.Y<<' '<<'\n';
		bool flag1 = 0, flag2 = 0;
		for(int i=0;i<wall.size();i++){
			pii cur = wall[i].X;
			pii nxt = wall[i].Y;
			if(x==cur.X && y==cur.Y && mid.X==nxt.X && mid.Y==nxt.Y) flag1 = 1;
			if(nx==cur.X && ny==cur.Y && mid.X==nxt.X && mid.Y==nxt.Y)  flag2 = 1;
		}
		// cout<<flag1<<' '<<flag2<<'\n';
		if(flag1 || flag2){ //둘중하나라도 true면 이동 X
			return 0;
		}
		else{
			return 1;
		}
	}
	if((dir/2)==1 && (mid1.Y==ny || mid2.Y==ny)){
		pii mid;
		if(mid1.Y==ny) mid = mid1;
		else mid = mid2;
		// cout<<"mid2 : "<<mid.X<<' '<<mid.Y<<' '<<'\n';
		bool flag1 = 0, flag2 = 0;
		for(int i=0;i<wall.size();i++){
			pii cur = wall[i].X;
			pii nxt = wall[i].Y;
			if(x==cur.X && y==cur.Y && mid.X==nxt.X && mid.Y==nxt.Y) flag1 = 1;
			if(nx==cur.X && ny==cur.Y && mid.X==nxt.X && mid.Y==nxt.Y)  flag2 = 1;
		}
		// cout<<flag1<<' '<<flag2<<'\n';
		if(flag1 || flag2){ //둘중하나라도 true면 이동 X
			return 0;
		}
		else{
			return 1;
		}
	}
	// cout<<"ret1: "<<ret1<<" / "<<"ret2: "<<ret2<<'\n';
	// cout<<"return : "<<(ret1||ret2)<<'\n';
	// cout<<"{"<<x<<','<<y<<"}->{"<<nx<<','<<ny<<"}\n";
	return 1;

}

void func(int x,int y,int val,int dir){ //1-1.
	tmp[x][y] = val;

	for(int i=0;i<3;i++){
		int nx = x + d[dir][i].X;
		int ny = y + d[dir][i].Y;
		if(nx<0||nx>=n||ny<0||ny>=m) continue;
		if(val==1) continue;
		// cout<<"{"<<x<<','<<y<<"}->{"<<nx<<','<<ny<<"}\n";
		bool flag = isMovable(x,y,nx,ny,dir);
		// cout<<"flag :: "<<flag<<'\n';
		if(!flag){
			// cout<<"{"<<x<<','<<y<<"}->{"<<nx<<','<<ny<<"}\n";
			continue;
		}

		func(nx,ny,val-1,dir);
	}

}

void flash(int x, int y, int dir){ //1.
	memset(tmp,0,sizeof(tmp));
	func(x+dx[dir],y+dy[dir],5,dir);
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			board[i][j] += tmp[i][j];
		}
	}
}

void tempControl(){ //2.
	memset(tmp,0,sizeof(tmp));
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(board[i][j]==0) continue;
			int cnt = 0;
			for(int dir=0;dir<4;dir++){
				int nx = i + dx[dir];
				int ny = j + dy[dir];
				if(nx<0||nx>=n||ny<0||ny>=m) continue;
				if(board[i][j] <= board[nx][ny]) continue;
				if(!isMovable(i,j,nx,ny,dir)) continue;
				int move = abs(board[nx][ny]-board[i][j])/4;
				tmp[nx][ny] += move;
				tmp[i][j] -= move;
			}
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			board[i][j]+=tmp[i][j];
		}
	}
	return;
}

void tempMinus(){ //3.
	for(int i=0;i<n;i++){
		if(board[i][0]!=0) board[i][0]--;
		if(board[i][m-1]!=0) board[i][m-1]--;
	}
	for(int i=1;i<m-1;i++){
		if(board[0][i]!=0) board[0][i]--;
		if(board[n-1][i]!=0) board[n-1][i]--;
	}
	return;
}

bool check(){ //5.
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(input[i][j]!=5) continue;
			if(board[i][j] < k) return false;
		}
	}
	return true;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);

	//입력
	in();

	do{
		if(cnt>100){
			break;
		}
		// printBoard();
		//1. 집에 있는 모든 온풍기에서 바람이 한 번 나옴
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(input[i][j]==5||input[i][j]==0) continue;
				flash(i,j,input[i][j]-1);
			}
		}
		// printBoard();

		//2. 온도가 조절됨
		tempControl();
		// printBoard();

		//3. 온도가 1 이상인 가장 바깥쪽 칸의 온도가 1씩 감소
		tempMinus();
		// printBoard();

		//4. 초콜릿을 하나 먹는다.
		cnt++;
		// cout<<"@@@@@@@@@@@@\n";
		//5. 조사하는 모든 칸의 온도가 K이상이 되었는지 검사.
		//모든 칸의 온도가 K이상이면 테스트를 중단하고, 아니면 1부터 다시 시작한다.
	}while(!check());
	// printBoard();
	cout<<cnt<<'\n';
}