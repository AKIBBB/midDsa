#include <iostream>
#include <algorithm> 
using namespace std;

int maxDollars(int sticks, int diamonds) {
    int tools = 0;

    while (sticks >= 1 && diamonds >= 2) {
        if (diamonds > sticks) {
            diamonds -= 2;
            sticks -= 1;
        }
        else {
            diamonds -= 1;
            sticks -= 2;
        }
        tools++; 
    }

    return tools;
}

int main() {
    int sticks, diamonds;
    cin >> sticks >> diamonds; 
    cout << maxDollars(sticks, diamonds) << endl; 
    return 0;
}
