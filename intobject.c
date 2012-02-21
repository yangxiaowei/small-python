#include <stdlib.h>
#include "intobject.h"

PyObject* PyInt_Create(int value)
{
    PyIntObject *object = (PyIntObject*)malloc(1*sizeof(PyIntObject));
    if (object == NULL)
        return NULL;
    object->ob_refcnt = 1;
    object->ob_type = &PyInt_Type;
    object->ob_ival = value;

    return (PyObject*)object; 
}

void 
PyInt_Print(PyObject *num)
{
    PyIntObject *i = (PyIntObject*)num;
    printf("%d\n",i->ob_ival);
}

PyObject*
PyInt_Add(PyObject* num1, PyObject* num2)
{
    PyIntObject *result = (PyIntObject*)PyInt_Create(0);
    if (result == NULL)
    {
        printf("No enough memory!\n");
        return NULL;
    }
    PyIntObject *n1 = (PyIntObject*)num1;
    PyIntObject *n2 = (PyIntObject*)num2;
    result->ob_ival = n1->ob_ival+n2->ob_ival;

    return (PyObject*)result;
}

long
PyInt_Hash(PyObject* o)
{
    return (long)(((PyIntObject*)o)->ob_ival);
}


PyTypeObject PyInt_Type = 
{
    PyObject_HEAD_INIT(&PyType_Type),
    "int",
    PyInt_Print,
    PyInt_Add,
    PyInt_Hash,
};

