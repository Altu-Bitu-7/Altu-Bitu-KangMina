// 계단 오르기
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 다음 계단 혹은 다다음 계단을 밟을 수 있음
// 연속 3개 계단 밟으면 안됨
// n 번째 계단 (마지막 계단) 반드시 밟아야 함

int stairGame(int n, const vector<int> stair){
    vector<int> dp(n + 1, 0); // dp[i]: i번째 계단을 밟았을 때의 최대 점수

    // dp 테이블 채우기 전 준비
    // 두 번째 계단까지 고려
    dp[1] = stair[1];
    if (n > 1) {
        dp[2] = stair[1] + stair[2]; 
    }

    // dp 테이블 채우기
    for (int i = 3; i <= n; i++) {
        dp[i] = max(dp[i - 2], dp[i - 3] + stair[i - 1]) + stair[i];
    }
    
    return dp[n];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;  // n: 계단의 개수
    vector<int> stair;  // stair[i] : i번째 계단에 있는 점수
    int answ;   // answ: 계단 오르기 게임에서 얻을 수 있는 총 점수의 최댓값

    // 입력
    cin >> n;
    stair.assign(n + 1, 0);
    for (int i = 1; i <= n; i++){
        cin >> stair[i];
    }

    // 연산
    answ = stairGame(n, stair);

    // 출력
    cout << answ << '\n';

    return 0;
}