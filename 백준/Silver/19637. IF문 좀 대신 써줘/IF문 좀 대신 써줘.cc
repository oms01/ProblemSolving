#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define X first
#define Y second
pair<string, int> input[100'001];
int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		string str;
		int num;
		cin>>str>>num;
		input[i] = {str,num};
	}
	for(int i=0;i<m;i++){
		int num;
		cin>>num;

		int st = 0, en = n;
		int ans;
		while(st<=en){
			int mid = (st+en)/2;

			if(input[mid].Y >= num){
				ans = mid;
				en = mid - 1;
			}
			else{
				st = mid + 1;
			}
		}
		cout<<input[ans].X<<'\n';
	}
}
