// 과자 나눠주기
#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define MAX_COOKIE 1000000000

// 길이 l 일 때 최대 몇명에게 과자를 줄 수 있는지 
int cntCookie(const vector<int> &cookies, int l){
    int cnt = 0;
    // for (int i = cookies.size() - 1; i >= 0; i--){
    //     int q = cookies[i] / l;
    //     cnt += q;
    //     if (q == 0) {
    //         return cnt;
    //     }
    // }
    for (int i = 0; i < cookies.size(); i++){
        cnt += cookies[i] / l;
    }
    return cnt;
}

// 이분 탐색: 조카 1명에게 줄 수 있는 막대과자의 최대 길이를 반환한다
int binarySearch(const vector<int> &cookies, int m){
    int right = MAX_COOKIE;
    int left = 1;   // 과자의 최소 길이
    int answ = 0;   // 반환할 답

    while (left <= right){
        int mid = (left + right) / 2;
        int cnt = cntCookie(cookies, mid);  // cnt: 길이 mid인 쿠키를 나눠줄 수 있는 조카의 수

        if (cnt >= m){  // cnt 가 나눠줘야하는 조카의 수보다 크거나 같을 때
            left = mid + 1; // 더 긴 쿠키 탐색
            answ = mid; // answ 값에 mid 저장
        }
        else{   // cnt 가 나눠줘야하는 조카의 수보다 작을 때
            right = mid - 1;    // 더 짧은 쿠키 탐색
        }
    }

    return answ;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int m;  // m: 조카의 수
    int n;  // n: 과자의 수
    vector<int> cookies;    // cookies: n개의 과자들의 길이
    int answ;   // answ: 조카 1명에게 줄 수 있는 막대 과자의 최대 길이

    // 입력
    cin >> m >> n;
    cookies.assign(n, 0);
    for (int i = 0; i < n; i++){
        cin >> cookies[i];
    }

    // 연산 및 출력
    answ = binarySearch(cookies, m);
    cout << answ;
}
