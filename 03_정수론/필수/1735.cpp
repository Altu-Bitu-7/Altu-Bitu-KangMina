// 분수 합
#include <iostream>

using namespace std;

// 최대공약수 구한다 (유클리드 호제법)
int getGcd(int a, int b){
    if (b==0){
        return a;
    }
    return getGcd(b, a%b);
}

// 최소공배수 구한다
int getLcm(int b1, int b2){
    return b1 * b2 / getGcd(b1, b2);
}

int sumFraction(int a1, int b1, int a2, int b2, int lcm){
    int tmp = (a1 * (lcm / b1)) + (a2 * (lcm / b2));
    return tmp;
}

void checkGCF(int & ans_a, int & ans_b){
    int tmp = getGcd(ans_a, ans_b);
    if (tmp != 1){
        ans_a /= tmp;
        ans_b /= tmp;
    }
}

int main(){
    int a1, b1; // 첫번째 분자 a1, 분모 b1
    int a2, b2; // 두번째 분자 a2, 분모 b2 
    int ans_a, ans_b; // 구한 기약분수의 분자, 분모

    // 입력
    cin >> a1 >> b1;
    cin >> a2 >> b2;

    // 연산
    // 분모 구하기
    ans_b = getLcm(b1, b2);

    // 분자 더하기
    ans_a = sumFraction(a1, b1, a2, b2, ans_b);

    // 기약분수인지 확인하고, 아니라면 기약분수로 만든다.
    checkGCF(ans_a, ans_b);

    // 출력
    cout << ans_a << ' ' << ans_b;

    return 0;
}