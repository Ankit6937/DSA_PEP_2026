class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int balance = 0;
        int total_tank=0;
        int curr_tank=0;
        int start=0;
        for(int i = 0; i<n; i++){
            balance = gas[i] -cost[i];
            total_tank+=balance;
            curr_tank+=balance;


            if(curr_tank<0){
                start=i+1;
                curr_tank=0;
            }
        }
        if(total_tank<0)return -1;
        return start;
    }
};