EXEC = myWorld

SRC = main.c

CFLAGS = -Wall

LDFLAGS = -lSDL2 -lm

all: $(EXEC)

$(EXEC): $(SRC)
	gcc $(CFLAGS) $^ -o $@ $(LDFLAGS)

clean:
	rm -f $(EXEC)
