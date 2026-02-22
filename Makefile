CC = gcc
LDFLAGS =
TARGET = main
HEADERS = circular_list.h
SOURCES = main.c circular_list.c
DEPENDENCIES = $(HEADERS) $(SOURCES)

all: $(TARGET)

$(TARGET): $(DEPENDENCIES)
	$(CC) $(SOURCES) -o $(TARGET)
	
run: $(TARGET)
	./$(TARGET)
	
clean:
	rm -f $(TARGET)