# Définition des fichiers sources et objets
SRCS=$(wildcard src/*.c)
OBJS=$(SRCS:.c=.o)

# Liste des fichiers .c dans players/
PLAYER_SRCS=$(wildcard players/*.c)
PLAYER_LIBS=$(PLAYER_SRCS:.c=.so)  # Création de la liste des .so

# Ajout de render.c
RENDER_SRCS=render.c
RENDER_LIBS=render.so

# Options de compilation
CFLAGS= -Wall -g2 -fPIC -I src/  # Ajout de src/ pour trouver actions.h
LDFLAGS= -ldl -lSDL2 -lSDL2_ttf $(PLAYER_LIBS) $(RENDER_LIBS)  # Lier toutes les bibliothèques .so
EXE=splashmem

# Compilation de l'exécutable principal
all: $(EXE)

$(EXE): $(OBJS) $(PLAYER_LIBS) $(RENDER_LIBS)
	@echo "Création de l'exécutable $(EXE)"
	gcc $(OBJS) $(LDFLAGS) -o $(EXE)

# Compilation de chaque fichier .c en bibliothèque partagée .so
players/%.so: players/%.c
	@echo "Création de la bibliothèque $@"
	gcc -shared -o $@ -fPIC $(CFLAGS) $<  # Ajout de $(CFLAGS) pour inclure src/

# Règle pour compiler render.c en .so
$(RENDER_LIBS): $(RENDER_SRCS)
	@echo "Création de la bibliothèque $@"
	gcc -shared -o $@ -fPIC $(CFLAGS) $<

# Règle pour nettoyer les fichiers générés
clean:
	rm -f $(OBJS) $(PLAYER_LIBS) $(RENDER_LIBS) $(EXE)
