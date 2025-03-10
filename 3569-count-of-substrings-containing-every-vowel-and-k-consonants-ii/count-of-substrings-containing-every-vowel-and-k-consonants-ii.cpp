/* Approach : Sliding Window
There are two conditions:
Atleast 1 vowel each and exactly k consonants.
In this type of problems, where there are two varying conditions (one atleast and one exact),
convert conditions to similar type i.e.
atleast -> convert all to atleast
atmost -> convert all to atmost
and use fAtleast(k) - fAtleast(k+1) to get exact k condition.

1. Use Sliding window to process substrings while maintaining vowels and consonant counts.
2. Expand right boundary and update vowel/consonant count.
3. Update ans if condition satisfied i.e. atleast 1 vowel each and atleast k consonants
    3.1. Since we are have converted condition to atleats, all substring from r to end will be eligble substrings
        So, ans += n-r
    3.2 Shrink left boundary -> update vowel, consonant count -> goto 3
5. Return ans

Time : O(n)
Space : O(1)
*/

class Solution {
public:
    bool isVowel(char c){
        if((c == 'a') || (c == 'e') || (c == 'i') || (c == 'o') || (c == 'u'))
            return true;
        return false;
    }

    long long countAtleastK(string& word, int k) {
        int n = word.size();
        long long ans = 0;
        int consonants = 0;
        int l = 0,r = 0;
        unordered_map<char,int> mp;     // to store vowels frequency
        while(r < n) {
            // expand right
            if (isVowel(word[r]))
                mp[word[r]]++;
            else
                consonants++;
            
            // update ans
            while ((mp.size() == 5) && (consonants >= k)) {
                ans += n - r;
                // shrink left
                if (isVowel(word[l])) {
                    mp[word[l]]--;
                    if (mp[word[l]] == 0)
                        mp.erase(word[l]);
                }
                else
                    consonants--;
                l++;
            }
            r++;    // for next iteration
        }
        return ans;
    }

    long long countOfSubstrings(string word, int k) {
        return countAtleastK(word, k) - countAtleastK(word, k+1);
    }
};