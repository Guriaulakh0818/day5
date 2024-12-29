#include <bits/stdc++.h>
using namespace std;
int findPeakUtil(const vector<int>& arr, int low, int high, int n) {
    int mid = low + (high - low) / 2;
    if ((mid == 0 || arr[mid - 1] <= arr[mid]) && (mid == n - 1 || arr[mid + 1] <= arr[mid])) {
        return mid;
    } else if (mid > 0 && arr[mid - 1] > arr[mid]) {
        return findPeakUtil(arr, low, mid - 1, n);
    } else {
        return findPeakUtil(arr, mid + 1, high, n);
    }
}
int findPeak(const vector<int>& arr) {
    int n = arr.size();
    return findPeakUtil(arr, 0, n - 1, n);
}
int main() {
    vector<int> arr = {1, 3, 20, 4, 1, 0};
    int peakIndex = findPeak(arr);
    cout << "Peak element is: " << arr[peakIndex] << " at index " << peakIndex << endl;
    return 0;
}
