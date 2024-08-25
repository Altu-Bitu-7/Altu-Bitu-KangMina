// 패션왕 신해빈
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main(){
    // 입출력 속도 향상
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);  cout.tie(NULL);

    int t;  // 테스트 케이스 개수 t

    // 입력
    cin >> t;
    vector<int> arr(t);

    for (int i = 0; i < t; i++){
        map<string, int> m; // 의상의 종류와 종류별 개수 저장
        string cloth_name;    // 의상의 이름
        string cloth_type;    // 의상의 종류
        int n;  // 의상의 개수 n

        cin >> n;
        for (int j = 0; j < n; j++){
            cin >> cloth_name >> cloth_type;
            if (m.find(cloth_type) == m.end()){
                // 의상의 종류가 이전에 없던 것이면 맵에 추가한다
                m[cloth_type] = 1;
            } else{
                // 의상의 종류가 기존에 있던 것이면 해당 key 의 value+1;
                m[cloth_type]++;
            }
        }

        // 연산
        int ans = 1;
        for (auto iter = m.begin(); iter != m.end(); iter++){
            ans *= (iter->second +1);
        }
        ans--;  // 아무것도 안입는 경우
        arr[i] = ans;
    }

    // 출력
    for (int i = 0; i < t; i++){
        cout << arr[i] << '\n';
    }

    return 0;
}