/*
 * Copyright (C) 2013 Argonne National Laboratory, Department of Energy,
 *                    UChicago Argonne, LLC and The HDF Group.
 * All rights reserved.
 *
 * The full copyright notice, including terms governing use, modification,
 * and redistribution, is contained in the COPYING file that can be
 * found at the root of the source code distribution tree.
 */

#include "mercury_string_object.h"

#include <string.h>
#include <stdlib.h>

/*---------------------------------------------------------------------------*/
int
hg_string_object_init(hg_string_object_t *string)
{
    int ret = HG_SUCCESS;

    string->data = NULL;
    string->is_owned = 0;
    string->is_const = 0;

    return ret;
}

/*---------------------------------------------------------------------------*/
int
hg_string_object_init_char(hg_string_object_t *string, char *s, hg_bool_t is_owned)
{
    int ret = HG_SUCCESS;

    string->data = s;
    string->is_owned = is_owned;
    string->is_const = 0;

    return ret;
}

/*---------------------------------------------------------------------------*/
int
hg_string_object_init_const_char(hg_string_object_t *string, const char *s, hg_bool_t is_owned)
{
    int ret = HG_SUCCESS;

    string->data = (char*) s;
    string->is_owned = is_owned;
    string->is_const = 1;

    return ret;
}

/*---------------------------------------------------------------------------*/
int
hg_string_object_free(hg_string_object_t *string)
{
    int ret = HG_SUCCESS;

    if (string->is_owned) {
        free(string->data);
        string->data = NULL;
    }

    return ret;
}

/*---------------------------------------------------------------------------*/
int
hg_string_object_dup(hg_string_object_t string, hg_string_object_t *new_string)
{
    int ret = HG_SUCCESS;

    new_string->data = strdup(string.data);
    new_string->is_owned = 1;
    new_string->is_const = 0;

    return ret;
}

/*---------------------------------------------------------------------------*/
char *
hg_string_object_swap(hg_string_object_t *string, char *s)
{
     char *old = string->data;

     string->data = s;
     string->is_const = 0;
     string->is_owned = 0;

     return old;
}