#include <stdio.h>
#include <stdint.h>
#include <netinet/in.h>

uint32_t my_ntohl(uint32_t a){

	uint32_t a1 = (a&0x000000FF)<<24;
	uint32_t a2 = (a&0x0000FF00)<<8;
	uint32_t a3 = (a&0x00FF0000)>>8;
	uint32_t a4 = (a&0xFF000000)>>24;

	return a1+a2+a3+a4;
}

int main(int argc, char *argv[]){

	uint32_t a, b;

	FILE *f1, *f2;

	f1 = fopen(argv[1], "r");
	f2 = fopen(argv[2], "r");

	fread(&a, sizeof(uint32_t), 1, f1);
	fread(&b, sizeof(uint32_t), 1, f2);

	fclose(f1);
       	fclose(f2);

//	a = ntohl(a);
	a = my_ntohl(a);
	b = ntohl(b);

	uint32_t sum = a+b;

	printf(("%d(0x%x) + %d(0x%x) = %d(0x%x)\n"), a, a, b, b, sum, sum);

}
