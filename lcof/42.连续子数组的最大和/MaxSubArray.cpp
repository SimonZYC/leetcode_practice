#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int dp = nums[0], ret = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            dp = dp <= 0? nums[i]: dp + nums[i];
            ret = std::max(dp, ret);
        }
        return ret;
    }

    // Print the max subarray (leftmost)
    int maxSubArray2(vector<int>& nums) {
        int dp = nums[0], ret = nums[0], mem[2] = {}, idx = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (dp <= 0) {
                dp = nums[i];
                idx = i;
            }
            else dp += nums[i];
            if (ret < dp) {
                ret = dp;
                mem[0] = idx;
                mem[1] = i;
            }
            ret = std::max(dp, ret);
        }
        for (int i = mem[0]; i <= mem[1]; i++)
            cout << nums[i] << " ";
        cout << endl;
        return ret;
    }
};

int main() {
    int a[] = {-2,1,-3,4,-1,2,1,-5,4};
    vector<int> b(a, a + sizeof(a) / sizeof(int));
    Solution s;
    int ret = s.maxSubArray2(b);
    cout << ret << endl;
    return 0;
}