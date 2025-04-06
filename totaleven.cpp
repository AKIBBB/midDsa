#include <iostream>
#include <vector>
using namespace std;
int countEvens(const vector<int>& arr, int low, int high) {
    if (low == high) {
        return (arr[low] % 2 == 0) ? 1 : 0;
    }

    int mid = low + (high - low) / 2;
    int leftCount = countEvens(arr, low, mid);
    int rightCount = countEvens(arr, mid + 1, high);

    return leftCount + rightCount;
}

int main() {
    vector<int> arr = {2, 5, 8, 7, 4, 1, 10, 3};

    int totalEven = countEvens(arr, 0, arr.size() - 1);
    cout << "Total even numbers in array: " << totalEven << endl;

    return 0;
}
