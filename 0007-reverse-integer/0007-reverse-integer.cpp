class Solution {
public:
    int reverse(int x) {
        long rev = 0;   // use long to detect overflow
        
        while(x != 0) {
            int digit = x % 10;
            rev = rev * 10 + digit;
            
            if(rev > INT_MAX || rev < INT_MIN)
                return 0;
                
            x = x / 10;
        }
        
        return (int)rev;
    }
};