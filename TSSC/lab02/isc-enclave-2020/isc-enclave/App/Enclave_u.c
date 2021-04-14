#include "Enclave_u.h"
#include <errno.h>

typedef struct ms_get_sum_t {
	int ms_retval;
	int ms_a;
	int ms_b;
} ms_get_sum_t;

typedef struct ms_generate_random_number_t {
	unsigned int ms_retval;
} ms_generate_random_number_t;

typedef struct ms_ocall_print_t {
	const char* ms_str;
} ms_ocall_print_t;

typedef struct ms_ocall_write_file_t {
	const char* ms_filename;
	const char* ms_buf;
	size_t ms_buf_len;
} ms_ocall_write_file_t;

typedef struct ms_ocall_read_file_t {
	const char* ms_filename;
	char* ms_buf;
	size_t ms_buf_len;
} ms_ocall_read_file_t;

static sgx_status_t SGX_CDECL Enclave_ocall_print(void* pms)
{
	ms_ocall_print_t* ms = SGX_CAST(ms_ocall_print_t*, pms);
	ocall_print(ms->ms_str);

	return SGX_SUCCESS;
}

static sgx_status_t SGX_CDECL Enclave_ocall_write_file(void* pms)
{
	ms_ocall_write_file_t* ms = SGX_CAST(ms_ocall_write_file_t*, pms);
	ocall_write_file(ms->ms_filename, ms->ms_buf, ms->ms_buf_len);

	return SGX_SUCCESS;
}

static sgx_status_t SGX_CDECL Enclave_ocall_read_file(void* pms)
{
	ms_ocall_read_file_t* ms = SGX_CAST(ms_ocall_read_file_t*, pms);
	ocall_read_file(ms->ms_filename, ms->ms_buf, ms->ms_buf_len);

	return SGX_SUCCESS;
}

static const struct {
	size_t nr_ocall;
	void * table[3];
} ocall_table_Enclave = {
	3,
	{
		(void*)Enclave_ocall_print,
		(void*)Enclave_ocall_write_file,
		(void*)Enclave_ocall_read_file,
	}
};
sgx_status_t get_sum(sgx_enclave_id_t eid, int* retval, int a, int b)
{
	sgx_status_t status;
	ms_get_sum_t ms;
	ms.ms_a = a;
	ms.ms_b = b;
	status = sgx_ecall(eid, 0, &ocall_table_Enclave, &ms);
	if (status == SGX_SUCCESS && retval) *retval = ms.ms_retval;
	return status;
}

sgx_status_t generate_random_number(sgx_enclave_id_t eid, unsigned int* retval)
{
	sgx_status_t status;
	ms_generate_random_number_t ms;
	status = sgx_ecall(eid, 1, &ocall_table_Enclave, &ms);
	if (status == SGX_SUCCESS && retval) *retval = ms.ms_retval;
	return status;
}

sgx_status_t seal_secret(sgx_enclave_id_t eid)
{
	sgx_status_t status;
	status = sgx_ecall(eid, 2, &ocall_table_Enclave, NULL);
	return status;
}

