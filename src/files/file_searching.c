#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>

#include "file_searching.h"


struct searching_entry* scan_direcoty_for_file(
    char *directory, char *target, char *searching_query, char **search_results_dst, int results_length, int entries_number
)
{
    DIR *directoy_fd = opendir(directory); 
    struct dirent *next_file; struct searching_entry *prev_entry = NULL, *first_entry = NULL;

    if (directoy_fd == -1)
    {
        return -1;
    }


    while((next_file = readdir(directoy_fd)) != NULL)
    {
        char *entry_start;
        if (entry_start = strstr(next_file->d_name, target) != NULL)
        {

            struct searching_entry *new_entry = malloc(sizeof(struct searching_entry));

            new_entry->directory = directory;
            new_entry->file_name = next_file->d_name;
            new_entry->entry_start = entry_start;
            prev_entry->next_entry = new_entry;
            prev_entry = new_entry;

            if(first_entry == NULL)
            {
                first_entry = new_entry;
            }
        }
        
    }

    closedir(directoy_fd);

    return first_entry;
}

struct searching_entry* scan_directories_for_file(char *target, char **directories_list)
{
    struct searching_entry *results = NULL;

    for(int i = 0; directories_list[i] != NULL; i++)
    {
        
    }
}
