#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool DFS(string start, vector<vector<string>> tickets, vector<bool>& check, vector<string>& answer, int num) {
    answer.push_back(start);
    if (num == tickets.size()) return true;

    for (int i = 0; i < tickets.size(); i++) {
        if (start == tickets[i][0] && check[i] == false) {
            check[i] = true;
            bool T = DFS(tickets[i][1], tickets, check, answer, num + 1);
            if (T == true) return true;
            check[i] = false;
        }

    }
    answer.pop_back();
    return false;
}

void main()
{
    vector<vector<string>> tickets = {{"ICN", "SFO"},{"ICN", "ATL"},{"SFO", "ATL"},{"ATL", "ICN"},{"ATL", "SFO"}};
    size_t n = tickets.size();
    vector<string> answer;
    vector<bool> check(n);
    sort(tickets.begin(), tickets.end());


    DFS("ICN", tickets, check, answer, 0);
    for(auto a : answer)
        cout << a << endl;
}
