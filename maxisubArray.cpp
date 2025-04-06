#include <bits/stdc++.h>
using namespace std;

int maxCrossingSum(vector<int> &arr, int l, int m, int h) {
    int sum = 0;
    int leftSum = INT_MIN;
    for (int i = m; i >= l; i--) {
        sum += arr[i];
        if (sum > leftSum)
            leftSum = sum;
    }

    sum = 0;
    int rightSum = INT_MIN;
    for (int i = m + 1; i <= h; i++) {
        sum += arr[i];
        if (sum > rightSum)
            rightSum = sum;
    }

    return leftSum + rightSum;
}

int MaxSum(vector<int> &arr, int l, int h) {
    if (l > h)
        return INT_MIN;
    if (l == h)
        return arr[l];

    int m = l + (h - l) / 2;

    int leftSum = MaxSum(arr, l, m);
    int rightSum = MaxSum(arr, m + 1, h);
    int crossSum = maxCrossingSum(arr, l, m, h);

    if (leftSum >= rightSum && leftSum >= crossSum)
        return leftSum;
    else if (rightSum >= leftSum && rightSum >= crossSum)
        return rightSum;
    else
        return crossSum;
}

int maxSubarraySum(vector<int> &arr) {
    return MaxSum(arr, 0, arr.size() - 1);
}

int main() {
    vector<int> arr = {2, 3, 4, 5, 7};
    cout << "Maximum subarray sum is: " << maxSubarraySum(arr) << endl;
    return 0;
}
