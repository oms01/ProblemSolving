import java.util.*;

class Solution {
    public static class pair implements Comparable<pair>{
        int a,b;
        pair(int a,int b){
            this.a = a;
            this.b = b;
        }
        @Override
        public int compareTo(pair p){
            return (this.a==p.a ? Integer.compare(p.b,this.b) : Integer.compare(p.a,this.a));
        }
    }
    
    public int dist(pair a, pair b){
        return Math.abs(a.a-b.a) + Math.abs(a.b-b.b);
    }
    
    public String solution(int[] numbers, String hand) {
        String answer = "";
        pair left = new pair(3,0);
        pair right = new pair(3,2);
        pair[] pos = new pair[11];
        pos[0] = new pair(3,1);
        for(int i=0;i<3;i++) for(int j=0;j<3;j++){
            pos[3*i+j+1] = new pair(i,j);
        }
        
        for(int cur : numbers){
            if(cur==1 || cur==4 || cur==7){
                answer+='L';
                left = pos[cur];
            }
            else if(cur==3 || cur==6 || cur==9){
                answer+='R';
                right = pos[cur];
            }
            else{
                if(dist(left,pos[cur]) < dist(right,pos[cur])){
                    answer+='L';
                    left = pos[cur];
                }
                else if(dist(left,pos[cur]) > dist(right,pos[cur])){
                    answer+='R';
                    right = pos[cur];
                }
                else{
                    if(hand.charAt(0)=='r'){
                        answer+='R';
                        right = pos[cur];
                    }
                    else{
                        answer+='L';
                        left = pos[cur];
                    }
                }
            }
        }
        return answer;
    }
}