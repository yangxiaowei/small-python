# ifndef Py_DICTOBJECT_H
# define Py_DICTOBJECT_H
#ifdef __cplusplus
extern "C" {
#endif
#include "object.h"

#define DICT_LEN 27

//typedef struct _node
//{
//    char key[50];
//    PyObject * ob_ptr;
//    struct _node * next;
//}Node,NodePtr*;

//typedef struct _head
//{
//    NodePtr node_head;
//    int node_num;
//}Head,HeadPtr*;

//typedef struct _dict
//{
//    int dict_len;
//    Head container[50];
//}Dict,DictPtr*;

typedef struct
{
    PyObject_HEAD
    //Dict ob_dvalu;
    PyObject * ob_dvalu[DICT_LEN];//只允许27个小写字母作为变量名
}PyDictObject;

PyTypeObject PyDict_Type;

#ifdef __cplusplus
}
#endif

#endif 
