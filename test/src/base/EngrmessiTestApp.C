//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "EngrmessiTestApp.h"
#include "EngrmessiApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"
#include "ModulesApp.h"

InputParameters
EngrmessiTestApp::validParams()
{
  InputParameters params = EngrmessiApp::validParams();
  return params;
}

EngrmessiTestApp::EngrmessiTestApp(InputParameters parameters) : MooseApp(parameters)
{
  EngrmessiTestApp::registerAll(
      _factory, _action_factory, _syntax, getParam<bool>("allow_test_objects"));
}

EngrmessiTestApp::~EngrmessiTestApp() {}

void
EngrmessiTestApp::registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs)
{
  EngrmessiApp::registerAll(f, af, s);
  if (use_test_objs)
  {
    Registry::registerObjectsTo(f, {"EngrmessiTestApp"});
    Registry::registerActionsTo(af, {"EngrmessiTestApp"});
  }
}

void
EngrmessiTestApp::registerApps()
{
  registerApp(EngrmessiApp);
  registerApp(EngrmessiTestApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
EngrmessiTestApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  EngrmessiTestApp::registerAll(f, af, s);
}
extern "C" void
EngrmessiTestApp__registerApps()
{
  EngrmessiTestApp::registerApps();
}
