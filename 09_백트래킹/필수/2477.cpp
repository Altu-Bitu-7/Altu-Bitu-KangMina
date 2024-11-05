// 참외밭
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 동쪽은 1, 서쪽은 2, 남쪽은 3, 북쪽은 4
//   4
// 2 + 1
//   3

const int SIZE = 6;

// 참외밭의 면적을 계산한다
int calArea(vector<int> dir_cnt, vector<int> &directions, vector<int> &sides){
    // key_idx 구하기
    // key_idx: 면적 구할 때 기준이 되는 변의 방향
    // dir_cnt 를 이용해 어떤 육각형인지 파악한다
    // 네가지 육각형 유형별로 key_idx 값이 다르다
    int key_idx;
    if (dir_cnt[1] == 1 && dir_cnt[4] == 1){
        key_idx = 4;
    }
    else if (dir_cnt[2] == 1 && dir_cnt[3] == 1){
        key_idx = 3;
    }
    else if (dir_cnt[1] == 1 && dir_cnt[3] == 1){
        key_idx = 1;
    }
    else if (dir_cnt[2] == 1 && dir_cnt[4] == 1){
        key_idx = 2;
    }

    // idx 구하기
    // idx: key_idx 값을 갖는 변의 directions 와 sides에서의 인덱스
    int idx = distance(directions.begin(), find(directions.begin(), directions.end(), key_idx));
    
    // area 구하기: 큰 사각형에서 작은 사각형을 뺀다
    // area: 밭의 면적 
    // idx 값을 기준으로 큰사각형과 작은사각형의 가로세로 알 수 있다
    int area = (sides[idx] * sides[(idx-1+SIZE) % SIZE]) - (sides[(idx+2) % SIZE] * sides[(idx+3) % SIZE]);

    return area;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int k; // k: 단위 넓이에 자라는 참외의 개수 (1 이상 20 이하)
    vector<int> directions;   // directions: 육각형 참외밭의 변들의 방향
    vector<int> sides;   // sides: 육각형 참외밭의 변들의 길이
    vector<int> dir_cnt(5, 0);  // 입력받은 방향들 개수 저장 (면적 구할 때 사용)
    int answ;   // answ: 입력으로 주어진 밭에서 자라는 참외의 수

    // 입력
    cin >> k;
    int dir, length;
    for (int i = 0; i < SIZE; i++){
        cin >> dir >> length;
        directions.push_back(dir);
        sides.push_back(length);
        dir_cnt[dir]++;
    }

    // 연산
    int area = calArea(dir_cnt, directions, sides);
    answ = area * k;

    // 출력
    cout << answ << '\n';

    return 0;
}