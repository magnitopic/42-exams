#include "ft_list.h"


void	ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
	t_list	*current_node;

	current_node = begin_list;
	while (current_node)
	{
		(*f)(current_node->data);
		current_node =  current_node->next;
	}
}

