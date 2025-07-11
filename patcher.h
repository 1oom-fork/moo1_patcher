#ifndef MOO1_PATCHER_PATCHER_H
#define MOO1_PATCHER_PATCHER_H

#include "patch.h"

extern patch_status_t execute_patcher(const char *filename, const patch_t *patch_set);
extern patch_status_t disable_func(const char *filename, int offset);

#endif
