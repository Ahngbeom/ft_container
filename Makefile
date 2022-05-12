NAME = a.out

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -g
INCFLAGS = -I ./include

SRSC_DIR = ./
SRCS_FILENAME = main.cpp
SRCS = $(addprefix $(SRSC_DIR), $(SRCS_FILENAME))
OBJS = $(SRCS:.cpp=.o)

all		: $(NAME)

.cpp.o	:
		$(CXX) $(CXXFLAGS) $(INCFLAGS) -c $< -o $@

$(NAME)	: $(OBJS)
		$(CXX) $(CXXFLAGS) $(INCFLAGS) $^ -o $@

clean	:
		$(RM) $(OBJS)

fclean	: clean
		$(RM) $(NAME)

re		: fclean all

.PHONY	: all clean fclean re