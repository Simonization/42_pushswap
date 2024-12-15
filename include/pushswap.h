/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slangero <slangero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 13:28:13 by slangero          #+#    #+#             */
/*   Updated: 2024/12/15 18:48:32 by slangero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H

# define PUSHSWAP_H

# include <stdio.h>

# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <limits.h>
# include <stdbool.h>
# include "libft.h"

typedef struct s_node
{
	int				value;
	int				pos;
	bool			upper_median;
	int				cost;
	bool			cheapest;
	struct s_node	*target_node;
	struct s_node	*next;
	struct s_node	*prev;	
}	t_node;

void		pa(t_node **stack_a, t_node **stack_b);
void		pb(t_node **stack_b, t_node **stack_a);
void		sa(t_node **stack_a);
void		sb(t_node **stack_b);
void		ss(t_node **stack_a, t_node **stack_b);
void		ra(t_node **stack_a);
void		rb(t_node **stack_b);
void		rr(t_node **stack_a, t_node **stack_b);
void		rotate_both(t_node	**stack_a, t_node	**stack_b,
				t_node	*cheapest_node);
void		rra(t_node **stack_a);
void		rrb(t_node **stack_b);
void		rrr(t_node **stack_a, t_node **stack_b);

void		init_stack_a(t_node **stack_a, char **av);
t_node		*init_stack_b(void);
t_node		*get_last_node(t_node *stack);
t_node		*get_penultimate_node(t_node *stack);
t_node		*node_new(int nb);
t_node		*stack_add(t_node *stack, t_node *node_new);
void		print_stack(t_node *stack_a, t_node *stack_b);

void		free_args(char **args);
void		free_stack(t_node **stack);
void		exit_error(t_node **stack_a, t_node **stack_b, char **argv);

int			split_av_size(char **av);
int			has_duplicates(char **argv);
int			syntax_errors(char *str);
int			validate_args(char **argv);

void		sort_stack(t_node **stack_a, t_node **stack_b);

bool		stack_is_sorted(t_node *stack);
int			get_stack_size(t_node *stack);
t_node		*find_min_node(t_node *stack);
t_node		*find_max_node(t_node *stack);
t_node		*get_cheapest(t_node *stack);

void		sort_three(t_node **stack);
void		sort_large(t_node **stack_a, t_node **stack_b);

void		current_pos(t_node *stack);
void		prep_for_push(t_node	**stack,
				t_node	*top_node,
				char stack_name);
void		set_cheapest(t_node	*stack);
void		init_nodes_a(t_node *stack_a, t_node *stack_b);
void		init_nodes_b(t_node *stack_a, t_node *stack_b);

void		set_target_a(t_node *stack_a, t_node *stack_b);
void		set_target_b(t_node *stack_a, t_node *stack_b);
/*    Tester  */
//void print_stacks(t_node *stack_a, t_node *stack_b);

#endif
