// 로봇 청소기
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}}; // 북, 동, 남, 서

// 청소하는 영역의 개수를 구한다.
int cleanRoom(int r, int c, int d, vector<vector<int>> room){
    int n = room.size();    
    int m = room[0].size();
    int cnt_clean = 0;

    while(true){
        // 현재 칸이 청소되지 않은 경우, 청소한다
        if (room[r][c] == 0){
            cnt_clean++;
            room[r][c] = 2;
        }

        // 현재 칸의 주변 4칸 확인 (현재방향의 반시계 90도 회전 방향부터)
        bool moved = false;
        for (int i = 0; i < 4; i++){
            // 전진 방향 확인
            d = (d + 3) % 4;
            int nr = r + dir[d][0];
            int nc = c + dir[d][1];

            if (nr < 0 || nr >= n || nc < 0 || nc >= m){
                continue;
            }

            // 현재 칸의 주변 4칸 중 청소되지 않은 빈 칸이 있는 경우,
            if (room[nr][nc] == 0){
                // 바라보는 방향을 기준으로 앞쪽 칸이 청소되지 않은 빈 칸인 경우 한 칸 전진한다.
                r = nr;
                c = nc;
                moved = true;
                break;
            }
        }
            
        // 현재 칸의 주변 4칸 중 청소되지 않은 빈 칸이 없는 경우,
        if (!moved){
            // 후진 방향 확인
            int nr = r - dir[d][0];
            int nc = c - dir[d][1];

            if (nr < 0 || nr >= n || nc < 0 || nc >= m){
                continue;
            }

            // 후진할 곳이 벽이 아니면 후진
            if (room[nr][nc] != 1) {
                r = nr;
                c = nc;
            } else {
                // 후진할 수 없으면 종료
                break;
            }
        }    
    }

    return cnt_clean;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    // 입력
    int n, m;   // 방의크기 n * m
    int r, c;   // 처음 로봇청소기 좌표 (r, c)
    int d;  // 처음에 로봇청소기가 바라보는 뱡향 (0-북, 1-동, 2-남, 3-서)
    vector<vector<int>> room;   // 각 칸의 상태 (0-빈칸, 1-벽)
    int answ; // 로봇청소기가 청소하는 칸의 개수

    cin >> n >> m;
    cin >> r >> c >> d;
    for (int i = 0; i < n; i++){
        vector<int> input(m, 0);
        for (int j = 0; j < m; j++){
            cin >> input[j];
        }
        room.push_back(input);
    }
    
    // 연산
    answ = cleanRoom(r, c, d, room);

    // 출력
    cout << answ << '\n';

    return 0;
}