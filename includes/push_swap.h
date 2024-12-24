/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qumiraud <qumiraud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 14:54:45 by qumiraud          #+#    #+#             */
/*   Updated: 2024/12/24 15:23:59 by qumiraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

//**************************************************/
//***************   LIB    *******************************/
#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include "../libft/libft.h"
//***************   LIB    *******************************/
//**************************************************/

//**************************************************/
//*******************   struct   *************************/
typedef struct s_stack
{
	int				nbr;
	struct s_stack	*next;

}					t_stack;
//*******************   struct   *************************/
//**************************************************/

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

//********************************************************/
//*******************   atol.c   *************************/
int		ft_atol(char *str);
int		ft_create_number(char *str, long nbr, int sign);
void	ft_atol_overflow_error(void);
void	ft_atol_not_digit_error(void);

//********************************************************/
//*******************   fullarg.c   **********************/
void	ft_badarg_error(void);
char	*ft_strcpy(char *dest, char *src);
char	*ft_strcat(char *dest, char *src);
char	*ft_concat_argv(char *strfullargv, char *tmp, char *argv);
char	*ft_strfullargv(int argc, char **argv);

//********************************************************/
//*******************   list_functions.c   ***************/
t_stack *ft_newstack(int number);
void	ft_stackadd_back(t_stack **stack, t_stack *new);

//********************************************************/
//*******************   utils.c   ************************/
void	ft_puterror_fd(const char *str, const char *color);

//???????????????????   fonctions   ??????????????????????/
//??????????????????????????????????????????????????/

#endif