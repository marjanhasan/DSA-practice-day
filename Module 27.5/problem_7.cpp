class Solution
{
public:
    bool isSubsequence(string s, string t)
    {
        bool ans = false;
        int i = 0;
        if (s.empty() && t.empty())
            return true;
        for (char c : t)
        {
            if (s[i] == c)
            {
                i++;
            }
            if (i == s.size())
            {
                ans = true;
                break;
            }
        }
        return ans;
    }
};