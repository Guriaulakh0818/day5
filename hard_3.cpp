#include <bits/stdc++.h>
using namespace std;
int findMissingElement(const vector<int>& arr, int n) {
    int left = 0;
    int right = arr.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == mid + 111) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return left + 111;
}
int main() {
    vector<int> arr = {111, 112, 113, 115, 116, 117};
    int n ;
    int missingElement = findMissingElement(arr, n);
    cout << "The missing element is: " << missingElement << endl;
    return 0;
}
