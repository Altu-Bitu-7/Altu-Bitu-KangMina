// 키 순서
#include <iostream>
#include <vector>
using namespace std;

const int INF = 1e9;

// 플로이드-워셜 알고리즘으로 모든 쌍의 관계 계산한다.
void calGraph(vector<vector<bool>> &graph, int n){
        
    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (graph[i][k] && graph[k][j]) {
                    graph[i][j] = true;
                }
            }
        }
    }

}

// 자신의 키 순위를 알 수 있는 학생 찾아서 반환한다.
int findAnswer(vector<vector<bool>> &graph, int n){
    int count = 0;
        
    for (int i = 1; i <= n; ++i) {
        int smaller = 0, larger = 0;

        for (int j = 1; j <= n; ++j) {
            if (graph[i][j]) smaller++;  // i보다 큰 학생 수
            if (graph[j][i]) larger++;  // i보다 작은 학생 수
        }

        if (smaller + larger == n - 1) {
            count++; // 자신보다 크거나 작은 학생 수가 정확히 N-1이면 순위를 알 수 있음
        }
    }

    return count;
}

int main() {
    int n, m;   // 학생들의 수 n (2 ≤ n ≤ 500), 두 학생 키를 비교한 횟수 m (0 ≤ m ≤ n(n-1)/2)

    // 입력
    cin >> n >> m;
    vector<vector<bool>> graph(n + 1, vector<bool>(n + 1, false));
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        graph[a][b] = true; // a < b
    }

    // 연산
    calGraph(graph, n);
    int answ = findAnswer(graph, n);

    // 출력
    cout << answ << endl;

    return 0;
}
