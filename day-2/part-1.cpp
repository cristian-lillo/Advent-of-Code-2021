#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int horizontal = 0, depth = 0;

    string instruction; int units;

    while (cin >> instruction >> units) {
        if (instruction.compare("forward") == 0) horizontal += units;
        else if (instruction.compare("down") == 0) depth += units;
        else if (instruction.compare("up") == 0) depth -= units;
    }

    cout << "You would have a horizontal position of " << horizontal << " and a depth of " << depth << ".\n";
    cout << "Multiplying these together produces " << horizontal * depth << ".\n";
    return 0;
}
