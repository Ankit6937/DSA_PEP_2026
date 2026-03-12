class Solution {
public:
    
    void solve(string digits, int index, string current, 
               vector<string>& result, unordered_map<char,string>& mp){
        
        if(index == digits.size()){
            result.push_back(current);
            return;
        }
        
        string letters = mp[digits[index]];
        
        for(char ch : letters){
            solve(digits, index + 1, current + ch, result, mp);
        }
    }
    
    vector<string> letterCombinations(string digits) {
        
        vector<string> result;
        if(digits.size() == 0) return result;
        
        unordered_map<char,string> mp;
        
        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";
        
        solve(digits, 0, "", result, mp);
        
        return result;
    }
};