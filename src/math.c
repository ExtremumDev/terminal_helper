
const char *correct_characters = "0123456789()+*/-\t ";


static int check_char_in_str(const char *str, char c)
{
    while (*str)
    {
        if (*str == c)
        {
            return 1;
        }
        
        str++;
    }
    return 0;
    
}


int check_correct_expression(char *expr)
{
    while(*expr)
    {
        if (!check_char_in_str(correct_characters, *expr))
        {
            return 0;
        }
        expr++;
    }

    return 1;
}