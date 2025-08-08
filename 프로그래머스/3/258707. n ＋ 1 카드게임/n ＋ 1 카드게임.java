import java.util.*;

class Solution {
    int n;

    public int solution(int coin, int[] cards) {
        TreeSet<Integer> s = new TreeSet<>();
        n = cards.length;
        for(int i=0;i<n/3;i++){
            s.add(cards[i]);
        }
        
        int ans = 0;
        TreeSet<Integer> tmp = new TreeSet<>();
        for(int i=n/3;i<n;i+=2){
            tmp.add(cards[i]);
            tmp.add(cards[i+1]);
            
            if(chk(s,s)){
                
            }
            else if(coin >= 1 && chk(s,tmp)){
                coin-=1;
            }
            else if(coin >= 2 && chk(tmp,tmp)){
                coin-=2;
            }
            else break;
            ans++;
        }
        
        return ans+1;
    }
    
    boolean chk(TreeSet<Integer> s1, TreeSet<Integer> s2){
        for(int x: s1){
            if(s2.contains(n+1-x)){
                s1.remove(x);
                s2.remove(n+1-x);
                return true;
            }
        }
        return false;
    }
}