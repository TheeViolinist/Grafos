#detecta se o sistema é de 32 ou 64 bits
BITS_OPTION = -m64


#### define o compilador
CPPC = g++
#############################

#### opcoes de compilacao e includes
CCOPT = $(BITS_OPTION) -O3 -fPIC -fexceptions -DNDEBUG -DIL_STD -std=c++0x
#CONCERTINCDIR = $(CONCERTDIR)/include
#CPLEXINCDIR   = $(CPLEXDIR)/include #Include das classes que vamos utilizar
#CCFLAGS = $(CCOPT) -I$(CPLEXINCDIR) -I$(CONCERTINCDIR) -I./include #-I Serve para o compilador identificar que isso é um include de arquivos
#############################

#### flags do linker
CCLNFLAGS = -lm -lpthread -ldl -O3
#############################

#### diretorios com os source files e com os objs files
SRCDIR = src
#############################

#### lista de todos os srcs
#WildCard irá listar todos os arquivos com *.cpp
SRCS = $(wildcard $(SRCDIR)/*.cpp)
#############################

#### regra principal, gera o executavel
$/main: $(SRCS) 
	@echo  "\033[31m \nLinking all objects files: \033[0m"
	$(CPPC) $(BITS_OPTION) $(SRCS) -o $@ $(CCLNFLAGS) $(CCFLAGS)
############################

