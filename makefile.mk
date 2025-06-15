# === 0. Global options =======================================================
# Disable built-ins for clarity; print commands as they run
MAKEFLAGS += --no-builtin-rules --no-builtin-variables
.SUFFIXES:                 # wipe old suffix rules
.DEFAULT_GOAL := all

# === 1. Variables ============================================================
APP      := demo                             # simple (=default goal’s basename)
SRC_DIR  := src
OBJ_DIR  := build

# Recursive (=) vs. simple (:=) assignment demo
CC       =  gcc                              # recursive: expands when used
CFLAGS  := -Wall -std=c11                    # simple: frozen now
DEBUG   ?=                                   # may be set by CLI: DEBUG=1 make

ifdef DEBUG                                   # conditional parts
  CFLAGS += -O0 -g
else
  CFLAGS += -O2
endif

# Get list of .c files with wildcard; turn into .o path list
SRCS  := $(wildcard $(SRC_DIR)/*.c)
OBJS  := $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))

# === 2. Phony meta-targets ===================================================
.PHONY: all clean print

all: $(APP)                                  # default build

clean:                                        # phony target
	@$(RM) -r $(OBJ_DIR) $(APP)

print:                                        # helper: show variables
	@echo "SRCS=$(SRCS)"; echo "OBJS=$(OBJS)"; echo "CFLAGS=$(CFLAGS)"

# === 3. Pattern & static pattern rules =======================================
# Build the final executable from objects
$(APP): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

# Rule: build/xyz.o from src/xyz.c  + order-only prerequisite =build directory
# $@ = target     $< = first prerequisite     $* = stem
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -MMD -MF $(@:%.o=%.d) -c $< -o $@

# Make sure OBJ_DIR exists but don't rebuild objects if its timestamp changes
$(OBJ_DIR):
	@mkdir -p $@

# === 4. Auto-generated dependency include ====================================
# Every %.o produced a %.d file above; pull them in if they exist
-include $(OBJS:%.o=%.d)

# === 5. Conditional install recipe (uses findstring) =========================
# If DESTDIR contains "usr", treat as system install; else local ./bin
install: $(APP)
ifneq ($(findstring usr,$(DESTDIR)),)
	install -m 755 -d $(DESTDIR)/bin
	install -m 755 $(APP) $(DESTDIR)/bin/$(APP)
else
	@mkdir -p bin
	cp $(APP) bin/
endif


