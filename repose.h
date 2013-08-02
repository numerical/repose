#ifndef REPOMAN_H
#define REPOMAN_H

#include <stdbool.h>
#include "alpm/pkghash.h"

enum state {
    REPO_NEW,
    REPO_CLEAN,
    REPO_DIRTY
};

enum compress {
    COMPRESS_NONE,
    COMPRESS_GZIP,
    COMPRESS_BZIP2,
    COMPRESS_XZ,
    COMPRESS_COMPRESS
};

enum action {
    ACTION_VERIFY,
    ACTION_UPDATE,
    ACTION_REMOVE,
    ACTION_QUERY,
    INVALID_ACTION
};

typedef struct file {
    char *file, *link_file;
    char *sig,  *link_sig;
} file_t;

typedef struct repo {
    alpm_pkghash_t *pkgcache;
    char *root;
    file_t db;
    file_t files;
    enum state state;
    enum compress compression;
    int dirfd;
} repo_t;

typedef struct colstr {
    const char *colon;
    const char *warn;
    const char *error;
    const char *nocolor;
} colstr_t;

#endif
