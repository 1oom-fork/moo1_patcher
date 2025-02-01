#include <stdint.h>
#include <stdio.h>

#include "patcher.h"

int main(int argc, char **argv)
{
    const uint8_t match0[] = {
        0xFF, 0x36, 0x0C, 0x77
    };
    const uint8_t replace0[] = {
        0xFF, 0x36, 0x0A, 0x77
    };
    int len0 = 4;
    int off0 = 0x7a6e5;
    int off1 = 0x7a6f7;
    int off2 = 0x7a70d;
    int off3 = 0x7a723;
    int off4 = 0x7a73d;
    int off5 = 0x7a74f;
    int off6 = 0x7a765;
    int off7 = 0x7a77b;
    const patch_t patch_set[] = {
        {match0, replace0, off0, len0},
        {match0, replace0, off1, len0},
        {match0, replace0, off2, len0},
        {match0, replace0, off3, len0},
        {replace0, match0, off4, len0},
        {replace0, match0, off5, len0},
        {replace0, match0, off6, len0},
        {replace0, match0, off7, len0},
        {NULL, NULL, 0, 0},
    };
    patch_status_t result = execute_patcher("STARMAP.EXE", patch_set);
    if (result == PATCH_STATUS_INVALID) {
        printf("Fail\n");
    }
    getchar();
    return 0;
}
