#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    /* we save the ten unique signal patterns, a | delimiter, and finally the four digit output value in a string */
    ifstream input_file("input.txt");
    string single_entry, four_digit_output;

    /* we update the counter of digits with a unique number of segments */
    int counter = 0;
    while (getline(input_file, single_entry)) {
        /* we ignore the ten unique signal patterns and focus on the four digit output value */
        int delimiter_pos = single_entry.find('|');
        four_digit_output = single_entry.substr(delimiter_pos+2);

        /* we define start and end positions for each digit output */
        int start_pos = 0;
        int end_pos = four_digit_output.find(" ");

        while (end_pos != string::npos) {
            /* we save the number of segments used by each digit and compare it to the ones used by the numbers 1, 4, 7 and 8 */
            int digit_segments = end_pos - start_pos;
            if (digit_segments == 2 || digit_segments == 4 || digit_segments == 3 || digit_segments == 7) counter++;

            /* we move to the next digit */
            start_pos = end_pos + 1;
            end_pos = four_digit_output.find(" ", start_pos);
        }

        /* we check on the last digit of the output */
        string last_digit = four_digit_output.substr(start_pos);
        int last_digit_segments = last_digit.length();
        if (last_digit_segments == 2 || last_digit_segments == 4 || last_digit_segments == 3 || last_digit_segments == 7) counter++;
    }

    cout << "There are " << counter << " instances of digits that use a unique number of segments.\n";
    return 0;
}
