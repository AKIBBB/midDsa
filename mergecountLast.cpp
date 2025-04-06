#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int mergeAndCount(vector<int>& nums, vector<int>& indices, int left, int mid, int right, vector<int>& count) {
    int i = left, j = mid + 1, k = left;
    int smallerCount = 0;

    vector<int> tempIndices(right - left + 1);
    while (i <= mid && j <= right) {
        if (nums[indices[i]] <= nums[indices[j]]) {
            count[indices[i]] += smallerCount;
            tempIndices[k - left] = indices[i];
            i++;
        } else {
            smallerCount++;
            tempIndices[k - left] = indices[j];
            j++;
        }
        k++;
    }

    while (i <= mid) {
        count[indices[i]] += smallerCount;
        tempIndices[k - left] = indices[i];
        i++;
        k++;
    }

    while (j <= right) {
        tempIndices[k - left] = indices[j];
        j++;
        k++;
    }

    for (int i = left; i <= right; i++) {
        indices[i] = tempIndices[i - left];
    }

    return smallerCount;
}

void countSmallerUtil(vector<int>& nums, vector<int>& indices, int left, int right, vector<int>& count) {
    if (left >= right) {
        return;
    }
    
    int mid = left + (right - left) / 2;
    
    countSmallerUtil(nums, indices, left, mid, count);
    countSmallerUtil(nums, indices, mid + 1, right, count);
    
    mergeAndCount(nums, indices, left, mid, right, count);
}


vector<int> countSmaller(vector<int>& nums) {
    int n = nums.size();
    vector<int> indices(n), count(n, 0);

    for (int i = 0; i < n; i++) {
        indices[i] = i;
    }

    countSmallerUtil(nums, indices, 0, n - 1, count);

    return count;
}

int main() {
    vector<int> nums = {5, 2, 6, 1};
    vector<int> result = countSmaller(nums);

    
    cout << "Number of smaller elements to the right of each element: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
