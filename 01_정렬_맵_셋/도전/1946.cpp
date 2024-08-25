// 신입 사원
// 패션왕 신해빈
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int> interviewee; // 지원자별 서류성적, 면접성적 pair  

int calAns(vector<interviewee> people){
    // 서류성적 기준으로 정렬한 후 면접성적을 비교한다
    // 서류성적 1등은 합격
    // 서류성적 2등부터는 자신보다 서류성적이 좋은 지원자 중 면접성적이 가장 좋은 사람보다 면접성적이 좋아야 합격

    sort(people.begin(), people.end());
    int cnt = 1;
    int score = people[0].second;    // 기준 면접심사 성적

    for (int i = 1; i < people.size(); i++){
        if (people[i].second < score){
            score = people[i].second;
            cnt++;
        }
    }

    return cnt;
}

int main(){
    // 입출력 속도 향상
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);  cout.tie(NULL);

    int t;  // 테스트 케이스 개수 t

    // 입력
    cin >> t;
    vector<int> answ(t);

    for (int i = 0; i < t; i++){
        int n;  // 지원자의 수 n
        int ans;    // 합격자의 최대 인원수 ans
        
        cin >> n;
        vector<interviewee> people(n, interviewee(0,0));

        for (int j = 0; j < n; j++){            
            // people[j].first 는 서류성적, people[j].second 는 면접 성적
            cin >> people[j].first >> people[j].second;
        }

        // 연산
        ans = calAns(people);
        answ[i] = ans;
    }

    // 출력
    for (int i = 0; i < t; i++){
        cout << answ[i] << '\n';
    }

    return 0;
}