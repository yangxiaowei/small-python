#include <stdlib.h>
#include <string.h>

#include "stringobject.h"



PyObject*
PyStr_Create(char *str)
{
    int len;
    if ((len=strlen(str)) > 49)
    {
        printf("Sorry,String must be less than 49 charactors!\n");
        return NULL;
    }

    PyStrObject *str_obj = (PyStrObject*) malloc(sizeof(PyStrObject)*1);
    if (str_obj == NULL)
    {
        printf("Sorry,no enough memory!\n");
        return NULL;
    }
    str_obj->ob_refcnt = 1;
    str_obj->ob_type = &PyStr_Type;
    str_obj->str_len = len;
    str_obj->hash_value = -1;
    memset(str_obj->ob_sval,0,50);
    strcpy(str_obj->ob_sval,str);

    return (PyObject*)str_obj;
}

void
PyStr_Print(PyObject * str_object)
{
    PyStrObject *ob = (PyStrObject*)str_object;
    printf("%s\n",ob->ob_sval);
}

PyObject*
PyStr_Add(PyObject *str_ob1, PyObject *str_ob2)
{
    PyStrObject *str_result = (PyStrObject*)PyStr_Create(""); 
    if (str_result== NULL)
    {
        printf("Sorry,no enough memory!\n");
        return NULL;
    }
    PyStrObject *ob1 = (PyStrObject*)str_ob1;
    PyStrObject *ob2 = (PyStrObject*)str_ob2;
    strcat(str_result->ob_sval,ob1->ob_sval);
    strcat(str_result->ob_sval,ob2->ob_sval);

    return (PyObject*)str_result;
}

long
PyStr_Hash(PyObject *str_object)
{
    PyStrObject * ob = (PyStrObject*)str_object;
    register long x = 0;
    /*
    unsigned int seed = 131;
    char *p = ob->ob_sval;

    while(*p++)
    {
        x = x*seed + (int)*p;
    }

    return (x & 0x7fffffff);
    */
    x = (int)ob->ob_sval[0]-(int)'a';//最简单的hash取法，取首字母的ascii码值，且以‘a‘为基准
    return x;
}

PyTypeObject PyStr_Type =
{
    PyObject_HEAD_INIT(&PyType_Type),
    "string",
    PyStr_Print,
    PyStr_Add,
    PyStr_Hash,
};

