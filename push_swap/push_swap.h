/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchua <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 03:35:15 by mchua             #+#    #+#             */
/*   Updated: 2024/04/13 03:35:15 by mchua            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>
# include "./libft/libft.h"

typedef struct s_node
{
	int				data;
	int				current_pos;
	int				final_index;
	int				cost;
	bool			below_mid;
	bool			cheapest;
	struct s_node	*target;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

//algo_utils.c
int		find_stack_length(t_node **stack);
t_node	*find_min_node(t_node *stack);
long	find_max_num(t_node **stack);

//algorithm.c
void	push_swap(t_node **stack_a, t_node **stack_b);
void	sort_three(t_node **stack);
void	sort_five(t_node **stack_a, t_node **stack_b);
void	initialize_node(t_node **stack_a, t_node **stack_b);
void	perform_move(t_node **stack_a, t_node **stack_b);

//init_node_utils.c
void	find_current_pos(t_node **stack);
void	find_target(t_node *stack_a, t_node *stack_b);
void	find_price(t_node *stack_a, t_node *stack_b);
void	find_cheapest(t_node *stack_b);
t_node	*get_cheapest_node(t_node *stack_b);

//push.c
void	push(t_node **src, t_node **dst);
void	pb(t_node **stack_a, t_node **stack_b);
void	pa(t_node **stack_b, t_node **stack_a);

//reverse_rotate.c
void	reverse_rotate(t_node **stack);
void	rra(t_node **stack_a);
void	rrb(t_node **stack_b);
void	rr_both(t_node **stack_a, t_node **stack_b);

//rotate.c
void	rotate(t_node **stack);
void	ra(t_node **stack_a);
void	rb(t_node **stack_b);
void	r_both(t_node **stack_a, t_node **stack_b);

//rotate_operations
void	rotate_both(t_node **stack_a, t_node **stack_b,
			t_node *cheapest_node);
void	reverse_rotate_both(t_node **stack_a, t_node **stack_b,
			t_node *cheapest_node);
void	continue_rotate(t_node **stack, t_node *node_on_top, char c);
//swap.c
void	swap(t_node **stack);
void	sa(t_node **stack_a);
void	sb(t_node **stack_b);
void	s_both(t_node **stack_a, t_node **stack_b);

//split_args.c
void	check_null(void *ptr);
int		count_words(char *str, char sep);
char	*next_word(char *str, char sep);
char	**split_args(char *str, char sep);

//stack_utils.c
t_node	*stack_tail(t_node **stack_a);
void	add_stack(t_node **stack_a, int nbr, char **argv);
void	stack_init(t_node **stack_a, char **argv);

//check_utils.c
bool	correct_input(char *argv);
bool	is_duplicate(t_node *stack_a, int argv);
long	convert_number(char *argv);
bool	in_order(t_node *stack_a);

//handle_error
void	free_array(char **argv);
void	handle_error(int i, char *str, char **argv);
void	free_stack(t_node **stack);
#endif