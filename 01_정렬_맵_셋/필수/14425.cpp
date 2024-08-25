// 문자열 집합
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
using namespace std;

int main(){
    // 입출력 속도 향상
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);  cout.tie(NULL);

    int n,m;
    string input;
    int ans = 0;
    set<string> s;

    // 입력 및 연산
    cin >> n >> m;
    for (int i = 0; i < n; i++){
        cin >> input;
        s.insert(input);
    }
    for (int i = 0; i < m; i++){
        cin >> input;
        if (s.find(input) != s.end()){  // S에 있는지 확인
            ans += 1;
        }
    }
    
    // 출력
    cout << ans;
    return 0;
}