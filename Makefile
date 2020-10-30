# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mvan-wij <mvan-wij@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2020/10/27 13:16:39 by mvan-wij      #+#    #+#                  #
#    Updated: 2020/10/30 21:04:00 by mvan-wij      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME			= libft.a

BONUSFILES		= ft_lst*
MOREBONUS		= *_bonus

CC				= gcc
CFLAGS			= -Wall -Wextra -Werror

SRCEXT			= c
SRCDIR			= .
HEADERDIR		= .
OBJEXT			= o
BUILDDIR		= obj
BINDIR			= bin

SOURCES			= $(shell find '$(SRCDIR)/' -type f \
					-name '*.$(SRCEXT)' -a \
					-not -name '$(BONUSFILES).$(SRCEXT)' -a \
					-not -name '$(MOREBONUS).$(SRCEXT)')
BONUSSOURCES	= $(shell find '$(SRCDIR)/' -type f \
					-name '$(BONUSFILES).$(SRCEXT)' -o \
					-name '$(MOREBONUS).$(SRCEXT)')
OBJECTS			= $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,\
				  $(SOURCES:.$(SRCEXT)=.$(OBJEXT)))
BONUSOBJECTS	= $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,\
				  $(BONUSSOURCES:.$(SRCEXT)=.$(OBJEXT)))

all: $(NAME)

$(NAME): $(BUILDDIR)/ $(OBJECTS)
	ar -cq $(NAME) $(OBJECTS)

bonus: $(BUILDDIR)/ $(OBJECTS) $(BONUSOBJECTS)
	ar -cq $(NAME) $(OBJECTS) $(BONUSOBJECTS)

so $(NAME:a=so): $(BUILDDIR)/ $(OBJECTS)
	$(CC) $(CFLAGS) -shared $(BUILDDIR)/*.$(OBJEXT) -o $(NAME:a=so)

clean:
	/bin/rm -rf $(BUILDDIR)/

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

$(BUILDDIR)/:
	mkdir -p $(BUILDDIR)

$(BINDIR)/:
	mkdir -p $(BINDIR)

$(BUILDDIR)/%.$(OBJEXT): $(SRCDIR)/%.$(SRCEXT)
	$(CC) $(CFLAGS) -I$(HEADERDIR) -c $< -o $@

.PHONY: all clean fclean re so bonus
