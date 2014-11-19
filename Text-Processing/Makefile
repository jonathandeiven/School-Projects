CXX = g++
CXXFLAGS = -g -Wall -MMD
EXEC = a4q4
OBJECTS = textprocess.o echo.o l337.o lower.o doublecon.o caesar.o main.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
