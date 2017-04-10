CXX = g++
CXXFLAGS = -c
LIBS = -lfl
                                  
all: bison.tab.h bison.y.o yy.lex.c bison

bison: yy.lex.o bison.y.o
	$(CXX) -o $@ $^ $(LIBS) -lm

bison.tab.h : bison.y
	bison -d -v -t $^
	mv bison.tab.h bison.h
	mv bison.tab.c bison.y.c

bison.y.o: bison.y.c
	$(CXX) $(CXXFLAGS) -Wno-deprecated $<

yy.lex.o: yy.lex.c
	$(CXX) $(CXXFLAGS) $<

yy.lex.c: input.lex
	flex -o $@ $<

clean:
	rm -f yy.lex.c bison.y.c bison.h *.o *.output bison *.exe *.il

#CXX = gcc
#CXXFLAGS = -g
#LIBS = -lfl

#all: bison

#bison: input.lex.o bison.y.o
#	$(CXX) $^ $(LIBS) -lm $@

#bison.y.o: bison.y
#	$(CXX) -c $<

#input.yy.c: input.lex
#	flex -o input.lex

#clean:
#	rm -f lex.yy.c bison.y.c *.o a.out
