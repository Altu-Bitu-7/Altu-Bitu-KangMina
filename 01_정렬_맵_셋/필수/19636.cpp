// 요요 시뮬레이션
#include <iostream>
#include <cmath>
using namespace std;

// 요요 여부 계산
string calYoyo(int i0, int i2, int a0){
    // i0: 다이어트 전 일일 에너지 섭취량
    // i2: 변화한 일일 기초 대사량
    // a0: 다이어트 전 일일 활동 대사량 (=0)
    if (i0 > i2){  // i0-i2-a0 > 0
        return "YOYO";
    }
    return "NO";
}

int main(){
    // 입출력 속도 향상
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);  cout.tie(NULL);

    // w0: 다이어트 전 체중, 
    // i0: 다이어트 전 일일 에너지 섭취량(=일일 기초 대사량), 
    // t: 기초대사량 변화 역치.
    int w0, i0, t;

    // d: 다이어트 기간,
    // i: 다이어트 기간 일일 에너지 섭취량,
    // a: 다이어트 기간 일일 활동 대사량.
    int d, i, a;

    // 입력
    cin >> w0 >> i0 >> t;
    cin >> d >> i >> a;

    // 연산
    // w1: 다이어트 후 예상 체중, i0: 일일 기초 대사량 (일일 기초 대사량 변화 x)
    int w1;
    int danger_1 = 0;
    w1 = w0 + (i - (i0 + a)) * d;
    if (w1 <= 0){
        danger_1 = 1;
    }

    // w2: 다이어트 후 예상 체중, i2: 일일 기초 대사량 (일일 기초 대사량 변화 o)
    int w2 = w0;
    int i2 = i0;
    int danger_2 = 0;
    for (int j = 0; j < d; j++){
        int weight_cng = i - (i2 + a); // weight_cng는 0 혹은 음수 (체중이 증가하는 경우는 주어지지 않음)
        w2 += weight_cng;   
        if (-weight_cng > t){    // 체중 변화의 절댓값이 역치 t보다 클 때 
            //i2 += weight_cng / 2;   // -5/2 = -2 나옴
            i2 += float(weight_cng) / 2.0;  // ??
        }
        if ((w2 <= 0) || (i2 <= 0)){
            danger_2 = 1;
            break;
        }
    }

    // 출력
    if (danger_1){
        cout << "Danger Diet" << "\n";
    } else{
        cout << w1 << " " << i0 << "\n";
    }

    if (danger_2){
        cout << "Danger Diet" << "\n";
    } else{
        cout << w2 << " " << i2 << " " << calYoyo(i0, i2, 0);
    }
    return 0;
}