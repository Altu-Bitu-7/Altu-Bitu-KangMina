// 숫자 카드
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// 상근이가 카드 가지고 있는지 이분탐색한다
int isExist(const vector<int> &cards, int n, int num){
    int left = 0, right = n - 1, mid;
    while(left <= right){
        mid = (left + right) / 2;
        if (cards[mid] == num){
            return 1;
        }
        else if (cards[mid] < num){
            left = mid + 1;
        }
        else if (cards[mid] > num){
            right = mid - 1;
        }
    }
    return 0;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n;  // n: 상근이가 가지고 있는 숫자 카드의 개수
    int m;  // m: 보유 여부 판단할 카드 개수
    vector<int> cards;  // cards: 숫자 카드에 적혀있는 n개의 정수 (중복 없음)
    vector<int> nums; // nums: 상근이가 가지고 있는지 확인할 m개의 정수

    // 입력
    cin >> n;
    cards.assign(n, 0);
    for (int i = 0; i < n; i++){
        cin >> cards[i];
    }
    cin >> m;
    nums.assign(m, 0);
    for (int i = 0; i < m; i++){
        cin >> nums[i];
    }

    // 연산 및 출력
    sort(cards.begin(), cards.end());   // 이분탐색 위한 정렬
    for (int num : nums){
        cout << isExist(cards, n, num) << " ";
    }
}