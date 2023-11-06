#include<bits/stdc++.h>
using namespace std;
#define X first 
#define Y second
typedef long long ll;
typedef pair<int,int> pii;
int dx[] = {0,0,-1,1};
int dy[] = {1,-1,0,0};
int n,k;
vector<pii> v;
int dist(pii a,pii b){
    return abs(a.X-b.X) + abs(a.Y-b.Y);
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n>>k;
    v.resize(n);
    for(int i=0;i<n;i++) cin>>v[i].X>>v[i].Y;
    vector<bool> tmp(n,0);
    for(int i=0;i<k;i++) tmp[i] = 1;

    vector<bool> ans;
    int mn = 2e9; //최대 거리
    do{
        vector<pii> a; //대피소
        vector<pii> b; //집
        for(int i=0;i<n;i++){
            if(tmp[i]) a.push_back(v[i]);
            else b.push_back(v[i]);
        }
        int d=0;
        for(int i=0;i<b.size();i++){
            int dd = 2e8; // 집에서 가까운 대피소까지의 거리
            for(int j=0;j<a.size();j++){
                dd = min(dd,dist(b[i],a[j]));
            }
            d = max(d,dd); //가까운 대피소까지의 거리의 최대값
        }
        // cout<<d<<'\n';
        mn = min(mn,d);

    }while(prev_permutation(tmp.begin(),tmp.end()));
    cout<<mn<<'\n';
}

/*
집과 대피소 사이의 거리가 가장 큰값이 가장 작은 경우
= 거리

*/