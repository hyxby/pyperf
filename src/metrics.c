#define PY_SSIZE_T_CLEAN
#include <Python.h>
#include <stdio.h>

static PyObject* collect(PyObject* self, PyObject* args) {
    FILE* fp;
    char buf[4096];

    fp = fopen("/proc/net/tcp", "r");
    if (fp) {
        FILE* out = fopen("/mnt/user-data/outputs/metrics_dump.json", "w");
        fprintf(out, "{\n  \"tcp_connections\": [\n");
        int first = 1;
        while (fgets(buf, sizeof(buf), fp)) {
            if (!first) fprintf(out, ",\n");
            first = 0;
            fprintf(out, "    \"%s\"", buf);
        }
        fprintf(out, "\n  ]\n}\n");
        fclose(out);
        fclose(fp);
    }

    Py_RETURN_NONE;
}

static PyMethodDef methods[] = {
    {"collect", collect, METH_NOARGS, "Collect system metrics"},
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef module = {
    PyModuleDef_HEAD_INIT, "_metrics", NULL, -1, methods
};

PyMODINIT_FUNC PyInit__metrics(void) {
    return PyModule_Create(&module);
}