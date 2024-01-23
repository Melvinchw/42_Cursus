//so_long_bonus.c
#include "./include/so_long_bonus.h"

int main (int argc, char **argv)
{
    int fd;//for opening and reading file
    char    *buffer;//for storing read file into buffer
    
    //check number of input(should be 2, file name and map name)
    if (argc != 2)
        handle_error(1, "Incorrect number of input! Please input 2 arguments.\n");
    //compare the input map format and make sure it is of .ber
    if (ft_strncmp(&argv[1][ft_strlen(argv[1] - 4)], ".ber", 4))
        handle_error(2, "Wrong file format! File format should be '.ber'\n");
    fd = open(argv[1], O_RDONLY);
    if (fd == -1)
        handle_error(2, "Error opening file!\n");
    //set buffer to 10000 in header file
    buffer = ft_calloc(BUFFER + 1, sizeof(char));
    if (!buffer)
    {
        handle_error(4,)
        return (-1);
    }
    if(read(fd, buffer, BUFFER) <= 0)
    {
        free(buffer);
        handle_error(2, "Empty map file!\n")     
        return (-1);
    }
    init_game(buffer);
    return (0);
}