// 숫자 할리갈리 게임
// 한 라운드의 조건을 잘못 생각했다 -> 문제를 꼼꼼히 읽기
// typedef 활용
// 카드더미의 위/아래 <-> 덱의 front/back 
#include <iostream>
#include <vector>
#include <deque>
using namespace std;

typedef vector<deque<int>> cards;   // cards[0]: 도도, cards[1]: 수연
const int DO = 0, SU = 1;

// 승리 판단하기
string judge(cards& deck) {
    int do_deck = deck[DO].size();
    int su_deck = deck[SU].size();
    // (도도가 덱에 가진 카드) > (수연이 덱에 가진 카드) 인 경우, (수연이의 덱이 빈 경우도 포함)
    if (do_deck > su_deck) {
        // 승자는 도도
        return "do";
    }
    // (도도가 덱에 가진 카드) < (수연이 덱에 가진 카드) 인 경우, (도도의 덱이 빈 경우도 포함)
    else if (do_deck < su_deck) {
        // 승자는 수연
        return "su";
    }
    // (도도가 덱에 가진 카드) = (수연이 덱에 가진 카드) 인 경우
    return "dosu";
}

// 그라운드에서 덱으로 카드 옮기기
void groundToDeck(deque<int> &deck, deque<int> &ground) {
    // 그라운드의 카드를 뒤집에서 (먼저 내서 아래에 위치한 카드부터) 내 덱의 아래에 넣는다
    // 즉,  그라운드의 back 에서 카드를 빼서 덱의 back 에 넣는다.
    while (!ground.empty()) {
        deck.push_back(ground.back());
        ground.pop_back();
    }
}

// 종을 쳤을 때: 카드를 그라운드에서 덱으로 가져간다
void ringTheBell(int player, cards& deck, cards& ground) {
    // 상대방 그라운드의 카드를 먼저 내 덱에 합치고
    groundToDeck(deck[player], ground[!player]);
    // 내 그라운드의 카드를 내 덱에 합친다
    groundToDeck(deck[player], ground[player]);
}

// 종을 울릴 수 있는 사람 판단
int whoCanRingTheBell(cards& deck, cards& ground) {
    // 벡터의 값 접근할 때 empty 체크 잊지말고 하자!
    // 값이 5인 카드가 나왔다 -> 도도가 종을 친다 (0)
    if (!ground[DO].empty() && ground[DO].front() == 5){    // 도도가 낸 카드가 5
        return DO;
    }
    if (!ground[SU].empty() && ground[SU].front() == 5){    // 수연이 낸 카드가 5
        return DO;
    }
    // 그라운드의 두 값을 합하면 5이다 -> 수연이 종을 친다 (1)
    if (!ground[DO].empty() && !ground[SU].empty() && (ground[DO].front() + ground[SU].front() == 5)){    
        return SU;
    }
    // 위의 어떤 경우도 해당하지 않으면, 아무도 종을 치지 못한다. (-1)
    return -1;
}

// 할리갈리 게임 진행
string halliGalli(int m, cards& deck, cards& ground) {
    bool turn = DO; // 도도가 먼저 게임을 시작한다
    while (m--) {// 게임을 m 라운드 진행한다
        // 카드 내려놓기 (덱 -> 그라운드)
        ground[turn].push_front(deck[turn].front());
        deck[turn].pop_front();
        // 덱이 비는지 체크
        if (deck[turn].empty()){
            break;
        }
        // 종을 울릴 수 있는 사람 체크
        int bell = whoCanRingTheBell(deck, ground);
        // 종을 울린 경우 카드 가져가기 (그라운드 -> 덱)
        if (bell != -1){
            ringTheBell(bell, deck, ground);
        }
        // 차례 바꾸기
        turn = !turn;   
    }
    // m 라운드가 끝나거나, 누군가의 덱이 비었을 때,
    return judge(deck); // 승자를 판단해 반환한다.
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;  // n: 도도와 수연이가 가지는 카드의 개수
    int m;  // m: 게임 진행 횟수
    cards deck(2), ground(2);   // [0]: 도도, [1]: 수연
    string answ;    // answ: 도도가 이기면 "do", 수연이 이기면 "su", 비기면 "dosu"

    // 입력
    cin >> n >> m;
    int d, s;
    for (int i = 0; i < n; i++){
        // 덱의 맨 아래에 위치한 카드에 적혀 있는 수부터 입력받음
        // 덱의 front가 위, back이 아래라 하자.
        cin >> d >> s;
        deck[DO].push_front(d);
        deck[SU].push_front(s);
    }

    // 연산
    answ = halliGalli(m, deck, ground);

    // 출력
    cout << answ << '\n';   
   
    return 0;
}