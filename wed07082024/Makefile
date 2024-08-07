# Variables
CC = gcc
CFLAGS = -Wall -fPIC
LDFLAGS = -shared
LIB_NAME = share
LIB_SRC = src/share.c
LIB_OBJ = $(LIB_SRC:.c=.o)
EXEC_NAME = main
EXEC_SRC = src/main.c
EXEC_OBJ = $(EXEC_SRC:.c=.o)
LIB_PATH = ./lib

# Regla por defecto.
all: $(EXEC_NAME)

# Creación del ejecutable principal.
$(EXEC_NAME): $(EXEC_OBJ) $(LIB_PATH)/lib$(LIB_NAME).so
	$(CC) -o $@ $(EXEC_OBJ) -L$(LIB_PATH) -l$(LIB_NAME)

# Creación de la biblioteca compartida.
$(LIB_PATH)/lib$(LIB_NAME).so: $(LIB_OBJ)
	mkdir -p $(LIB_PATH)
	$(CC) $(LDFLAGS) -o $@ $(LIB_OBJ)

# Compilación del archivo "objeto" de la biblioteca compartida.
%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Compilación del archivo "objeto" del ejecutable.
%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Limpieza de los archivos generados.
clean:
	rm -f $(LIB_PATH)/*.so $(EXEC_NAME) $(EXEC_OBJ) $(LIB_OBJ)

.PHONY: all clean