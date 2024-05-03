#include<bits/stdc++.h>
using namespace std;
int t;
int boy[11][6], girl[11][6];
int match_boy[11], match_girl[11];
int func(){ //시뮬레이션
   	int cnt = 0;
   	while(cnt<5){
      //if(cnt>=5) break;
    	for(int i=6;i<=10;i++){ //i번 여자차례
        	if(match_girl[i]!=0) continue; //여자가 짝이 있으면 패스
			//cout<<i<<"차례 : "<<match_girl[i]<<'\n';
	        for(int j=0;j<5;j++){
    	        //i번 여자의 j번째 남자
        	    int boynum = girl[i][j];
				if(boynum==0) continue; //퇴짜맞은 경험이 있던 남자

				if(match_boy[boynum]!=0){ //남자가 이미 매치됨

					//지금 매칭할 여자와 이미 매칭된 여자와의 우선순위 비교
					//남자 번호, 남자와 이미 매칭된 여자 번호, 이번에 매칭예정인 여자 번호
					//cout<<boynum<<' '<<match_boy[boynum]<<' '<<i<<"\n";
					int idx1 = find(boy[boynum],boy[boynum]+6,i) - boy[boynum]; //지금
					int idx2 = find(boy[boynum],boy[boynum]+6,match_boy[boynum]) - boy[boynum]; //이미
					//cout<<idx1<<" , "<<idx2<<'\n';

					if(idx1 > idx2){ //idx1가 퇴짜맞음
						girl[i][j] = 0; 
					}

					else if(idx1 < idx2){ //idx2가 퇴짜맞음
						//퇴짜맞은 여자의 선호도 리스트에서 퇴짜놓은 남자의 인덱스 찾기
						//match_boy[boynum] 남자가 매칭이 되어있는가?
						int idx = find(girl[match_boy[boynum]],girl[match_boy[boynum]+6],boynum)-girl[match_boy[boynum]];
						girl[match_boy[boynum]][idx] = 0;
						match_girl[match_boy[boynum]] = 0; //전여자 매칭 끊고
						match_boy[boynum] = i; //새여자 삽입
						match_girl[i] = boynum;
					}
					//cout<<"win "<<match_boy[boynum]<<'\n';
					break;
				}
				//매치되지 않은 남자
				match_boy[boynum] = i;
				match_girl[i] = boynum;
				cnt++;
				//cout<<i<<' '<<boynum<<'\n';
				break;
			}
		}
   	}

	//1번과 매치된 여자 번호
	return match_boy[1];
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>t;
    while(t--){
		int inputboy[11][6], inputgirl[11][6];
        memset(boy,0,sizeof(boy));
        memset(girl,0,sizeof(girl));
        for(int i=2;i<=5;i++){
            for(int j=0;j<5;j++) cin>>inputboy[i][j];
        }
        for(int i=6;i<=10;i++){
            for(int j=0;j<5;j++) cin>>inputgirl[i][j];
        }
		int ans = 10;
		int cnt = 0;
		int tmp[5] = {6,7,8,9,10};
		int origin = 0;
		do{
			memset(match_boy,0,sizeof(match_boy));
       		memset(match_girl,0,sizeof(match_girl));
			for(int i=2;i<=5;i++){
				for(int j=0;j<5;j++) boy[i][j] = inputboy[i][j];
			}
			for(int i=6;i<=10;i++){
				for(int j=0;j<5;j++) girl[i][j] = inputgirl[i][j];
			}

			for(int i=0;i<5;i++) boy[1][i] = tmp[i];
			if(cnt==0){
				origin = func();
				cnt++;
			}
			else{
				ans = min(ans,func());
			}

		}while(next_permutation(tmp,tmp+5));

		if(origin > ans){
			cout<<"YES\n";
		}
		else cout<<"NO\n";
    }
}