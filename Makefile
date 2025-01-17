CXX = g++
CXXFLAGS = -std=c++14 -Wall -MMD -Werror=vla -L/usr/X11R6/lib
EXEC = biquadris 
# all blocks are missing from compiling at the moment
# levelzero and levelone isnt being compiled as well cuz its broken
# OBJECTS = main.o subject.o tile.o graphicdisplay.o grid.o level.o textdisplay.o window.o
OBJECTS = main.o window.o graphicsdisplay.o subject.o tile.o grid.o textdisplay.o level.o levelZero.o levelOne.o levelTwo.o levelThree.o levelFour.o block.o iblock.o jblock.o lblock.o oblock.o sblock.o tblock.o zblock.o centreblock.o
# OBJECTS = main.o subject.o tile.o graphicdisplay.o grid.o level.o textdisplay.o window.o block.o iblock.o jblock.o lblock.o oblock.o sblock.o tblock.o zblock.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -lX11 -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
