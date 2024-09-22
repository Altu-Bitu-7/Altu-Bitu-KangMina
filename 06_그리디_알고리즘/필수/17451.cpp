// 평행 우주
#include <iostream>
#include <vector>
using namespace std;

/* 이동규칙
* 지구를 벗어나면 속도를 떨어뜨릴 수 있을 뿐 높일 수는 없다.
* 필요한 속도의 양의 정수 배로도 다음 지역으로 이동할 수 있다.
* 어떤 행성에서는 도달한 뒤 속도를 유지한 채 다음 행성으로 이동할 수도 있다.
-> 속도는 v[i]의 배수이거나 v[i]이상이어야 한다.
*/

// 지구에서 올려야 하는 속도의 최솟값을 계산한다
// 뒤에서부터 값을 찾는다
int calMinVel(const vector<int> &v, int n){
    int min_vel = v[n - 1]; // min_vel 초기화 (v의 가장 마지막 값으로)
    for (int i = n - 2; i >= 0; i--){ 
        if (v[i] < min_vel){    // 현재값이 min_vel 보다 작을 때
            // 현재값 v[i]의 배수 중 min_vel 이상인 값으로 min_vel을 업데이트
            int s = 2;
            while (true){
                int temp = v[i] * s;
                if (temp > min_vel){
                    min_vel = temp;
                    break;
                }
                s++;
            }
        }
        // 현재값이 min_vel 보다 크거나 같을 때 
        min_vel = v[i];
        cout <<"min_vel"<< i << " : "<< min_vel << '\n';
    }

    return min_vel;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n; // n: 지구를 포함한 행성의 개수 (지구는 행성0, 행성1~행성(n-1)은 지구가 아님)
    vector<int> v(n, 0);  // v: 행성(i)에서 행성(i+1)로 이동하는 데 필요한 (최소) 속도 v[i] (i: 0~n-1)
    int answ; // answ: 지구에서 올려야 하는 속도의 최솟값

    // 입력
    cin >> n;
    for (int i=0; i<n; i++){
        cin >> v[i];
    }

    // 연산
    answ = calMinVel(v, n);

    // 출력
    cout << answ;
}