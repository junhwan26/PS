#include<iostream>
#include<vector>
#include<algorithm>
bool check[10000];
using namespace std;

int f(int a, int b, int c, int d) {
    int num1 = a * 1000 + b * 100 + c * 10 + d;
    int num2 = b * 1000 + c * 100 + d * 10 + a;
    int num3 = c * 1000 + d * 100 + a * 10 + b;
    int num4 = d * 1000 + a * 100 + b * 10 + c;
    return min({ num1, num2, num3, num4 });
}

int main(void)
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int input = f(a, b, c, d);

    for (int i = 1; i < 10; i++) {
        for (int j = 1; j < 10; j++) {
            for (int k = 1; k < 10; k++) {
                for (int l = 1; l < 10; l++) {
                    int clock = f(i, j, k, l);
                    if (check[clock] == false) {
                        check[clock] = true;
                    }
                }
            }
        }
    }
    int sol = 0;
    for(int i = 1111; i <= input; i++) {
        if ( check[i]) sol++;
    }

    cout<<sol;
    return 0;
}
