#include <stdint.h>
#include <stdio.h>

#include "patcher.h"

int main(int argc, char **argv)
{
    const uint8_t match0[] = {
        0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfa,
    };
    const uint8_t replace0[] = {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfa,
    };
    int len0 = 10;
    int off0 = 0x3bc20;
    const patch_t patch_set[] = {
        {match0, replace0, off0, len0},
        {NULL, NULL, 0, 0},
    };
    patch_status_t result = execute_patcher("STARMAP.EXE", patch_set);
    if (result == PATCH_STATUS_INVALID) {
        printf("Fail\n");
    }
    getchar();
    return 0;
}
