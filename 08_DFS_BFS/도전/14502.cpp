// 연구소
#include <iostream>
#include <vector>
using namespace std;

// 0은 빈 칸, 1은 벽, 2는 바이러스
// 새로 세울 수 있는 벽의 개수는 3개이며, 꼭 3개를 세워야 한다.
int lab[8][8];  // 입력받은 원본 실험실 상황
int lab_test[8][8]; // 바이러스 퍼뜨려서 개수 셀 떄 사용
int moving[4][2] = { {-1,0}, {1,0}, {0,-1}, {0,1} };    // 상하좌우 탐색
int virus[64][2];   // 바이러스들의 위치 저장
int n;  // n: 연구소의 세로 크기 (3이상 8이하)
int m;  // m: 연구소의 가로 크기 (3이상 8이하)
int x1, x2, x3, y1, y2, y3; // 새로 세울 벽 세개의 x좌표와 y좌표

// dfs 이용해 바이러스 퍼뜨린다.
void dfs(int x, int y){
    for (int i = 0; i < 4; i++){    // 상하좌우 탐색
        int new_x = x + moving[i][0];
        int new_y = y + moving[i][1];

        if (new_x > 0 && new_x<= n && new_y >0 && new_y <=m && !lab_test[new_x][new_y]){
            lab_test[new_x][new_y] = 2;
            dfs(new_x, new_y);
        }
    }   
    return;
}

// 얻을 수 있는 안전 영역의 최대 크기 찾는다
int calAnsw(int v_cnt) {
    int safe_max = 0;

    // 세개의 벽을 세우는 가능한 모든 경우에서
    for (int i = 0; i < n*m; i++){
        // 벽1 좌표 설정
        x1 = i / m + 1; // 행
        y1 = i % m + 1; // 열
        if (lab_test[x1][y1])   continue;
        for (int j = i + 1; j < n*m; j++){
            // 벽2 좌표 설정
            x2 = j / m + 1;
            y2 = j % m + 1;
            if (lab_test[x2][y2])   continue;
            for (int k = j + 1; k < n*m; k++){
                // 벽3 좌표 설정
                x3 = k / m + 1;
                y3 = k % m + 1;
                if (lab_test[x3][y3])   continue;

                // 세개의 벽을 세운 후
                lab_test[x1][y1] = 1;
                lab_test[x2][y2] = 1;
                lab_test[x3][y3] = 1;

                // 해당 상황에서 바이러스 퍼뜨려서
                // for (auto v:virus){
                //     int x = virus[0];
                //     int y = virus[1];
                //     dfs(x, y);
                // }
                for(int p=0;p<v_cnt;p++) {
					dfs(virus[p][0], virus[p][1]);
                }

                // 안전지대 개수를 센다
                int safe_cnt = 0;
                for (int p = 1; p <= n; p++){
                    for (int q = 1; q <= m; q++){
                        if (!lab_test[p][q]) {
                            safe_cnt++;
                        }
                    }
                }

                // 안전지대 크기 비교
                safe_max = max(safe_max, safe_cnt);

                // 다음 테스트 위해 lab_test 초기화(lab과 동일하게)
                for (int p = 1; p <= n; p++){
                    for (int q = 1; q <= m; q++){
                        lab_test[p][q] = lab[p][q];
                    }
                }
            }
        }

    }
    return safe_max;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int answ;   // answ: 얻을 수 있는 안전 영역의 최대 크기

    // 입력
    cin >> n >> m;
    int v_cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> lab[i][j];
            lab_test[i][j] = lab[i][j];

            if (lab[i][j] == 2){
                virus[v_cnt][0] = i;
                virus[v_cnt][1] = j;
                v_cnt++;
            }
        }
    }

    // 연산
    answ = calAnsw(v_cnt);

    // 출력
    cout << answ << '\n';

    return 0;
}
