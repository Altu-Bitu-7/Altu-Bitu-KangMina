// 드래곤 커브
#include <iostream>
#include <vector>
#include <set>

using namespace std;

// 방향 이동 배열 (우, 상, 좌, 하)
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, -1, 0, 1};

// 드래곤 커브 생성
void generateDragonCurve(vector<pair<int, int>> &curve, int g) {
    for (int generation = 0; generation < g; ++generation) {
        int size = curve.size();
        pair<int, int> end = curve.back();
        for (int i = size - 2; i >= 0; --i) {
            int x = curve[i].first;
            int y = curve[i].second;
            // 회전 변환
            int newX = end.first - (y - end.second);
            int newY = end.second + (x - end.first);
            curve.push_back({newX, newY});
        }
    }
}

// 1x1 정사각형의 개수 계산
int calSquare(vector<vector<bool>> &grid){
    
    int squareCount = 0;
    for (int i = 0; i < 100; ++i) {
        for (int j = 0; j < 100; ++j) {
            if (grid[i][j] && grid[i + 1][j] && grid[i][j + 1] && grid[i + 1][j + 1]) {
                ++squareCount;
            }
        }
    }
    return squareCount;

}

int main() {
    int n;
    cin >> n;

    // 101x101 격자를 초기화 (격자는 0~100까지 사용)
    vector<vector<bool>> grid(101, vector<bool>(101, false));

    // 입력 및 드래곤 커브 생성
    for (int i = 0; i < n; ++i) {
        int x, y, d, g;
        cin >> x >> y >> d >> g;

        // 초기 드래곤 커브 설정
        vector<pair<int, int>> curve;
        curve.push_back({x, y});
        curve.push_back({x + dx[d], y + dy[d]});

        // 드래곤 커브 생성
        generateDragonCurve(curve, g);

        // 격자에 드래곤 커브 표시
        for (auto c : curve) {
            int cx = c.first;
            int cy = c.second;
            if (cx >= 0 && cx <= 100 && cy >= 0 && cy <= 100) {
                grid[cx][cy] = true;
            }
        }
    }

    int squareCount = calSquare(grid);

    // 출력
    cout << squareCount << endl;

    return 0;
}
