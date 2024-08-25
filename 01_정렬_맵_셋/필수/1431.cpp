// 시리얼 번호
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

// 시리얼 번호 안의 숫자 합 구하는 함수
int sumNum(string s){
    int sum = 0;
    for (int i = 0; i < s.size(); i++){
        if (isdigit(s[i])){
            sum += s[i] - '0';
        }
    }
    return sum;
}

// 비교 함수
bool cmp(const string& a, const string& b){
    if (a.size() != b.size()){  // 길이 다를 때: 짧은 것이 먼저
        return a.size() < b.size();
        
    }
    if (sumNum(a) != sumNum(b)){  // 길이 같을 때: 숫자 합 작은 것이 먼저
        return sumNum(a) < sumNum(b);
    }
    return a < b;   // 길이, 숫자 합 같을 때: 사전순 (숫자가 알파벳보다 먼저)
}

int main()
{
    int n;
    string input;
    vector<string> inputs;
    
    // 입력
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> input;
        inputs.push_back(input);
    }

    // 연산
    sort(inputs.begin(), inputs.end(), cmp);

    // 출력
    for (int i = 0; i < n; i++){
        cout << inputs[i] << '\n';
    }
    
    return 0;
}