.PHONY: clean all

all: ll1parser

ll1parser: ll1parser.o lexer.o
	clang++ -o ll1parser ll1parser.o lexer.o

ll1parser.o: ${GRAMMAR}.hpp ll1parser.cpp tokens_${GRAMMAR}.h
	clang++ -DTOKENS=\"tokens_${GRAMMAR}.h\" -DHPP=\"${GRAMMAR}.hpp\" -DSYMBTBL=\"symbtbl_${GRAMMAR}.h\" -c ll1parser.cpp

lexer.o: lexer.cpp tokens_${GRAMMAR}.h
	clang++ -c lexer.cpp

lexer.cpp: lexer_${GRAMMAR}.l
	flex++ -o lexer.cpp lexer_${GRAMMAR}.l

${GRAMMAR}.hpp: ${GRAMMAR}.ll1
	python3 first_and_follow.py ${GRAMMAR}.ll1
	python3 makell1parser.py ${GRAMMAR}

clean:
	rm -f *~ *.o ll1parser lexer.cpp tokens_${GRAMMAR}.h ${GRAMMAR}.hpp *.pickle
