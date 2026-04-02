#include <Python.h>
#include <stdio.h>

int main()
{
    Py_Initialize();
    if (Py_IsInitialized())
    {
        PyRun_SimpleString("print('Hello from embedded Python 3.14!')");
    }
    Py_Finalize();
    printf("Python embedding test completed successfully.\n");
    return 0;
}
