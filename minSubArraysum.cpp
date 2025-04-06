#include <bits/stdc++.h>
using namespace std;
int minCrossingSum(vector<int> &arr, int l, int m, int h) {
    int sum = 0;
    int leftSum = INT_MAX;

    for (int i = m; i >= l; i--) {
        sum += arr[i];
        if (sum < leftSum)
            leftSum = sum;
    }

    sum = 0;
    int rightSum = INT_MAX;

    for (int i = m + 1; i <= h; i++) {
        sum += arr[i];
        if (sum < rightSum)
            rightSum = sum;
    }

    return leftSum + rightSum;
}

int MinSum(vector<int> &arr, int l, int h) {
    if (l > h)
        return INT_MAX;

    if (l == h)
        return arr[l];

    int m = l + (h - l) / 2;

    int leftSum = MinSum(arr, l, m);
    int rightSum = MinSum(arr, m + 1, h);
    int crossSum = minCrossingSum(arr, l, m, h);

    return min({leftSum, rightSum, crossSum});
}


int minSubarraySum(vector<int> &arr) {
    return MinSum(arr, 0, arr.size() - 1);
}


int main() {
    vector<int> arr = {3, -4, 2, -3, -1, 7, -5};
    cout << "Minimum subarray sum is: " << minSubarraySum(arr) << endl;
    return 0;
}
