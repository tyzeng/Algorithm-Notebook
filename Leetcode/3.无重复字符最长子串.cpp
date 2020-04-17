//简单dp

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int rec[100005];
        rec[0] = 1;
        int mx = 1;
        if(s.length() == 0)
            return 0;
        for(int i = 1;i<s.length(); i++)
        {
            int j = i-1;
            for(; j > i-1-rec[i-1]; j--)
            {
                if(s[j] == s[i]) {
                    break;
                }
            }
            rec[i] = i-j;
            mx = mx>rec[i]?mx:rec[i];
        }
        return mx;     
    }
};
