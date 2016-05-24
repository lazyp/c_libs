test :libparse_kv_conf 
	gcc -L. test_parse_kv_conf.c -o test_parse_kv_conf -lparse_kv_conf
*.o:
	gcc -c parse_kv_conf.c
libparse_kv_conf:*.o
	ar cur libparse_kv_conf.a parse_kv_conf.o
	ranlib libparse_kv_conf.a
