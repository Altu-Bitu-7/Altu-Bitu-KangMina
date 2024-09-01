// 소수상근수
#include <iostream>
#include <vector>
#include <set>
#include <string>

using namespace std;

// 소수 찾기 (에라토스테네스의 체)
void findPrime(vector<bool> &primes, int n){
    primes[0] = primes[1] = false;

    for (int i = 2; i * i <= n; i++){
        if (primes[i]){
            for (int j = i * i; j <= n; j += i){
                primes[j] = false;
            }
        }
    }
}

// 각 자리수의 제곱의 합 계산하기
int sumSquare(int n){
    // 문자열로 변환
    string s = to_string(n);    

    // 문자열 내의 각 문자마다 정수로 변환한 후에 합 구한다
    int answ = 0;
    for (char i : s){
        int tmp = i - '0';
        answ += (tmp * tmp);
    }

    return answ;
}

int sumSquare2(int n) {
    int answ = 0;
    while (n > 0) { // 0이 될 때까지
        int digit = n % 10;  // 1의 자릿수부터 구함
        answ += digit * digit;  // 구한 자릿수의 제곱을 더함
        n /= 10;  // 10으로 나눠서 다음(10배 큰) 자릿수 구함
    }
    return answ;
}

// 상근수인지 확인
bool checkNum(int n){
    // 그냥 끝날 때까지 계산하는건가..
    int tmp = sumSquare2(n); // tmp: 각 자릿수 제곱의 합
    set<int> nums;  // 지금까지 나왔던 합 저장할 셋

    while (tmp != 1){   // tmp가 1이 아닐 동안
        if (nums.find(tmp) != nums.end()){  // tmp가 셋에 이미 존재하는 경우
            return false;   // n은 상근수가 아니다(반복되니까)
        }
        nums.insert(tmp);   // 셋에 tmp 저장
        tmp = sumSquare2(tmp);   // tmp 업데이트
    }
    
    return true;    // tmp(각 자릿수 제곱의 합)이 1일 때 n은 상근수이다
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    // 입력
    int n;
    cin >> n;
    
    // n이하 소수 구한다
    vector<bool> primes(n+1, true);
    findPrime(primes, n);

    // 그중에서 상근수 찾는다.
    for (int i = 2; i <= n; i++){
        if (!primes[i]){
            continue;
        }
        if (checkNum(i)){ // 상근수인지 확인한다
            cout << i << '\n';
        } 
    }
    
    return 0;
}