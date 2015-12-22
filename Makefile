OBJS =		main.o Dottop.o SDLWidget.o util.o CNProc.o

LIBS =		$(shell sdl2-config --libs) -lSDL2_ttf

INCLUDES = 	$(shell sdl2-config --cflags)

TARGET =	dottop

CXXFLAGS =	-O2 -g -Wall -std=c++11 -fmessage-length=0 $(INCLUDES) 

$(TARGET):	$(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) $(LIBS)

all:	$(TARGET)

clean:
	rm -f *.o $(TARGET)
