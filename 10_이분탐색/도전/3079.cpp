// 입국심사
#include <iostream>
#include <vector>
using namespace std;

// 시간이 t 일 때, 몇명까지 입국심사를 마칠 수 있는지 계산한다.
long long calCnt(const vector<int> &arr, int m, long long t){
    long long cnt = 0;
    for (int i = 0; i < arr.size(); i++){
        cnt += (t / arr[i]);
        if (cnt >= m) break;
    }
    return cnt;
}

// 이분 탐색: 상근이와 친구들이 심사를 마치는데 걸리는 시간의 최솟값을 구한다
long long binarySearch(const vector<int> &arr, int m){
    // 걸리는 시간의 최솟값은 1에서 시작하고 최댓값은 1^18이다(m최댓값 * 소요시간최댓값)
    long long low = 1, high = 1e18;
    while (low < high){
        // cnt(시간이 mid일 때 몇명까지 입국심사를 마칠 수 있는지)를 계산한다.
        long long mid = (low + high) / 2;
        long long cnt = calCnt(arr, m, mid);

        // cnt가 주어진 m보다 크면, 더 작은 시간을 탐색한다
        if (cnt >= m){
            high = mid;
        }
        // cnt가 주어진 m보다 작거나 같으면, 더 큰 시간을 탐색한다
        else{
            low = mid + 1;
        }
    }

    return low;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;  // n: 입국심사대 개수
    int m;  // m: 상근이와 친구들 명수 (1이상 1^9이하)
    vector<int> arr;    // arr: 각 입국심사대에서 걸리는 시간 (시간은 1이상 1^9이하)
    // int answ;    // answ: 상근이와 친구들이 심사를 마치는데 걸리는 시간의 최솟값
    long long answ;    // answ: 상근이와 친구들이 심사를 마치는데 걸리는 시간의 최솟값

    // 입력
    cin >> n >> m;
    arr.assign(n, 0);
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }

    // 연산
    answ = binarySearch(arr, m);

    // 출력
    cout << answ << '\n';

    return 0;
}