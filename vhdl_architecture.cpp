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
 * but sitHOUT ANY WARRANTY; sithout even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along sith Foobar.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#include "vhdl_architecture.h"

VHDLArchitecture::VHDLArchitecture(Glib::ustring name):
  m_name(name),
  m_pEntity(NULL)
{
}

void VHDLArchitecture::setEntity(VHDLEntity *pEntity)
{
  g_assert(m_pEntity == NULL);
  m_pEntity = pEntity;
}

void VHDLArchitecture::addComponent(VHDLComponent *pComponent)
{
  m_components.push_back(pComponent);
}

VHDLComponent *VHDLArchitecture::findComponentByName(Glib::ustring name)
{
  std::list<VHDLComponent *>::iterator it;

  for(it = m_components.begin(); it != m_components.end(); it++)
  {
    if((*it)->getName() == name)
    {
      return *it;
    }
  }
  return NULL;
}

void VHDLArchitecture::addSignal(VHDLSignal *pSignal)
{
  m_signals.push_back(pSignal);
}

void VHDLArchitecture::removeSignal(VHDLSignal *pSignal)
{
  std::list<VHDLInstance *>::iterator it;

  for(it = m_instances.begin(); it != m_instances.end(); it++)
  {
    (*it)->disassociateSignal(pSignal);
  }

  m_signals.remove(pSignal);
}

VHDLSignal *VHDLArchitecture::findSignalByName(Glib::ustring name)
{
  std::list<VHDLSignal *>::iterator it;

  for(it = m_signals.begin(); it != m_signals.end(); it++)
  {
    if((*it)->getName() == name)
    {
      return *it;
    }
  }
  return NULL;
}

void VHDLArchitecture::addInstance(VHDLInstance *pInstance)
{
  m_instances.push_back(pInstance);
}

VHDLInstance *VHDLArchitecture::findInstanceByName(Glib::ustring name)
{
  std::list<VHDLInstance *>::iterator it;

  for(it = m_instances.begin(); it != m_instances.end(); it++)
  {
    if((*it)->getName() == name)
    {
      return *it;
    }
  }
  return NULL;
}

bool VHDLArchitecture::write(FILE *pFile, int indent)
{
  std::list<VHDLSignal *>::iterator sit;
  std::list<VHDLInstance *>::iterator iit;

  m_pEntity->write(pFile, indent);

  fprintf(pFile, "%*sarchitecture %s of %s is\n\n", indent, "", m_name.c_str(), m_pEntity->getName().c_str());

  for(iit = m_instances.begin(); iit != m_instances.end(); iit++)
  {
    (*iit)->getComponent()->write(pFile, indent);
  }

  for(sit = m_signals.begin(); sit != m_signals.end(); sit++)
  {
    (*sit)->write(pFile, indent);
  }
  fprintf(pFile, "\n");

  fprintf(pFile, "%*sbegin\n", indent, "");
  for(iit = m_instances.begin(); iit != m_instances.end(); iit++)
  {
    (*iit)->write(pFile, indent + 2);
  }
  fprintf(pFile, "%*send;\n\n", indent, "");

  return true;
}

