#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    /* we save the line segment x1,y1 -> x2,y2 in a string */
    ifstream input_file("input.txt");
    string line_of_vents;

    /* we look for the maximum x and y to create our ocean floor map */
    int max_x = 0, max_y = 0;

    while (getline(input_file, line_of_vents)) {
        /* we separate x1,y1 from x2,y2 */
        int delimiter_pos = line_of_vents.find("->");
        string x1_y1 = line_of_vents.substr(0, delimiter_pos);
        string x2_y2 = line_of_vents.substr(delimiter_pos+3);

        /* we separate x1 from y1 */
        delimiter_pos = x1_y1.find(',');
        int x1 = stoi(x1_y1.substr(0, delimiter_pos));
        int y1 = stoi(x1_y1.substr(delimiter_pos+1));

        /* we separate x2 from y2 */
        delimiter_pos = x2_y2.find(',');
        int x2 = stoi(x2_y2.substr(0, delimiter_pos));
        int y2 = stoi(x2_y2.substr(delimiter_pos+1));

        /* we update the value of max_x if x1 or x2 are highest */
        if (x1 > max_x) max_x = x1;
        if (x2 > max_x) max_x = x2;

        /* we update the value of max_y if y1 or y2 are highest */
        if (y1 > max_y) max_y = y1;
        if (y2 > max_y) max_y = y2;
    }

    /* we create a 2D vector filled with zeros to use as our ocean floor map */
    vector<vector<int>> ocean_floor(max_y+1, vector<int> (max_x+1, 0));

    /* we must go back to the begging of the input file and read it again */
    input_file.clear();
    input_file.seekg(0, input_file.beg);

    while (getline(input_file, line_of_vents)) {
        /* we separate x1,y1 from x2,y2 */
        int delimiter_pos = line_of_vents.find("->");
        string x1_y1 = line_of_vents.substr(0, delimiter_pos);
        string x2_y2 = line_of_vents.substr(delimiter_pos+3);

        /* we separate x1 from y1 */
        delimiter_pos = x1_y1.find(',');
        int x1 = stoi(x1_y1.substr(0, delimiter_pos));
        int y1 = stoi(x1_y1.substr(delimiter_pos+1));

        /* we separate x2 from y2 */
        delimiter_pos = x2_y2.find(',');
        int x2 = stoi(x2_y2.substr(0, delimiter_pos));
        int y2 = stoi(x2_y2.substr(delimiter_pos+1));

        /* if both points are on the same horizontal position then we build a vertical line */
        if (x1 == x2) {
            if (y1 > y2) swap(y1, y2);
            for (int j = y1; j <= y2; j++) ocean_floor[j][x1]++;
        }

        /* if both points are on the same vertical position then we build a horizontal line */
        else if (y1 == y2) {
            if (x1 > x2) swap(x1, x2);
            for (int i = x1; i <= x2; i++) ocean_floor[y1][i]++;
        }

        /* if the points don't coincide on any coordinate then it's a diagonal line */
        else {
            if (x1 < x2) {
                if (y1 < y2) {
                    int i = x1;
                    for (int j = y1; j <= y2; j++) {
                        ocean_floor[j][i]++;
                        i++;
                    }
                } else if (y1 > y2) {
                    int i = x1;
                    for (int j = y1; j >= y2; j--) {
                        ocean_floor[j][i]++;
                        i++;
                    }
                }
            } else if (x1 > x2) {
                if (y1 < y2) {
                    int i = x1;
                    for (int j = y1; j <= y2; j++) {
                        ocean_floor[j][i]++;
                        i--;
                    }
                } else if (y1 > y2) {
                    int i = x1;
                    for (int j = y1; j >= y2; j--) {
                        ocean_floor[j][i]++;
                        i--;
                    }
                }
            }
        }
    }

    /* we must check every point of the map for overlapping lines */
    int overlapping_lines = 0;
    for (int j = 0; j <= max_y; j++) {
        for (int i = 0; i <= max_x; i++) {
            if (ocean_floor[j][i] >= 2) overlapping_lines++;
        }
    }

    cout << "The number of points where at least two lines overlap is " << overlapping_lines << ".\n";
    return 0;
}
