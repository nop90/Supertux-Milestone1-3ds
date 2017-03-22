//  $Id$
// 
//  SuperTux
//  Copyright (C) 2004 Tobias Glaesser <tobi.web@gmx.de>
//
//  This program is free software; you can redistribute it and/or
//  modify it under the terms of the GNU General Public License
//  as published by the Free Software Foundation; either version 2
//  of the License, or (at your option) any later version.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
// 
//  You should have received a copy of the GNU General Public License
//  along with this program; if not, write to the Free Software
//  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA
//  02111-1307, USA.

#ifndef SUPERTUX_PHYSIC_H
#define SUPERTUX_PHYSIC_H

/** This is a very simplistic physics engine handling accelerated and constant
  * movement along with gravity.
  */
class Physic
{
public:
    Physic();
    ~Physic();

    /** resets all velocities and accelerations to 0 */
    void reset();

    /** sets velocity to a fixed value */
    void set_velocity(float vx, float vy);

    void set_velocity_x(float vx);
    void set_velocity_y(float vy);

    /** velocities invertion */
    void inverse_velocity_x();
    void inverse_velocity_y();

    float get_velocity_x();
    float get_velocity_y();
    
    /** sets acceleration applied to the object. (Note that gravity is
     * eventually added to the vertical acceleration)
     */
    void set_acceleration(float ax, float ay);

    void set_acceleration_x(float ax);
    void set_acceleration_y(float ay);

    float get_acceleration_x();
    float get_acceleration_y();

    /** enables or disables handling of gravity */
    void enable_gravity(bool gravity_enabled);

    /** applies the physical simulation to given x and y coordinates */
    void apply(float frame_ratio, float &x, float &y); 

private:
    /// horizontal and vertical acceleration
    float ax, ay;
    /// horizontal and vertical velocity
    float vx, vy;
    /// should we respect gravity in out calculations?
    bool gravity_enabled;
};

#endif /*SUPERTUX_PHYSIC_H*/
