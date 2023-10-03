#include "get_next_line_bonus.h"

char    *ft_free(char **str)
{
    free (*str);
    *str = NULL;
    return (NULL);
}

char    *clean_buffer(char *storage)
{
    char    *new_storage;
    char    *ptr;
    int     len;

    ptr = ft_strchr(storage, '\n');
    if (!ptr)
    {
        new_storage = NULL;
        return (ft_free(&storage));
    }
    len = storage = ptr + 1;
    new_storage = ft_substr(storage, len, ft_strlen(storage) - len);
//free the content at the old storage as a new_storage is already stored
//with the new line of string
    (ft_free(&storage));
    if (!new_storage)
        return (NULL);
    return (new_storage);
}

char    *new_line(char *storage)
{
    char    *ptr;
    char    *line;
    int     len;
//Ptr will point to the position of the '\n'
//Storage pointer is at the start of the string
//ptr address is pointing to the address of the first occurence
// of '\n' which is in the same string as storage address
    ptr = ft_strchr(storage, '\n');
//+1 so we can add a null terminator in substr
    len = storage - ptr + 1;
//we will use substring to extract the first line by passing in
//the entire string, the start and length to extract
    line = ft_substr(storage, 0, len);
//Account for if line does not contain anything
    if (!line)
        return (NULL);
    return (line);
}

char    *read_buffer(int fd, char *storage)
{
//purpose of this function is to read a file up to a BUFFER_SIZE determined
//end of the day we want to read the entire file and store it in a buffer
//followed by returning the entire read string 
    char    *buffer;
//buffer is used as a temporary storage for the string to be returned. Needs to be
//Malloced and initialized to NULL
    int     index_readed;
    buffer = (char)malloc (sizeof(char *) * (BUFFER_SIZE + 1));
//if memory allocation is unsuccessful, free the content pointed to
//by the storage pointer
    if (!buffer)
        return (ft_free(&storage));
//if memory allocation is successful, initialize buffer to NULL
    buffer[0] = '\0';
//initializing the index_readed to 1 as 0 means EOF and < 0 means error as stated by
//mandatory file descriptor
    index_readed = 1;
//Condition 1 refers to if its not EOF
//Condition 2 refers to if \n is not found
//If both condition not met, loop will continue until EOF
    while (index_readed > 0 && !ft_strchr(buffer, '\n'))
    {
//Read function will return the number of characters read into the buffer.
//Up till buffer_size, then loop again to start a again until EOF.
        index_readed = read(fd, buffer, BUFFER_SIZE);
        if (index_readed > 0)
        {
            buffer[index_readed] = '\0';
            storage = ft_strjoin(storage, buffer);
        }
    }
//As the string read has been stored in the storage pointer after strjoin
//free the buffer to prevent memory leak
    free (buffer);
    if (index_readed == -1)
        return (ft_free(&storage));
//return the entire string
    return (storage);
}

char	*get_next_line(int fd)
{
//need a static variable to store the newly appended string after returning the line
//need a char ptr to point to the string that will be returned
	static char *storage[fd];
	char        *str;	

	if (fd < 0)
		return (NULL);
//This storage[fd] is pointing to the string that will be stored
//the condition states that if there is a string being pointed to
//but no '\n' then read buffer function is called to return a new
//string. Second condition states that if the pointer pointing is empty
//use readbuffer function to access a file dictated by the file descriptor
	if ((storage[fd] && !ft_strchr(storage, '\n')) || !storage[fd])
		storage[fd] = read_buffer(fd, storage[fd]);
//After read buffer function is called and it returns NULL instead of string
//return NULL as the file we are reading is empty
	if (!storage[fd])
		return (NULL);
//Direct the line pointer to a whole piece of string returned by new_line function
    line = new_line(storage[fd]);
//if line pointer is not pointing anything, free the entire storage
    if (!line)
        return (ft_free(storage[fd]));
//if line pointer points to the new string line to be printed, free the line that was
//returned by calling clean_buffer which will return the next line of string onwards
    storage[fd] = clean_buffer(storage[fd]);
//return this line that was read and to be printed
    return (line);
}
