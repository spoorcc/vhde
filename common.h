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

#ifndef _COMMON_H
#define _COMMON_H

#define DIR_TO_NAME(d) ((d == DIR_IN) ? "IN" : \
                        (d == DIR_OUT) ? "OUT" : \
                        (d == DIR_INOUT) ? "INOUT" : \
                                           "INVALID")

typedef enum {
  DIR_IN,
  DIR_OUT,
  DIR_INOUT,
  DIR_INVALID
} Direction;

#endif /* _COMMON_H */