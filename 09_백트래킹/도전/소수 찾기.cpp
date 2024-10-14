// 프로그래머스 소수찾기
// https://school.programmers.co.kr/learn/courses/30/lessons/42839

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

string s;
vector<bool> primes;
int s_size;
set<int> answ;

// 소수 찾기 (에라토스테네스의 체)
void findPrime(int n){
    primes.assign(n + 1, true);
    primes[0] = primes[1] = false;

    for (int i = 2; i * i <= n; i++){
        if (primes[i]){
            for (int j = i * i; j <= n; j += i){
                primes[j] = false;
            }
        }
    }
    return;
}

void bt(int cnt, int len, string cur){
    if (cnt == len) {
        if (!cur.empty()){
            // 소수라면 answ에 넣는다
            int num = stoi(cur);
            if (primes[num]) answ.insert(num);
        }
        return;
    }

    for (int i = 0; i < s_size; i++){
        if (s[i] == 'x') continue;  // 사용한 숫자는 스킵
        char temp = s[i];
        s[i] = 'x';
        bt(cnt + 1, len, cur + temp);
        s[i] = temp;
    }
    
}

int solution(string numbers) {
    s_size = numbers.size();
    s = numbers;

    sort(numbers.begin(), numbers.end(), greater<char>());
    int max_n = stoi(numbers);
    findPrime(max_n);
    
    for (int i = 1; i <= s_size; i++){
        bt(0, i, "");
    }
    
    return answ.size();
}

// 점검용 : 프로그래머스 제출 시 제외하기
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    string numbers;
    cin >> numbers;
    cout << solution(numbers) << '\n';
    for (auto iter = answ.begin(); iter != answ.end(); iter++){
        cout << *iter << "\n";
    }

    return 0;
}