class Solution {
    public int solution(int[] a) {
        int n = a.length;
        
        int[] lmn = new int[n+1];
        int[] rmn = new int[n+1];
        for(int i=0;i<n;i++) lmn[i] = rmn[i] = Integer.MAX_VALUE;
        lmn[0] = a[0];
        rmn[n-1] = a[n-1];
        for(int i=1;i<n;i++) lmn[i] = Math.min(lmn[i-1], a[i]);
        for(int i=n-2;i>=0;i--) rmn[i] = Math.min(rmn[i+1], a[i]);
        
        int cnt = 0;
        for(int i=0;i<n;i++){
            if(rmn[i] < a[i] && lmn[i] < a[i]) cnt++;
        }
        return n-cnt;
        
    }
}