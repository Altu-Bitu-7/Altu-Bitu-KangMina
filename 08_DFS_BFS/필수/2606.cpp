// 바이러스
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int bfs(int start, vector<vector<int>> &graph){
    int n = graph.size();
    vector<bool> visited(n + 1, false); // visited: 방문 여부 체크
    queue<int> q;
    int answ = 0;

    q.push(1);  
    visited[1] = true;
    
    while(!q.empty()) {
        int now = q.front();
        q.pop();

        for (int i : graph[now]){
            if (!visited[i]){
                visited[i] = true;
                answ++;
                q.push(i);
            }
        }
    }

    return answ;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;  // n: 컴퓨터의 수 (컴퓨터에는 1~n 번호가 매겨진다)
    int p;  // p: 연결되어 있는 컴퓨터 쌍의 수

    // 입력
    cin >> n;
    cin >> p;

    vector<vector<int>> graph(n + 1,vector<int>()); // graph: 컴퓨터 연결관계 저장된 인접 리스트
    int input1, input2;
    for (int i = 0; i < p; i++){
        cin >> input1 >> input2;
        graph[input1].push_back(input2);
        graph[input2].push_back(input1);
    }
    
    // 연산
    int start = 1;  // 1번 컴퓨터부터 바이러스에 걸림
    int answ = bfs(start, graph);
    
    // 출력
    cout << answ << '\n';

    return 0;
}
