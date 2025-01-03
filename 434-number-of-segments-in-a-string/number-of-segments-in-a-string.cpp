class Solution {
public:
    int countSegments(string s) {
        int n=s.size();
        int ans=0;
        int prevspace=1;
        int i=0;
        while(i<s.size()){
            if(s[i]==' '){
                prevspace=1;
            }
            if(prevspace==1 &&( s[i]!=' ')){
                ans++;
                prevspace=0;
            }
            i++;
        }
        return ans;
    }
};