/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qumiraud <qumiraud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 14:54:45 by qumiraud          #+#    #+#             */
/*   Updated: 2025/02/07 13:28:19 by qumiraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H


//***************   LIB    *******************************/
#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include "../libft/libft.h"
//***************   LIB    *******************************/

//*******************   struct   *************************/
typedef struct s_stack
{
	long				nbr;
	int					bestmove;
	int					proxi;
	int					over_middle;
	struct s_stack	*next;

}					t_stack;
//*******************   struct   *************************/


//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!/
//!!!!!!!!!!!   ERRORS COLORS   !!!!!!!!!!!!!!!!!!!!!!!!!!/
# define RESET_COLOR	"\x1b[0m"
# define RED			"\x1b[31m"
# define GREEN			"\x1b[32m"
# define YELLOW			"\x1b[33m"
# define BLUE			"\x1b[34m"
# define PURPLE			"\x1b[35m"
# define CYAN			"\x1b[36m"
# define BLANC			"\x1b[37m"
//!!!!!!!!!!!   ERRORS COLORS   !!!!!!!!!!!!!!!!!!!!!!!!!!/
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!/

//??????????????????????????????????????????????????/
//???????????????????   fonctions   ??????????????????????/
int		main(int argc, char **argv);



//*******************   atol.c   *************************/
long	ft_atol(char *str);
long	ft_create_number(char *str, long nbr, int sign);

//*******************   fullarg.c   **********************/
char	*ft_concat_argv(char *strfullargv, char *tmp, char *argv);
char	*ft_strfullargv(int argc, char **argv);

//*******************   list_functions.c   ***************/
t_stack *ft_newstack(long number);
void	ft_stackadd_back(t_stack **stack, t_stack *new);
void	ft_clearstack(t_stack **stack_a);
int		ft_stacksize(t_stack *stack);
t_stack	*ft_stacklast(t_stack *stack);

//*******************   no_double.c   *************************/
int		ft_nodouble(t_stack *stack_a);

//*******************   swap.c   *************************/
void	swap_a(t_stack **stack_a);
void	swap_b(t_stack **stack_b);
void	swap_swap(t_stack **stack_a, t_stack **stack_b);

//*******************   swap.c   *************************/
void	push_a(t_stack **stack_a, t_stack **stack_b);
void	push_b(t_stack **stack_a, t_stack **stack_b);

//*******************   rotate.c   *************************/
void	rotate_a(t_stack **stack_a);
void	rotate_b(t_stack **stack_b);
void	rotate_rotate(t_stack **stack_a, t_stack **stack_b);

//*******************   reverse_rotate.c   **********************/
void	reverse_rotate_a(t_stack **stack_a);
void	reverse_rotate_b(t_stack **stack_b);
void	reverse_rotate_rotate(t_stack **stack_a, t_stack **stack_b);

//*******************   sort.c   *******************************/
void	ft_go_pushswap(t_stack **stack_a);
int		ft_good_order(t_stack	*stack);
int		ft_find_min(t_stack	*stack);
int		ft_find_max(t_stack	*stack_a);

//*******************   special_case.c   *******************************/
void	ft_special_case(t_stack **stack_a, int size); //je suis commertyaire

//*******************   for_three.c   *******************************/
void	ft_for_three_high_first(t_stack **stack_a, t_stack *lastnode);
void	ft_for_three(t_stack **stack_a, t_stack *lastnode);

//*******************   for_five.c   *******************************/
void	ft_for_five(t_stack	**stack_a, t_stack **stack_b);
void	ft_bestmove_for_five(t_stack **stack_a, t_stack **stack_b, int size);

//*******************   overfive.c   *******************************/
void	ft_over_five(t_stack **stack_a, int size);

//*******************   cheapest_move.c   *******************************/
int		ft_cheapest_move(t_stack **stack_a, t_stack *stack_b, int size_b);
int		get_index_b(t_stack *stack_b, int i, t_stack *nav_a);
void	change_best_index(int i, int *j, t_stack **reset, t_stack *nav_a);
int		break_conditions(t_stack *stack_b, t_stack *nav_a, t_stack *nav_b);

//*******************   search_proxi.c   *******************************/
void	search_proxi(int ref, t_stack *stack);
void	search_proxi_for_return(int ref, t_stack *stack);

//*******************   bestmove_in_a.c   *******************************/
void	bestmove_in_top_a_little(t_stack **stack_a, t_stack **stack_b, int *move);
void	move_a_on_top(int i, t_stack **stack_a);
void	bestmove_in_top_a_big(t_stack **stack_a, t_stack **stack_b, int *move);
void	bestmove_i_big_a(int i, int *move, t_stack **stack_a, t_stack **stack_b);

//*******************   bestmove_in_b.c   *******************************/
void	bestmove_in_top_b_little(t_stack **stack_b, t_stack **stack_a, int *move);
int	get_bestmove_pos(t_stack **stack_b);
void	bestmove_in_top_b_big(t_stack **stack_b, t_stack **stack_a, int *move);
void	bestmove_i_big_b(int i, int *move, t_stack **stack_a, t_stack **stack_b);

//*******************   utils.c   ************************/
void	ft_puterror_fd(char *str);
int		ft_countarg(char **tab);
void	ft_freeall(char **tab, int i);
char	*ft_strcat(char *dest, char *src);
char	*ft_strcpy(char *dest, char *src);

//*******************   errors.c   *************************/
void	ft_badarg_error(char *str);
void	ft_atol_overflow_error(void);
void	ft_atol_not_digit_error(void);

//*******************   ft_printstack.c   *************************/
void	ft_printstack(t_stack *stack_a, t_stack *stack_b);

//???????????????????   fonctions   ??????????????????????/
//??????????????????????????????????????????????????/

#endif