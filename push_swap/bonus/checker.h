/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-j <dramos-j@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 16:02:17 by dramos-j          #+#    #+#             */
/*   Updated: 2024/08/24 16:02:17 by dramos-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "get_next_line/get_next_line.h"
# include "../push_swap.h"

int		check_command(char *command, t_stack **a, t_stack **b);
int		check_command2(char *command, t_stack **a, t_stack **b);
void	print_return(t_stack *a, t_stack *b);

#endif
