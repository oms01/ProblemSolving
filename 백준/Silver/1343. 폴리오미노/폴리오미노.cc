#include<bits/stdc++.h>
using namespace std;
string str;
int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	cin>>str;
	int stk=0;
	for(int i=0;i<str.size();i++){
		if(str[i]=='X'){
			stk++;
		}
		if(str[i]=='.'){
			stk=0;
			continue;
		}
		
		if(stk==2){
			str[i]=str[i-1]='B';
		}
		if(stk==4){
			str[i]=str[i-1]=str[i-2]=str[i-3]='A';
			stk=0;
		}
		
	}
	for(int i=0;i<str.size();i++){
		if(str[i]=='X'){
			cout<<-1;
			return 0;
		}
	}
	cout<<str;
}

/*
*/