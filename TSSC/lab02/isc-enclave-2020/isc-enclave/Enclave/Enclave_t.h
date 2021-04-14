#ifndef ENCLAVE_T_H__
#define ENCLAVE_T_H__

#include <stdint.h>
#include <wchar.h>
#include <stddef.h>
#include "sgx_edger8r.h" /* for sgx_ocall etc. */


#include <stdlib.h> /* for size_t */

#define SGX_CAST(type, item) ((type)(item))

#ifdef __cplusplus
extern "C" {
#endif

int get_sum(int a, int b);
unsigned int generate_random_number(void);
void seal_secret(void);

sgx_status_t SGX_CDECL ocall_print(const char* str);
sgx_status_t SGX_CDECL ocall_write_file(const char* filename, const char* buf, size_t buf_len);
sgx_status_t SGX_CDECL ocall_read_file(const char* filename, char* buf, size_t buf_len);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif
