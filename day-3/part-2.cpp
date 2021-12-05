#include <bits/stdc++.h>

#define N_BITS 12

using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    vector<string> oxygen_vector, co2_vector;
    string oxygen_binary, co2_binary;
    int oxygen_generator_rating, co2_scrubber_rating, life_support_rating;

    ifstream input_file("input.txt");
    string binary_number;
    vector<int> bits(N_BITS, 0);

    while (input_file >> binary_number) {
        for (int i = 0; i < N_BITS; i++) {
            binary_number[i] == '1' ? bits[i]++ : bits[i]--;
        }

        oxygen_vector.push_back(binary_number);
        co2_vector.push_back(binary_number);
    }

    while (oxygen_vector.size() > 1) {
        auto it_begin = oxygen_vector.begin();

        for (int i = 0; i < N_BITS; i++) {
            for (int j = 0; j < oxygen_vector.size(); j++) {
                if (bits[i] >= 0 && oxygen_vector[j][i] == '0') oxygen_vector.erase(it_begin + j);
                else if (bits[i] < 0 && oxygen_vector[j][i] == '1') oxygen_vector.erase(it_begin + j);
            }
        }
    }

    while (co2_vector.size() > 1) {
        auto it_begin = co2_vector.begin();

        for (int i = 0; i < N_BITS; i++) {
            for (int j = 0; j < oxygen_vector.size(); j++) {
                if (bits[i] <= 0 && co2_vector[j][i] == '1') oxygen_vector.erase(it_begin + j);
                else if (bits[i] > 0 && co2_vector[j][i] == '0') oxygen_vector.erase(it_begin + j);
            }
        }
    }

    oxygen_binary = oxygen_vector[0];
    co2_binary = co2_vector[0];

    oxygen_generator_rating = stoi(oxygen_binary, nullptr, 2);
    co2_scrubber_rating = stoi(co2_binary, nullptr, 2);
    life_support_rating = oxygen_generator_rating * co2_scrubber_rating;

    cout << "The oxygen generator rating is the binary number " << oxygen_binary << ", or " << oxygen_generator_rating << " in decimal.\n";
    cout << "The CO2 scrubber rating is the binary number " << co2_binary << ", or " << co2_scrubber_rating << " in decimal.\n";
    cout << "Multiply the oxygen generator rating by the CO2 scrubber rating to get " << life_support_rating << ".\n";
    return 0;
}
