// 꽃길
#include <iostream>
#include <vector>
using namespace std;

int dir[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
bool visited[10][10];   // 꽃을 심었는지 여부 저장

// 꽃(십자가 모양 5칸 차지함) 3개가 최소의 가격으로 필 수 있도록 하기
// 꽃끼리 서로 겹치거나 꽃잎이 화단 밖으로 나가면 꽃이 죽음

int main(){
    // 입출력 속도 향상
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n; // n: 화단의 한 변의 길이 (6 이상 10 이하)
    int input; // input: 입력받은 화단의 지점당 가격 (n^2번 입력받음)
    int min_cost;   // min_cost: 꽃을 심기 위한 최소 비용
    vector<vector<int>> ground; // ground: 화단의 각 칸의 가격을 저장할 벡터
    // [0][0] 부터 [n-1][n-1] 까지의 인덱스에 n^2 개의 가격 입력받아 저장한다.


    // 입력
    cin >> n;
    // vector<vector<int>> ground(n, vector<int>(n,0));
    for (int i = 0; i < n; i++){
        vector<int> row;    // row: ground 벡터에 값 입력받을 때 사용
        for (int j = 0; j < n; j++){
            cin >> input;
            row.pushback(input);
        }
        ground[i].pushback(row);
        //ground.pushback(row);
    }

    // 연산
    min_cost = findMinCost(ground);

    // 출력
    cout << min_cost;

    retrun 0;
}

int findMinCost(vector<vector<int>> ground){
    int min_cost;
    
    for (int i = 1; i < n - 1; i++) {
		for (int j = 1; j < n - 1; j++) {
			int sum= sumCost(i, j);
			dfs(i, j, 1, sum);
			resetVisited(i, j);
		}
	}
    return min_cost;
    // 씨앗 심을 자리 3개 골라서
    // 인덱스 1부터 n-1까지만 탐색하면 된다 (가장자리에 심으면 죽음)
    // 고르면서(더하면서) min_cost랑 비교
}

// 해당 자리에 씨앗을 심었을 때 드는 비용 (5지점의 가격을 더한다)
int calCost(vector<vector<int>> ground, int row, int col){
    int cost;
    cost = ground[row, col] + ground[row-1,col] + ground[row+1,col] + ground[row,col-1] + ground[row,col+1];
    return cost;
}

// 해당 자리에서 꽃을 지움(visited의 다섯 자리를 false로 바꿈)
void resetVisited(int row, int col){
    visited[row][col] = false;

    for(int i=0; i<4; i++){
        int r = row + dir[i][0];
        int c = col + dir[i][1];
        visited[r][c] = false;
    } 
}

// 해당 자리에 꽃을 심는다면
int sumCost(int row, int col){
    // 사방을 확인함, 겹쳐서 꽃이 죽는 경우:
    for(int i=0; i<4; i++){ 
        int r = row + dir[i][0];
        int c = col + dir[i][1];
        if (visited[r][c]){ 
            return -1;  // -1을 반환
        }
    }

    // 꽃이 죽지 않는 경우: 꽃을 심는다(visited 변화), 합 반환
    int sum = ground[row][col];
    for(int i=0; i<4; i++){
        int r = row + dir[i][0];
        int c = col + dir[i][1];
        visited[r][c] = true;
        sum += ground[r][c];
    }
    return sum;
}

// 탐색
void dfs(int row, int col, int cnt, int cost){
    if (cnt == 3){
        min_cost = min(min_cost, cost)
        return;
    }
    for (int i = row; i < n-1; i++){
        for (int j = 1; j < n-1; j++){
            if (visited[i][j]){
                continue;
            }
            int sum = sumCost(i,j);
            if (sum != -1){
                dfs(i, j, cnt+1, cost + sum);
                resetVisited(i,j);
            }
        }
    }
}