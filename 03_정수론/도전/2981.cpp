// 검문
// 제출 x
#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    int n;  // n: input의 개수(2이상 100이하)
    set<int> inputs; // inputs: 입력받은 num들을 저장 (중복 없으니 셋 사용)
    set<int> answ;  // answ: 가능한 m들을 저장
    
    // 입력
    cin >> n;
    for (int i = 0; i < n; i++){
        int num;  // num: 종이에 적은 수
        cin >> num;
        inputs.insert(num);
    }
    
    // 연산
    int m; // 몫 m
    int r; // 나머지 r
    for ()
    
    // 출력
    for (auto i : answ){
        cout << answ;
    }

    return 0;
}


/*입력 예시
3
6
34
38

#include <iostream>
#include <ctime>
using namespace std;
 
int main() {
    clock_t start, finish;
    double duration;
    start = clock();
    
    //코드
 
    finish = clock();
    duration = (double)(finish - start) / CLOCKS_PER_SEC;
    cout << duration << "초" << endl;
 
    return 0;
}
*/