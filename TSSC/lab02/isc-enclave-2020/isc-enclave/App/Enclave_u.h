#ifndef ENCLAVE_U_H__
#define ENCLAVE_U_H__

#include <stdint.h>
#include <wchar.h>
#include <stddef.h>
#include <string.h>
#include "sgx_edger8r.h" /* for sgx_status_t etc. */


#include <stdlib.h> /* for size_t */

#define SGX_CAST(type, item) ((type)(item))

#ifdef __cplusplus
extern "C" {
#endif

#ifndef OCALL_PRINT_DEFINED__
#define OCALL_PRINT_DEFINED__
void SGX_UBRIDGE(SGX_NOCONVENTION, ocall_print, (const char* str));
#endif
#ifndef OCALL_WRITE_FILE_DEFINED__
#define OCALL_WRITE_FILE_DEFINED__
void SGX_UBRIDGE(SGX_NOCONVENTION, ocall_write_file, (const char* filename, const char* buf, size_t buf_len));
#endif
#ifndef OCALL_READ_FILE_DEFINED__
#define OCALL_READ_FILE_DEFINED__
void SGX_UBRIDGE(SGX_NOCONVENTION, ocall_read_file, (const char* filename, char* buf, size_t buf_len));
#endif

sgx_status_t get_sum(sgx_enclave_id_t eid, int* retval, int a, int b);
sgx_status_t generate_random_number(sgx_enclave_id_t eid, unsigned int* retval);
sgx_status_t seal_secret(sgx_enclave_id_t eid);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif
