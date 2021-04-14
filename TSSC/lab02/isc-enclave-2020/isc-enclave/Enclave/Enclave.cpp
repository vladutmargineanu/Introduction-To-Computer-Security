#include "string.h"
#include "Enclave_t.h"
#include<stdio.h>
/* TODO: Add SGX trusted libraries headers if needed */ 

#include <sgx_trts.h>
#include <sgx_tseal.h>

#define SECRET_FILE "enclave_secret"

void printf(const char *fmt, ...)
{
    char buf[BUFSIZ] = {'\0'};
    va_list ap;
    va_start(ap, fmt);
    vsnprintf(buf, BUFSIZ, fmt, ap);
    va_end(ap);
    ocall_print(buf);
}

int get_sum(int a, int b) {
	ocall_print("Adding numbers inside enclave...");
	return a + b;
}

/* TODO 1: Generate a random unsigned int using a trusted library */
unsigned int generate_random_number() {
	// Add code here
	unsigned int res;
	sgx_read_rand((unsigned char*)&res, sizeof(unsigned int));
	return res % 40 + 3;
}


/* TODO 3: Sealing function */
void seal_secret() {
	// Add code here to seal "SGX_RULLZ".
	const char* data_to_be_sealed = "SGX_RULLZ";
	const uint32_t data_size = (uint32_t)(strlen(data_to_be_sealed) + 1);
	uint32_t sealed_data_size;
	char* sealed_data;

	sealed_data_size = sgx_calc_sealed_data_size(0, data_size);
	sealed_data = (char*) malloc(sealed_data_size);

	sgx_seal_data(0, NULL, data_size, (uint8_t*)&data_to_be_sealed, sealed_data_size, (sgx_sealed_data_t*)sealed_data);

	ocall_write_file(SECRET_FILE, sealed_data, sealed_data_size);
	free(sealed_data);
	
	// TODO 4: Generate random string to seal.
	
}


/* TODO 5: Unsealing function
void unseal_secret(){
	// Add code here
}
*/
