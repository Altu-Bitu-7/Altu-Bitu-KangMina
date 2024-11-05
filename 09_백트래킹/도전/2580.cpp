// 스도쿠
#include <iostream>
#include <vector>

using namespace std;

const int SIZE = 9;

// 스도쿠 판을 출력
void printBoard(const vector<vector<int>>& board) {
    for (const auto& row : board) {
        for (int num : row) {
            cout << num << " ";
        }
        cout << "\n";
    }
}

// 현재 board에서 주어진 숫자 num이 해당 위치(row, col)에 놓일 수 있는지 확인
bool isValid(const vector<vector<int>>& board, int row, int col, int num) {
    // 가로세로줄 체크
    for (int i = 0; i < SIZE; i++) {
        if (board[row][i] == num || board[i][col] == num) {
            return false;
        }
    }

    // 3x3 박스 체크
    int startRow = row / 3 * 3;
    int startCol = col / 3 * 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[startRow + i][startCol + j] == num) {
                return false;
            }
        }
    }

    return true;
}

// 스도쿠를 해결
bool solveSudoku(vector<vector<int>>& board) {
    int row, col;
    bool emptyCell = false;

    // 빈 칸 찾기
    for (row = 0; row < SIZE; row++) {
        for (col = 0; col < SIZE; col++) {
            if (board[row][col] == 0) {  // 0이면 빈 칸
                emptyCell = true;
                break;
            }
        }
        if (emptyCell) break;
    }

    // 더 이상 빈 칸이 없으면 해결 완료
    if (!emptyCell) {
        return true;
    }

    // 1부터 9까지 숫자 넣는다
    for (int num = 1; num <= SIZE; num++) {
        // 해당 자리에 숫자를 넣을 수 있으면 (= isValid값 true면)
        if (isValid(board, row, col, num)) {
            // 숫자를 일단 구한 빈칸에 넣음
            board[row][col] = num;  

            // 다음 빈 칸 해결 (재귀)
            if (solveSudoku(board)) {
                return true;
            }

            // 실패 시 다시 빈 칸으로 설정
            board[row][col] = 0;
        }
    }

    return false; 
}

int main() {
    vector<vector<int>> board(SIZE, vector<int>(SIZE));

    // 입력
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            cin >> board[i][j];
        }
    }

    // 연산
    solveSudoku(board);

    // 출력
    printBoard(board);

    return 0;
}
