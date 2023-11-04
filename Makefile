# Output filename NAME
NAME := libft.a

# Compiler & flags
CC := cc
CFLAGS := -Wall -Wextra -Werror

# Source files
SOURCES := $(filter-out %_bonus.c, $(wildcard ft_*.c))
BONUS_SOURCES := $(wildcard ft_*_bonus.c)

# Object files
OBJECTS := $(SOURCES:.c=.o)
BONUS_OBJECTS := $(BONUS_SOURCES:.c=.o)

.PHONY = all bonus clean fclean re

all: $(NAME)

# Link object files to create an archive file for library with
# Linux command: ar crs
# where c = create, r = replace, s = index (as ranlib)
$(NAME): $(OBJECTS)
	ar crs $@ $^

# Compile source files into object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

bonus:
	@$(MAKE) OBJECTS="$(OBJECTS) $(BONUS_OBJECTS)" --no-print-directory

# Delete object files
clean:
	rm -f *.o

# Delete object files and program file
fclean: clean
	rm -f $(NAME)

# Rebuild
re: fclean $(NAME)
