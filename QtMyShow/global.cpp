#include "global.h"

Global *Global::Instance()
{
	static Global inst;
	return &inst;
}

Global::Global()
{

}

Global::~Global()
{

}