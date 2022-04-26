CC=clang
CFLAGS=`pkg-config --cflags raylib` -std=c99
LIBS=`pkg-config --libs raylib`

MKDIR=mkdir -p
RMDIR=rm -rf

SRC_DIR=src
OUT_DIR=build

OBJS=$(OUT_DIR)/main.o
OBJS=$(OUT_DIR)/player.o \
	 $(OUT_DIR)/main.o

all: $(OUT_DIR) $(OBJS)
 $(CC) $(OBJS) -o $(OUT_DIR)/main $(LIBS)

run: all
 $(OUT_DIR)/main

clean:
 $(RMDIR) $(OUT_DIR)

.PHONY: clean

$(OUT_DIR)/%.o: $(SRC_DIR)/%.c
 $(CC) -c $< -o $@ $(CFLAGS)

$(OUT_DIR):
 $(MKDIR) $(OUT_DIR)