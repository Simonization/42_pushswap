/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slangero <slangero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 13:28:13 by slangero          #+#    #+#             */
/*   Updated: 2024/12/16 18:44:52 by slangero         ###   ########.fr       */
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

/* Structures */
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

/* Basic Stack Operations */
// Push Operations
void		pa(t_node **stack_a, t_node **stack_b);
void		pb(t_node **stack_b, t_node **stack_a);

// Swap Operations
void		sa(t_node **stack_a);
void		sb(t_node **stack_b);
void		ss(t_node **stack_a, t_node **stack_b);

// Rotate Operations
void		ra(t_node **stack_a);
void		rb(t_node **stack_b);
void		rr(t_node **stack_a, t_node **stack_b);
void		rotate_both(t_node	**stack_a, t_node	**stack_b,
				t_node	*cheapest_node);

// Reverse Rotate Operations
void		rra(t_node **stack_a);
void		rrb(t_node **stack_b);
void		rrr(t_node **stack_a, t_node **stack_b);

/* Stack Management */
// Initialization Functions
void		init_stack_a(t_node **stack_a, char **av);
t_node		*init_stack_b(void);
t_node		*node_new(int nb);
t_node		*stack_add(t_node *stack, t_node *node_new);

// Stack Navigation
t_node		*get_last_node(t_node *stack);
t_node		*get_penultimate_node(t_node *stack);
int			get_stack_size(t_node *stack);

/* Stack Analysis and Cost Calculation */
// Position Management
void		current_pos(t_node *stack);
void		set_target_value(t_node *stack);
void		prep_for_push(t_node	**stack, t_node	*top_node, char stack_name);
bool		stack_is_sorted(t_node *stack);

// Node Finding
t_node		*find_min_node(t_node *stack);
t_node		*find_max_node(t_node *stack);
t_node		*get_cheapest(t_node *stack);

/* Sorting Algorithms */
// Main Sorting Functions
void		sort_stack(t_node **stack_a, t_node **stack_b);
void		sort_three(t_node **stack);
void		sort_large(t_node **stack_a, t_node **stack_b);

/* Initialization and Target Setting */
void		init_nodes_a(t_node *stack_a, t_node *stack_b);
void		init_nodes_b(t_node *stack_a, t_node *stack_b);
void		set_target_a(t_node *stack_a, t_node *stack_b);
void		set_target_b(t_node *stack_a, t_node *stack_b);
void		set_cheapest(t_node	*stack);

/* Stack Movement Operations */
void		rotate_until_top(t_node **stack, t_node *node,
				bool is_median, char stack_name);
void		min_on_top(t_node **stack_a);
void		move_a_to_b(t_node **stack_a, t_node **stack_b);
void		move_b_to_a(t_node **stack_a, t_node **stack_b);

/* Stack A Cost Analysis and Target Finding */
int			get_position_cost_a(t_node *node, int stack_size);
int			get_combined_cost_a(int cost_a, int cost_b,
				t_node *node_a, t_node *target);
void		cost_analysis_a(t_node *stack_a, t_node *stack_b);
t_node		*find_target_in_b(t_node *a, t_node *b);

/* Stack B Cost Analysis and Target Finding */
int			get_position_cost_b(t_node *node, int stack_size);
int			get_combined_cost_b(int cost_a, int cost_b,
				t_node *node_a, t_node *target);
void		cost_analysis_b(t_node *stack_a, t_node *stack_b);
t_node		*find_target_in_a(t_node *a, t_node *b);

/* Error Handling and Validation */
void		free_args(char **args);
void		free_stack(t_node **stack);
void		exit_error(t_node **stack_a, t_node **stack_b, char **argv);
int			handle_input_error(char **args);
int			validate_args(char **argv);
int			syntax_errors(char *str);
int			has_duplicates(char **argv);

/* Debug Functions */
void		print_stack(t_node *stack_a, t_node *stack_b);

#endif
