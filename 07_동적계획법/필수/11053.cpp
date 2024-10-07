// 가장 긴 증가하는 부분 수열
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    int len;
    int answ = 0;   // answ: 가장 긴 증가하는 부분 수열의 길이

    int a[1001];    // a: 수열
    int dp[1001];   // dp[i]: 수열 a[i]까지 봤을 때, 가장 긴 증가하는 부분 수열 크기
    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> a[i];
        len = 0;

        for(int j = 0; j < i; j++) {
            // len 값이 이전 dp 값 중 가장 큰 값이 되도록 함
            if(a[i] > a[j]) {
                len = max(dp[j], len);
            }
        }

        dp[i] = len + 1;    // dp[i] 값 갱신
        answ = max(answ, dp[i]);    // answ 값 확인
    }

    cout << answ << '\n';

    return 0;
}