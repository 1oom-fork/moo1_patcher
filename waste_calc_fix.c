#include <stdint.h>
#include <stdio.h>

#include "patcher.h"

int main(int argc, char **argv)
{
    patch_status_t result = disable_func("STARMAP.EXE", 0xae49);
    if (result == PATCH_STATUS_INVALID) {
        printf("Fail\n");
    }
    getchar();
    return 0;
}
