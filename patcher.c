#include "patcher.h"

patch_status_t execute_patcher(const char *filename, const patch_t *patch_set)
{
    FILE *f = fopen(filename, "r+b");
    patch_status_t result = PATCH_STATUS_INVALID;
    if (!f) {
        printf("%s not found\n", filename);
        return PATCH_STATUS_INVALID;
    }
    const patch_status_t status = get_patch_set_status(f, patch_set);
    if (status == PATCH_STATUS_INVALID) {
        result = PATCH_STATUS_INVALID;
        printf("Wrong file\n");
    } else if (status == PATCH_STATUS_PATCHED) {
        remove_patch_set(f, patch_set);
        result = PATCH_STATUS_ORIGINAL;
        printf("Patch removed\n");
    } else if (status == PATCH_STATUS_ORIGINAL) {
        apply_patch_set(f, patch_set);
        result = PATCH_STATUS_PATCHED;
        printf("Patch applied\n");
    }
    if (f) {
        fclose(f);
    }
    return result;
}


patch_status_t disable_func(const char *filename, int offset)
{
    const uint8_t match[] = {
        0x55, 0x8b, 0xec
    };
    const uint8_t replace[] = {
        0xcb, 0x8b, 0xec
    };
    int len = 3;
    const patch_t patch_set[] = {
        {match, replace, offset, len},
        {NULL, NULL, 0, 0},
    };
    patch_status_t result = execute_patcher(filename, patch_set);
}
