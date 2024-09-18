// N번째 큰 수
#include <iostream>
#include <queue>
using namespace std;

// 모든 수는 자신의 한 칸 위에 있는 수보다 크다. 
// 표에 채워진 수는 모두 다르다.

// min_heap 우선순위큐 n_numbers 에는 딱 n개만 저장 -> 최종적으로 top이 n번째 큰 수가 되도록)
// 새로 들어온 input과 top = q.top()을 비교할 것임
// input > top 이면 input을 q에 추가하고, top을 q에서 제거함
void checkNum(priority_queue<int, vector<int>, greater<int>> &n_numbers, int input){
    if (input > n_numbers.top()){
        n_numbers.push(input);
        n_numbers.pop();    // 가장 작은 값을 제거하여 크기를 유지
    }
}

int main(){
    // 입출력 속도 향상
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n; // n: n*n개의 수가 주어진다 (1이상 1500이하)
    int input; // input: 입력받는 정수 (n^2개 입력받음)
    int answ; // answ: 출력할 n번째 큰 수
    priority_queue<int, vector<int>, greater<int>> n_numbers; // n_numbers: answ 구하기 위한 min_heap 우선순위큐 

    // 입력
    cin >> n;
    // n_numbers에 n개의 값 저장
    for (int i = 0; i < n; i++){
        cin >> input;
        n_numbers.push(input);
    }
    for (int i = 0; i < n-1; i++){
        for (int j = 0; j < n; j++){
            cin >> input;
            checkNum(n_numbers, input);
        }
    }

    // 연산
    answ = n_numbers.top();

    // 출력
    cout << answ;
    
    return 0;
}