#include "lists.h"

/**
 * print_listint - prints all the elements of a listint_t list.
 * @h: pointer to the list.
 * Return: number of nodes.
 **/
size_t print_listint(const listint_t *h)
{
	size_t count = 0;

	for (; h != NULL; h = h->next, count++)
		printf("%d\n", h->n);

	return (count);
}


