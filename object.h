#ifndef Py_OBJECT_H
#define Py_OBJECT_H
#ifdef __cplusplus
extern "C" {
#endif

#include <stdlib.h>
#include <stdio.h>
#include <string.h>


#define PyObject_HEAD \
    int ob_refcnt;    \ 
    struct _typeobject *ob_type;

#define PyObject_Var_HEAD \
    PyObject_HEAD         \
    int ob_size; 

#define PyObject_HEAD_INIT(typeptr) \
    0,typeptr


typedef struct _object
{
   PyObject_HEAD 
}PyObject; /*不可变对象:int*/ 

typedef struct {
    PyObject_Var_HEAD
}PyVarObject; /*可变对象:str,dict*/ 

/* 函数指针 */ 
typedef void (*printFunc)(PyObject *);
typedef PyObject *(*addFunc)(PyObject * ,PyObject *);
typedef long (*hashFunc)(PyObject *);

typedef struct _typeobject
{
    PyObject_HEAD
    char *name;
    printFunc py_print;
    addFunc   py_add;
    hashFunc  py_hash;
}PyTypeObject;//数据类型，可以用来定义数据

static PyTypeObject PyType_Type =
{ 
    PyObject_HEAD_INIT(&PyType_Type),
    "type",
    NULL,
    NULL,
    NULL,
};



#ifdef __cplusplus
}
#endif
#endif    /*Py_OBJECT_H*/ 
