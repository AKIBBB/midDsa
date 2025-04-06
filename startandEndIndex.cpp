#include <iostream>
#include <vector>
using namespace std;

void maxSubarraySumWithIndices(const vector<int> &arr) {
    int maxSoFar = arr[0];
    int maxEndingHere = arr[0];

    int start = 0, end = 0, tempStart = 0;

    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] > maxEndingHere + arr[i]) {
            maxEndingHere = arr[i];
            tempStart = i;
        } else {
            maxEndingHere += arr[i];
        }

        if (maxEndingHere > maxSoFar) {
            maxSoFar = maxEndingHere;
            start = tempStart;
            end = i;
        }
    }

    cout << "Maximum Subarray Sum: " << maxSoFar << endl;
    cout << "Start Index: " << start << endl;
    cout << "End Index: " << end << endl;

    cout << "Subarray: ";
    for (int i = start; i <= end; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    vector<int> arr = {-2, -3, 4, -1, -2, 1, 5, -3};
    maxSubarraySumWithIndices(arr);
    return 0;
}
