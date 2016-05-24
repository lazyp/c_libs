#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "parse_kv_conf.h"

int main()
{
	int i = 0;
	char path[256] = "kv.conf";
	kv_pairs kv_pairs = NULL;
	printf("parse the conf : %s \n" , path);
	kv_pairs = parse_kv_conf(path);
	while(kv_pairs[i])
	{
		printf("\n****** key = %s , value = %s ******\n" , kv_pairs[i]->key , kv_pairs[i]->value);
		++i;
	}
	printf("\n end \n");
	return 0;
}
