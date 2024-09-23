// 톱니바퀴2
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 톱니바퀴는 8개의 정수 톱니로 이루어져 있고, 
// 가장 왼쪽 톱니바퀴부터 순서대로 주어진다. 
// 12시방향부터 시계방향 순서대로 주어진다. N극은 0, S극은 1.
// 왼쪽의 3시 방향 톱니(12시 방향 +2)와 오른쪽의 9시방향 톱니(12시 방향 +6)가 맞닿아있다

// 톱니바퀴별 회전 방향 업데이트
void setWheelsDir(const vector<string> wheels, vector<int> &wheels_12_idx, vector<int> &wheels_dir, int rotation_num){
    // 회전 시작한 톱니바퀴의 왼쪽 방향 확인
    for (int i = rotation_num - 1; i >= 0; i--) {
        int l_3_idx = (wheels_12_idx[i] + 2) % 8;   // l_r_idx: 접점에서 왼쪽 바퀴의 3시 방향 인덱스
        int r_9_idx = (wheels_12_idx[i + 1] + 6) % 8;   // r_9_idx: 접점에서 오른쪽 바퀴의 9시 방향 인덱스
        if (wheels[i][l_3_idx] != wheels[i + 1][r_9_idx]) { // 접점에서 톱니의 극이 다르면,
            wheels_dir[i] = -wheels_dir[i + 1];  // 맞물린 톱니는 회전 방향이 반대
        } else {    // 접점에서 톱니의 극이 같으면,
            break;  // 회전 안함
        }
    }

    // 회전 시작한 톱니바퀴의 오른쪽 방향 확인
    for (int i = rotation_num; i < wheels.size()-1; i++){
        int l_3_idx = (wheels_12_idx[i] + 2) % 8;   // l_r_idx: 접점에서 왼쪽 바퀴의 3시 방향 인덱스
        int r_9_idx = (wheels_12_idx[i + 1] + 6) % 8;   // r_9_idx: 접점에서 오른쪽 바퀴의 9시 방향 인덱스
        if (wheels[i][l_3_idx] != wheels[i + 1][r_9_idx]) { // 접점에서 톱니의 극이 다르면,
            wheels_dir[i+1] = -wheels_dir[i];  // 오른쪽 톱니: 왼쪽 톱니와 회전 방향이 반대
        } else {    // 접점에서 톱니의 극이 같으면,
            break;  // 회전 안함
        }
    }
}

// 톱니바퀴를 회전시킨다 = wheels_12_idx 의 값들을 바꾼다
void rotate(const vector<int> &wheels_dir, vector<int> &wheels_12_idx) {
    for (int i = 0; i < wheels_dir.size(); i++) {
        if (wheels_dir[i] == 1) { // 시계 방향 회전
            wheels_12_idx[i] = (wheels_12_idx[i] - 1 + 8) % 8;
        } 
        else if (wheels_dir[i] == -1) { // 반시계 방향 회전
            wheels_12_idx[i] = (wheels_12_idx[i] + 1) % 8;
        }
    }
}

// 12시 방향이 s극(1)인 톱니바퀴의 개수 계산한다.
int calAnsw(const vector<string> &wheels, vector<int> &wheels_12_idx){
    int cnt = 0;
    for (int i = 0; i < wheels.size(); i++){
        int dir12 = wheels[i][wheels_12_idx[i]];
        if (dir12 == '1'){ // 12시 방향이 s극(1)이라면
            cnt++;
        }
    }
    return cnt;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t; // t: 톱니바퀴의 개수(1이상 1000이하)
    int k; // k: 회전 횟수(1이상 1000이하)
    int rotation_num; // rotation_num: 회전시킨 톱니바퀴의 번호, 
    int rotation_dir; // rotation_dir: 회전시킨 방향(1:시계방향, -1:반시계방향)
    int answ; //answ: 총 K번 회전시킨 이후에 12시방향이 S극인 톱니바퀴의 개수
    
    // 입력 및 연산
    cin >> t;
    vector<string> wheels(t); // wheels: t개의 톱니바퀴 정보 저장
    vector<int> wheels_12_idx (t, 0); // wheels_12_idx: 각 톱니바퀴들의 12시 방향 인덱스
    vector<int> wheels_dir(t,0);    // wheels_dir: 각 톱니바퀴들의 회전방향 저장 (매 회전마다 업데이트)
    for (int i=0; i<t; i++){
        cin >> wheels[i];
    }

    cin >> k;
    for (int i=0; i<k; i++){
        cin >> rotation_num >> rotation_dir;
        rotation_num--; // 0부터 시작하는 인덱스에 맞게 바꿈

        // 톱니바퀴별 회전 방향 업데이트
        fill(wheels_dir.begin(), wheels_dir.end(), 0);
        wheels_dir[rotation_num] = rotation_dir;
        setWheelsDir(wheels, wheels_12_idx, wheels_dir, rotation_num);

        // 회전
        rotate(wheels_dir, wheels_12_idx);
    }
    answ = calAnsw(wheels, wheels_12_idx);

    // 출력
    cout << answ;
}