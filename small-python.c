#include "object.h"
#include "intobject.h"
#include "stringobject.h"
#include "dictobject.h"

PyDictObject  smallPyVar ;

void execute_print(char var_name)
{
    char var[2];
    var[0] = var_name;
    var[1] = '\0';
    PyObject *o = dict_value(&smallPyVar,PyStr_Create((char*)var));
    if (o!=NULL)
        o->ob_type->py_print(o);
    else
        printf("%c is undefined\n",var_name);
}

PyObject* execute_add(char * cmd)
{
    char var1[2];
    char var2[2];
    var1[0] = cmd[0];
    var2[0] = cmd[2];
    var1[1] = var2[1] = '\0';

    PyObject *o1 = dict_value(&smallPyVar,PyStr_Create((char*)var1));
    PyObject *o2 = dict_value(&smallPyVar,PyStr_Create((char*)var2));
    if (o1==NULL)
    {
        printf("%s is undefined",var1);
        return NULL;
    }
    if (o2==NULL)
    {
        printf("%s is undefined",var2);
        return NULL;
    }
    PyObject *r = NULL;
    char *type1 = o1->ob_type->name;
    char *type2 = o2->ob_type->name;
    if (strcmp(type1,type2)!=0)
    {
        printf("%s can't be added to %s\n",type1,type2);
        return NULL;
    }
    r = o1->ob_type->py_add(o1,o2);
    return r;

}

void execute_init(char name,PyObject *val)
{
    char var[2];
    var[0] = name;
    var[1] = '\0';
    dictinsert(&smallPyVar,PyStr_Create((char*)var),val); 
}

void analysize_cmd(char * lineptr)
{
    char * line = NULL;
    int len = strlen(lineptr);
    lineptr[len-1] = '\0';//remove \n
    if ((line=strstr(lineptr,"print"))!=NULL)
    {
        execute_print(lineptr[6]);
    }
    else if((line=strchr(lineptr,(int)'+'))!=NULL)
    {
        PyObject *result = execute_add(strchr(lineptr,(int)'=')+1);
        if (result != NULL)
            execute_init(lineptr[0],result);
    }
    else if((line=strchr(lineptr,(int)'='))!=NULL)
    {
        if((strchr(lineptr,(int)"'"))==NULL && (strchr(lineptr,(int)'"'))==NULL)//digite
        {
            PyObject *i = PyInt_Create(atoi(lineptr+2));
            execute_init(lineptr[0],i);
        }
        else//string
        {
            char * str = NULL;
            if((str=strchr(lineptr,(int)"'"))==NULL)
                str = strchr(lineptr,(int)'"');
            str ++;//remove first quote
            lineptr[len-2] = '\0';//remove second quote
            PyObject *s = PyStr_Create(str);
            execute_init(lineptr[0],s);
        }

    }
    else
    {
        printf("Syntax errors\n");
    }

}

void init(void)
{
    int i=0;
    for (i=0; i<DICT_LEN; i++)
        smallPyVar.ob_dvalu[i]=NULL;
}
int main(void)
{
    char* prompt = ">>>";

    FILE * fp = stdin;
    size_t len = 0;
    char * lineptr;
    ssize_t read_len = 0;

    init();

    printf("%s",prompt);
    while(-1 != (read_len=(getline(&lineptr,&read_len,fp))))
    {
        if (read_len == 0)
        {
            printf("%s",prompt);
        }
        else if (0==strcmp(lineptr,"exit\n") || 0==strcmp(lineptr,"q\n"))
        {
            exit(0);
        }
        else
        {
            analysize_cmd(lineptr);
            printf("%s",prompt);
        }

    }
    return 0;
}
