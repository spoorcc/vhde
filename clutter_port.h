/* vim: ts=2:sw=2:expandtab
 *
 * Copyright 2009 Maurice van der Pot <griffon26@kfk4ever.com>
 *
 * This file is part of Foobar.
 *
 * Foobar is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Foobar is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Foobar.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#ifndef _CLUTTER_PORT_H
#define _CLUTTER_PORT_H

#include <cluttermm.h>

class ClutterPort: public Clutter::Actor
{
public:
  typedef enum {
    EAST,
    SOUTH,
    WEST,
    NORTH
  } Orientation;

  typedef enum {
    TYPE_INPUT,
    TYPE_OUTPUT,
    TYPE_BIDIRECTIONAL
  } Type;

private:
  Clutter::Color  m_color;
  Orientation     m_orientation;
  Type            m_type;

public:
  static Glib::RefPtr<ClutterPort> create(const Clutter::Color &color);

  void setOrientation(Orientation orientation);
  void setType(Type type);

private:
  explicit ClutterPort(const Clutter::Color &color);

  void drawTriangle(const Clutter::Color &color, bool hasBorder);

  void on_paint();
  void pick_vfunc(const Clutter::Color &color);
};

#endif /* _CLUTTER_PORT_H */