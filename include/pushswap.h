/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slangero <slangero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 13:28:13 by slangero          #+#    #+#             */
/*   Updated: 2024/11/03 19:21:45 by slangero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H

#define PUSHSWAP_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>
# include "libft.h"

typedef struct s_node
{
	int				value;
//	int				pos;
//	int				target_pos;
//	int				cost_a;
//	int				cost_b;
	struct s_node	*next;
}	t_node;


void		pa(t_node **stack_a, t_node **stack_b);
void		pb(t_node **stack_a, t_node **stack_b);
void		sa(t_node **stack_a);
void		sb(t_node **stack_b);
void		ss(t_node **stack_a, t_node **stack_b);
void		ra(t_node **stack_a);
void		rb(t_node **stack_b);
void		rr(t_node **stack_a, t_node **stack_b);
void		rra(t_node **stack_a);
void		rrb(t_node **stack_b);
void		rrr(t_node **stack_a, t_node **stack_b);

t_node	*init_stack_a(int argc, char **argv);
t_node	*init_stack_b(void);
t_node	*get_last_node(t_node *stack);
t_node	*get_penultimate_node(t_node *stack);
t_node	*node_new(int nb);
t_node	*stack_add(t_node *stack, t_node *node_new);
void	print_stack(t_node *stack_a, t_node *stack_b);

void 	free_stack(t_node **stack);
void 	exit_error(t_node **stack_a, t_node **stack_b, char **argv);
void    check_args(char **argv);

void    sort_stack(t_node **stack_a, t_node **stack_b);
int		get_stack_size(t_node *stack);
t_node  *find_min_node(t_node *stack);
t_node  *find_max_node(t_node *stack);

void	sort_three(t_node **stack);
//void    sort_five(t_node **stack_a, t_node **stack_b);
void	sort_large(t_node **stack_a, t_node **stack_b);

#endif
