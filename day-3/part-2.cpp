#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    /* we save the binary number of each line in a string and create a vector to check the most and least common number of every bit */
    ifstream input_file("input.txt");
    string binary_number; int num_of_bits = 12;
    vector<int> bits(num_of_bits, 0);

    /* we create vectors to save all binary numbers and later filter them according to each element criteria */
    vector<string> oxygen_vector, co2_vector;

    /* we update the values of every bit position in our vector and save the whole number on both oxygen and co2 vectors */
    while (input_file >> binary_number) {
        for (int i = 0; i < num_of_bits; i++) {
            binary_number[i] == '1' ? bits[i]++ : bits[i]--;
        }

        oxygen_vector.push_back(binary_number);
        co2_vector.push_back(binary_number);
    }

    while (oxygen_vector.size() > 1) {
        auto it_begin = oxygen_vector.begin();

        for (int i = 0; i < num_of_bits; i++) {
            for (int j = 0; j < oxygen_vector.size(); j++) {
                if (bits[i] >= 0 && oxygen_vector[j][i] == '0') oxygen_vector.erase(it_begin + j);
                else if (bits[i] < 0 && oxygen_vector[j][i] == '1') oxygen_vector.erase(it_begin + j);
            }
        }
    }

    while (co2_vector.size() > 1) {
        auto it_begin = co2_vector.begin();

        for (int i = 0; i < num_of_bits; i++) {
            for (int j = 0; j < oxygen_vector.size(); j++) {
                if (bits[i] <= 0 && co2_vector[j][i] == '1') oxygen_vector.erase(it_begin + j);
                else if (bits[i] > 0 && co2_vector[j][i] == '0') oxygen_vector.erase(it_begin + j);
            }
        }
    }

    string oxygen_binary = oxygen_vector[0];
    string co2_binary = co2_vector[0];

    int oxygen_generator_rating = stoi(oxygen_binary, nullptr, 2);
    int co2_scrubber_rating = stoi(co2_binary, nullptr, 2);
    int life_support_rating = oxygen_generator_rating * co2_scrubber_rating;

    cout << "The oxygen generator rating is the binary number " << oxygen_binary << ", or " << oxygen_generator_rating << " in decimal.\n";
    cout << "The CO2 scrubber rating is the binary number " << co2_binary << ", or " << co2_scrubber_rating << " in decimal.\n";
    cout << "Multiply the oxygen generator rating by the CO2 scrubber rating to get " << life_support_rating << ".\n";
    return 0;
}
