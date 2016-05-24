#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "parse_kv_conf.h"

#define MAX_KV_PAIRS 256

kv_pairs parse_kv_conf(char *path)
{
    if (!path)
    {
        return NULL;
    }

    kv_pairs kv_pairs;
    FILE *fp;
    char buf[2048], key[256], value[1024];
    int r_len, i, idx , kv_idx = -1;

    fp = fopen(path, "r");

    if (!fp)
    {
        printf("[parse_kv_conf] ERROR: open the file %s fail.", path);
        return NULL;
    }

    kv_pairs = malloc(MAX_KV_PAIRS * sizeof(kv_pair*));
    kv_pairs[0] = NULL;

    memset(buf, '\0', 2048);

    while ((fgets(buf, 2047, fp)) != NULL)
    {
        if (buf[0] == '#')
        {
            memset(buf, '\0', 2048);
            continue;
        }

        memset(key, '\0', 256);
        memset(value, '\0', 1024);

        r_len = strlen(buf);
        i = 0;

        //read key
        idx = 0;
        for (; i < r_len; ++i)
        {
            if (isspace(buf[i]))
            {
                continue;
            }

            if (buf[i] == '=')
            {
                break;
            }

            key[idx++] = buf[i];
        }

        //read value
        idx = 0;
        for (i = i + 1; i < r_len; ++i)
        {
            if (isspace(buf[i]))
            {
                continue;
            }

            if(buf[i] == '#')
            {
                break;
            }

            value[idx++] = buf[i];
        }

        if(strlen(key) > 0 && strlen(value) > 0)
        {
            kv_pairs[++kv_idx] = malloc(sizeof(kv_pair));
            kv_pairs[kv_idx]->key = strdup(key);
            kv_pairs[kv_idx]->value = strdup(value);
            kv_pairs[kv_idx+1] = NULL;
            if(kv_idx == MAX_KV_PAIRS-1)
            {
                break;
            }
        }
    }

    fclose(fp);

    return kv_pairs;
}

void free_kv_pairs(kv_pairs kv_pairs)
{
    if(!kv_pairs)
    {
        return;
    }

    int i = 0;
    while(kv_pairs[i])
    {
        free(kv_pairs[i]->key);
        free(kv_pairs[i]->value);
        free(kv_pairs[i]);
        ++i;
    }

    free(kv_pairs);
}

