// 연산자 끼워넣기
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 주어진 수의 순서를 바꾸면 안 된다.
// 식의 계산은 연산자 우선 순위를 무시하고 앞에서부터 진행해야 한다. 
// 나눗셈은 정수 나눗셈으로 몫만 취한다. 
// (0:+) (1:-) (2:*) (3:/)

int n;  // n: 수의 개수
vector<int> numbers;    // numbers: 수열, n개의 숫자
vector<int> oper(4);   // oper: +-*/ 의 개수, 합하면 n-1개
vector<int> re_oper;
int min_num = 1e9; 
int max_num = -1e9;
vector<int> cur;

void initReOper(){
    for (int i = 0; i < 4; i++){
        re_oper.insert(re_oper.end(), oper[i], i);
    }
    return;
}

int calNum(){
    int num = numbers[0];

    for (int i = 0; i < n-1; i++){
        switch (cur[i]){
            case 0:
                num += numbers[i + 1];
                break;
            case 1:
                num -= numbers[i + 1];
                break;
            case 2:
                num *= numbers[i + 1];
                break;
            case 3:
                if (numbers[i + 1] != 0) // 0으로 나누는 경우 방지
                    num /= numbers[i + 1];
                break;
        }
    }

    return num;
}

void bt(int cnt){
    if (cnt == n - 1){
        int curNum = calNum();
        min_num = min(min_num, curNum);
        max_num = max(max_num, curNum);
        return;
    }

    for (int i = 0; i < re_oper.size(); i++){
        if (re_oper[i] == -1){
            continue;
        }
        cur[cnt] = re_oper[i];
        int temp = re_oper[i];
        re_oper[i] = -1; // 연산자를 사용했음을 표시
        bt(cnt + 1);
        re_oper[i] = temp; // 사용한 연산자 반환
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    // 입력
    cin >> n;
    numbers.assign(n, 0);
    cur.assign(n - 1, -1);
    for (int i = 0; i < n; i++){
        cin >> numbers[i];
    }
    for (int i = 0; i < 4; i++){
        cin >> oper[i];
    }
    
    // 연산
    initReOper();
    bt(0);

    // 출력
    cout << max_num << '\n' << min_num;

    return 0;
}