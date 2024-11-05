// 오목
#include <iostream>
#include <vector>
using namespace std;

const int SIZE = 19;    
typedef pair<int, int> location;
int ground[SIZE][SIZE]; // (0~18) * (0~18) 바둑판 (인덱스 주의)
int moving[4][2] = {{0,1}, {1,0}, {1,1}, {-1,1}};  // 오른쪽, 아래, 우하향 대각선, 우상향 대각선 <- 가장 왼쪽 돌의 좌표 구해야 하니까 이 네방향 탐색한다
bool visited[SIZE][SIZE][4][2]; // [x][y][moving][1/2] : (x,y)자리에서 검은색/흰색 돌에 대해 moving 방향의 탐색 했는지 여부

// 오목인지 탐색한다.
int dfs(int r, int c, int dir, int stone, int cnt) {
    visited[r][c][dir][stone] = true;
    int newR = r + moving[dir][0];
    int newC = c + moving[dir][1];

    if (newR < 0 || newR >= SIZE || newC < 0 || newC >= SIZE || ground[newR][newC] != stone){
    // 바둑판을 벗어나거나, 다음에 오는 바둑돌의 색이 다를 때
        if (cnt == 5) {
        // 오목인 경우 (육목은 안됨)
            return stone;
        }
        else {
        // 오목이 아닌 경우
            return 0;
        }
    }

    // 다음 탐색
    return dfs(newR, newC, dir, stone, cnt + 1);
}

// 승자를 찾아서 반환한다.
int findWinner(location &answ_loc){

    // 위에서 아래로, 왼쪽에서 오른쪽으로 ground를 훑는다
    for (int i = 0; i < SIZE; i++){
        for (int j = 0; j < SIZE; j++){

            // 돌이 없으면 넘어가고
            if (ground[j][i] == 0){
                continue;
            }

            // 돌이 있으면 네 방향을 탐색한다
            for (int dir = 0; dir < 4; dir++) { 

                // 이미 해당 위치, 돌, 방향을 탐색했다면 넘어간다.
                if (visited[j][i][dir][ground[j][i]]) continue;

                // 해당 방향으로 탐색한 결과가 검이든 흰이든 오목이 나오면
                if (dfs(j, i, dir, ground[j][i], 1) != 0) {
                    answ_loc = {j, i};  // 오목의 가장 위쪽 돌 위치
                    return ground[j][i];    // 검흰 중 승자 반환
                }
            }

        }
    }

    return 0;   // 아직 승부가 결정되지 않음
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    location answ_loc;   // answ_loc: 오목 중에서 가장 왼쪽에 있는 바둑알

    // 입력
    for (int i = 0; i < SIZE; i++){
        for (int j = 0; j < SIZE; j++){
            cin >> ground[i][j];
        }
    }

    // 연산
    int answ = findWinner(answ_loc);    // answ: 승자 (0: 아직 없음, 1: 검, 2: 흰)

    // 출력
    cout << answ << '\n';
    if (answ){
        cout << answ_loc.first + 1 << " " << answ_loc.second + 1;
    }

    return 0;
}