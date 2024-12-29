#include<bits/stdc++.h>
using namespace std;

vector<int> searchRange(vector<int>& nums, int target) {
    int left = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
    int right = upper_bound(nums.begin(), nums.end(), target) - nums.begin() - 1;

    if (left <= right && left < nums.size() && nums[left] == target) {
        return {left, right};
    }
    return {-1, -1};
}

int main() {
    vector<int> nums = {5, 7, 7, 8, 8, 10};
    int target = 8;
    
    vector<int> result = searchRange(nums, target);

    if (result[0] != -1) {
        cout << "Target found at indices: " << result[0] << " to " << result[1] << endl;
    } else {
        cout << "Target not found." << endl;
    }

    return 0;
}
