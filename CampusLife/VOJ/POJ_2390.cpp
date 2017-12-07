#include <cstdio>
#include <cstdlib>

int main(){
    int r, m, y;
    int i;
    double value, rate;

    while (scanf("%d%d%d", &r, &m , &y) != EOF){
        rate = 1 + (double)r / 100.0;
        value = m;
        for (i = 0; i < y; i++){
            value *= rate;
            //printf("%d %lf\n", i + 1, value);
        }
        printf("%d\n", (int)value);
    }
    return 0;
}
