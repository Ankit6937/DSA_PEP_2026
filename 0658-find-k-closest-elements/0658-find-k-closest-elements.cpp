class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        
        priority_queue<pair<int,int>> maxHeap;
        
        for(int a : arr){
            maxHeap.push({abs(a - x), a});
            
            if(maxHeap.size() > k){
                maxHeap.pop();
            }
        }
        
        vector<int> ans;
        
        while(!maxHeap.empty()){
            ans.push_back(maxHeap.top().second);
            maxHeap.pop();
        }
        
        sort(ans.begin(), ans.end());
        
        return ans;
    }
};