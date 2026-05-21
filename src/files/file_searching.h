
#ifndef FILE_SEARCHING_H_SENTRY
#define FILE_SEARCHING_H_SENTRY

struct searching_entry {
    char *directory;
    char *file_name;
    char *entry_start;

    struct searching_query *next_entry;
};

#endif
