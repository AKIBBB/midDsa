#include <iostream>
#include <vector>
using namespace std;

int countInRange(const vector<int>& nums, int num, int left, int right) {
    int count = 0;
    for (int i = left; i <= right; i++) {
        if (nums[i] == num) count++;
    }
    return count;
}

int majorityElementRec(const vector<int>& nums, int left, int right) {
    if (left == right)
        return nums[left];

    int mid = left + (right - left) / 2;

    int leftMajor = majorityElementRec(nums, left, mid);
    int rightMajor = majorityElementRec(nums, mid + 1, right);

    if (leftMajor == rightMajor)
        return leftMajor;

    int leftCount = countInRange(nums, leftMajor, left, right);
    int rightCount = countInRange(nums, rightMajor, left, right);

    return (leftCount > rightCount) ? leftMajor : rightMajor;
}

int majorityElement(const vector<int>& nums) {
    return majorityElementRec(nums, 0, nums.size() - 1);
}

int main() {
    vector<int> nums = {2, 2, 1, 1, 2, 2, 2};
    cout << "Majority Element: " << majorityElement(nums) << endl;
    return 0;
}

// MaximumSumSubarraywithNonNegativeNumbers