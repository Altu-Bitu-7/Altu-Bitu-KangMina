// 톱니바퀴2
#include <iostream>
#include <vector>
using namespace std;

// 가장 왼쪽 톱니바퀴부터 순서대로 주어진다. 
// 톱니바퀴는 8개의 정수 톱니로 이루어져 있고, 
// 12시방향부터 시계방향 순서대로 주어진다. (3번째-7번째 톱니)
// N극은 0, S극은 1로 나타나있다.

// 회전시킨다.
void rotate(vector<int> &wheels, int rotation_num, int rotation_dir){

}

// 12시 방향이 s극(1)인 톱니바퀴의 개수 계산한다.
int calAnsw(vector<int> &wheels, int t){
    int cnt=0;
    int w;
    for (int i = 0; i < t; i++){
        w = wheels[i];
        if (w[0] == 1){ // 12시 방향이 s극(1)이라면
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
    int answ; //answ: 총 K번 회전시킨 이후에 12시방향이 S극인 톱니바퀴의 개수
    vector<int> wheels; // wheels: t개의 톱니바퀴 정보 저장
    int rotation_num; // rotate_num: 회전시킨 톱니바퀴의 번호, 
    int rotation_dir; // rotate_dir: 방향(1:시계방향, -1:반시계방향)

    // 입력 및 연산
    cin >> t;
    // 
    int temp;
    for (int i=0; i<t; i++){
        cin >> temp;
        wheels.push_back(temp);
    }
    /* 아래랑 비교해보기
    wheels.assign(8, 0);
    for (int i=0; i<t; i++){
        cin >> wheels[i];
    }
    */

    cin >> k;
    for (int i=0; i<k; i++){
        cin >> rotation_num >> rotation_dir;
        rotate(wheels, rotation_num, rotation_dir);
    }

    answ = calAnsw(wheels, t);

    // 출력
    cout << answ;
}