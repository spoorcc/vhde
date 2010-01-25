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

#include "layout_port.h"

LayoutPort::LayoutPort():
  m_pPort(NULL)
{
}

void LayoutPort::associateVHDLPort(INamedItem *pPort)
{
  g_assert(m_pPort == NULL);
  m_pPort = pPort;
}

INamedItem *LayoutPort::getAssociatedVHDLPort()
{
  g_assert(m_pPort != NULL);
  return m_pPort;
}

Glib::ustring LayoutPort::getName()
{
  return m_pPort->getName();
}
