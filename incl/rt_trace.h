/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_trace.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 12:04:38 by mperseus          #+#    #+#             */
/*   Updated: 2020/08/26 12:04:40 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef rt_TRACE_H

# define rt_TRACE_H

# define VIEWPORT_SIZE_W				1.25
# define VIEWPORT_SIZE_H				1
# define VIEWPORT_DISTANCE				1

# define EMPTY							-2

# define LIGHT_TYPE_AMBIENT				0
# define LIGHT_TYPE_POINT				1
# define LIGHT_TYPE_DIRECTIONAL			2

# define OBJECT_TYPE_PLANE				0
# define OBJECT_TYPE_SPHERE				1
# define OBJECT_TYPE_CYLINDER			2
# define OBJECT_TYPE_CONE				3

# define REFLECTION_DEPTH				3
# define MIN							0.0001
# define MAX							100000

# define PI								3.14159265

void		trace_rays(t_scene *scene);
void		prepare_pixs(t_scene *scene);
void		get_centered_coordinates(t_pix *pix);
void		get_pix_viewport_coordinates(t_scene *scene, t_pix *pix);
void		rotate_pix(t_pix *pix, t_cam *cam);

void		trace_pixel(t_scene *scene, t_vec cam, t_pix *pix, int refl_depth);
void		get_prop(t_scene *scene, t_pix *pix, t_pnt *point, t_obj *obj);
void		get_normal(t_pnt *point, t_vec pix, t_obj *obj, t_vec cam);

t_obj		intersect(t_objs objs, t_vec cam, t_vec pix, t_mn_mx t_min_max);
t_obj		check_closest_obj(t_obj closest_obj, double closest);
void		select_obj_intersect(t_obj *obj, t_vec cam, t_vec pix);

void		plane(t_obj *obj, t_vec cam, t_vec pix);
void		sphere(t_obj *obj, t_vec cam, t_vec pix);
void		cylinder(t_obj *obj, t_vec cam, t_vec pix);
void		cone(t_obj *obj, t_vec cam, t_vec pix);

void		plane_n(t_pnt *pnt, t_vec pix, t_obj *obj);
void		sphere_n(t_pnt *pnt, t_vec pix, t_obj *obj);
void		cylinder_n(t_pnt *pnt, t_vec pix, t_obj *obj, t_vec cam);
void		cone_n(t_pnt *pnt, t_vec pix, t_obj *obj, t_vec cam);

double		get_light(t_scene *scene, t_pnt point, t_vec pix);
double		diffuse_and_specular(t_scene *scene, t_pnt point, t_vec pix, int i);
double		diffuse(t_vec normal, t_vec light);
double		specular(t_vec normal, t_vec light, t_vec pix, double specular);
t_vec		reflect_ray(t_vec ray, t_vec normal);

double		deg_to_rad(int degrees);
double		dot(t_vec v1, t_vec v2);
double		len(t_vec v1);
t_vec		nrm(t_vec v);

t_vec		add(t_vec v1, t_vec v2);
t_vec		sub(t_vec v1, t_vec v2);
t_vec		mult(double k, t_vec v);

#endif
