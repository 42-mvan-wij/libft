# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mvan-wij <mvan-wij@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2020/10/27 13:16:39 by mvan-wij      #+#    #+#                  #
#    Updated: 2022/03/25 14:10:56 by mvan-wij      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

################################################################################

include utils.mk
include sources.mk

################################################################################

PROJECT		:= libft
NAME		:= libft.a
NAME_BONUS	:= libft.a

LIBFT		:=
MINILIBX	:=

CC			:= cc
CFLAGS		+= -Wall -Wextra -Werror $(if $(DEBUG), -g3) $(if $(SANITIZE), -fsanitize=address -g3)

################################################################################

USER_LIBS +=
SYSTEM_LIBS +=
FRAMEWORKS +=
HEADERS :=		\
	libft.h
# SOURCES :=

################################################################################

ifdef BONUS
NAME	:= $(NAME_BONUS)
HEADERS +=
SOURCES	+=
CFLAGS	+= -DBONUS
endif

################################################################################

OBJDIR := obj
OBJECTS := $(addprefix $(OBJDIR)/, $(SOURCES:c=o))
INCLUDE_FLAGS += $(addprefix -I, $(sort $(dir $(HEADERS))))
LIB_FLAGS += $(addprefix -L, $(sort $(dir $(USER_LIBS)))) $(addprefix -l, $(SYSTEM_LIBS) $(patsubst lib%,%,$(basename $(notdir $(USER_LIBS))))) $(addprefix -framework , $(FRAMEWORKS))

export CFLAGS := $(sort $(CFLAGS))
export LIB_FLAGS := $(LIB_FLAGS)

DATA_FILE := .make_data.txt
MAKE_DATA := $(CFLAGS) $(LIB_FLAGS) $(INCLUDE_FLAGS) $(sort $(OBJECTS))
ifneq ($(shell echo $(MAKE_DATA)), $(shell cat "$(DATA_FILE)" 2> /dev/null))
PRE_RULES := clean
endif

################################################################################

all: $(PRE_RULES) $(NAME)

$(NAME): $(USER_LIBS) $(OBJECTS)
	@$(call print_prefix,"$(PROJECT)","make")
	ar -cr $(NAME) $(OBJECTS)
	@$(call print_prefix,"$(PROJECT)","make")
	@printf "$(BLUE_FG)$(NAME)$(RESET_COLOR) created\n"


$(OBJDIR)/%.o: %.c $(HEADERS)
	@mkdir -p $(@D)
	@$(call print_prefix,"$(PROJECT)","make")
	@$(call exec_no_nl,$(CC) $(CFLAGS) $(INCLUDE_FLAGS) $(INCLUDES) -c $< -o $@)


debug:
	@$(MAKE) DEBUG=1

clean:
	@$(call print_prefix,"$(PROJECT)","$@")
	rm -rf $(OBJDIR)

fclean: clean
	@$(call print_prefix,"$(PROJECT)","$@")
	rm -f $(NAME)
	@$(call print_prefix,"$(PROJECT)","$@")
	rm -f $(DATA_FILE)

re: fclean all

# Can be used as follows:
# $(LIBFT): $(addprefix $(dir $(LIBFT)), $(shell $(MAKE) -s -C $(dir $(LIBFT)) sources))
sources:
	@echo $(SOURCES)

.PHONY: all debug clean fclean re sources

################################################################################
