#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define rep(i,x,y) for(int i=x;i<y;i++)
#define all(x) begin(x),end(x)
#define rall(x) rbegin(x),rend(x)
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int> tiii;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
/*----------------------*/

// {{target,condition},{array of ingredient}}
vector<pair<pair<int,int>,vector<int>>> query;

map<string,int> m;
int foodMapper(string str){
    if(m.find(str)==m.end()) m[str] = m.size()+1;
    return m[str];
}
set<int> topping;
bool isQuery(string str){
    for(char x:str){
        if(x==' ') return 1;
    }
    return 0;
}
vector<string> split(string str){
    vector<string> ret;
    stringstream ss(str);
    string tmp;
    while(ss>>tmp) ret.push_back(tmp);
    return ret;
}
pair<pair<int,bool>,vector<int>> queryParse(string str){
    vector<string> v = split(str);

    bool cond = (v[2] == "and");
    int target = foodMapper(v[v.size()-1]);
    
    vector<int> ret;
    rep(i,0,v.size()-1){
        if(v[i]=="and"||v[i]=="or"||v[i]=="if"||v[i]=="then") continue;
        ret.push_back(foodMapper(v[i]));
    }
    ret.erase(unique(all(ret)),ret.end());

    return {{target,cond},ret};
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    cin.ignore();

    string str;
    rep(i,0,n){
        getline(cin,str);
        if(isQuery(str)) query.push_back(queryParse(str));
        else{
            topping.insert(foodMapper(str));
        }
    }

    bool flag = 1;
    do{
        flag = 0;
        auto it = query.begin();
        
        while(it!=query.end()){
            int tar;
            bool cond;
            tie(tar,cond) = it->X;
            vector<int> v = it->Y;
            if(topping.find(tar)!=topping.end()){
                it = query.erase(it);
                continue;
            }

            int cnt = count_if(all(v),[&](int hash){
                return topping.count(hash);
            });


            if((cond==1&&cnt==v.size()) || (cond==0&&cnt!=0)){
                it = query.erase(it);
                topping.insert(tar);
                flag = 1;
            }
            else{
                ++it;
            }
        }
    }while(flag);
    
    cout<<topping.size()<<'\n';
}