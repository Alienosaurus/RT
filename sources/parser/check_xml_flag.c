/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_xml_flag.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafanass <vafanass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 20:39:28 by vafanass          #+#    #+#             */
/*   Updated: 2017/03/25 20:25:07 by vafanass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void	check_flag_quater(t_parser *parser, UINT flag)
{
	if ((flag ^ BYTE_SPHERE) == (BYTE_OBJ | BYTE_DIFFLIGHT | BYTE_COLOR) ||
		(flag ^ BYTE_PLANE) == (BYTE_OBJ | BYTE_DIFFLIGHT | BYTE_COLOR) ||
		(flag ^ BYTE_CONE) == (BYTE_OBJ | BYTE_DIFFLIGHT | BYTE_COLOR) ||
		(flag ^ BYTE_CYLINDER) == (BYTE_OBJ | BYTE_DIFFLIGHT | BYTE_COLOR) ||
		(flag ^ BYTE_ELLIPSOID) == (BYTE_OBJ | BYTE_DIFFLIGHT | BYTE_COLOR) ||
		(flag ^ BYTE_PARABLOID) == (BYTE_OBJ | BYTE_DIFFLIGHT | BYTE_COLOR) ||
		(flag ^ BYTE_TRIANGLE) == (BYTE_OBJ | BYTE_DIFFLIGHT | BYTE_COLOR))
		parser->f = (void*)&bo_difflight_color;
	else if ((flag ^ BYTE_SPHERE) == (BYTE_OBJ | BYTE_LAMBERT | BYTE_COLOR) ||
		(flag ^ BYTE_PLANE) == (BYTE_OBJ | BYTE_LAMBERT | BYTE_COLOR) ||
		(flag ^ BYTE_CONE) == (BYTE_OBJ | BYTE_LAMBERT | BYTE_COLOR) ||
		(flag ^ BYTE_CYLINDER) == (BYTE_OBJ | BYTE_LAMBERT | BYTE_COLOR) ||
		(flag ^ BYTE_ELLIPSOID) == (BYTE_OBJ | BYTE_LAMBERT | BYTE_COLOR) ||
		(flag ^ BYTE_PARABLOID) == (BYTE_OBJ | BYTE_LAMBERT | BYTE_COLOR) ||
		(flag ^ BYTE_TRIANGLE) == (BYTE_OBJ | BYTE_LAMBERT | BYTE_COLOR))
		parser->f = (void*)&bo_lambert_color;
	else
		check_flag_dielect(parser, flag);
}

static void	check_flag_ter(t_parser *parser, UINT flag)
{
	if (flag == (BYTE_OBJ | BYTE_ELLIPSOID | BYTE_HEIGHT))
		parser->f = (void*)&bo_ellipsoid_height;
	else if (flag == (BYTE_OBJ | BYTE_PARABLOID | BYTE_HEIGHT))
		parser->f = (void*)&bo_paraboloid_height;
	else if (flag == (BYTE_OBJ | BYTE_PARABLOID | BYTE_POS))
		parser->f = (void*)&bo_paraboloid_pos;
	else if (flag == (BYTE_OBJ | BYTE_PARABLOID | BYTE_ROTATE))
		parser->f = (void*)&bo_paraboloid_rotate;
	else if (flag == (BYTE_OBJ | BYTE_TRIANGLE | BYTE_POS))
		parser->f = (void*)&bo_triangle_pos;
	else if (flag == (BYTE_OBJ | BYTE_CYLINDER | BYTE_HEIGHT))
		parser->f = (void*)&bo_cylinder_height;
	else if (flag == (BYTE_OBJ | BYTE_CONE | BYTE_HEIGHT))
		parser->f = (void*)&bo_cone_height;
	else if (flag == (BYTE_OBJ | BYTE_PLANE | BYTE_RADIUS))
		parser->f = (void*)&bo_plane_radius;
	else
		check_flag_quater(parser, flag);
}

static void	check_flag_bis(t_parser *parser, UINT flag)
{
	if (flag == (BYTE_OBJ | BYTE_CONE | BYTE_RADIUS))
		parser->f = (void*)&bo_cone_radius;
	else if (flag == (BYTE_OBJ | BYTE_CONE | BYTE_ROTATE))
		parser->f = (void*)&bo_cone_rotate;
	else if (flag == (BYTE_OBJ | BYTE_CYLINDER | BYTE_POS))
		parser->f = (void*)&bo_cylinder_pos;
	else if (flag == (BYTE_OBJ | BYTE_CYLINDER | BYTE_RADIUS))
		parser->f = (void*)&bo_cylinder_radius;
	else if (flag == (BYTE_OBJ | BYTE_CYLINDER | BYTE_ROTATE))
		parser->f = (void*)&bo_cylinder_rotate;
	else if (flag == (BYTE_SKYBOX | BYTE_GRADIENT | BYTE_COLOR))
		parser->f = (void*)&bo_skgradient_color;
	else if (flag == (BYTE_OBJ | BYTE_ELLIPSOID | BYTE_POS))
		parser->f = (void*)&bo_ellipsoid_pos;
	else if (flag == (BYTE_OBJ | BYTE_ELLIPSOID | BYTE_ROTATE))
		parser->f = (void*)&bo_ellipsoid_rotate;
	else if (flag == (BYTE_OBJ | BYTE_ELLIPSOID | BYTE_RADIUS))
		parser->f = (void*)&bo_ellipsoid_radius;
	else
		check_flag_ter(parser, flag);
}

void		check_flag(t_parser *parser, UINT flag)
{
	if (flag == (BYTE_CAM | BYTE_POS))
		parser->f = (void*)&bo_cam_pos;
	else if (flag == (BYTE_CAM | BYTE_TARGET))
		parser->f = (void*)&bo_cam_target;
	else if (flag == (BYTE_CAM | BYTE_ROTATE))
		parser->f = (void*)&bo_cam_rotate;
	else if (flag == (BYTE_CAM | BYTE_FOV))
		parser->f = (void*)&bo_cam_fov;
	else if (flag == (BYTE_CAM | BYTE_APERT))
		parser->f = (void*)&bo_cam_apert;
	else if (flag == (BYTE_OBJ | BYTE_SPHERE | BYTE_POS))
		parser->f = (void*)&bo_sphere_pos;
	else if (flag == (BYTE_OBJ | BYTE_SPHERE | BYTE_RADIUS))
		parser->f = (void*)&bo_sphere_radius;
	else if (flag == (BYTE_OBJ | BYTE_PLANE | BYTE_POS))
		parser->f = (void*)&bo_plane_pos;
	else if (flag == (BYTE_OBJ | BYTE_PLANE | BYTE_ROTATE))
		parser->f = (void*)&bo_plane_rotate;
	else if (flag == (BYTE_OBJ | BYTE_CONE | BYTE_POS))
		parser->f = (void*)&bo_cone_pos;
	else
		check_flag_bis(parser, flag);
}

void		check_objsame(t_parser *p, char *line, char *str)
{
	if (1 != p->same)
	{
		ft_printf("XML %s ERROR - Can't assign more or less (%d) %s than "
		"initiated at line %d: '%s'\n", __FUNCTION__, p->i_obj, str, p->l,
		line);
		exit(-1);
	}
	p->same++;
}
