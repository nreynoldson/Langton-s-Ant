###############################################################################
# Project name: Project 1 - Langton's Ant Simulator - Makefile
# Name: Nicole Reynoldson
# Date: 7/7/19
# #############################################################################

CXX = g++
CXXFLAGS = -g -std=c++0x -Wall -pedantic-errors
OBJS = $(SRCS:.cpp=.o)
#OBJS = main.o menus.o getInput.o board.o ant.o randLoc.o
SRCS = main.cpp menus.cpp getInput.cpp board.cpp ant.cpp randLoc.cpp
HEADERS = ant.hpp board.hpp getInput.hpp menus.hpp randLoc.hpp

project1: $(OBJS)
	$(CXX) $(OBJS) -o project1

$(OBJS): $(SRCS) $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $(@:.o=.cpp)

clean:
	rm $(OBJS) project1

