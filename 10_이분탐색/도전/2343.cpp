// 기타 레슨
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// 블루레이 크기가 capacity 인 m개의 블루레이에 담을 수 있는지 확인
bool isPossible(const vector<int> &arr, int m, int capacity){
    // cnt: 사용한 블루레이의 개수, sum: 현재 강의를 담고있는 블루레이를 얼만큼 사용했는지
    int cnt = 1, sum = 0;
    for (int l : arr){
        if (sum + l > capacity){    // 해당 강의를 넣으면 블루레이 용량을 초과하는 경우
            // 새로운 블루레이에 강의를 담기 시작한다
            cnt++;  
            sum = l;
        }
        else {
            // 강의를 담던 블루레이에 계속 담는다
            sum += l;
        }
    }

    bool answ = (cnt <= m);
    return answ;
}

// 이분탐색: 가능한 최소의 블루레이 크기를 구한다
int binarySearch(const vector<int> &arr, int m, int max_length, int total_length){
    // 블루레이 크기의 최솟값은 가장 긴 강의의 길이이고, 최댓값은 전체 강의 길이의 합이다
    int left = max_length, right = total_length;
    int answ = total_length; 

    while(left <= right){
        int mid = (left + right) / 2;
        if (isPossible(arr, m, mid)){   // 크기 mid인 블루레이들에 담을 수 있다면
            // answ 값 갱신하고, 블루레이 크기 더 줄일 수 있는지 확인한다
            answ = mid;
            right = mid - 1;
        }
        else{   // 크기 mid인 블루레이들에 담을 수 없다면
            // 블루레이 크기를 키워서 탐색한다
            left = mid + 1;
        }
    }

    return answ;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;  // n: 블루레이에 들어가는 강의의 개수
    int m;  // m: 블루레이의 개수 (모두 같은 크기)
    vector<int> arr;    // arr: 각 강의의 길이(분단위, 이 순서 유지)
    int max_length = 0; // max_length: 강의 중 가장 긴 강의의 길이
    int total_length = 0;   // total_length: 전체 강의 길이의 합
    int answ;    // answ: 최소가 되는 블루레이의 크기

    // 입력
    cin >> n >> m;
    arr.assign(n, 0);
    for (int i = 0; i < n; i++){
        cin >> arr[i];
        max_length = max(max_length, arr[i]);
        total_length += arr[i];
    }

    // 연산
    answ = binarySearch(arr, m, max_length, total_length);

    // 출력
    cout << answ;
}