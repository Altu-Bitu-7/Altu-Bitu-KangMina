// 뱀
#include <iostream>
#include <vector>
#include <deque>
#include <map>
using namespace std;

// 방향 벡터 (동, 남, 서, 북 순서)
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};

// 
int runGame(int n, vector<vector<int>> &board, deque<pair<int, int>> &snake, map<int, char> &directions){
    int time = 0, dir = 0; // 시간, 초기 방향(동쪽)
    
    while (true) {
        ++time;

        // 현재 머리 위치와 새 위치 계산
        int x = snake.front().first;
        int y = snake.front().second;
        int nx = x + dx[dir];
        int ny = y + dy[dir];

        // 벽이나 자기 몸과 부딪혔는지 확인
        if (nx <= 0 || ny <= 0 || nx > n || ny > n || board[nx][ny] == 2) {
            return time; // 게임 종료
        }

        // 이동한 칸에 사과가 있는 경우
        if (board[nx][ny] == 1) {
            board[nx][ny] = 2; // 머리 위치 업데이트
            snake.push_front({nx, ny});
        }
        // 이동한 칸에 사과가 없는 경우
        else {
            board[nx][ny] = 2; // 머리 위치 업데이트
            snake.push_front({nx, ny});
            auto tail = snake.back(); // 꼬리 위치
            snake.pop_back();
            board[tail.first][tail.second] = 0; // 꼬리 위치 비우기
        }

        // 방향 변환 처리
        if (directions.count(time)) {
            char turn = directions[time];
            if (turn == 'L') {
                dir = (dir + 3) % 4; // 왼쪽 회전
            } else if (turn == 'D') {
                dir = (dir + 1) % 4; // 오른쪽 회전
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, k;  // n: 보드의 크기 (2 이상 100 이하), k: 사과의 개수 (0 이상 100 이하)
    int l;  // l: 뱀의 방향 변환 횟수

    // 보드 초기화
    cin >> n >> k;
    vector<vector<int>> board(n + 1, vector<int>(n + 1, 0));
    for (int i = 0; i < k; ++i) {
        int r, c;
        cin >> r >> c;
        board[r][c] = 1; // 사과 위치한 칸은 1로 표시
    }

    // 방향 변환 정보 입력
    cin >> l;
    map<int, char> directions;
    for (int i = 0; i < l; ++i) {
        int x;
        char c;
        cin >> x >> c;
        directions[x] = c;
    }

    // 뱀 초기화
    deque<pair<int, int>> snake;
    snake.push_back({1, 1});
    board[1][1] = 2; // 뱀이 위치한 칸은 2로 표시

    // 게임 실행 및 결과 출력
    cout << runGame(n, board, snake, directions) << '\n';

    return 0;
}