#include <bits/stdc++.h>
using namespace std;

struct Pair {
    int max;
    int min;
};

Pair maxi(int arr[], int low, int high) {
    Pair result, left, right;
    int mid;

    if (low == high) {
        result.max = arr[low];
        result.min = arr[low];
        return result;
    }


    if (high == low + 1) {
        if (arr[low] > arr[high]) {
            result.max = arr[low];
            result.min = arr[high];
        } else {
            result.max = arr[high];
            result.min = arr[low];
        }
        return result;
    }

    mid = (low + high) / 2;
    left = maxi(arr, low, mid);
    right = maxi(arr, mid + 1, high);

    result.max = max(left.max, right.max);
    result.min = min(left.min, right.min);

    return result;
}

int main() {
    int arr[] = {6, 4, 26, 14, 33, 64, 46};     
    int n = sizeof(arr) / sizeof(arr[0]); 
    Pair result = maxi(arr, 0, n - 1);
    cout << "Maximum num: " << result.max << endl;
    cout << "Minimum num: " << result.min << endl;
    return 0;
}
