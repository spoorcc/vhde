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

#include "clutter_block.h"

/*
 * Public methods
 */

Glib::RefPtr<ClutterBlock> ClutterBlock::create(const Clutter::Color &color)
{
  return Glib::RefPtr<ClutterBlock>(new ClutterBlock(color));
}

/*
 * Private methods
 */

ClutterBlock::ClutterBlock(const Clutter::Color &color):
  m_color(color)
{
}

void ClutterBlock::drawBox(const Clutter::Color &color, bool hasBorder)
{
  float width, height;

  get_size(width, height);

  cogl_set_source_color4ub(color.get_red(), color.get_green(), color.get_blue(), get_opacity());
  cogl_rectangle(0, 0, width, height);

  if(hasBorder)
  {
    cogl_set_source_color4ub(0x00, 0x00, 0x00, get_opacity());
    cogl_path_rectangle(0, 0, width, height);
    cogl_path_stroke();
  }
}

void ClutterBlock::on_paint()
{
  drawBox(m_color, true);
}

void ClutterBlock::pick_vfunc(const Clutter::Color &color)
{
  drawBox(color, false);
}