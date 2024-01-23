#include "./include/so_long.h"

int main (int argc, char **argv)
{
    int fd;//for opening and reading file
    char    *buffer;//for storing read file into buffer
    
    //check number of input(should be 2, file name and map name)
    if (argc != 2)
        handle_error(1, "Incorrect number of input");
    //compare the input map format and make sure it is of .ber
    if (ft_strncmp(&argv[1][ft_strlen(argv[1] - 4)], ".ber", 4))
        handle_error(2, "Wrong file format");
    fd = open(argv[1], O_RDONLY);
    if (fd == -1)
        handle_error(8, "Error opening file");
    //set buffer to 10000 in header file
    buffer = ft_calloc(BUFFER + 1, sizeof(char));
    if (!buffer)
        return (-1);
    if(read(fd, buffer, BUFFER) <= 0)
    {
        free(buffer);
        handle_error(2, "Empty map file!");
        return (-1);
    }
    init_game(buffer);
    return (0);
}