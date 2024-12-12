#include "push_swap.h"

int	syntax_errors(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!str[i])
		return (1);
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (1);
		i++;
	}
	return (0);
}

int	dup_error(t_list *a, int nb)
{
	if (!a)
		return (0);
	while (a)
	{
		if (a->content == nb)
			return (1);
		a = a->next;
	}
	return (0);
}

void	free_lst(t_list **lst)
{
	t_list	*tmp;
	t_list	*current;

	if (!lst)
		return ;
	current = *lst;
	while (current)
	{
		tmp = current->next;
		current->content = 0;
		free(current);
		current = tmp;
	}
	*lst = NULL;
}

void	free_errors(t_list **a)
{
	free_lst(a);
	write(2, "Error\n", 6);
	exit(1);
}

void	exit_error_av(t_list **a, t_list **b)
{
	if (a == NULL || *a != NULL)
		free_lst(a);
	if (b == NULL || *b != NULL)
		free_lst(b);
	write(2, "Error\n", 6);
	exit(1);
}

#include "push_swap.h"

t_list	*find_target_in_b(t_list *a, t_list *b)
{
	t_list	*tmp_b;
	t_list	*target;
	int		match;

	tmp_b = b;
	target = NULL;
	match = INT_MIN;
	while (tmp_b)
	{
		if (tmp_b->content < a->content && tmp_b->content > match)
		{
			match = tmp_b->content;
			target = tmp_b;
		}
		tmp_b = tmp_b->next;
	}
	if (!target)
		target = find_max(b);
	return (target);
}

void	find_target_a(t_list *a, t_list *b)
{
	while (a)
	{
		if (!b)
			a->target = NULL;
		else
			a->target = find_target_in_b(a, b);
		a = a->next;
	}
}

void	cost_move(t_list *a, t_list *b)
{
	int	len_a;
	int	len_b;

	len_a = lst_size(a);
	len_b = lst_size(b);
	while (a)
	{
		a->cost = a->index;
		if (!(a->div))
			a->cost = len_a - (a->index);
		if (a->target->div)
			a->cost += a->target->index;
		else
			a->cost += len_b - (a->target->index);
		a = a->next;
	}
}

void	cheapest_moves(t_list *lst)
{
	t_list	*cheap;
	int		min_val;

	if (!lst)
		return ;
	cheap = NULL;
	min_val = INT_MAX;
	while (lst)
	{
		if (lst->cost < min_val)
		{
			min_val = lst->cost;
			cheap = lst;
		}
		lst = lst->next;
	}
	cheap->cheapest = true;
}

void	make_lst_a(t_list *a, t_list *b)
{
	define_index(a);
	define_index(b);
	find_target_a(a, b);
	cost_move(a, b);
	cheapest_moves(a);
}

#include "push_swap.h"

void	find_target_b(t_list *a, t_list *b)
{
	t_list	*current_a;
	t_list	*target_node;
	int		best_match_index;

	while (b)
	{
		best_match_index = INT_MAX;
		current_a = a;
		while (current_a)
		{
			if (current_a->content > b->content
				&& current_a->content < best_match_index)
			{
				best_match_index = current_a->content;
				target_node = current_a;
			}
			current_a = current_a->next;
		}
		if (best_match_index == INT_MAX)
			b->target = find_min(a);
		else
			b->target = target_node;
		b = b->next;
	}
}

void	make_lst_b(t_list *a, t_list *b)
{
	define_index(a);
	define_index(b);
	find_target_b(a, b);
}


#include "push_swap.h"

void	move_a_to_b(t_list **a, t_list **b)
{
	t_list	*cheap;

	cheap = get_cheapest_nb(*a);
	if (cheap->div && cheap->target->div)
		rotate_both(a, b, cheap);
	else if (!(cheap->div)
		&& !(cheap->target->div))
		rev_rot_both(a, b, cheap);
	prep_to_push(a, cheap, 'a');
	prep_to_push(b, cheap->target, 'b');
	pb(b, a, false);
}

void	move_b_to_a(t_list **a, t_list **b)
{
	if (*b)
	{
		prep_to_push(a, (*b)->target, 'a');
		pa(a, b, false);
	}
}


#include "push_swap.h"

static void	min_on_top(t_list **a)
{
	while ((*a)->content != find_min(*a)->content)
	{
		if (find_min(*a)->div)
			ra(a, false);
		else
			rra(a, false);
	}
}

void	rotate_both(t_list **a, t_list **b, t_list *cheap)
{
	while (*b != cheap->target && *a != cheap)
		rr(a, b, false);
	define_index(*a);
	define_index(*b);
}

void	rev_rot_both(t_list **a, t_list **b, t_list *cheap)
{
	while (*b != cheap->target && *a != cheap)
		rrr(a, b, false);
	define_index(*a);
	define_index(*b);
}

void	sort_three(t_list **a)
{
	t_list	*big_nb;

	big_nb = find_max(*a);
	if (big_nb == *a)
		ra(a, false);
	else if ((*a)->next == big_nb)
		rra(a, false);
	if ((*a)->content > (*a)->next->content)
		sa(a, false);
}

void	sort_lst(t_list **a, t_list **b)
{
	int	len;

	len = lst_size(*a);
	if (len > 3 && !lst_sorted(*a))
		pb(b, a, false);
	len -= 1;
	if (len > 3 && !lst_sorted(*a))
		pb(b, a, false);
	len -= 1;
	while (len > 3 && !lst_sorted(*a))
	{
		make_lst_a(*a, *b);
		move_a_to_b(a, b);
		len -= 1;
	}
	sort_three(a);
	while (*b)
	{
		make_lst_b(*a, *b);
		move_b_to_a(a, b);
	}
	define_index(*a);
	min_on_top(a);
}

#include "push_swap.h"

void	push(t_list **dest, t_list **src)
{
	t_list	*push_node;

	if (!*src)
		return ;
	push_node = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	push_node->prev = NULL;
	if (!*dest)
	{
		*dest = push_node;
		push_node->next = NULL;
	}
	else
	{
		push_node->next = *dest;
		push_node->next->prev = push_node;
		*dest = push_node;
	}
}

void	swap(t_list **head)
{
	t_list	*first;
	t_list	*second;

	if (!*head || !(*head)->next)
		return ;
	first = *head;
	second = first->next;
	first->next = second->next;
	if (second->next)
		second->next->prev = first;
	second->prev = NULL;
	second->next = first;
	first->prev = second;
	*head = second;
}

void	rotate(t_list **lst)
{
	t_list	*last_node;
	t_list	*first_node;

	if (!*lst || !(*lst)->next)
		return ;
	first_node = *lst;
	last_node = lst_last(*lst);
	*lst = first_node->next;
	(*lst)->prev = NULL;
	first_node->next = NULL;
	last_node->next = first_node;
	first_node->prev = last_node;
}

void	reverse_rotate(t_list **lst)
{
	t_list	*second_last_node;
	t_list	*last_node;

	if (!*lst || !(*lst)->next)
		return ;
	last_node = lst_last(*lst);
	second_last_node = last_node->prev;
	second_last_node->next = NULL;
	last_node->prev = NULL;
	last_node->next = *lst;
	(*lst)->prev = last_node;
	*lst = last_node;
}

#include "push_swap.h"
//#include <stdio.h>

static void	lst_new(t_list **lst, int nb)
{
	t_list	*last_node;
	t_list	*node;

	if (!lst)
		return ;
	node = malloc(sizeof(t_list));
	if (!node)
		return ;
	node->next = NULL;
	node->content = nb;
	if (!(*lst))
	{
		*lst = node;
		node->prev = NULL;
	}
	else
	{
		last_node = lst_last(*lst);
		last_node->next = node;
		node->prev = last_node;
	}
}

static void	launch_sort(t_list **a, t_list **b)
{
	if (!lst_sorted(*a))
	{
		if (lst_size(*a) == 2)
			sa(a, false);
		else if (lst_size(*a) == 3)
			sort_three(a);
		else
			sort_lst(a, b);
	}
}

static void	lst_check_a(t_list **a, char **av)
{
	long	nb;
	int		i;

	i = 0;
	while (av[i])
	{
		if (syntax_errors(av[i]))
			free_errors(a);
		nb = ft_atol(av[i]);
		if (nb > INT_MAX || nb < INT_MIN || nb == LONG_MAX || nb == LONG_MIN)
			free_errors(a);
		if (dup_error(*a, (int)nb))
			free_errors(a);
		lst_new(a, (int)nb);
		i++;
	}
}

int	main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;
	char	**strs;

	a = NULL;
	b = NULL;
	strs = NULL;
	if (ac > 1)
	{
		if (ac == 2)
		{
			strs = ft_split(av[1], ' ');
			if (!strs || !strs[0])
				exit_error_av(NULL, NULL);
			lst_check_a(&a, strs);
		}
		else
			lst_check_a(&a, av + 1);
		launch_sort(&a, &b);
		free_lst(&a);
		return (0);
	}
	else
		return (1);
}

// t_list *tmp = a;
// 		while (tmp)
// 		{
// 			printf("%d ", tmp->content);
// 			tmp = tmp->next;
// 		}


#include "push_swap.h"

int	lst_size(t_list *lst)
{
	t_list	*tmp;
	int		count;

	tmp = lst;
	count = 0;
	if (!tmp)
		return (0);
	while (tmp)
	{
		tmp = tmp->next;
		count++;
	}
	return (count);
}

t_list	*lst_last(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

bool	lst_sorted(t_list *lst)
{
	if (!lst)
		return (true);
	while (lst->next)
	{
		if (lst->content > lst->next->content)
			return (false);
		lst = lst->next;
	}
	return (true);
}

void	define_index(t_list *lst)
{
	int	i;
	int	divide;

	i = 0;
	if (!lst)
		return ;
	divide = lst_size(lst) / 2;
	while (lst)
	{
		lst->index = i;
		if (i <= divide)
			lst->div = true;
		else
			lst->div = false;
		lst = lst->next;
		i++;
	}
}



#include "push_swap.h"

static void	if_a_if_b(t_list **lst, t_list *top_node, char lst_name)
{
	if (lst_name == 'a')
	{
		if (top_node->div)
			ra(lst, false);
		else
			rra(lst, false);
	}
	else if (lst_name == 'b')
	{
		if (top_node->div)
			rb(lst, false);
		else
			rrb(lst, false);
	}
}

void	prep_to_push(t_list **lst, t_list *top_node, char lst_name)
{
	t_list	*tmp;
	bool	found;

	tmp = *lst;
	found = false;
	while (tmp)
	{
		if (tmp == top_node)
		{
			found = true;
			break ;
		}
		tmp = tmp->next;
	}
	if (!found)
		return ;
	while (*lst != top_node)
	{
		if_a_if_b(lst, top_node, lst_name);
	}
}

t_list	*find_min(t_list *lst)
{
	int		min;
	t_list	*min_node;

	if (!lst)
		return (NULL);
	min = INT_MAX;
	while (lst)
	{
		if (lst->content < min)
		{
			min = lst->content;
			min_node = lst;
		}
		lst = lst->next;
	}
	return (min_node);
}

t_list	*find_max(t_list *lst)
{
	int		max;
	t_list	*max_node;

	if (!lst)
		return (NULL);
	max = INT_MIN;
	while (lst)
	{
		if (lst->content > max)
		{
			max = lst->content;
			max_node = lst;
		}
		lst = lst->next;
	}
	return (max_node);
}

t_list	*get_cheapest_nb(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst)
	{
		if (lst->cheapest)
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}





