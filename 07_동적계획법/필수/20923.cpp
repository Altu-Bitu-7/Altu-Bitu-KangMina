// 숫자 할리갈리 게임
// 추가제출 예정입니다.
#include <iostream>
#include <deque>
#include <stack>
using namespace std;

// 승자를 찾아서 반환한다.
string findWinner(const deque<int> &dodo, const deque<int> &su){
    int d_size = dodo.size();
    int s_size = su.size();

    // 각자의 덱에 있는 카드의 개수가 같다면 비긴 것
    if (d_size == s_size){
        return "dosu";
    }

    // 자신의 덱에 더 많은 카드를 지닌 사람이 승자
    string winner = (d_size > s_size) ? "do" : "su";
    return winner;
}

/* 종치는 경우
수연: 그라운드에 나와 있는 각각의 카드 더미에서 가장 위에 위치한 카드의 숫자 합이 5가 되는 순간
(단, 어느 쪽의 그라운드도 비어있으면 안된다.)
도도: 그라운드에 나와 있는 각각의 카드 더미 중 가장 위에 위치한 카드의 숫자가 5가 나오는 순간

그라운드에 카드 내고나서 종치기 전에 덱 empty 여부 확인? (예제2)
*/

// 그라운드의 상황 파악
// 0:아무일도 없음, 1: 도도가 종침,  2: 수연이가 종침
int checkGround(stack<int> &d_ground, stack<int> &s_ground, deque<int> &dodo, deque<int> &su){
    int d = d_ground.top();
    int s = s_ground.top();

    if (d == 5 || s == 5){   //도도가 종침
        while (!s_ground.empty()) {
            dodo.push_front(s_ground.top());
            s_ground.pop();
        }
        while (!d_ground.empty()) {
            dodo.push_front(d_ground.top());
            d_ground.pop();
        }
        return 1;
    }
    else if(d+s == 5){  // 수연이가 종침
        // 상대방의 그라운드에 있는 카드 더미를 뒤집어 자신의 덱 아래로 그대로 합친 후
        while (!d_ground.empty()) {
            su.push_front(d_ground.top());
            d_ground.pop();
        }
        // 자신의 그라운드에 있는 카드 더미 역시 뒤집어 자신의 덱 아래로 그대로 가져와 합친다.
        while (!s_ground.empty()) {
            su.push_front(s_ground.top());
            s_ground.pop();
        }
        return 2;
    }
    return 0;
}

// 할리갈리 게임을 m 라운드 진행하고 승자를 반환한다.
string halliGalli(int n, int m, deque<int> &dodo, deque<int> &su){
    int round = 0;  // 라운드 1개 끝날 때마다 +1
    stack<int> d_ground;
    stack<int> s_ground;

    while ((round < m) && (!dodo.empty()) && (!su.empty())){
        // 도도부터 카드 꺼낸다
        int d_card = dodo.front();
        dodo.pop_front();
        d_ground.push(d_card);
        
        if (!checkGround(d_ground, s_ground, dodo, su)){
            round++;
        }

        // 수연 카드 꺼낸다
        int s_card = su.front();
        su.pop_front();
        s_ground.push(s_card);
        
        if (!checkGround(d_ground, s_ground, dodo, su)){
            round++;
        }
        
    }

    // 게임 진행 도중 자신의 덱에 있는 카드의 수가 0개가 되면 상대방이 승리한 것
    if (dodo.empty()){ // su.empty
            return "su";    //do
    } else {
        return "do";
    }

    return findWinner(dodo, su);
}

 // 덱의 front가 위, back이 아래라 하자.
 // 카드를 꺼낼 때는 덱의 front에서 꺼내서 뒤집는다.
 // 카드를 추가할 때는 덱의 back에다 한다.

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;  // n: 도도와 수연이가 가지는 카드의 개수
    int m;  // m: 게임 진행 횟수
    deque<int> dodo;    // dodo: 도도의 카드 더미
    deque<int> su;  // su: 수연의 카드 더미
    string answ;    // answ: 도도가 이기면 "do", 수연이 이기면 "su", 비기면 "dosu"

    // 입력
    cin >> n >> m;
    int d, s;
    for (int i = 0; i < n; i++){
        // 덱의 맨 아래에 위치한 카드에 적혀 있는 수부터 입력받음
        cin >> d >> s;
        dodo.push_back(d);
        su.push_back(s);
    }

    // 연산
    answ = halliGalli(n, m, dodo, su);

    // 출력
    cout << answ << '\n';   
   
    return 0;
}