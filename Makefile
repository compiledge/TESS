CC = gcc
CFLAGS = -Wall
LDFLAGS = -lm
OBJFILES = utils.o main.o
TARGET = tess

all: $(TARGET)

$(TARGET):
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJFILES)

debug:
	$(CC) -g $(CFLAGS) -o $(TARGET) $(OBJFILES)

clean:
	rm -f $(OBJFILES) $(TARGET)
