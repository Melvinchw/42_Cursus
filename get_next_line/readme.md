# Get_next_line
## Prototype: get_next_line(fd)
### Content
- [Requirement](https://github.com/Melvinchw/42_Cursus/edit/main/get_next_line/readme.md#requirement)
- Pseudocode
- Function Brief
- Terminology
- Resources
### Requirement
- Using a loop in the main function get_next_line should print one line at a time
- If there is nothing else to read or there is an error, it should return NULL
- Returned line should consist of the `\n` character in it unless `EOF` has been reached.
### Pseudocode(TBC)
- Error handling for negative FD
- Get and store line in buffer
- Access buffer and print line up to the `\n` character
- Remove line that was printed
- In the event of any error, free allocated memory
- Return line that was retrieved

## Function Brief
- get_next_line
> This is the main function that will call for the rest of the sub-functions and return the new line to be printed.
- read_buffer
> The purpose of this function is to `read` the file that was opened in the `int main` function pass through the `get_next_line` function and store it in the buffer. Number of character to store is determined by the buffer size. It then the individual buffer together using `substring` to return a full string up to the first `\n` and return that string.
- new_line
> The purpose of this function is to access the storage where the joined line was returned from `read_buffer` function and extract a string up to the first `\n` character.
- clear_buffer
> The purpose of this function is to remove the string that has been printed up to the first `\n` character.
- ft_free
> The purpose of this function is to remove the content pointed to by the pointer and initialize it to NULL.
## Function breakdown
### get_next_line
1. To start with this function, we need a `static variable`. Static variable is used to store newly appended string after returning the line.
2. A char ptr `line` is declared and initialized to point to the string that will be returned at the end of the function.
3. Static variable `Storage[fd]` is pointing to the string that is stored in the buffer when `read_buffer` is called.
4. Conditions for the `get_next_line` functions is stated below:
> - if int `fd` is lesser than 0, this indicates error. As such it should return `NULL`
> - if `storage[fd]` has a value and have not reached `\n` or `storage[fd]` is empty, call for `read_buffer` function to access file and start getting lines.
> - if `storage[fd]` passed into `read_buffer` comes back with a NULL,  return `NULL` as this probably indicates `EOF` or Error.
5. At this point, `storage[fd]` contains the entire file that was read. To get the function to work, we have to extract 1 line by 1 line. This is done by calling new_line function.
> - Function will take storage[fd] as argument
> - It will then return a string up to the first `\n`
6. After the new line is stored by `line` pointer. We have to remove the line that was returned from the storage so that subsequent calls will start from the new line due to the usage of static variables. This is done by calling for `clean_buffer` function.

		char	*get_next_line(int fd)
		{
			static char *storage[fd];
			char        *line;	
		
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

### read_buffer
1. `buffer` array is declared so that we can dynamically allocate memory to it.
2. `index-readed` is declared to help keep track of how many characters were read as `read` returns the number of characters read. It is initialized as 1 to indicate
   at there is data in the file.
4. `buffer` is malloced to buffer size + 1 to account for all the characters and a NULL terminator. Error handling is done for memory leaks here. If allocation is unsuccessful, we will call for `ft_free`
5. A `while` loop is used with the following conditions:
> - `index_readed` is greater than 0 to indicate there is data in the file
> - `strchr` is not `\n` so that the loop continues until it hits the new line.
6. Buffer is stored with characters that was read. `strjoin` is used to join characters stored in `buffer` into `storage`. This keeps looping until the conditions are not met and it exits the loop.
7. Once the loop is exited. Since storage contains the whole string. We can `free` the buffer.
8. At the end of the file, we also have to check if there was an error reading file, this is indicated by index_readed == -1. If so, we have to call for `ft_free` function.
9. Return `storage`

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

### new_line
1. `ptr` is declared as a pointer to the position of `\n`. This is done by using `strchr` function which returns the first occurence of the `\n` character.
2. `line` is declared to extract the string that we would like to return.
3. `len` is declared to determine the length that we would like to extract. This is done by subtracting `storage` pointer with `ptr` pointer + 1 to account for a NULL character. This is possible because both pointers are pointing to an array with sequential index.
5. `ft_substr` is used to extract the line and subsequently, line is returned.

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
 
### clean_buffer
1. `ptr` is declared as a pointer to the position of `\n`. This is done by using `strchr` function which returns the first occurence of the `\n` character.
2. `line` is declared to extract the string that we would like to return.
3. `len` is declared to determine the length that we would like to extract. This is done by subtracting `ft_strlen(storage)` pointer with `ptr` pointer + 1 to account for a NULL 
//free the content at the old storage as a new_storage is already stored
//with the new line of string.

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

### ft_free
1. This function frees the value of the pointer it is pointing to.
2. After which, it initialize it to NULL.
3. Return NULL as a good practice. This is to indicate that memory have been freed correctly.
	
	 	char    *ft_free(char **str)
		{
		    free (*str);
		    *str = NULL;
		    return (NULL);
		}

## Terminology
### Static Variables
#### Variables are stored in the data portion of the memory. If the value is initialized, it will remain even if the programme stops. However, each time a programme is run, if the value is altered it will be reflected in the variables. These variables are stored within the function and can be used to store data values when the previous function call do something to the data eg get_next_line.
### Read/Open/Close
### Read
#### int read(int fd)
#### `read()` attempts to read up to count bytes from the file descriptor (fd) into the buffer. It functions are as follow:
- read operation will commence at the file offset, this means that it will continue from where the previous read operation stops.
- when `eof` is reached, no bytes are read, and read() returns zero. If the count is zero, read() will try to detect for errors.
- read will return 0 if no error is found. If error is found it will return -1.
### Open
#### int open(const chcar *pathname, int flags, mode_t mode)
#### `open()` calls the file specified by the pathname and opens it. In the event that the file to be opened does not exist it may be created with `O_CREAT` flag.
- open() returns a file descriptor integer which is then used in subsequent system calls to refer to the opened file.
- the returned file descriptor from this command will be the **lowest numbered** file descriptor that is not currently open for the process.
- Commonly used flags are: `O_RDONLY`, `O_WRONLY`, `O_RDWR`. For more information search for `man open`.
### Close
#### int close(int fd)
#### `close()` is used to close a file descriptor
- once the file is closed, it no longer refers to any file and the file descriptor may be reused.
- upon success, `close()` returns zero and -1 upone error. errno is set to indicate the error.
## Life after get_next_line
> - I managed to finish this by reading the whole file. I am looking to see if there is anyway to read and store buffer line by line such that if the buffer size is too small. It won't time out. I want to try to make the code more efficient.'
> - I used strjoin to complete this project. Next up I will be looking to use linked list to complete it as practice for linked list.
