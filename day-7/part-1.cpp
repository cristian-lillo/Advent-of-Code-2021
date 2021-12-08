#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    /* we save the comma-separated integers in a string */
    ifstream input_file("input.txt");
    string input_str;
    input_file >> input_str;

    /* we create a vector to save every crab position */
    stringstream str_stream(input_str);
    int horizontal_position;
    vector<int> crabs_positions;

    /* we update the vector with each crab submarine position */
    while (str_stream >> horizontal_position) {
        crabs_positions.push_back(horizontal_position);
        if (str_stream.peek() == ',') str_stream.ignore();
    }

    /* we sort the vector in ascending order and save the number of crab submarines in a variable */
    sort(crabs_positions.begin(), crabs_positions.end());
    int n = crabs_positions.size();

    /* we create a variable to save the lowest cost of fuel */
    int min_fuel_cost;
    for (int i = 0; i < n; i++) {
        /* we create a variable to save the amount of fuel we'll spend to move every crab to the i-th position */
        int ith_fuel_cost = 0;

        /* we update the variable by the difference between the j-th submarine position and the i-th submarine position */
        for (int j = 0; j < n; j++) ith_fuel_cost += abs(crabs_positions[i] - crabs_positions[j]);

        /* we'll update the minimum fuel cost variable if the i-th fuel cost variable is lower or if we are on the first position */
        if (i == 0 || ith_fuel_cost < min_fuel_cost) min_fuel_cost = ith_fuel_cost;
    }

    cout << "This costs a total of " << min_fuel_cost << " fuel.\n";
    return 0;
}
