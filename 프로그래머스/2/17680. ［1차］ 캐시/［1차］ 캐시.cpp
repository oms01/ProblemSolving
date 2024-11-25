#include <bits/stdc++.h>
using namespace std;
vector<string> cache;
void eraseAndPushback(string erase, string insert){
    int idx = find(cache.begin(),cache.end(), erase)-cache.begin();

    for(int i=idx;i<cache.size()-1;i++){
        cache[i] = cache[i+1];
    }
    
    if(cache.size()!=0) cache.back() = insert;
    
    return;
}
string lowercase(string str){
    for(auto& c : str){
        if('A'<=c&& c<='Z') c = 'a'+c-'A';
    }
    return str;
}
int solution(int cacheSize, vector<string> cities) {
    int answer = 0;

    for(auto city : cities){
        city = lowercase(city);
        
        if(find(cache.begin(),cache.end(), city)!=cache.end()){
            //hit
            answer++;
            eraseAndPushback(city, city);
        }
        else{
            //miss
            answer+=5;
            if(cache.size()>=cacheSize){
                if(cacheSize == 0) continue;
                eraseAndPushback(cache[0],city);
            }
            else cache.push_back(city);
        }
    }
    return answer;
}
