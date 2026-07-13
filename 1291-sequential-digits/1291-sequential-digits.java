class Solution {
    static List<Integer> all;
    static{
        all = new ArrayList<>();
        for(int i=1; i<9; i++){
            int val = i;
            for(int j=i+1; j<=9; j++){
                val = val*10 + j;
                all.add(val);
            }
        }
        Collections.sort(all);
    }
    public List<Integer> sequentialDigits(int low, int high) {
        List<Integer> ans = new ArrayList<>();
        for(int i : all){
            if(i>=low && i<=high) ans.add(i);
        }
        return ans;
    }
}