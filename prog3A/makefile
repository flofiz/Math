
CFLAGS=$(HDR_PATHS) -Wno-deprecated

CC=g++
#CC=gcc

ok : projetMathbernstein 

.cc.o:
	$(CC) -c -O3 $(CFLAGS) $<

OBJECTS_main = projetMathbernstein.o

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
