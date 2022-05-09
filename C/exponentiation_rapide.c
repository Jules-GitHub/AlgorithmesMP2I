#include "stdlib.h"
#include "stdio.h"

int expo_rapide(int n, int p) {
    if (p==0) {
        return 1;
    } else if (p%2 == 0) {
        int m = expo_rapide(n, p/2);
        return m*m;
    } else {
        int m = expo_rapide(n, p/2);
        return n*m*m;
    }
}

int main() {

    printf("%d\n", expo_rapide(10, 9));

    return EXIT_SUCCESS;

}