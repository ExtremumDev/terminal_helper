#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>

#include "file_searching.h"


struct searching_entry* scan_directory_for_file(
    char *directory, char *target, struct searching_entry *prev_entry
)
{
    DIR *directoy_fd = opendir(directory); 
    struct dirent *next_file;

    if (directoy_fd == NULL)
    {
        return NULL;
    }


    while((next_file = readdir(directoy_fd)) != NULL)
    {
        char *entry_start;
        if ((entry_start = strstr(next_file->d_name, target)) != NULL)
        {

            struct searching_entry *new_entry = malloc(sizeof(struct searching_entry));

            new_entry->directory = directory;
            new_entry->file_name = next_file->d_name;
            new_entry->entry_start = entry_start;
            new_entry->prev_entry = prev_entry;
            prev_entry = new_entry;
        }
        
    }

    closedir(directoy_fd);

    return prev_entry;
}

struct searching_entry* scan_all_directories_for_file(char *target, char **directories_list)
{
    struct searching_entry *results = NULL;

    for(int i = 0; directories_list[i] != NULL; i++)
    {
        struct searching_entry *directory_entrys = scan_directory_for_file(
            directories_list[i],
            target,
            results
        );

        if (directory_entrys == NULL)
        {
            continue;
        }

        results = directory_entrys;
        
    }

    return results;
}
