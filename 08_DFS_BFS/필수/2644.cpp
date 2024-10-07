// 촌수 계산
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 인덱스 0은 본인으로 시작해서 조상들 리스트를 반환한다. 
// [0]의 부모는 [1], [1]의 부모는 [2] ...
vector<int> findAncestors(int child, vector<int> &parent){
    vector<int> answ;   // 반환할 리스트

    int cur = child;
    while(cur != 0){
        answ.push_back(cur);
        cur = parent[cur];
    }

    return answ;
}

// 촌수를 반환한다.
// 각 사람의 부모는 최대 한명만 주어짐
int calRelation(int p1, int p2, vector<int> &parent){
    int n1, n2;

    // p1과 p2 각각의 조상 찾기
    vector<int> p1_ancestors = findAncestors(p1, parent);
    vector<int> p2_ancestors = findAncestors(p2, parent);

    // 공통 조상 찾기
    for (int i = 0; i < p1_ancestors.size(); i++){
        int cur = p1_ancestors[i];
        auto idx = find(p2_ancestors.begin(), p2_ancestors.end(), cur);
        if (idx != p2_ancestors.end()){
            int answ = i + (idx - p2_ancestors.begin());
            return answ;
        }
    }

    return -1;  // 두 사람의 친척 관계가 없을 때
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;  // n: 전체 사람의 수(1 이상 100 이하)
    int p1, p2; // p1, p2: 둘 사이의 촌수를 계산해야 함
    int m;  // m: 부모 자식들 간 관계의 개수

    // 입력
    cin >> n;
    cin >> p1 >> p2;
    cin >> m;

    vector<int> parent(n + 1, 0);    // parent: 입력받은 가족관계 저장 , parent[2] = 3 -> 2 의 부모는 3이다.

    for (int i = 0; i < m; i++){
        int x, y;   // x, y: x 는 y 의 부모이다.
        cin >> x >> y;
        parent[y] = x;
    }

    // 연산
    int answ = calRelation(p1, p2, parent);

    // 출력
    cout << answ;

    return 0;
}