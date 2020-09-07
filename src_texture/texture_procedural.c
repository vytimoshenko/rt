/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_procedural.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wquirrel <wquirrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 18:48:06 by wquirrel          #+#    #+#             */
/*   Updated: 2020/09/06 19:17:58 by wquirrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "rt.h"

int		stripe_pattern(t_vec p)
{
	if ((int )floor(p.x) % 2 == 0)
		return T_COLOR_W;
	else
		return T_COLOR_BL;
}

int		choose_pattern(int p, t_vec pnt)
{
	if (p == STRIPE)
		return stripe_pattern(pnt);
	return (0);
}