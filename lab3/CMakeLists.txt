cmake_minimum_required(VERSION 3.17)
project(lab3)

set(CMAKE_CXX_STANDARD 11)

add_executable(lab3 main.cpp Model.cpp Model.h View.cpp View.h
        BotPlayer.cpp BotPlayer.h ConsolePlayer.h ConsolePlayer.cpp
        Controller.h Controller.cpp Game.cpp Game.h Player.h
        GameObserver.h)
