#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    ifstream input_file("input.txt");

    int first_depth, second_depth, third_depth;
    input_file >> first_depth >> second_depth >> third_depth;

    int first_window = first_depth + second_depth + third_depth;
    
    int fourth_depth, second_window;
    int increased_counter = 0;

    while (input_file >> fourth_depth) {
        second_window = second_depth + third_depth + fourth_depth;
        if (second_window > first_window) increased_counter++;

        first_depth = second_depth;
        second_depth = third_depth;
        third_depth = fourth_depth;
        first_window = second_window;
    }

    cout << "There are " << increased_counter << " sums that are larger than the previous sum." << '\n';
    return 0;
}
