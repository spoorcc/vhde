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

#include "vhdl_entity.h"

VHDLEntity::VHDLEntity(Glib::ustring name):
  VHDLInterface(name)
{

}

/*

  entity INV is
    port (A: in STD_LOGIC;
    F: out STD_LOGIC);
  end INV;

*/
bool VHDLEntity::write(FILE *pFile, int indent)
{
  std::list<VHDLGeneric *>::iterator git;
  std::list<VHDLPort *>::iterator pit;

  fprintf(pFile, "%*sentity %s is\n", indent, "", m_name.c_str());

  fprintf(pFile, "%*sport (\n", indent + 2, "");
  for(pit = m_ports.begin(); pit != m_ports.end(); pit++)
  {
    (*pit)->write(pFile, indent + 4);
  }
  fprintf(pFile, "%*s)\n", indent + 2, "");

  fprintf(pFile, "%*send %s\n\n", indent, "", m_name.c_str());

  return true;
}