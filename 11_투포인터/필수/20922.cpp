// 겹치는 건 싫어
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int n, int k, const vector<int> arr){
    int left = 0, right = 0;
    int max_len = 0;

    len = left - right + 1;
    max_len = max(max_len, len);

    return lmax_len;
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
    answ = solution(n, k, arr);

    // 출력
    cout << answ << '\n';

    return 0;
}