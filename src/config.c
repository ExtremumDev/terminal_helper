#include <stdlib.h>
#include <string.h>

#include "config.h"

#define DIRECTORY_PATH_MAX_SIZE 5

static int check_config()
{
    return 0;
    
}

int create_default_configs(struct main_config *config)
{

    char *home_directory_copy, *home_directory = getenv("HOME");

    if(home_directory == NULL)
    {
        return -1;
    }

    config->file_searching_directories = malloc(sizeof(char*) * 2);

    if(config->file_searching_directories == NULL)
    {
        return -1;
    }
    
    config->file_searching_directories[1] = NULL;


    home_directory_copy = malloc(strlen(home_directory) + 1);

    if(home_directory_copy == NULL)
    {
        return -1;
    }
    strcpy(home_directory_copy, home_directory);
    config->file_searching_directories[0] = home_directory_copy;

    config->searching_directories_number = 1;

    return 1;
}


int free_config(struct main_config *config)
{
    if (config->file_searching_directories != NULL)
    {

        for(int i = 0; config->file_searching_directories[i] != NULL; i++)
        {
            free(config->file_searching_directories[i]);
        }
        free(config->file_searching_directories);
    }

    return 1;
}
