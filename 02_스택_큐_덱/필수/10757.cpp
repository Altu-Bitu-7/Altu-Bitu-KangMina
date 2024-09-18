// 큰 수 A+B
#include <iostream>
#include <vector>

using namespace std;

// 둘 중 작은 자릿수의 숫자 앞에 0을 채워서 두 숫자의 자릿수를 맞춰준다
void calDigits(string &a, string &b){
    int a_size = a.size();
    int b_size = b.size();
    int size_diff = a_size - b_size;

    if (size_diff > 0){ // a가 더 길 때
        b = string(size_diff, '0') + b;
    }
    else if (size_diff < 0){    // b가 더 길 때
        size_diff *= -1;
        a = string(size_diff, '0') + a;
    }
}

// 각 자릿수마다 더한다
vector<int> calBigNum(string a, string b){
    vector<int> vec;
    int carry = 0;

    for (int i=a.size() - 1; i>=0; i--){
        int n1 = a[i] - '0';
        int n2 = b[i] - '0';
        int sum = n1 + n2 + carry;

        vec.push_back(sum % 10);
        carry = sum / 10;
    }
    if (carry != 0){    // 마지막 자릿수 덧셈에서 10이상 결과가 나온 경우(자릿수 추가)
        vec.push_back(carry);
    }

    return vec;
}

int main(){
    // 입출력 속도 향상
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);  cout.tie(NULL);
	
    // 입력
    string a, b;
    cin >> a >> b;
    vector<int> answ;

    // 연산
    calDigits(a,b);
    answ = calBigNum(a,b);

    // 출력
    for (int i = answ.size() - 1; i>=0; i--){
        cout << answ[i];
    }
    
    return 0;
}