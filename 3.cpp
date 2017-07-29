#include <unordered_set>
#include <queue>
#include <algorithm>

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        queue<char> rightSubstring;
        unordered_set<char> rightSubstringSet;
        int longest = 0;
        for (auto newChar : s)
        {
            if (rightSubstringSet.find(newChar) != rightSubstringSet.end())
            {
                char c;
                do
                {
                    c = rightSubstring.front();
                    rightSubstring.pop();
                    rightSubstringSet.erase(c);
                }
                while (c != newChar);
            }
            rightSubstringSet.insert(newChar);
            rightSubstring.push(newChar);
            longest = std::max(static_cast<int>(rightSubstring.size()), longest);
        }
        return longest;
    }
};


//////////////////////
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> m;
        int start = -1;
        int longest = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (m.find(s[i]) != m.end())
            {
                if (m[s[i]] > start)
                    start = m[s[i]];
            }
            m[s[i]] = i;
            longest = std::max(longest, i - start);
        }
        return longest;
    }
};