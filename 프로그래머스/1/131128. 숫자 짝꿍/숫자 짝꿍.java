import java.util.*;

class Solution {
    public String solution(String X, String Y) {

        int[] x = new int[11];
        for(int i=0;i<X.length();i++) x[X.charAt(i)-'0']++;
        
        int[] y = new int[11];
        for(int i=0;i<Y.length();i++) y[Y.charAt(i)-'0']++;
        
        int[] cnt = new int[11];
        for(int i=0;i<10;i++) cnt[i] = Math.min(x[i],y[i]);

        StringBuffer sb = new StringBuffer(); 
        for(int i=9;i>=0;i--){
            for(int j=0;j<cnt[i];j++){
                sb.append(i);
            }
        }
        
        String answer = sb.toString();
        if(answer.length()==0) return "-1";
        if(answer.charAt(0)=='0') return "0";
        return answer;
        
        
    }
}