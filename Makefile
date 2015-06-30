OBJS =		glogin.o

LIBS =		-lSDLmain -Wl,-framework,AppKit -lSDL -Wl,-framework,Cocoa

LIBDIRS =	-L/opt/local/lib

INCLUDES = 	-I/opt/local/include/SDL -D_GNU_SOURCE=1 -D_THREAD_SAFE

TARGET =	glogin

CXXFLAGS =	-O2 -g -Wall -fmessage-length=0 $(INCLUDES) 

$(TARGET):	$(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) $(LIBDIRS) $(LIBS)

all:	$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)
