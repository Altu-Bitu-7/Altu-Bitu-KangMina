// 평행 우주
// answ 타입으로 long long 사용해야 하는 이유 생각해보기
#include <iostream>
#include <vector>

using namespace std;

/* 이동규칙
* 지구를 벗어나면 속도를 떨어뜨릴 수 있을 뿐 높일 수는 없다.
* 필요한 속도의 양의 정수 배로도 다음 지역으로 이동할 수 있다.
* 어떤 행성에서는 도달한 뒤 속도를 유지한 채 다음 행성으로 이동할 수도 있다.
*/

// 지구에서 올려야 하는 속도의 최솟값을 계산한다
// 뒤에서부터 값을 찾는다
long long calMinVel(const vector<int> &v, int n){
    long long min_vel = v[n - 1]; // v의 가장 마지막 값으로 초기
    for (int i = n - 2; i >= 0; i--){ 
        if ((min_vel % v[i]) != 0){    // 
            // 현재값 v[i]의 배수 중 min_vel 이상인 값으로 업데이트
            min_vel = v[i] * ((min_vel / v[i]) + 1);
        }
    }
    return min_vel;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n; // n: 지구를 포함한 행성의 개수 (지구는 행성0, 행성1~행성(n-1)은 지구가 아님)
    long long answ; // answ: 지구에서 올려야 하는 속도의 최솟값

    // 입력
    cin >> n;
    vector<int> v(n);  // v: 행성(i)에서 행성(i+1)로 이동하는 데 필요한 (최소) 속도 v[i] (i: 0~n-1)
    for (int i=0; i<n; i++){
        cin >> v[i];
    }
    // 연산
    answ = calMinVel(v, n);

    // 출력
    cout << answ;
}