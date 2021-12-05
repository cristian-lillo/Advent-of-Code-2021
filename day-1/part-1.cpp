#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int current_depth;
    cin >> current_depth;

    int next_depth, increased_counter = 0;

    while (cin >> next_depth) {
        if (next_depth > current_depth) increased_counter++;

        current_depth = next_depth;
    }

    cout << "There are " << increased_counter << " measurements that are larger than the previous measurement." << '\n';
    return 0;
}
