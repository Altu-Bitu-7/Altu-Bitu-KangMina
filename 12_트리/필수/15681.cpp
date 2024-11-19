// 트리와 쿼리
#include <iostream>
#include <vector>
using namespace std;

const int MAX_N = 100005;
vector<int> tree[MAX_N];    // 트리 간선 정보 저장
int subtree_size[MAX_N];    // 각 노드의 서브트리 크기를 저장

// dfs 를 이용해 각 서브트리 크기 계산
void dfs(int node, int parent){
    subtree_size[node] = 1; // 자기 자신을 포함하므로 초기값은 1
    for (int neighbor : tree[node]) {
        if (neighbor != parent) { // 부모 노드로 돌아가지 않음
            dfs(neighbor, node);
            subtree_size[node] += subtree_size[neighbor];
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, r, q; // 트리의 정점의 수 n과 루트의 번호 r, 쿼리의 수 q
    int u, v;

    // 입력
    cin >> n >> r >> q;
    for (int i = 0; i < n - 1; i++){
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    // 서브트리 크기 계산
    dfs(r, -1);

    // 쿼리 입력, 연산, 출력
    for (int i = 0; i < q; i++){
        int input;
        cin >> input;
        cout << subtree_size[input] << '\n';
    }    

    return 0;
}