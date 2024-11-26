// 파티
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int INF = 1e9; // 큰 값

vector<pair<int, int>> graph[1001]; // 인접 리스트 그래프

// X에서 다른 마을로 가는 최단 거리 구하기(다익스트라 알고리즘 이용)
vector<int> dijkstra(int start, int n) {
    vector<int> dist(n + 1, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        int cur_dist = pq.top().first;
        int cur_node = pq.top().second;
        pq.pop();

        if (cur_dist > dist[cur_node]) continue;

        for (auto &edge : graph[cur_node]) {
            int next_node = edge.first;
            int weight = edge.second;

            if (dist[cur_node] + weight < dist[next_node]) {
                dist[next_node] = dist[cur_node] + weight;
                pq.push({dist[next_node], next_node});
            }
        }
    }

    return dist;
}

// 각 마을에서 X로 가는 최단 거리 계산
int findMax(int x, int n, vector<int> &dist_from_x){
    int max_time = 0;

    for (int i = 1; i <= n; i++) {
        if (i == x) continue;

        vector<int> dist_to_x = dijkstra(i, n);
        max_time = max(max_time, dist_to_x[x] + dist_from_x[i]);
    }

    return max_time;
}

int main() {

    //  입력
    int n, m, x;
    cin >> n >> m >> x;

    for (int i = 0; i < m; i++) {
        int u, v, t;
        cin >> u >> v >> t;
        graph[u].push_back({v, t});
    }

    // 연산
    vector<int> dist_from_x = dijkstra(x, n);
    int max_time = findMax(x, n, dist_from_x);

    // 출력
    cout << max_time << endl;

    return 0;
}
