// 적록색약
#include <iostream>
#include <vector>
#include <cstring>  // visited memset
using namespace std;

const int SIZE = 100;
char grid[SIZE + 1][SIZE + 1];
bool visited[SIZE + 1][SIZE + 1];
int moving[4][2] = { {-1,0}, {1,0}, {0,-1}, {0,1} };   // 상하좌우 탐색
// 그리드의 각 칸에 R(빨강), G(초록), B(파랑) 중 하나 있다
// 적록색약이 아닌 사람은 구역을 R, G, B의 3색으로 구분한다.
// 적록색약인 사람은 구역을 R-G, B의 2색으로 구분한다.(R과 G를 구분하지 않는다.)

// dfs 이용해 영역을 탐색한다.
void dfs(int x, int y){
    if (visited[x][y])  {   // 방문한 적 있는 칸이면
        return;
    }
    visited[x][y] = true;   // 방문 표시

    for (int i = 0; i < 4; i++){    // 상하좌우 탐색
        int new_x = x + moving[i][0];
        int new_y = y + moving[i][1];

        if ((grid[x][y] == grid[new_x][new_y]) && !visited[new_x][new_y]){
            // 다음 칸과 동일한 색상이고(같은 구역), 다음 칸이 방문한 적이 없는 칸이면
            // 다음 칸으로 dfs 를 이어간다
            dfs(new_x, new_y);
        }
    }   
}

// 그리드의 R을 G로 바꾼다 (문제상 R과 G를 동일하게 취급하는 적록색약 구역계산 위해)
void changeRG(int n){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){

            if (grid[i][j] == 'R'){
                grid[i][j] = 'G';
            }

        }
    }
}

// 구역의 개수 계산
int calZone(int n) {
    int cnt = 0;

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){

            if (!visited[i][j]){
                dfs(i, j);
                cnt++;
            }

        }
    }

    return cnt;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;  // n: 그리드의 크기
    int answNo;  // answNo: 적록색약이 아닌 사람이 봤을 때의 구역의 개수
    int answYes;  // answYes: 적록색약인 사람이 봤을 때의 구역의 수

    // 입력
    cin >> n;
    //vector<vector<char>> grid(n, vector<char>(n, 0)); // grid: n*n 칸 가짐
    for (int i = 0; i < n; i++) {
        string input;
        cin >> input;
        for (int j = 0; j < n; j++) {
            grid[i][j] = input[j];
        }
    }

    // 연산
    // 적록색약이 아닌 사람이 본 구역의 개수 계산
    answNo = calZone(n);

    // 적록색약인 사람이 본 구역의 개수 계산
    memset(visited, false, sizeof(visited));
    changeRG(n);
    answYes = calZone(n);

    // 출력
    cout << answNo << " " << answYes << "\n";

    return 0;
}