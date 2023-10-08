#include "main.h"

/**
 * _memcpy_n - will copy info between void pointers.
 * @new_ptr: destination pointer.
 * @pointer: source pointer
 * @size_n: size of the new pointer.
 *
 * Return: no return.
 */
void _memcpy_n(void *new_ptr, const void *pointer, unsigned int size_n)
{
	char *char_ptr = (char *)pointer;
	char *char_newptr = (char *)new_ptr;
	unsigned int e;

	for (e = 0; e < size_n; e++)
		char_newptr[e] = char_ptr[e];
}

/**
 * _realloc_n - ireallocates a memory block.
 * @pointer: ppointer to the memory previously allocated.
 * @old_size_n: size, in bytes, of the allocated space of ptr.
 * @new_size_n: new size, in bytes, of the new mem block.
 *
 * Return: pointer.
 * if new_size_n == old_size, returns ptr without changes.
 * if malloc fails,will returns NULL.
 */

void *_realloc_n(void *pointer, unsigned int old_size_n,
				unsigned int new_size_n)
{
	void *new_ptr;

	if (pointer == NULL)
		return (malloc(new_size_n));

	if (new_size_n == 0)
	{
		free(pointer);
		return (NULL);
	}

	if (new_size_n == old_size_n)
		return (pointer);

	new_ptr = malloc(new_size_n);
	if (new_ptr == NULL)
		return (NULL);

	if (new_size_n < old_size_n)
		_memcpy_n(new_ptr, pointer, new_size_n);
	else
		_memcpy_n(new_ptr, pointer, old_size_n);

	free(pointer);
	return (new_ptr);
}

/**
 * _reallocdp_n - Reallocates a memory block of a double pointer.
 * @pointer: pointer to the memory previously allocated.
 * @old_size_n: size, in bytes, of the allocated space of ptr.
 * @new_size_n: new size, in bytes, of new mem Block.
 *
 * Return: pointer.
 * if new_size_n == old_size, returns ptr wt changes.
 * if malloc fails, will returns NULL.
 */

char **_reallocdp_n(char **pointer,
		unsigned int old_size_n, unsigned int new_size_n)
{
	char **new_ptr;
	unsigned int e;

	if (pointer == NULL)
		return (malloc(sizeof(char *) * new_size_n));

	if (new_size_n == old_size_n)
		return (pointer);

	new_ptr = malloc(sizeof(char *) * new_size_n);
	if (new_ptr == NULL)
		return (NULL);

	for (e = 0; e < old_size_n; e++)
		new_ptr[e] = pointer[e];

	free(pointer);

	return (new_ptr);
}
