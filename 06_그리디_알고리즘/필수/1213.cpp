// 팰린드롬 만들기
#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
홀수개는 하나까지만 되고, 그 이외에는 다 짝수개 있어야함
정답이 여러 개일 경우에는 사전순으로 앞서는 것을 출력
*/

// 단어 받아서 팰린드롬 만든다
string makePalin(string name){
    vector<int> alphabet_count(26,0);  // alphabet_count: 알파벳별 등장 횟수 저장할 벡터
    for (char c : name){    
        // 인덱스 0~25에 A~Z를 저장한다
        alphabet_count[c - 'A']++;  
    }

    string half, middle = "", r_half;
    int odd_cnt = 0; // odd_cnt: 홀수개 알파벳 등장 횟수
    for (int i = 0; i < 26; i++){
        if (alphabet_count[i] % 2 == 1){    // 해당 알파벳 홀수개일때
            odd_cnt++;
            middle = char(i + 'A');
        }
        half.append(alphabet_count[i] / 2, (char)(i + 'A'));
    }

    if (odd_cnt > 1){
        return "I'm Sorry Hansoo";
    }
    r_half = string(half.rbegin(), half.rend());

    return half + middle + r_half;
}

int main(){
    string name;    // name: 임한수의 영어 이름 (알파벳대문자, 50자 이하)
    string answ;    // answ: name을 팰린드롬으로 바꿈

    // 입력
    cin >> name;

    // 연산
    answ = makePalin(name);

    // 출력
    cout << answ;
}