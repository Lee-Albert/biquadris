CXX = g++
CXXFLAGS = -std=c++14 -Wall -MMD -Werror=vla
EXEC = biquadris 
# all blocks are missing from compiling at the moment
# levelzero and levelone isnt being compiled as well cuz its broken
# OBJECTS = main.o subject.o tile.o graphicdisplay.o grid.o level.o textdisplay.o window.o block.o
OBJECTS = main.o subject.o tile.o graphicdisplay.o grid.o level.o textdisplay.o window.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
