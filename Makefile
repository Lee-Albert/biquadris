CXX = g++
CXXFLAGS = -std=c++14 -Wall -MMD -Werror=vla
EXEC = biquadris 
OBJECTS = main.o block.o centreblock.o graphicdisplay.o grid.o iblock.o jblock.o lblock.o level.o levelOne.o levelZero.o oblock.o sblock.o subject.o tblock.o textdisplay.o tile.o window.o zblock.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
