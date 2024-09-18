// 행운의 바퀴
// 중복 체크 안하면 틀림
#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main(){
    // 입출력 속도 향상
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);  cout.tie(NULL);

    int n, k; // n: 바퀴의 칸 수, k: 바퀴를 돌리는 횟수 
    int in_int; // 화살표가 가리키는 글자가 몇번 바뀌었는지
    char in_char; // 이때 화살표가 가리키는 글자
    int ptr = 0; // ptr: 화살표가 현재 가리키는 칸
    bool is_wheel = true;   // is_wheel: 해당 행운의 바퀴가 존재하는지 여부

    cin >> n >> k;
    vector<char> wheel(n, '?'); // 행운의 바퀴
    set<char> wheel_char;   // 바퀴 내 중복되는 글자 체크 용도

    while(k--){
        cin >> in_int >> in_char;
        ptr = (ptr + in_int) % n;

        else if (wheel[ptr] == '?'){ 
            // 현재 화살표가 가리키는 칸에 정해진 알파벳이 없는 경우  
            if (wheel_char.find(in_char) != wheel_char.end()){  
                // 바퀴에 같은 글자가 등장하는 경우
                is_wheel = false;
            }
            else{
                // 문제 없는 경우
                wheel[ptr] = in_char;
                wheel_char.insert(in_char);
            }
        }
        else if (wheel[ptr] != in_char){
            // 현재 화살표가 가리키는 칸에 이미 정해진 알파벳과 모순되는 경우     
            is_wheel = false;
        }
    }

    // 출력
    // 해당 행운의 수레바퀴가 없는 경우
    if(!is_wheel){  
        cout << "!";
        return 0;
    }
    // 해당 행운의 수레바퀴가 정상적으로 존재하는 경우
    for(int i = n; i > 0; i--){
        cout << wheel[(ptr + i) % n];
    }

    return 0;
}