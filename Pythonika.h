/*
    Pythonika 1.0 (c) 2006. Ero Carrera
    
    Python Interpreter Interface for Mathematica.

*/

#include <Python.h>
#include <pyport.h>
#include <compile.h>
#include <object.h>
#include <eval.h>

#include <stdio.h>

/*
#define DEBUG(x)    {           \
    FILE *fd;                   \
    fd = fopen("/Volumes/Personal Image/Devel/Pythonika/log.dat", "a+");\
    fputs(x, fd);               \
    fputs("\n", fd);            \
    fclose(fd);}
*/
#define DEBUG(x)    {}


// Structure holding the objects dealing
// with a interactive interpreter instance.

typedef struct interpreter_state {
    PyObject *main_module;
    PyObject *main_dict;
    PyObject *capture_stdout;
    PyObject *capture_stderr;
    PyObject *__builtins__;
} InterpreterState;

void init_interpreter(void);
void shutdown_interpreter(void);
void handle_error(void);
void mat_eval_compiled_code(PyObject *code_obj, int parse_mode);
void mat_eval_compiled_code_silent(PyObject *code_obj, int parse_mode);
void mat_process_iterable_object(PyObject *obj, char *error_msg);
void python_to_mathematica_object(PyObject *obj);
void Pythonika(char *input);
