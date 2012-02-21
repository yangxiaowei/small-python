#include "dictobject.h"


int 
dictinsert(PyDictObject *ob_dict, PyObject *key, PyObject *value)
{
    ob_dict->ob_dvalu[key->ob_type->py_hash(key)] = value;
    return 0;
}


PyObject*
dict_value_char(PyDictObject *ob_dict, char key)
{
    return ob_dict->ob_dvalu[key];
}

PyObject* 
dict_value(PyDictObject *ob_dict, PyObject *key)
{
    return ob_dict->ob_dvalu[key->ob_type->py_hash(key)];
}

PyObject*
PyDict_Create()
{
    PyDictObject *ob_dict = (PyDictObject*) malloc(sizeof(PyDictObject)*1);
    if (ob_dict == NULL)
    {
        printf("Sorry,no enough memory!\n");
        return NULL;
    }
    ob_dict ->ob_refcnt = 1;
    ob_dict ->ob_type = &PyDict_Type;

    memset(ob_dict->ob_dvalu,0,27);
    return (PyObject*) ob_dict;
    
    /*
    ob_dict ->ob_dvalu.dict_len = 50;
    for(int i=0;i<50;i++)
    {
        ob_dict ->ob_dvalu.container[i].node_num = 0;
        ob_dict ->ob_dvalu.container[i].node_head = NULL;
    }

    return (PyObject*)ob_dict;
    */

}

PyTypeObject PyDict_Type = 
{
    PyObject_HEAD_INIT(&PyType_Type),
    "dict",
    NULL,
    NULL,
    NULL,
};

