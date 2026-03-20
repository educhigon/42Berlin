int main(int argc, char **argv)
{
    int fh;
    char *std_path;
    char *to_find;

    to_find = argv[1];
    std_path = "./test_numbers.dict";
    fh = open_file(std_path);

    find_number(fh, to_find);
    close(fh);
}

int open_file(char *path)
{
    return(open(path,O_RDONLY));
}

int is_space(int c)
{
	return (c == ' ');
}

int is_colon(int c)
{
	return (c == ':');
}

int skip_spaces(int i, char *str)
{
	while (is_space(str[i]))
		i++;
	return (i);
}

int skip_colon(int i, char *str)
{
	while (is_colon(str[i]))
		i++;
	return (i);
}

int check_find_nbr(char *buffer, int i, char *to_find)
{
    int j;

    j = 0;
    while(to_find[j])
    {
        if(buffer[i+j] != to_find[j])
            return (0);
        j++;
        read
    }
    if (to_find[j] == '\0' || (buffer[i+j] < '0' && buffer[i+j] > '9'))
        return (1);
    return (0);
}

int find_number(int fh, char *to_find)
{
    char buffer[21];
	int	cn;

  	while ((cn = read(fh, buffer, sizeof(buffer))) > 0)
    {
        if  (buffer[i] == to_find[0])
            check_find_nbr(buffer, i, to_find);
    }

}