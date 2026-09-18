#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc <= 1) {
        printf("Uso: %s <texto>\n", argv[0]);
        return 1;
    }
    printf("%s\n", argv[1]);

    return 0;
}
