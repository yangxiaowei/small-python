#ifndef Py_STRINGOBJECT_H
#define Py_STRINGOBJECT_H

#ifdef __cplusplus
extern "C" {
#endif

#include "object.h"

typedef struct
{
    PyObject_HEAD
    int str_len;
    long hash_value;
    char ob_sval[50];//静态
}PyStrObject;

PyTypeObject PyStr_Type ;
#ifdef __cplusplus
}
#endif

#endif
