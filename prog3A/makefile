LIB_PATHS= -L/usr/X11R6/lib -L/usr/lib
HDR_PATHS= -I/usr/X11R6/include
LIBS= -lm -L/usr/X11/lib  #-lXmu -lXi -lX11 -g-std=c++98

CFLAGS=$(HDR_PATHS) -Wno-deprecated

CC=g++
#CC=gcc

ok : projetMathbernstein 

.cc.o:
	$(CC) -c -O3 $(CFLAGS) $<

OBJECTS_main = projetMathbernstein.o Polynome.o Fonctions.o

projetMathbernstein:  $(OBJECTS_main)
	$(CC) $(OBJECTS_main) -o projetMathbernstein $(LIB_PATHS) $(LIBS)

	
indenter :
	for i in *.h *.cpp do sed -i~ -f sed.sed  $i done
	indent  *.h *.cpp

clean :
	rm -fr *.o
#	touch *.cpp *.h

delete :
	rm -f *.h~
	rm -f *.cc~
	rm -f *.txt
