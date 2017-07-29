class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> all;
        int i = 0;
        int j = 0;
        while (i < nums1.size() || j < nums2.size())
        {
            if (i >= nums1.size())
            {
                all.push_back(nums2[j++]);
                continue;
            }
            if (j >= nums2.size())
            {
                all.push_back(nums1[i++]);
                continue;
            }
            if (nums1[i] < nums2[j])
            {
                all.push_back(nums1[i++]);
            }
            else
            {
                all.push_back(nums2[j++]);
            }
        }
        if (all.empty())
            return 0.0f;
        if (all.size() % 2 == 0)
        {
            return (all[all.size() / 2] + all[all.size() / 2 - 1]) / 2.0f;
        }
        return all[all.size() / 2];
    }
};

/////////////////////////
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size())
            nums1.swap(nums2);
        int m = static_cast<int>(nums1.size());
        int n = static_cast<int>(nums2.size());
        int start = 0;
        int end = m;
        while (start <= end)
        {
            int i = (start + end) / 2;
            int j = (m + n + 1) / 2 - i;
            if (i < end && nums2[j - 1] > nums1[i])
            {
                start = i + 1;
            }
            else if (i > 0 && nums1[i - 1 ] > nums2[j])
            {
                end = i - 1;
            }
            else
            {
                int maxLeft = 0;
                if (i <= 0)
                    maxLeft = nums2[j - 1];
                else if (j <= 0)
                    maxLeft = nums1[i - 1];
                else
                    maxLeft = std::max(nums1[i - 1], nums2[j - 1]);
                if ((m + n) % 2 == 1)
                    return maxLeft;
                int minRight = 0;
                if (i >= m)
                    minRight = nums2[j];
                else if ( j >= n)
                    minRight = nums1[i];
                else
                    minRight = std::min(nums1[i], nums2[j]);
                return (maxLeft + minRight) / 2.0f;
            }
        }
        return 0.0f;
    }
};