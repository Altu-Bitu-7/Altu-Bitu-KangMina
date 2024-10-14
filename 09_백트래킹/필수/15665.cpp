// N과 M(11)
#include <iostream>
#include <vector>
#include <set>
#include <string>
using namespace std;

// N개의 자연수 중에서 M개를 고른 수열
// 같은 수를 여러 번 골라도 된다
// 중복되는 수열을 여러 번 출력하면 안된다
// 수열은 사전 순으로 증가하는 순서로 출력해야 한다

set<int> numbers;
set<vector<int>> sequences;
vector<int> seq;
int n, m;

void backtrack(int cnt){
    if (cnt == m){
        sequences.insert(seq);
        return;
    }

    for (int n : numbers){
        seq[cnt] = n;
        backtrack(cnt + 1);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    // 입력
    cin >> n >> m;
    seq.assign(m, '0');
    int input;
    for (int i = 0; i < n; i++){
        cin >> input;
        numbers.insert(input);
    }

    // 연산
    backtrack(0);

    // 출력
    for (auto seq: sequences){
        for (auto c: seq){
            cout << c << ' ';
        }
        cout << '\n';
    }

    return 0;
}