class Solution {
public:
    int sumOfEncryptedInt(vector<int>& nums) {
        int sum = 0;

        for (int x : nums) {
            int temp = x;
            int maxDigit = 0;
            int digits = 0;

            // Step 1: find max digit and count digits
            while (temp > 0) {
                maxDigit = max(maxDigit, temp % 10);
                temp /= 10;
                digits++;
            }

            // Step 2: build encrypted number
            int encrypted = 0;
            while (digits--) {
                encrypted = encrypted * 10 + maxDigit;
            }

            sum += encrypted;
        }

        return sum;
    }
};
