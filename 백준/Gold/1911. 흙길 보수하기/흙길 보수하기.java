import java.util.*;
import java.io.*;


public class Main {
    public static class pair implements Comparable<pair>{
        int a;
        int b;
        public pair(int a, int b) {
            this.a = a;
            this.b = b;
        }

        @Override
        public int compareTo(pair p) {
            if (this.a == p.a){
                return Integer.compare(p.b,this.b);
            }
            return Integer.compare(p.a,this.a);
        }
    }

    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int l = sc.nextInt();
        pair[] arr = new pair[n];

        for(int i=0;i<n;i++){
            int st = sc.nextInt();
            int en = sc.nextInt();
            arr[i] = new pair(st,en);
        }
        Arrays.sort(arr, Collections.reverseOrder());

        int cnt = 0;
        int en = 0;
        for(int i=0;i<n;i++){
            pair cur = arr[i];
            if(en>cur.b) continue;
            en = Math.max(en,cur.a);

            cnt += (cur.b-en+l-1)/l;
            en += (cur.b-en+l-1)/l*l;
        }
        System.out.println(cnt);

    }
}