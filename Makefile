<<<<<<< HEAD
include Make_msys2.inc

CXXFLAGS = -std=c++20
=======

include Make_msys2.inc


CXXFLAGS = -std=c++20 `sdl2-config --cflags`
>>>>>>> ccbf099b7c53c1cc01ec99c47f260cc61c8ca73a
ifdef DEBUG
CXXFLAGS += -g -O0 -Wall -fbounds-check -pedantic -D_GLIBCXX_DEBUG -DDEBUG
else
CXXFLAGS += -O3 -march=native -Wall
endif

<<<<<<< HEAD
=======
LIBS = $(LIB) `sdl2-config --cflags` -lSDL2_ttf -lSDL2_image  `sdl2-config --libs` 
>>>>>>> ccbf099b7c53c1cc01ec99c47f260cc61c8ca73a
ALL= main.exe

default:	help

<<<<<<< HEAD
all:	$(ALL)

clean:
	@rm -fr *.o *.exe

OBJS =   pompe.o condensateur.o circuit.o pressuriseur.o circuitprimaire.o circuitsecondaire.o centrale.o reacteur.o salleDeControle.o

condensateur.o: condensateur.hpp  condensateur.cpp
	$(CXX) $(CXXFLAGS) -c condensateur.cpp -o condensateur.o


circuit.o: circuit.hpp pompe.hpp circuit.cpp
	$(CXX) $(CXXFLAGS) -c circuit.cpp -o circuit.o

reacteur.o: reacteur.hpp  reacteur.cpp
	$(CXX) $(CXXFLAGS) -c reacteur.cpp -o reacteur.o

pompe.o: pompe.hpp pompe.cpp
	$(CXX) $(CXXFLAGS) -c pompe.cpp -o pompe.o

pressuriseur.o: pressuriseur.hpp  pressuriseur.cpp
	$(CXX) $(CXXFLAGS) -c pressuriseur.cpp -o pressuriseur.o


circuitprimaire.o: circuitprimaire.hpp circuit.hpp  pressuriseur.hpp reacteur.hpp circuitsecondaire.hpp centrale.hpp circuitprimaire.cpp
	$(CXX) $(CXXFLAGS) -c circuitprimaire.cpp -o circuitprimaire.o

circuitsecondaire.o: circuitsecondaire.hpp circuit.hpp  condensateur.hpp circuitprimaire.hpp circuitsecondaire.cpp
	$(CXX) $(CXXFLAGS) -c circuitsecondaire.cpp -o circuitsecondaire.o


centrale.o: centrale.hpp circuitprimaire.hpp  circuitsecondaire.hpp reacteur.hpp centrale.cpp
	$(CXX) $(CXXFLAGS) -c centrale.cpp -o centrale.o

salleDeControle.o: salleDeControle.hpp centrale.hpp salleDeControle.cpp
	$(CXX) $(CXXFLAGS) -c salleDeControle.cpp -o salleDeControle.o

main.exe : $(OBJS) main.cpp
	$(CXX) $(CXXFLAGS) $(OBJS) main.cpp -o main.exe


help:
		@echo "Available targets : "
		@echo "    all            : compile the executable"
		@echo "    main.exe     : compile the executable"
		@echo "Add DEBUG=yes to compile in debug"
		@echo "Configuration :"
		@echo "    CXX      :    $(CXX)"
		@echo "    CXXFLAGS :    $(CXXFLAGS)"

show:
		@echo "LIB   : $(LIB)"
		@echo "LIBS  : $(LIBS)"
=======
all: $(ALL)

clean:
	@rm -fr SDL2/*.o *.exe SDL2/*~ 

OBJS = SDL2/sdl2.o SDL2/geometry.o SDL2/window.o SDL2/font.o SDL2/event.o SDL2/texte.o SDL2/image.o SDL2/formated_text.o

SDL2/sdl2.o:	SDL2/sdl2.hpp SDL2/sdl2.cpp
	$(CXX) $(CXXFLAGS) -c SDL2/sdl2.cpp -o SDL2/sdl2.o

SDL2/geometry.o:	SDL2/geometry.hpp SDL2/window.hpp SDL2/geometry.cpp
	$(CXX) $(CXXFLAGS) -c SDL2/geometry.cpp -o SDL2/geometry.o

SDL2/window.o:	SDL2/window.hpp SDL2/window.cpp
	$(CXX) $(CXXFLAGS) -c SDL2/window.cpp -o SDL2/window.o

SDL2/font.o:	SDL2/window.hpp SDL2/font.hpp SDL2/font.cpp
	$(CXX) $(CXXFLAGS) -c SDL2/font.cpp -o SDL2/font.o

SDL2/event.o : SDL2/window.hpp SDL2/event.hpp SDL2/event.cpp
	$(CXX) $(CXXFLAGS) -c SDL2/event.cpp -o SDL2/event.o

SDL2/texte.o : SDL2/window.hpp SDL2/font.hpp SDL2/texte.hpp SDL2/texte.cpp
	$(CXX) $(CXXFLAGS) -c SDL2/texte.cpp -o SDL2/texte.o

SDL2/formated_texte.o : SDL2/window.hpp SDL2/font.hpp SDL2/formated_text.hpp SDL2/formated_text.cpp
	$(CXX) $(CXXFLAGS) -c SDL2/formated_text.cpp -o SDL2/formated_text.o


SDL2/image.o : SDL2/window.hpp SDL2/image.hpp SDL2/image.cpp
	$(CXX) $(CXXFLAGS) -c SDL2/image.cpp -o SDL2/image.o

#sdl2_documentation.exe : $(OBJS) sdl2_documentation.cpp
#	$(CXX) $(CXXFLAGS) $(OBJS) sdl2_documentation.cpp -o sdl2_documentation.exe $(LIBS)

main.exe : $(OBJS) main.cpp
	$(CXX) $(CXXFLAGS) $(OBJS) main.cpp -o main.exe $(LIBS)


help:
	@echo "Available targets : "
	@echo "    all            : compile the executable"
	@echo "    main.exe     : compile the executable"
	@echo "Add DEBUG=yes to compile in debug"
	@echo "Configuration :"
	@echo "    CXX      :    $(CXX)"
	@echo "    CXXFLAGS :    $(CXXFLAGS)"

show:
	@echo "LIB   : $(LIB)"
	@echo "LIBS  : $(LIBS)"

%.html: %.md
	pandoc -s --toc $< --css=./github-pandoc.css -o $@
>>>>>>> ccbf099b7c53c1cc01ec99c47f260cc61c8ca73a
