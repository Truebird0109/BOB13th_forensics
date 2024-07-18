#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

uint32_t my_htons(uint32_t value) {
    return ((value & 0xFF) << 24) | ((value & 0xFF00) << 8) | ((value >> 8) & 0xFF00) | ((value >> 24) & 0xFF);
}


int main(int argc, char *argv[]) {
    uint32_t buf1;
    uint32_t buf2;

    FILE *fp1 = fopen(argv[1], "rb");
    size_t bytesRead1 = fread(&buf1, sizeof(unsigned char), 4, fp1);
    fclose(fp1);
    uint32_t change1 = my_htons(buf1);

    FILE *fp2 = fopen(argv[2], "rb");
    size_t bytesRead2 = fread(&buf2, sizeof(unsigned char), 4, fp2);
    fclose(fp2);
    uint32_t change2 = my_htons(buf2);

    printf("%d(0x%02X) + %d(0x%02X) = %d(0x%02X) \n",change1,change1,change2,change2,change1+change2,change1+change2);

    return 0;
}