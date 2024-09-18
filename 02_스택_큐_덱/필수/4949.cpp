// 균형잡힌 세상
#include <iostream>
#include <stack>

using namespace std;

bool checkIsBalanced(string line){
    stack<char> bracket;    // 괄호 균형 판단할 스택 초기화

    for (auto i : line){
        // '[', '('가 들어오면 스택 bracket에 넣음 
        if (i == '[' || i == '('){
            bracket.push(i);
        }
        
        // ']', ')'가 들어오면 스택의 top 이랑 비교
        else if (i == ']' || i == ')'){
            // 스택 비어있는 경우
            if (bracket.empty()){   
                return(false);
            }
            // 스택 맨 위의 괄호와 쌍이 맞는 경우
            else if ((i==']' && bracket.top()== '[') || (i==')' && bracket.top()== '(')){
                bracket.pop();
            }
            // 스택 맨 위의 괄호와 쌍이 맞지 않는 경우
            else {
                return(false);
            }
        }
    }

    return (bracket.empty());   // 마지막으로 bracket이 비어있는지 확인
}

int main(){
    // 입출력 속도 향상
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);  cout.tie(NULL);

    string line;    // 주어진 문자열
    bool is_balanced;   // 균형잡힌 문자열인지 아닌지
    string answ;    // 출력할 yes 혹은 no
    
/*
    // 입력
    getline(cin, line); // line 변수에 '\n' 기준으로 입력받음
    
    while(line != "."){
        is_balanced = checkIsBalanced(line);   // is_balanced 판단
        getline(cin, line); // 다음 줄 입력받음
            
        // 출력
        // is_balanced가 true 면서 stack이 비어있으면 yes, 그렇지 않으면 no
        answ = (is_balanced && bracket.empty())? "yes": "no";
        cout << answ << '\n';
    }
*/
    while(true){
        getline(cin, line); // line 변수에 '\n' 기준으로 입력받음

        if (line == "."){
            break;
        }

        is_balanced = checkIsBalanced(line);   // is_balanced 판단
        answ = (is_balanced)? "yes": "no";
        cout << answ << '\n';
    }


    return 0;
}