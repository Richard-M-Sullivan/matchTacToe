#pragma once

#include <string>
#include <hexapawnfactory.h>
#include <tictactoefactory.h>

namespace AbstractGameFactory
{
    GameFactory* createGameFactory(std::string);
}
