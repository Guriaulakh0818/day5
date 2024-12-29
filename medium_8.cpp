#include <bits/stdc++.h>
using namespace std;
int findKthLargest(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end(), greater<int>());
    return nums[k - 1];
}
int main() {
    vector<int> nums = {3, 2, 1, 5, 6, 4};
    int k = 4;
    cout << "The " << k << " position largest element is " << findKthLargest(nums, k) << endl;
    return 0;
}
