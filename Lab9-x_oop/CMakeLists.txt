cmake_minimum_required(VERSION 3.30)
project(Lab9_x_oop)

set(CMAKE_CXX_STANDARD 20)

add_executable(Lab9_x_oop main.cpp Bilet.cpp Bilet.h Repository.cpp Repository.h testRepository.cpp testRepository.h
Service.cpp Service.h testService.cpp testService.h UI.cpp UI.h RepositoryFile.cpp RepositoryFile.h bilete.txt
testRepositoryFile.cpp testRepositoryFile.h Exception.h ExceptionBiletInexistent.h ExceptionFonduriInsuficiente.h
ExceptionBancnoteInsuficiente.h ValidatorBilet.h ValidatorDenumire.h)