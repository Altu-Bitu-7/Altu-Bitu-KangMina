// 요세푸스 문제
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(){
    // 입출력 속도 향상
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);  cout.tie(NULL);
    
    vector<int> answ;
    queue<int> q;
    int n,k;

    // 입력
    cin >> n >> k;

    // 연산
    for (int i = 1; i <= n; i++){
        // 1 부터 n 까지의 숫자로 이루어진 큐 만든다. 
        q.push(i);
    }
    for (int i = 0; i < n; i++){
        // k-1번째 숫자까지는 pop해서 q 뒤에 다시 넣고
        // k번째 숫자는 pop해서 answ에 넣는다.
        for (int i = 0; i < k-1; i++){
            q.push(q.front());
            q.pop();
        }
        answ.push_back(q.front());
        q.pop();
    }
    
    // 출력
    cout << "<";
    for (int i = 0; i < n; i++){
        cout << answ[i];
        if (i != n - 1){
            cout << ", ";
        }
    }
    cout << ">";
    
    return 0;
}