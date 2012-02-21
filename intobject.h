#ifndef Py_INTOBJECT_H         
#define Py_INTOBJECT_H         
#ifdef __cplusplus             
extern "C" {
#endif

#include "object.h"

typedef struct {
    PyObject_HEAD              
    int ob_ival;
} PyIntObject;

PyTypeObject PyInt_Type; 
#ifdef __cplusplus
}
#endif
#endif
