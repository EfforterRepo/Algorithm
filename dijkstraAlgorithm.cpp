#include <vector>
#include <iostream>
#include <queue>

#define MAX 100        // 최대 정점의 개수 
#define INF 99999999

using namespace std;

vector<int> dijkstraAlgorithm(int start, int V, vector<pair<int, int>> adj[]) {
    vector<int> dist(V, INF);
    priority_queue<pair<int, int>> pq;

    dist[start] = 0;
    pq.push(make_pair(0, start));

    while (!pq.empty()) {
        // 첫 번째 값은 방문한 정점의 dist 값 (거리 값을 뜻함)
        int cost = -pq.top().first;
        // 두 번째 값은 현재 방문한 정점의 값을 뜻함.
        int cur = pq.top().second;
        pq.pop();

        //현재 방문한 정점의 인근 정점을 비교한다.
        for (int i = 0; i < adj[cur].size(); i++) {
            int next = adj[cur][i].first; // 다음 정점
            int nCost = adj[cur][i].second + cost; // 현재 비용 + 다음 정점에 도달하는 비용
            if (nCost < dist[next]) { // 배열에 저장된 값보다 작다면,
                dist[next] = nCost; //갱신을 해준다.
                pq.push(make_pair(-nCost, next));
            }
        }
    }
    return dist;
}

int main()
{
    // V는 정점의 수 , E는 노드의 수
    int V, E;
    // 거리를 나타내는 adj
    vector<pair<int, int>> adj[MAX];
    cout << "정점의 개수 입력 : ";
    cin >> V;
    cout << "간선의 개수 입력 : ";
    cin >> E;

    // 노드의 수만큼 for문을 돌린다.
    for (int i = 0; i < E; i++) {
        int from, to, cost;
        cin >> from >> to >> cost;
        //양방향 노드의 수를 만들기.
        adj[from].push_back(make_pair(to, cost));
        adj[to].push_back(make_pair(from, cost));
    }

    printf("\n===dijkstra 알고리즘 결과 ===\n");
    vector<int> dist = dijkstraAlgorithm(0, V, adj);
    for (int i = 0; i < V; i++) {
        printf("0번 정점에서 %d번 정점까지 최단거리 : %d\n", i, dist[i]);
    }
    return 0;
    
}