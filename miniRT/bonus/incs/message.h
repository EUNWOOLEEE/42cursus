/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 17:02:19 by eunwolee          #+#    #+#             */
/*   Updated: 2023/10/30 07:02:14 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MESSAGE_H
# define MESSAGE_H

# define MEMORY "Memory allocation failure"

# define NOTALLOWED "Contain not allowed type"

# define LACK "Lack of essentials"

# define USAGE_ARG "Usage: ./miniRT file.rt"

# define USAGE_A "Usage: A  1.0  255,255,255\n\
- Identifier A\n\
- Ambient lighting ratio in range [0.0,1.0]\n\
- R,G,B colors in range [0-255]"

# define USAGE_SR "Usage: SR 1.0\n\
- Identifier SR\n\
- Specular lighting ratio in range [0.0,1.0]\n"

# define USAGE_C "Usage: C  -50,0,50  0,0,0  90\n\
- Identifier C\n\
- x,y,z coordinates of the view point\n\
- 3d normalized orientation vector. In range [-1,1] for each x,y,z axis\n\
- FOV : Horizontal field of view in degrees in range [0,180]"

# define USAGE_L "Usage: L  -50,0,50  10 255,255,255\n\
- Identifier L\n\
- x,y,z coordinates of the light point\n\
- The light brightness ratio in range\n\
- R,G,B colors in range [0-255]"

# define USAGE_SP "Usage: sp  -50,0,50  10  255,255,255\n\
- Identifier sp\n\
- x,y,z coordinates of the sphere center\n\
- The sphere diameter\n\
- R,G,B colors in range [0-255]"

# define USAGE_PL "Usage: pl  -50,0,50  0,0,0  255,255,255\n\
- Identifier pl\n\
- x,y,z coordinates of a point in the plane\n\
- 3d normalized normal vector. In range [-1,1] for each x,y,z axis\n\
- R,G,B colors in range [0-255]"

# define USAGE_CY "Usage: cy  -50,0,50  0,0,0  10  10  255,255,255\n\
- Identifier cy\n\
- x,y,z coordinates of the center of the cylinder\n\
- 3d normalized vector of axis of cylinder. In range [-1,1] for each x,y,z axis\n\
- The cylinder diameter\n\
- The cylinder height\n\
- R,G,B colors in range [0,255]"

# define USAGE_CO "Usage: co  -50,0,50  0,0,0  10  10  255,255,255\n\
- Identifier co\n\
- x,y,z coordinates of the center of the cone\n\
- 3d normalized vector of axis of cone. In range [-1,1] for each x,y,z axis\n\
- The cone diameter\n\
- The cone height\n\
- R,G,B colors in range [0,255]"

#endif