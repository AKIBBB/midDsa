#include <iostream>
using namespace std;

int minDaysToBuyFood(int S, int N, int M) {
    int total_food_needed = S * M;

    int num_sundays = S / 7;

    int days_to_buy = S - num_sundays;

    if (total_food_needed > days_to_buy * N) {
        return -1;  
    }

    int days_bought_food = 0;
    int remaining_food_needed = total_food_needed;

    while (remaining_food_needed > 0) {
        remaining_food_needed -= N;
        days_bought_food++;  
    }

    return days_bought_food;
}

int main() {
    int S = 10, N = 16, M = 2;
    int result = minDaysToBuyFood(S, N, M);

    if (result == -1) {
        cout << "It is not possible to survive" << endl;
    } else {
        cout << "Minimum days to buy food: " << result << endl;
    }

    return 0;
}
