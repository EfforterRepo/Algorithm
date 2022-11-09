#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>
using namespace std;

int main() {
    int K = 7;
    vector<int> scoville = { 1, 2, 3, 9, 10, 12 };
    int answer = 0;
    int temp = 0;
    priority_queue<int> q;
    // priority_queue<int, vector<int>, greater<int>> pq (scoville.begin(),scoville.end());
    for (auto s : scoville) {
        q.push(-s);
    }

    while (-q.top() < K) {
        temp = -q.top(); q.pop();
        if (q.empty()) return -1;
        temp = q.top() * -2 + temp;
        q.pop(); q.push(-temp);
        answer++;
    }
    cout <<  answer << endl;
}