#include "EngrmessiApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

InputParameters
EngrmessiApp::validParams()
{
  InputParameters params = MooseApp::validParams();

  return params;
}

EngrmessiApp::EngrmessiApp(InputParameters parameters) : MooseApp(parameters)
{
  EngrmessiApp::registerAll(_factory, _action_factory, _syntax);
}

EngrmessiApp::~EngrmessiApp() {}

void
EngrmessiApp::registerAll(Factory & f, ActionFactory & af, Syntax & syntax)
{
  ModulesApp::registerAll(f, af, syntax);
  Registry::registerObjectsTo(f, {"EngrmessiApp"});
  Registry::registerActionsTo(af, {"EngrmessiApp"});

  /* register custom execute flags, action syntax, etc. here */
}

void
EngrmessiApp::registerApps()
{
  registerApp(EngrmessiApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
EngrmessiApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  EngrmessiApp::registerAll(f, af, s);
}
extern "C" void
EngrmessiApp__registerApps()
{
  EngrmessiApp::registerApps();
}
