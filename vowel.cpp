#include <iostream>
#include <string>
using namespace std;

bool isVowel(char ch) {
    ch = tolower(ch); 
    return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
}

int countVowels(const string& str, int low, int high) {
    if (low > high) return 0;

    if (low == high)
        return isVowel(str[low]) ? 1 : 0;


    int mid = low + (high - low) / 2;
    int leftCount = countVowels(str, low, mid);
    int rightCount = countVowels(str, mid + 1, high);

    return leftCount + rightCount;
}

int main() {
    string input = "DivideAndConquerApproach";

    int totalVowels = countVowels(input, 0, input.length() - 1);
    cout << "Total number of vowels: " << totalVowels << endl;

    return 0;
}
