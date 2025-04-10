# Nom de l'exécutable
TARGET = create_player

# Fichiers sources
SRC = create_player.c

# Compilation et options
CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -I/usr/include/SDL2 $(shell sdl2-config --cflags)
LDFLAGS = $(shell sdl2-config --libs) -lSDL2_ttf

# Règle par défaut
all: $(TARGET)

# Compilation de l'exécutable
$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

# Nettoyage
clean:
	rm -f $(TARGET) *.o

# Forcer la recompilation
rebuild: clean all
