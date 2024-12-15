class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
       if (s1 == s2) { return true; }
        vector<int> letters(26, 0);
        for (int i = 0; i < s1.size(); i++) {
            letters[s1[i]-'a']++; letters[s2[i]-'a']--;
        }
        for (int i = 0; i < 26; i++) {
            if (letters[i] != 0) { return false; }
        }
        int k = 0;
        for (int i = 0; i < s1.size(); i++) {
            if (s1[i] != s2[i]) { k++; };
        }
        return k == 2; 
    }
};