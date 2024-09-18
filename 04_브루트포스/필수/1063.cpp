// 킹
#include <iostream>
#include <string>
using namespace std;

/*
8*8크기의 체스판
열은 가장 왼쪽 열이 A이고, 가장 오른쪽 열이 H까지 이고, 
행은 가장 아래가 1이고 가장 위가 8이다.

킹이 움직일 수 있는 8가지 방식
R : 한 칸 오른쪽으로 : (+1, 0)
L : 한 칸 왼쪽으로 : (-1, 0)
B : 한 칸 아래로 : (0, -1)
T : 한 칸 위로 : (0, +1)
RT : 오른쪽 위 대각선으로 : (+1, +1)
LT : 왼쪽 위 대각선으로 : (-1, +1)
RB : 오른쪽 아래 대각선으로 : (+1, -1)
LB : 왼쪽 아래 대각선으로 : (-1, -1)

*/
void setAb(int &a, int&b, string movement){
    if (movement == "R"){
        a = 1; b = 0;
    }
    else if (movement == "L"){
        a = -1; b = 0;
    }
    else if (movement == "B"){
        a = 0; b = -1;
    }
    else if (movement == "T"){
        a = 0; b = 1;
    }
    else if (movement == "RT"){
        a = 1; b = 1;
    }
    else if (movement == "LT"){
        a = -1; b = 1;
    }
    else if (movement == "RB"){
        a = 1; b = -1;
    }
    else if (movement == "LB"){
        a = -1; b = -1;
    }
}

// 열을 알파벳에서 정수로 바꿔 표현. (A ~ H) -> (1 ~ 8)
int toInt(char c){
    string row  = "rABCDEFGH";
    for (int i = 0; i < row.size(); i++){
        if (c == row[i]){
            return i;
        }
    }
    return -1;  // 유효하지 않은 입력
}

// 열을 정수에서 알파벳으로 바꿔 표현. (1 ~ 8) -> (A ~ H)
char toAbc(int n){
    string row  = "rABCDEFGH";
    return row[n];
}

int moveKing(pair<int, int> &king, pair<int, int> &stone, string movement){
    int a, b;   //a: 가로방향 움직임, b: 세로방향 움직임
    setAb(a,b,movement);    // 킹의 움직임 a, b를 설정한다.

    king.first += a; king.second += b;  // 킹을 a,b 만큼 움직인다
    if (king.first < 1 || king.first > 8 || king.second < 1 || king.second > 8){  // 움직였는데 킹이 체스판 밖으로 나가는 경우
        // 킹 원상복귀
        king.first -= a; king.second -= b;
        return 0;
    }

    if (king.first == stone.first && king.second == stone.second){ // 킹을 움직였는데 돌이 있는 칸일 때
        stone.first += a; stone.second += b;    // 돌도 같은 방향으로 움직임
        if (stone.first < 1 || stone.first > 8 || stone.second < 1 || stone.second > 8){   // 근데 돌이 체스판 밖으로 나가는 경우
            // 돌도 원상복귀, 킹도 원상복귀
            stone.first -= a; stone.second -= b;
            king.first -= a; king.second -= b;
        }
    }

    return 0;
}

int main(){
    // 입출력 속도 향상
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);  cout.tie(NULL);

    string str_king;    // str_king: 입력받은 킹의 위치
    string str_stone;   // str_stone: 입력받은 돌의 위치
    int n;  // n: 움직이는 횟수
    string movement;    // movement: 입력받은 킹의 움직임 명령어 (8가지)
    pair<int, int> king;     // king: 킹의 현재 위치. first에 숫자로 바꾼 열, second에 행을 저장한다.
    pair<int, int> stone;    // stone: 돌의 현재 위치. (숫자로 바꾼 열, 행)

    // 입력: 킹의 초기 위치, 돌의 초기 위치, 움직임 개수
    cin >> str_king >> str_stone >> n;

    // 킹과 돌의 초기 위치 세팅
    king.first = toInt(str_king[0]); king.second = str_king[1] - '0'; 
    stone.first = toInt(str_stone[0]); stone.second = str_stone[1] - '0';

    // 입력 및 킹 위치 변화
    for (int i=0; i<n; i++){
        cin >> movement;
        moveKing(king, stone, movement);
    }

    // 출력: 킹의 마지막 위치, 돌의 마지막 위치
    cout << toAbc(king.first) << king.second << '\n'; 
    cout << toAbc(stone.first) << stone.second;

    return 0;
}