class Solution {
public:
    string convert(string s, int r) {
        if (r <= 1) return s;
        string result;
        int cycle = 2 * r - 2;
        for (int i = 0; i < r; i++)
        {
            for (int j = i; j < s.length(); j += cycle)
            {
                result.push_back(s[j]);
                int secondJ = (j - i) + cycle - i;
                if (i != 0 && i != r - 1 && secondJ < s.length())
                    result.push_back(s[secondJ]);
            }
        }
        return result;
    }
};