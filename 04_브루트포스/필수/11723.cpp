// 집합
// 비트마스크
#include <iostream>
#include <string>
using namespace std;

void all(int &s){   // s의 1부터 20까지의 인덱스의 비트 필드를 1로 채운다.
    s = (1 << 21) - 1;
}
void empty(int &s){ // s의 1부터 20까지의 인덱스의 비트 필드가 0이 되도록 한다.
    s = 0;
}
void add(int &s, int x){    // s의 인덱스 x인 비트 필드를 1로 만든다.
    int temp = 1 << x;
    s = s | temp;   // or 연산
}
void remove(int &s, int x){    // s의 인덱스 x인 비트 필드를 0으로 만든다.
    int temp = 1 << x;
    s = s & (~temp);   // a-b = a&(~b)
}
int check(int &s, int x){    // s의 인덱스 x인 비트 필드가 0이면 0, 1이면 1을 반환한다.
    int temp = 1 << x;
    int answ = (s & temp)? 1: 0;
    return answ;
}
void toggle(int &s, int x){   
    if (check(s,x)){  // s의 인덱스 x인 비트 필드가 0이면 1로 만든다.
        remove(s,x);
    }
    else {  // s의 인덱스 x인 비트 필드가 1이면 0으로 만든다.
        add(s,x);
    }
}

int main(){
    // 입출력 속도 향상
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);  cout.tie(NULL);

    int s = 0;  // s: 1부터 20까지 인덱스의 비트필드를 사용 
    int m;  // m: 수행해야 하는 연산의 수
    cin >> m;
    
    while (m--){
        string input;   // input: 입력받은 수행해야 하는 명령어
        cin >> input;

        if (input == "all"){ // S를 {1, 2, ..., 20} 으로 바꾼다.
            all(s); 
            continue;
        }
        else if (input == "empty"){ // S를 공집합으로 바꾼다.
            empty(s);   
            continue;
        }

        int x;  // x: 명령어가 all, empty일 때 빼고는 필요함. (x는 1이상 20이하)
        cin >> x;

        if (input == "add"){ // S에 x를 추가한다. x가 이미 있는 경우에는 연산을 무시한다.
            add(s,x);   
        }
        else if (input == "remove"){ // S에서 x를 제거한다. S에 x가 없는 경우에는 연산을 무시한다.
            remove(s,x);    
        }
        else if (input == "check"){ // S에 x가 있으면 1을, 없으면 0을 출력한다.
            cout << check(s,x) << '\n';
        }
        else if (input == "toggle"){ // S에 x가 있으면 x를 제거하고, 없으면 x를 추가한다.
            toggle(s,x);
        }
    }

    return 0;
}