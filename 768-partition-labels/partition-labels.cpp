class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int>v(26);
    for(int i=0;i<s.length();i++)
        v[s[i]-'a']=i;
        
    int maxx=0,start=0;    
    vector<int>ans;
        for(int i=0;i<s.length();i++)
        {
            maxx=max(maxx,v[s[i]-'a']);
            if(maxx==i)
            {
                ans.push_back(maxx-start+1);
                start=i+1;
                maxx=0;
            }
        }
        return ans;
    }
};