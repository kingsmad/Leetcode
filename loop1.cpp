#include <iostream>
#include <vector>
// this version is patched
// just produce sequa
int main(int argc, char const *argv[])
{
	/* code */

	if(argc < 2)
		return 0;
	int len = atoi(argv[1]);

	printf("%d ", len);
	for(int i=0; i<len; ++i)
		printf("%d ", i);
	printf("\n");
	return 0;
}
