#include <vector>
#include <iostream>
#include <queue>

#define MAX 100        // �ִ� ������ ���� 
#define INF 99999999

using namespace std;

vector<int> dijkstraAlgorithm(int start, int V, vector<pair<int, int>> adj[]) {
    vector<int> dist(V, INF);
    priority_queue<pair<int, int>> pq;

    dist[start] = 0;
    pq.push(make_pair(0, start));

    while (!pq.empty()) {
        // ù ��° ���� �湮�� ������ dist �� (�Ÿ� ���� ����)
        int cost = -pq.top().first;
        // �� ��° ���� ���� �湮�� ������ ���� ����.
        int cur = pq.top().second;
        pq.pop();

        //���� �湮�� ������ �α� ������ ���Ѵ�.
        for (int i = 0; i < adj[cur].size(); i++) {
            int next = adj[cur][i].first; // ���� ����
            int nCost = adj[cur][i].second + cost; // ���� ��� + ���� ������ �����ϴ� ���
            if (nCost < dist[next]) { // �迭�� ����� ������ �۴ٸ�,
                dist[next] = nCost; //������ ���ش�.
                pq.push(make_pair(-nCost, next));
            }
        }
    }
    return dist;
}

int main()
{
    // V�� ������ �� , E�� ����� ��
    int V, E;
    // �Ÿ��� ��Ÿ���� adj
    vector<pair<int, int>> adj[MAX];
    cout << "������ ���� �Է� : ";
    cin >> V;
    cout << "������ ���� �Է� : ";
    cin >> E;

    // ����� ����ŭ for���� ������.
    for (int i = 0; i < E; i++) {
        int from, to, cost;
        cin >> from >> to >> cost;
        //����� ����� ���� �����.
        adj[from].push_back(make_pair(to, cost));
        adj[to].push_back(make_pair(from, cost));
    }

    printf("\n===dijkstra �˰��� ��� ===\n");
    vector<int> dist = dijkstraAlgorithm(0, V, adj);
    for (int i = 0; i < V; i++) {
        printf("0�� �������� %d�� �������� �ִܰŸ� : %d\n", i, dist[i]);
    }
    return 0;
    
}