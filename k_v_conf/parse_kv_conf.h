#ifndef __PARSE_KV_CONF_H
#define __PARSE_KV_CONF_H

typedef struct _kv_pair{
    char *key;
    char *value;
}kv_pair;

typedef kv_pair ** kv_pairs;

kv_pairs parse_kv_conf(char *path);

void free_kv_pairs(kv_pairs kv_pairs);

#endif
