
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
	
	    (ft_free(&storage));
	    if (!new_storage)
	        return (NULL);
	    return (new_storage);
	}
 
//free the content at the old storage as a new_storage is already stored
//with the new line of string

	char    *new_line(char *storage)
	{
	    char    *ptr;
	    char    *line;
	    int     len;
	
	    ptr = ft_strchr(storage, '\n');
	    len = storage - ptr + 1;
	    line = ft_substr(storage, 0, len);
	    if (!line)
		return (NULL);
	    return (line);
	}
 
//Ptr will point to the position of the '\n'
//Storage pointer is at the start of the string
//ptr address is pointing to the address of the first occurence
// of '\n' which is in the same string as storage address
//+1 so we can add a null terminator in substr
//we will use substring to extract the first line by passing in
//the entire string, the start and length to extract
//Account for if line does not contain anything

	char    *read_buffer(int fd, char *storage)
	{
	    char    *buffer;
	    int     index_readed;
	    buffer = (char)malloc (sizeof(char *) * (BUFFER_SIZE + 1));
	    if (!buffer)
	        return (ft_free(&storage));
	    buffer[0] = '\0';
	    index_readed = 1;
	    while (index_readed > 0 && !ft_strchr(buffer, '\n'))
	    {
	        index_readed = read(fd, buffer, BUFFER_SIZE);
	        if (index_readed > 0)
	        {
	            buffer[index_readed] = '\0';
	            storage = ft_strjoin(storage, buffer);
	        }
	    }
	    free (buffer);
	    if (index_readed == -1)
	        return (ft_free(&storage));
	    return (storage);
	}

//purpose of this function is to read a file up to a BUFFER_SIZE determined
//end of the day we want to read the entire file and store it in a buffer
//followed by returning the entire read string 
//buffer is used as a temporary storage for the string to be returned. Needs to be
//Malloced and initialized to NULL
//if memory allocation is unsuccessful, free the content pointed to
//by the storage pointer
//if memory allocation is successful, initialize buffer to NULL
//initializing the index_readed to 1 as 0 means EOF and < 0 means error as stated by
//mandatory file descriptor
//Condition 1 refers to if its not EOF
//Condition 2 refers to if \n is not found
//If both condition not met, loop will continue until EOF
//Read function will return the number of characters read into the buffer.
//Up till buffer_size, then loop again to start a again until EOF.
//As the string read has been stored in the storage pointer after strjoin
//free the buffer to prevent memory leak
//return the entire string

	char	*get_next_line(int fd)
	{
		static char *storage[fd];
		char        *str;	
	
		if (fd < 0)
			return (NULL);
		if ((storage[fd] && !ft_strchr(storage, '\n')) || !storage[fd])
			storage[fd] = read_buffer(fd, storage[fd]);
		if (!storage[fd])
			return (NULL);
	    	line = new_line(storage[fd]);
	    	if (!line)
	        	return (ft_free(storage[fd]));
	    	storage[fd] = clean_buffer(storage[fd]);
	    	return (line);
	}
1. To start with this function, we need a 'static variable'. Static variable is used to store newly appended string after returning the line.
> 	**How static variables work?**
>>	- Variables are stored in the data portion of the memory. If the value is initialized, it will remain even if the programme stops. However, each time a programme is run, if the value is altered it will be reflected in the variables. These variables are stored within the function and can be used to store data values when the previous function call do something to the data eg get_next_line.
//need a static variable to store the newly appended string after returning the line
//need a char ptr to point to the string that will be returned
//This storage[fd] is pointing to the string that will be stored
//the condition states that if there is a string being pointed to
//but no '\n' then read buffer function is called to return a new
//string. Second condition states that if the pointer pointing is empty
//use readbuffer function to access a file dictated by the file descriptor
//After read buffer function is called and it returns NULL instead of string
//return NULL as the file we are reading is empty
//Direct the line pointer to a whole piece of string returned by new_line function
//if line pointer is not pointing anything, free the entire storage
//if line pointer points to the new string line to be printed, free the line that was
//returned by calling clean_buffer which will return the next line of string onwards
//return this line that was read and to be printed
