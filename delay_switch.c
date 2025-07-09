#include <stdint.h>
#include <stdio.h>

#include "patcher.h"

int main(int argc, char **argv)
{
    const uint8_t match0[] = {
        0x01,
    };
    const uint8_t replace0[] = {
        0x00,
    };
    int len0 = 1;
    int off0 = 0x3bc22;
    int off1 = 0x235c6;
    const patch_t patch_set[] = {
        {match0, replace0, off0, len0},
        {NULL, NULL, 0, 0},
    };
    const patch_t patch_set2[] = {
        {match0, replace0, off1, len0},
        {NULL, NULL, 0, 0},
    };

    patch_status_t result = execute_patcher("STARMAP.EXE", patch_set);
    if (result == PATCH_STATUS_INVALID) {
        printf("Fail\n");
    }
    result = execute_patcher("ORION.EXE", patch_set2);
    if (result == PATCH_STATUS_INVALID) {
        printf("Fail\n");
    }
    getchar();
    return 0;
}
