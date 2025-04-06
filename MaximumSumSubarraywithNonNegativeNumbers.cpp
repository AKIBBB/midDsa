#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int maxSumNonNegative(const vector<int>& arr, int low, int high) {
    if (low == high) {
        return (arr[low] >= 0) ? arr[low] : 0;
    }

    int mid = low + (high - low) / 2;

    int leftMax = maxSumNonNegative(arr, low, mid);
    int rightMax = maxSumNonNegative(arr, mid + 1, high);
    int crossMax = 0;
    int tempSum = 0;

    for (int i = mid; i >= low; i--) {
        if (arr[i] < 0) break;
        tempSum += arr[i];
        crossMax = max(crossMax, tempSum);
    }

    tempSum = 0;
    for (int i = mid + 1; i <= high; i++) {
        if (arr[i] < 0) break;
        tempSum += arr[i];
        crossMax = max(crossMax, tempSum);
    }

    return max(max(leftMax, rightMax), crossMax);
}

int main() {
    vector<int> arr = {1, 2, 5, -1, 3, 4, 2, -1, 6};

    int result = maxSumNonNegative(arr, 0, arr.size() - 1);

    cout << "Maximum sum of subarray with non-negative numbers: " << result << endl;

    return 0;
}

