#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<vector<int>> land = { {1, 2, 3, 5},{5, 6, 7, 8},{4, 3, 2, 1} };
    int answer = 0;
    for (int i = 0; i < land.size() - 1; i++) {
        land[i+1][0] += max(land[i][1], max(land[i][2], land[i][3]));
        land[i+1][1] += max(land[i][0], max(land[i][2], land[i][3]));
        land[i+1][2] += max(land[i][0], max(land[i][1], land[i][3]));
        land[i+1][3] += max(land[i][0], max(land[i][1], land[i][2]));
    }
    answer = max(max(land[land.size() - 1][0], land[land.size() - 1][1]), max(land[land.size() - 1][2], land[land.size() - 1][3]));
    cout << answer << endl;
}