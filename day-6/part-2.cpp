#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    /* we save the comma-separated integers in a string */
    ifstream input_file("input.txt");
    string input_str;
    input_file >> input_str;

    /* we create an array with a space for each possible internal timer */
    stringstream str_stream(input_str);
    ll counter[9] = { }, internal_timer, number_of_lantern_fishes = 0;

    /* we update the array according to the internal timer of each lantern fish at the initial state */
    while (str_stream >> internal_timer) {
        counter[internal_timer]++;
        if (str_stream.peek() == ',') str_stream.ignore();
    }

    /* we update the array during the 256-day period */
    for (int i = 0; i < 256; i++) {
        /* we save the number of lantern fishes that are going to restart their timer and create new lantern fishes */
        ll zero_counter = counter[0];

        /* we move the number of lantern fishes with j+1 days on their internal timer to the j days space */
        for (int j = 0; j < 8; j++) counter[j] = counter[j+1];

        /* we add the fishes that are restarting their timer and the newly created lantern fishes */
        counter[6] += zero_counter;
        counter[8] = zero_counter;
    }

    /* we sum up all lantern fish with an internal timer */
    for (int i = 0; i < 9; i++) number_of_lantern_fishes += counter[i];

    cout << "After 256 days, there would be a total of " << number_of_lantern_fishes << " fish.\n";
    return 0;
}
