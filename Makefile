CC = g++
override CFLAGS += -c -Wall -O2
CXXFLAGS = $(CFLAGS)
RM = rm
FORCE = -f
LDFLAGS =
SOURCES = trace.cpp vector.cpp
OBJECTS = $(SOURCES:.cpp=.o)
EXECUTABLE = vector

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CXXFLAGS) $(DFLAGS) $< -o $@

dep:
	$(CC) -M *.cpp > .depend

clean:
	$(RM) $(FORCE) $(OBJECTS) $(EXECUTABLE) 

DEBUG:	
	@echo "Debugger mode, try this to trace your code:"
	@echo 'make clean CFLAGS+="-D __TRACE__" all'

help:
	@echo "This is makefile command information:"
	@echo "==============================================="
	@echo "all = compile all the file."
	@echo "DEBUG = the detail of debugger mode."
	@echo "clean = remove executable and object file."
	@echo "==============================================="
	@echo 'Just use "make (FLAG)" then pass argument to make command.'
	@echo ""
