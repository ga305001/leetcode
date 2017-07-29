#include <algorithm>

class Solution {
public:
    string longestPalindrome(string s) {
        if (s.size() <= 1)
            return s;
        int longestIndex = 0;
        int longest = 0;
        int size = static_cast<int>(s.size());
        for (int i = 0; i < size;)
        {
            int j = i;
            int k = i;
            while (k < size - 1 && s[k] == s[k + 1]) k++;
            i = k + 1;
            while (k < size - 1 && j > 0 && s[k + 1] == s[j - 1]) {k++; j--;}
            int current = k- j + 1;
            if (current > longest)
            {
                longest = current;
                longestIndex = j;
            }
        }
        return s.substr(longestIndex, longest);
    }
};