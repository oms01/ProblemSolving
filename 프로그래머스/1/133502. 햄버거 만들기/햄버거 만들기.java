import java.util.*;
class Solution {
    public int solution(int[] ingredient) {
        int answer = 0;
        Stack<Integer> s = new Stack<>();
        for(int x : ingredient){
            if(s.empty()) s.push((x==1?1:0));
            else{
                if((s.peek()==1&&x==2)||(s.peek()==2&&x==3)) s.push(x);
                else if(s.peek()==3&&x==1){
                    answer++;
                    s.pop(); s.pop(); s.pop();
                }
                else{
                    s.push((x==1?1:0));
                }
            }
        }
        return answer;
    }
}