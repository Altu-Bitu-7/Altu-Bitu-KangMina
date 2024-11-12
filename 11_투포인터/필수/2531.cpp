// 회전 초밥
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 슬라이딩 윈도우로 주어진 회전 초밥 벨트에서 먹을 수 있는 초밥의 가짓수의 최댓값을 반환
int findMaxEat(int n, int k, int c, const vector<int> &arr){
    vector<int> count(3001, 0); // 초밥 종류별 카운트 배열, 초밥의 최대 종류 수만큼 크기 지정
    int max_cnt = 0, current_cnt = 0;

    // 초기화: 첫 번째 윈도우
    for (int i = 0; i < k; i++) {
        if (count[arr[i]] == 0) current_cnt++;
        count[arr[i]]++;
    }

    // 쿠폰 초밥 추가
    if (count[c] == 0) current_cnt++;
    count[c]++;
    max_cnt = current_cnt;

    // 슬라이딩 윈도우
    for (int i = 0; i < n; i++) {
        int remove_idx = arr[i];
        int add_idx = arr[(i + k) % n];

        // 이전 초밥 제거
        count[remove_idx]--;
        if (count[remove_idx] == 0) current_cnt--;

        // 새로운 초밥 추가
        if (count[add_idx] == 0) current_cnt++;
        count[add_idx]++;

        // 최대 가짓수 업데이트
        max_cnt = max(max_cnt, current_cnt);
    }

    return max_cnt;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    // 회전 초밥 벨트에 놓인 접시의 수 n, 초밥의 가짓수 d, 
    // 연속해서 먹는 접시의 수 k, 쿠폰 번호 c    
    int n, d, k, c;
    vector<int> arr;    // 벨트 위에 있는 초밥들
    int answ;   // 주어진 회전 초밥 벨트에서 먹을 수 있는 초밥의 가짓수의 최댓값

    // 입력
    cin >> n >> d >> k >> c;
    arr.assign(n, 0);
    for (int i=0; i<n; i++){
        cin >> arr[i];
    }

    // 연산
    answ = findMaxEat(n, k, c, arr);

    // 출력
    cout << answ << '\n';

    return 0;
}