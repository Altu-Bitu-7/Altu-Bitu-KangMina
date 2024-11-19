// 이진 검색 트리
#include <iostream>
#include <vector>
using namespace std;

// 후위 순회하고 출력하는 함수
void postorder(const vector<int> &preorder, int start, int end){
    if (start > end) return;

    int root = preorder[start];
    int right_start = start + 1;

    // 오른쪽 서브트리의 시작 위치 찾기
    // right_start 는 (preorder[i] > root 인 순간의 i) 이다.
    while (right_start <= end && preorder[right_start] < root) {
        right_start++;
    }

    // 왼쪽 서브트리
    postorder(preorder, start + 1, right_start - 1);

    // 오른쪽 서브트리
    postorder(preorder, right_start, end);

    // 루트 노드 출력
    cout << root << '\n';
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int input;
    vector<int> preorder;
    
    // 입력 (전위 순회)
    while (cin >> input){
        preorder.push_back(input);
    }
    
    // 후위 순회 연산 및 출력
    postorder(preorder, 0, preorder.size() - 1);

    return 0;
}