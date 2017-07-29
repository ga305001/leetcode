class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                if (nums[i] + nums[j] == target)
                {
                    result.push_back(i);
                    result.push_back(j);
                    break;
                }
            }
        }
        return result;
    }
};

//////////////////////////
#include <unordered_map>
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        std::unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); i++)
        {
            int left = target - nums[i];
            if (m.find(left) != m.end())
            {
                result.push_back(m[left]);
                result.push_back(i);
                break;
            }
            else
            {
                m[nums[i]] = i;
            }
        }
        return result;
    }
};
