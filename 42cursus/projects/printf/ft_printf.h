/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnoda-ta <mnoda-ta@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 10:21:02 by mnoda-ta          #+#    #+#             */
/*   Updated: 2026/05/13 10:21:05 by mnoda-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>

int	ft_printf(const char *str, ...);

/*
	====== FORMATTING ======
*/
int	ft_putchar(char c);
int	ft_putstr(char *s);
int	ft_putnbr(int nb);
int	ft_putnbr_base(unsigned int nb, char *base);
int	ft_putuint(unsigned int nb);
int	ft_putptr(unsigned long long);

/*
	====== AUXILIARS ======
*/
int	ft_strlen(char *s);
#endif
