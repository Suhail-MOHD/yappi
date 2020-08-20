#include "Python.h"

#if PY_MAJOR_VERSION >= 3 && PY_MINOR_VERSION >= 7
#define PY_NEW_TSS_API
#else
#endif

#ifdef PY_NEW_TSS_API
typedef Py_tss_t tls_key_t;
#else
typedef int tls_key_t;
#endif

tls_key_t create_tls_key() {
    #ifdef PY_NEW_TSS_API
    return PyThread_tss_alloc();
    #else
    return PyThread_create_key();
}

int set_tls_key_value(tls_key_t key, void* value) {

}

void* get_tls_key_value(tls_key_t key) {

}

int delete_tls_key(tls_key_t key) {

}