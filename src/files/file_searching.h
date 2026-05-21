
#ifndef FILE_SEARCHING_H_SENTRY
#define FILE_SEARCHING_H_SENTRY

struct searching_entry {
    char *directory;
    char *file_name;
    char *entry_start;

    struct searching_entry *prev_entry;
};

struct searching_entry* scan_direcoty_for_file(
    char *directory, char *target, char *searching_query, struct searching_entry *prev_entry
);

struct searching_entry* scan_all_directories_for_file(char *target, char **directories_list);



#endif
