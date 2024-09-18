// 크리스마스 선물
#include <iostream>
#include <queue>
using namespace std;

int givePresent(priority_queue<int> &presents){
    // 줄 선물이 없을 때
    if (presents.empty()){
        return -1;
    }
    // 줄 선물이 있다면, 가진 것 중 가장 가치가 높은 선물을 준다.
    int answ = presents.top();
    presents.pop();
    return answ;
}

int main(){
    // 입출력 속도 향상
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n; // n: 아이들 및 거점지를 방문한 횟수(1이상 5000이하)
    int a; // a: 거점지에서 충전한 선물의 개수
    int input; // input: 거점지에서 a개 입력받은 선물들의 가치 
    int answ; // answ: 아이들에게 준 선물의 가치 (줄 선물이 없으면 -1)
    priority_queue<int> presents;   // presents: 산타가 가진 선물들
    
    // 입력
    cin >> n; 
    for (int i = 0; i < n; i++){
        cin >> a;
        if (a == 0){    // 산타가 아이를 만났을 때
            answ = givePresent(presents);
            cout << answ << '\n';
        } 
        else{   
            for (int j = 0; j < a; j++){
                cin >> input;
                presents.push(input);
            }
        }
    }

    return 0;
}