#include <iostream>
#include <vector>
#include <climits>
using namespace std;


pair<int, int> findLargestPair(const vector<int>& arr, int low, int high) {

    if (high - low == 1) {
        if (arr[low] > arr[high])
            return {arr[low], arr[high]};
        else
            return {arr[high], arr[low]};
    }


    if (low == high) {
        return {arr[low], INT_MIN};
    }

    int mid = (low + high) / 2;
    pair<int, int> left = findLargestPair(arr, low, mid);
    pair<int, int> right = findLargestPair(arr, mid + 1, high);
    vector<int> candidates = {left.first, left.second, right.first, right.second};
    
    int firstMax = INT_MIN, secondMax = INT_MIN;
    for (int num : candidates) {
        if (num > firstMax) {
            secondMax = firstMax;
            firstMax = num;
        } else if (num > secondMax && num != firstMax) {
            secondMax = num;
        }
    }

    return {firstMax, secondMax};
}

int main() {
    vector<int> arr = {10, 45, 98, 23, 98, 67};

    if (arr.size() < 2) {
        cout << "Array must have at least two elements." << endl;
        return 0;
    }

    pair<int, int> result = findLargestPair(arr, 0, arr.size() - 1);
    if (result.second == INT_MIN)
        cout << "No valid pair found (all elements might be the same)." << endl;
    else
        cout << "Largest pair: " << result.first << " and " << result.second << endl;

    return 0;
}
