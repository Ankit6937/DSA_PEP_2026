class Solution {
public:
    string reverseWords(string s) {
        vector<string> words;
        int i = 0, n = s.length();

        while (i < n) {
            // skip spaces
            while (i < n && s[i] == ' ') i++;

            if (i >= n) break;

            // collect word
            int j = i;
            while (j < n && s[j] != ' ') j++;

            words.push_back(s.substr(i, j - i));
            i = j;
        }

        // reverse words
        reverse(words.begin(), words.end());

        // join with single space
        string result = "";
        for (int k = 0; k < words.size(); k++) {
            result += words[k];
            if (k != words.size() - 1)
                result += " ";
        }

        return result;
    }
};
