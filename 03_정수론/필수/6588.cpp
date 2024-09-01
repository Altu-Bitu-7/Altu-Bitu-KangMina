// 골드바흐의 추측
#include <iostream>
#include <vector>

using namespace std;
const int MAX = 1000000; // 테스트 케이스 및 n의 최대 범위

// n 이하의 홀수인 소수를 찾는다. (에라토스테네스의 체)
void findOddPrime(vector<bool> &primes, int n){
    primes[0] = primes[1] = false;  // 0과 1은 소수가 아님

    for (int i = 2; i * i <= n; i++){
        if (primes[i]){
            for (int j = i * i; j <= n; j += i){
                primes[j] = false;
            }
        }
    }

    primes[2] = false;  // 2는 홀수가 아님
}

// 골드베르크 추측을 증명하는 a를 찾아서 반환한다. (찾지 못한 경우 0반환)
int testConjecture(const vector<bool>& primes, int n){
    for (int i = 3; i <= n / 2; i += 2){
        if (primes[i]){
            int b = n - i;
            if (primes[b]){
                return i;
            }
        }
    }
    return 0;   // 두 홀수 소수의 합으로 n을 나타낼 수 없는 경우 n = 0
}

int main(){
    // 입출력 속도 향상
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);  cout.tie(NULL);

    int input; // 4 초과 1000000 이하의 짝수 정수 (6,8,10, ... , 1000000)
    vector<int> testcases;
    int max_n = 4; // 테스트 케이스 중 가장 큰 숫자 

    // 첫 테스트 케이스 입력받음
    cin >> input;   
    while(input != 0){
        testcases.push_back(input);
        if (input > max_n){
            max_n = input;
        }
        // 다음 테스트 케이스 입력받음
        cin >> input;   
    }

    // max_n 까지의 홀수 소수 찾기
    vector<bool> primes(max_n + 1, true); // 각 primes[i]에 i가 홀수 소수인지 저장
    findOddPrime(primes, max_n);    // max_n 까지의 홀수 소수 찾아놓기

    // 각 테스트 케이스별 검증 및 출력
    for (int n : testcases){
        int a = testConjecture(primes, n);   // 골드베르크 추측 검증
        
        if (a){
            cout << n << " = " << a << " + " << n - a << '\n';
        }
        else{
            cout << "Goldbach's conjecture is wrong." << '\n';
        }
    }

    return 0;
}