#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>> v;
int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		int st,en;
		cin>>st>>en;
		v.push_back({en,st}); // {종료시간, 시작시간}
	}
	
	sort(v.begin(),v.end()); // 종료시간 순으로 정렬
	
	int time = v[0].first; // 제일 빨리 끝나는걸 초기값으로
	int cnt=1;
	
	for(int i=1;i<t;i++){
		if(time<=v[i].second){ // 종료시간이 시작시간보다 크면
			//cout<<"{"<<v[i].second<<", "<<v[i].first<<"}\n";
			cnt++;
			time = v[i].first;
		}
	}
	cout<<cnt;
}