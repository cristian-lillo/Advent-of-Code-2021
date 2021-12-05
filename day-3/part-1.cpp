#include <bits/stdc++.h>

#define N_BITS 12

using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    string gamma_rate_binary = "000000000000", epsilon_rate_binary = "000000000000";
    int gamma_rate, epsilon_rate, power_consumption;

    ifstream input_file("input.txt");
    string binary_number;
    vector<int> bits(N_BITS, 0);

    while (input_file >> binary_number) {
        for (int i = 0; i < N_BITS; i++) {
            binary_number[i] == '1' ? bits[i]++ : bits[i]--;
        }
    }

    for (int i = 0; i < N_BITS; i++) {
        gamma_rate_binary[i] = (bits[i] > 0) ? '1' : '0';
    }

    for (int i = 0; i < N_BITS; i++) {
        epsilon_rate_binary[i] = (bits[i] > 0) ? '0' : '1';
    }

    gamma_rate = stoi(gamma_rate_binary, nullptr, 2);
    epsilon_rate = stoi(epsilon_rate_binary, nullptr, 2);
    power_consumption = gamma_rate * epsilon_rate;

    cout << "The gamma rate is the binary number " << gamma_rate_binary << ", or " << gamma_rate << " in decimal.\n";
    cout << "The epsilon rate is the binary number " << epsilon_rate_binary << ", or " << epsilon_rate << " in decimal.\n";
    cout << "Multiplying the gamma rate by the epsilon rate produces the power consumption, " << power_consumption << ".\n";
    return 0;
}
