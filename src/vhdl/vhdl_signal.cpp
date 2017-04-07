/* vim: ts=2:sw=2:expandtab
 *
 * VHDE - The VHDL Diagram Editor
 * Copyright (C) 2009-2010  Maurice van der Pot <griffon26@kfk4ever.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License as
 * published by the Free Software Foundation, either version 3 of the
 * License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#include "vhdl_signal.h"

VHDLSignal::VHDLSignal(Glib::ustring name):
  m_name(name)
{
}

VHDLSignal::~VHDLSignal()
{
  removed.emit(this);
}

void setType(VHDLType type)
{
}

bool VHDLSignal::write(std::ostream &outStream, int indent)
{
  outStream << std::string(indent, ' ') << "signal " << m_name << ": sometype;\n";
  return true;
}
