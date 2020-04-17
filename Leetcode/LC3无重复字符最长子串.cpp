class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length() == 0)
            return 0; 
        vector<int> position(256, -1);
        int len = s.length();
        int curLen = 0, maxLen = 0;
        for(int i = 0; i < len; i++)
        {
            int prevIdx = position[s[i]];
            if(prevIdx == -1 || i - prevIdx > curLen)
                curLen++;
            else
            {
                maxLen = max(curLen, maxLen);
                curLen = i - prevIdx;
            }
            position[s[i]] = i;
        }
        maxLen = max(curLen, maxLen);
        return maxLen;
    }
};
