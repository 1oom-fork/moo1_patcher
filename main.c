#include <stdint.h>
#include <stdio.h>

#include "patcher.h"

int disable_mouse_warping(void)
{
    const uint8_t match0[] = {
        0x8B, 0xC6, 0xBA, 0x26, 0x00, 0xF7, 0xEA, 0xC4, 0x1E, 0x6E,
        0xEC, 0x03, 0xD8, 0x26, 0x81, 0x3F, 0x40, 0x01, 0x7C, 0x03
    };
    int len0 = 20;
    int off0 = 0x2a84c;
    const uint8_t match1[] = {
        0xFF, 0x76, 0x0A, 0x57, 0x9A, 0x78, 0x06, 0x3E, 0x25, 0x59,
        0x59
    };
    int len1 = 11;
    int off1[] = {
        0x312f8, 0x313de, 0x3142a
    };
    int num1 = 3;
    const uint8_t match2[] = {
        0x8B, 0xC6, 0xBA, 0x26, 0x00, 0xF7, 0xEA, 0xC4, 0x1E, 0x6E,
        0xEC, 0x03, 0xD8, 0x26, 0x83, 0x7F, 0x08, 0x04, 0x75, 0x0F
    };
    int len2 = 20;
    int off2[] = {
        0x312bf, 0x313a5
    };
    int num2 = 2;
    const uint8_t match3[] = {
        0xFF, 0x76, 0xFA, 0x9A, 0x9C, 0x1F, 0x15, 0x26, 0x59
    };
    int len3 = 9;
    int off3 = 0x15ea5;
    const patch_t chunk_list[] = {
        {match0, NULL, off0, len0},
        {match1, NULL, off1[0], len1},
        {match1, NULL, off1[1], len1},
        //{match1, NULL, off1[2], len1},
        {match2, NULL, off2[0], len2},
        {match2, NULL, off2[1], len2},
        {match3, NULL, off3, len3},
        {NULL, NULL, 0, 0},
    };
    // Check https://github.com/1oom-fork/1oom
    // See 26a29666fd87a59f1a8765ca34ef0a4c712004e8 and 28def32346d5b3704a510567f7809f7cfc48b442
    return execute_patcher("STARMAP.EXE", chunk_list);
}

int fix_ship_scanners(void)
{
    const uint8_t match0[] = {
        0x83, 0x7e, 0xe6, 0x00, 0x7f, 0x03, 0xe9, 0xd8, 0x00
    };
    int len0 = 9;
    int off0 = 0x6d8f5;
    const uint8_t match1[] = {
        0x8b, 0x46, 0xec, 0xbb, 0x0a, 0x00, 0x99, 0xf7, 0xfb, 0x0b,
        0xd2, 0x75, 0x0b, 0x8b, 0x46, 0xec, 0xbb, 0x0a, 0x00, 0x99,
        0xf7, 0xfb, 0xeb, 0x0a, 0x8b, 0x46, 0xec, 0xbb, 0x0a, 0x00,
        0x99, 0xf7, 0xfb, 0x40, 0x89, 0x46, 0xec
    };
    int len1 = 37;
    int off1 = 0x6d96e;
    const uint8_t match2[] = {
        0x8b, 0x46, 0xf2, 0x89, 0x46, 0xec
    };
    const uint8_t replace2[]={
        0x8b, 0x46, 0xec, 0x89, 0x46, 0xf2
    };
    int len2 = 6;
    int off2 = 0x6d99b;
    const patch_t chunk_list[] = {          // Check https://github.com/1oom-fork/1oom
        {match0, NULL, off0, len0},         // See 9eee0ac925e4c721f6ebc27d1dfa14307b16c098
        {match1, NULL, off1, len1},         // See af4ba8540867d4afb63c5227c7b581e8260f845c
        {match2, replace2, off2, len2},     // See f494885b9a7b2f28546abc0ee2921e379bb342b9
        {NULL, NULL, 0, 0},
    };
    return execute_patcher("STARMAP.EXE", chunk_list);
}

int main(int argc, char **argv)
{
    if (fix_ship_scanners() == PATCH_STATUS_INVALID || disable_mouse_warping() == PATCH_STATUS_INVALID) {
        printf("Fail\n");
    }
    getchar();
    return 0;
}
