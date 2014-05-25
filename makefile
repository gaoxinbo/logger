bin=main
SHARED_OBJ=liblogger.so
OBJECTS=Appender.o Layout.o ConsoleAppender.o FileAppender.o Logger.o

CC=g++
OPTIMING=-O2
CXX_FLAGS=-g -Wall -Werror -Wno-unused-variable ${OPTIMING} 
LD_FLAGS=-g

all:liblogger.so ${bin}


.cc.o:
	${CC} -c $^ ${CXX_FLAGS} -o $@

${SHARED_OBJ}:${OBJECTS}
	${CC} $^ -o $@ -fPIC -shared ${LD_FLAGS}

${bin}:${SHARED_OBJ} main.o
	${CC} $^ -o $@ ${LD_FLAGS}

.PHONY:clean

clean:
	rm -v *.o
	rm -v ${bin}
	rm -v ${SHARED_OBJ}

