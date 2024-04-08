#include<bits/stdc++.h>
using namespace std;
int n;
vector<pair<int,int>> event;
int main(){
	ios::sync_with_stdio(); cin.tie();
	cin>>n;
	for(int i=0;i<n;i++){
		int st,en;
		cin>>st>>en;
		event.push_back({st,1});
		event.push_back({en,-1});
	}
	sort(event.begin(),event.end());
	int ans=0; // 필요한 강의실 수
	int curtime=event[0].first; //제일 첫 수업 시작시간
	int cur=0;//현재 열려있는 강의실 수
	int idx=0;//현재 보고있는 event의 인덱스
	while(true){
		
		//idx가 범위 안이고 수업 시작시간이 현재시간이랑 같을때
		while(idx<2*n && event[idx].first==curtime){
			cur+=event[idx].second;
			idx++;
		}
		ans=max(ans,cur);
		if(idx==2*n) break;
		curtime=event[idx].first;
	}
	cout<<ans<<'\n';
}
//결국 답은 가장 수업이 많이 진행되고있는 시간에서의 수업의 개수