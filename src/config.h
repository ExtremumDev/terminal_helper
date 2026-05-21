
#ifndef CONFIG_H_SENTRY
#define CONFIG_H_SENTRY

struct main_config
{
    char **file_searching_directories;
    int searching_directories_number;
};

int create_default_configs(struct main_config *config);

int free_config(struct main_config *config);

#endif
