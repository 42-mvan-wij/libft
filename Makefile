# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mvan-wij <mvan-wij@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2020/10/27 13:16:39 by mvan-wij      #+#    #+#                  #
#    Updated: 2021/07/27 16:06:31 by mvan-wij      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME			= libft.a

CC				= gcc
CFLAGS			= -Wall -Wextra -Werror
ifdef DEBUG
CFLAGS 			+= -g
endif
LIBS			=
HEADERS			= libft.h
INCLUDES		= $(addprefix -I,$(dir $(HEADERS)))

SOURCES			= src/arr/ft_array.c \
\
src/char/ft_isalnum.c src/char/ft_isalpha.c src/char/ft_isascii.c src/char/ft_iscntrl.c src/char/ft_isdigit.c src/char/ft_isgraph.c src/char/ft_islower.c src/char/ft_isprint.c src/char/ft_ispunct.c src/char/ft_isspace.c src/char/ft_isupper.c src/char/ft_isxdigit.c src/char/ft_tolower.c src/char/ft_toupper.c \
\
src/gnl/get_next_line.c src/gnl/get_next_line_utils.c \
\
src/io/ft_putchar_fd.c src/io/ft_putendl_fd.c src/io/ft_putnbr_base_fd.c src/io/ft_putnbr_fd.c src/io/ft_putstr_fd.c \
\
src/lst/ft_lstadd_back.c src/lst/ft_lstadd_front.c src/lst/ft_lstclear.c src/lst/ft_lstdelone.c src/lst/ft_lstinsert.c src/lst/ft_lstiter.c src/lst/ft_lstlast.c src/lst/ft_lstmap.c src/lst/ft_lstnew.c src/lst/ft_lstsize.c \
\
src/mem/ft_bzero.c src/mem/ft_calloc.c src/mem/ft_malloc.c src/mem/ft_memccpy.c src/mem/ft_memchr.c src/mem/ft_memcmp.c src/mem/ft_memcpy.c src/mem/ft_memmove.c src/mem/ft_memrchr.c src/mem/ft_memset.c \
\
src/nbr/ft_atod.c src/nbr/ft_atoi.c src/nbr/ft_itoa_base.c src/nbr/ft_itoa_basei.c src/nbr/ft_itoa.c src/nbr/ft_nbrlen_u.c src/nbr/ft_nbrlen.c src/nbr/ft_utoa_base.c src/nbr/ft_utoa_basei.c src/nbr/ft_utoa.c \
\
src/str/ft_split.c src/str/ft_str_filter.c src/str/ft_strchr.c src/str/ft_strdup.c src/str/ft_strjoin.c src/str/ft_strlcat.c src/str/ft_strlcpy.c src/str/ft_strlen.c src/str/ft_strmapi.c src/str/ft_strncmp.c src/str/ft_strnstr.c src/str/ft_strrchr.c src/str/ft_strtolower.c src/str/ft_strtoupper.c src/str/ft_strtrim.c src/str/ft_substr.c \
\
src/tree/ft_treenew.c

ifdef BONUS
	SOURCES		+=
	CFLAGS		+=
	LIBS		+=
endif

SRCDIR			= src
OBJDIR			= obj

OBJECTS			= $(patsubst $(SRCDIR)/%,$(OBJDIR)/%,$(SOURCES:c=o))

.PHONY: all clean fclean re so bonus debug sources

all: $(NAME)

$(NAME): $(OBJECTS)
	ar -cr $(NAME) $(OBJECTS)

bonus:
	$(MAKE) BONUS=1

debug:
	$(MAKE) DEBUG=1

$(OBJDIR)/%.o: $(SRCDIR)/%.c $(HEADERS)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -rf $(OBJDIR)
	rm -f $(NAME)

re: fclean all

# Can be used as follows:
# $(LIBFT): $(addprefix $(dir $(LIBFT)), $(shell $(MAKE) -s -C $(dir $(LIBFT)) sources))
sources:
	@echo $(SOURCES)

