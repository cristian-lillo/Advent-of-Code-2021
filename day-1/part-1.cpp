#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    ifstream input_file("input.txt");

    int current_depth, next_depth;
    int increased_counter = 0;

    input_file >> current_depth;
    while (input_file >> next_depth) {
        if (next_depth > current_depth) increased_counter++;
        current_depth = next_depth;
    }

    cout << "There are " << increased_counter << " measurements that are larger than the previous measurement." << '\n';
    return 0;
}
