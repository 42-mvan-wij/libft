# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mvan-wij <mvan-wij@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2020/10/27 13:16:39 by mvan-wij      #+#    #+#                  #
#    Updated: 2021/09/06 14:20:04 by mvan-wij      ########   odam.nl          #
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

include			sources.mk

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

