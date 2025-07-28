#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define rep(i,x,y) for(int i=x;i<y;i++)
#define REP(i,x,y) for(int i=x;i<=y;i++)
#define all(x) begin(x),end(x)
#define rall(x) rbegin(x),rend(x)
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pldld;
typedef tuple<int,int,int> ti3;
typedef tuple<ll,ll,ll> tl3;
typedef tuple<int,int,int,int> ti4;
int dx[] = {-1,0,0,1};
int dy[] = {0,-1,1,0};
/*----------------------*/

int day[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
bool chk(int y, int m, int d){

	if(y<1900 || y>2011) return 0;
	if(m<1 || m>12) return 0;

	if((y%4==0 && y%100!=0 || y%400==0) && m==2){ //윤년
		if(d<1 || d>29) return 0;
	}
	else{
		if(d<1 || d>day[m]) return 0; 
	}
	return 1;
	
}
int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	string str; cin>>str;
	int n; cin>>n;
	vector<string> v(n);
	rep(i,0,n) cin>>v[i];

	//지역코드 
	bool flag = 0;
	for(auto x: v){
		if(str.substr(0,6)==x){
			flag = 1;
		}
	}
	if(!flag) return !(cout<<"I\n");

	//생일
	int y = stoi(str.substr(6,4));
	int m = stoi(str.substr(10,2)); 
	int d = stoi(str.substr(12,2));
	if(!chk(y,m,d)) return !(cout<<"I\n");
	// cout<<y<<' '<<m<<' '<<d<<'\n';

	//성별
	int code = stoi(str.substr(14,3));
	if(code==0) return !(cout<<"I\n");
	string sex = (code%2 ? "M":"F"); 

	//체크섬
	ll cal = 0;
	for(int i=0;i<str.length()-1;i++){
		cal += (str[i]-'0')*(1<<(17-i));
		cal%=11;
	}
	ll checksum = (12 - cal)%11;
	// cout<<checksum<<' '<<cal<<'\n';
	if(checksum==10 && str.back()!='X') return !(cout<<"I\n");
	if(checksum!=10 && checksum!=(str.back()-'0')) return !(cout<<"I\n");
	cout<<sex<<'\n';



}