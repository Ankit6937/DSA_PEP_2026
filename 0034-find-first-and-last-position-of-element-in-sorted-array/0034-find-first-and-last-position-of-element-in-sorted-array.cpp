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


// class Solution {
// public:
//     int firstOccurance(vector<int> &nums, int target) {
//         int left = 0, right = nums.size() - 1;
//         int ans = -1;

//         while (left <= right) {
//             int mid = left + (right - left) / 2;

//             if (nums[mid] == target) {
//                 ans = mid;
//                 right = mid - 1;   // left side search
//             }
//             else if (nums[mid] < target) {
//                 left = mid + 1;
//             }
//             else {
//                 right = mid - 1;
//             }
//         }
//         return ans;
//     }

//     int lastOccurance(vector<int> &nums, int target) {
//         int left = 0, right = nums.size() - 1;
//         int ans = -1;

//         while (left <= right) {
//             int mid = left + (right - left) / 2;

//             if (nums[mid] == target) {
//                 ans = mid;
//                 left = mid + 1;   // right side search
//             }
//             else if (nums[mid] < target) {
//                 left = mid + 1;
//             }
//             else {
//                 right = mid - 1;
//             }
//         }
//         return ans;
//     }

//     vector<int> searchRange(vector<int>& nums, int target) {
//         return { firstOccurance(nums, target),
//                  lastOccurance(nums, target) };
//     }
// };
// class Solution {
// public:
//     vector<int> searchRange(vector<int>& nums, int target) {

//         int first = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
//         int last = upper_bound(nums.begin(), nums.end(), target) - nums.begin() - 1;

//         if (first == nums.size() || nums[first] != target)
//             return {-1, -1};

//         return {first, last};
//     }
// };
class Solution {
public:
    int binarySearch(vector<int>& nums, int target, bool first) {
        int left = 0, right = nums.size() - 1;
        int ans = -1;

        while (left <= right) {
            int mid = (left + right) / 2;

            if (nums[mid] == target) {
                ans = mid;

                if (first)
                    right = mid - 1;  
                else
                    left = mid + 1;    
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
        return {binarySearch(nums, target, true),
                binarySearch(nums, target, false)};
    }
};