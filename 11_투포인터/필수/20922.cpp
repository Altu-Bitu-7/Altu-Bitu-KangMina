// 겹치는 건 싫어
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX_NUM = 100001;  // 문제 내 수열 길이 최댓값 조건

// 같은 정수를 k개 이하로 가지는 최장 연속 부분 수열의 길이 구하기
int solution(const vector<int> arr, int k, int n){
    // 초기화
    int answ = 1;    // 시작 시점 길이: 0번째 원소만 포함
    int left = 0, right = 1;    // 부분 수열의 왼쪽, 오른쪽 포인터. 왼쪽은 포함하고 오른쪽은 포함 안함
    vector<int> count(MAX_NUM, 0);  // 수열 내 각 숫자의 개수
    count[arr[left]]++; // (left = 0)의 해당 원소 개수 증가

    // 오른쪽 포인터가 수열 끝에 다다를 때까지
    while (right < n){
        // right를 오른쪽으로 증가하면서 right번째 숫자를 수열에 추가할 수 있는지 확인
        if(count[arr[right]] >= k){ // right번째 숫자의 개수가 k 이상이면 추가 불가능
            count[arr[left]]--; // left 숫자를 삭제
            left++; // left 오른쪽으로 이동
            continue;   // 다시 right 추가 가능한지 확인
        }

        // right 숫자를 수열에 추가 가능한 경우
        count[arr[right]]++;    // right 숫자를 수열에 추가
        right++;    // right 오른쪽으로 이동
        answ = max(answ, right - left);   // 최대값 갱신
    }

    return answ;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;   // n: 주어진 수열 길이
    int k;  // k: 같은 정수 포함 가능 개수
    vector<int> arr;    // arr: 수열
    int answ;   // answ: 같은 정수를 k개 이하로 포함한 최장 연속 부분 수열의 길이

    // 입력
    cin >> n >> k;
    arr.assign(n, 0);
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }

    // 연산
    answ = solution(arr, k, n);

    // 출력
    cout << answ << '\n';

    return 0;
}