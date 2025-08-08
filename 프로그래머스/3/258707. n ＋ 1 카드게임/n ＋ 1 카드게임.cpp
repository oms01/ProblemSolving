#include <bits/stdc++.h>
using namespace std;

int n;
bool f(set<int>& s1, set<int>& s2){
    for(auto x: s1){
        if(s2.count(n+1-x)){
            s1.erase(x);
            s2.erase(n+1-x);
            return 1;
        }
    }
    return 0;
}

int solution(int coin, vector<int> cards) {
    n = cards.size();
    
    set<int> hand;
    for(int i=0;i<n/3;i++) hand.insert(cards[i]);
    
    int ans = 0;
    set<int> tmp;
    for(int i=n/3;i<n;i+=2){
        tmp.insert(cards[i]);
        tmp.insert(cards[i+1]);
        
        if(f(hand, hand)){
            
        }
        else if(coin>=1 && f(hand, tmp)){
            coin-=1;
        }
        else if(coin>=2 && f(tmp,tmp)){
            coin-=2;
        }
        else break;
        ans++;
    }
    
    
    return ans+1;
}