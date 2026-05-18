
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>

struct search_file_entry {};


int scan_direcoty_for_file(char *file_name, char **search_results_dst, int results_length, int entries_number)
{
    DIR *directoy_fd = opendir("./");

    if (directoy_fd == -1)
    {
        return -1;
    }

    struct dirent *next_file;


    while((next_file = readdir(directoy_fd)) != NULL)
    {
        if (strstr(next_file->d_name, file_name))
        {
            entries_number++;
            if (entries_number == results_length)
            {
                search_results_dst = realloc(search_results_dst, (results_length + 10) * sizeof(char));
                results_length += 10;
            }
            
        }
        
    }

    closedir(directoy_fd);

    return 1;
}
