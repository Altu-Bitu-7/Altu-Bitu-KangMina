// 영화감독 숌
#include <iostream>
using namespace std;

// 해당 숫자가 종말의 수인지 확인한다. 종말의 수일 때는 1, 아닐 때는 0을 반환한다.
int isNumber(int num){
    int cnt6 = 0;   // 연속된 6의 개수
    int q = num;    // q는 몫, r은 나머지
    
    // 1의 자리 숫자부터 6인지 확인한다.
    while(q != 0){
        int r = q % 10;
        cnt6 = (r == 6)? cnt6+1 : 0;
        if (cnt6 == 3){ // 연속으로 세번 6이 나왔을 때
            return 1;   // 종말의 수이다!
        }
        q /= 10;   
    }

    return 0;
}

// n 번째 작은 종말의 수를 구한다.
int countNum(int n){
    int cnt = 0;   // 지금까지 센 종말의 숫자 개수
    int check = 666;    // 종말의 수인지 확인할 숫자

    // 숫자 666부터 1씩 더해가며 해당 숫자가 종말의 숫자인지 확인한다
    while(cnt != n){ // 지금까지 센 종말의 숫자 개수가 n이 아직 아닐 때
        cnt += isNumber(check);
        check += 1; // 다음에 확인할 종말의 수
    }
    
    return check-1;
}

int main(){
    int n;  // n: 몇 번째 영화의 수를 구해야 하는지 입력받음
    int answ;   //answ: n 번째로 작은 종말의 수

    // 입력
    cin >> n;

    // n 번째로 작은 종말의 수 연산
    answ = countNum(n);

    // 출력
    cout << answ;
    return 0;
}