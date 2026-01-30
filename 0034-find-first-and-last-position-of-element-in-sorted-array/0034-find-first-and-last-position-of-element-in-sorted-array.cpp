// class Solution {
// public:
//     int firstOccurance(vector<int> &nums, int target){
//         int left = 0, right=nums.size()-1
//         int ans =-1;
//         while(left <= right){
//             int mid =(left +right)/2;
//             if(nums[mid] == target);
//             ans=mid

//         }
//     }
//     int lastOccurance(vector<int> &nums, int target){
        
//     }
//     vector<int> searchRange(vector<int>& nums, int target) {
//         return{firstOccurance(nums, target), lastOccurance(nums,target)}
//     }
// };


class Solution {
public:
    int firstOccurance(vector<int> &nums, int target) {
        int left = 0, right = nums.size() - 1;
        int ans = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) {
                ans = mid;
                right = mid - 1;   // left side search
            }
            else if (nums[mid] < target) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        return ans;
    }

    int lastOccurance(vector<int> &nums, int target) {
        int left = 0, right = nums.size() - 1;
        int ans = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) {
                ans = mid;
                left = mid + 1;   // right side search
            }
            else if (nums[mid] < target) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        return { firstOccurance(nums, target),
                 lastOccurance(nums, target) };
    }
};
