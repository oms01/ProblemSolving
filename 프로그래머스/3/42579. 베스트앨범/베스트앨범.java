import java.util.*;

class Solution {
    public List<Integer> solution(String[] genres, int[] plays) {
        Map<String, List<int[]>> genre = new HashMap<>();
        Map<String, Integer> cnt = new HashMap<>();
        
        for(int i=0;i<genres.length;i++){
            genre.putIfAbsent(genres[i], new ArrayList<>());
            genre.get(genres[i]).add(new int[]{plays[i], i});
            cnt.put(genres[i], cnt.getOrDefault(genres[i],0) + plays[i]);
        }
        
        List<String> tmp = new ArrayList<>(cnt.keySet());
        tmp.sort((a,b)-> cnt.get(b)-cnt.get(a));
        
        List<Integer> ans = new ArrayList<>();
        for(String g: tmp){
            List<int[]> cur = genre.get(g);
            
            cur.sort((a,b)-> {
                if(b[0]!=a[0]) return b[0]-a[0];
                return a[1]-b[1];
            });
            
            for(int i=0;i<Math.min(2,cur.size());i++){
                ans.add(cur.get(i)[1]);
            }
        }
        
        return ans;
    }
}