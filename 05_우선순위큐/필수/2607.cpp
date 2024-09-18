// 비슷한 단어
#include <iostream>
#include <string>
using namespace std;

// 비슷한 단어인지 체크하는 함수: 비슷한 단어면 1, 아니면 0을 반환한다.
int checkWord(string w1, string w2){
    int w1_size = w1.size(); int w2_size = w2.size(); 
    // 일단 길이가 2 이상 차이나면 비슷한 단어가 될 수 없음
    if (abs(w1_size - w2_size) > 1){ 
        return 0;
    }
    // w1이 w2보다 길거나 같은 문자열이 되도록 한다.
    if (w1_size < w2_size){
        swap(w1, w2);
    }

    int cnt = 0; // cnt: w2에 있는 char 중에 w1에 없는 char의 개수
    for (char c : w2){    // w2의 문자들이 w1에도 있는지 확인한다
        int is_in_w1 = w1.find(c);
        if (is_in_w1 == -1){    // w1에 없는 경우, cnt에 1을 더한다
            cnt += 1;
        }
        else {  // w1에 있는 경우, w1에서 해당 문자를 삭제한다
            w1.erase(is_in_w1, 1);
        }
        if (cnt > 1){
            return 0;
        }
    }
    if (w1.size() > 1){ // w2의 모든 문자들을 확인한 후, w1에 남은 문자가 2 이상이면
        return 0;
    }    
    
    return 1;
}

int main(){
    // 입출력 속도 향상
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n; // n: 단어의 개수(100이하)
    string first_word; // first_word: 비슷한 단어 비교 기준이 되는 단어
    string input_word; // input_word: 입력받은 단어 (영문 대문자 알파벳으로 구성) (길이 10 이하)
    int answ = 0; // answ: 입력으로 주어진 첫 번째 단어와 비슷한 단어의 개수
    
    // 입력
    cin >> n;
    cin >> first_word;

    for (int i = 0; i < n-1; i++){
        cin >> input_word;
        answ += checkWord(first_word, input_word);
    }

    // 출력
    cout << answ;
    
    return 0;
}