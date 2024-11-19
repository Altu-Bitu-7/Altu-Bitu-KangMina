// 어두운 굴다리
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// 가로등은 모두 높이가 같아야 하고, 정수이다.
// 가로등의 높이가 H라면 왼쪽으로 H, 오른쪽으로 H만큼 주위를 비춘다.

// 현재 상태에서 높이 h일 때 굴다리를 모두 비출 수 있는지 
bool isBright(const vector<int> &lights, int n, int h){
    int idxCovered = 0;  // 이 인덱스까지 빛이 비춤
    for (int x: lights){
        // 현재 가로등은 [x - h, x + h] 범위를 비추고 있음
        int left = x - h;
        int right = x + h;

        // 빛이 안드는 구간이 있음
        if (left > idxCovered) {
            return false;
        }

        // 빛이 비추는 범위 갱신
        idxCovered = right;

        // 굴다리의 전부 다 밝힐 수 있음
        if (idxCovered >= n){
            return true;
        }
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n;  // n: 굴다리의 길이
    int m;  // m: 가로등의 개수
    cin >> n >> m;

    // 입력: 중복 없음, 오름차순
    vector<int> lights(m);   // lights: m개의 가로등의 위치
    for (int i = 0; i < m; i++){
        cin >> lights[i];
    }
    
    // 연산
    int answ = n;   // answ: 굴다리의 길이 n을 모두 비추기 위한 가로등의 최소 높이
    int low = 0, high = n;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (isBright(lights, n, mid)){
            answ = mid;
            high = mid - 1;
        } else{
            low = mid + 1;
        }
    }
    
    // 출력
    cout << answ;
}
