#
# Makefile template for CSE 30 -- PA3
#

HEADERS		= pa3.h pa3_strings.h

C_SRCS 		= appendAnagram.c createHashKey.c createAnagramHeader.c\
		  initTable.c main.c printAnagrams.c searchForAnagrams.c\
		  pa3_globals.c

ASM_SRCS	= charCompare.s printUsage.s stripNewLine.s

C_OBJS		= $(C_SRCS:.c=.o)

ASM_OBJS	= $(ASM_SRCS:.c=.o)

OBJS		= ${C_OBJS} ${ASM_OBJS}

EXE		= anagrams

TEST_SRCS	= testappendAnagram.c testcharCompare.c testcreateHashKey.c\
		  testcreateAnagramHeader.c teststripNewLine.c

TEST_EXE	= $(TEST_SRCS:.c=)

#
# You should not need to change anything below this line
#

#
# Relevant man pages:
# man gcc
# man as
# man lint
#

GCC		= gcc
ASM		= $(GCC)
LINT		= lint

GCC_FLAGS	= -c -g3 -Wall -D__EXTENSIONS__ -std=c99
LINT_FLAGS1	= -c -err=warn
LINT_FLAGS2	= -u -err=warn
ASM_FLAGS	= -c -g3
LD_FLAGS	= -g3 -Wall

#
# Standard rules
#

.s.o:
	@echo "Assembling each assembly source file separately ..."
	$(ASM) $(ASM_FLAGS) $<
	@echo ""

.c.o:
	@echo "Linting each C source file separately ..."
	$(LINT) $(LINT_FLAGS1) $<
	@echo ""
	@echo "Compiling each C source file separately ..."
	$(GCC) $(GCC_FLAGS) $<
	@echo ""

#
# Simply have our project target be a single default "anagrams" executable.
#
$(EXE):	$(OBJS)
	@echo "2nd phase lint on all C source files ..."
	$(LINT) $(LINT_FLAGS2) *.ln
	@echo ""
	@echo "Linking all object modules ..."
	$(GCC) -o $(EXE) $(LD_FLAGS) $(OBJS)
	@echo "Done."

${C_OBJS}:      ${HEADERS}

clean:
	@echo "Cleaning up project directory ..."
	rm -f *.o $(EXE) *.ln core $(TEST_EXE) 
	@echo ""
	@echo "Clean."

new:
	make --no-print-directory clean
	make --no-print-directory

# --- Test for appendAnagram ---
testappendAnagram: appendAnagram.c testappendAnagram.c pa3.h test.h 
	@echo "Compiling testappendAnagram"
	gcc -g3 -o testappendAnagram appendAnagram.c testappendAnagram.c test.h
	@echo "Done."

runtestappendAnagram: testappendAnagram 
	@echo "Running testappendAnagram" 
	@./testappendAnagram

# --- Test for charCompare ---
testcharCompare: charCompare.s testcharCompare.c pa3.h test.h 
	@echo "Compiling testcharCompare"
	gcc -g3 -o testcharCompare charCompare.s testcharCompare.c test.h
	@echo "Done."

runtestcharCompare: testcharCompare 
	@echo "Running testcharCompare" 
	@./testcharCompare

# --- Test for createAnagramHeader ---
testcreateAnagramHeader: createAnagramHeader.c testcreateAnagramHeader.c pa3.h\
			 test.h 
	@echo "Compiling testcreateAnagramHeader"
	gcc -g3 -o testcreateAnagramHeader createAnagramHeader.c\
		   testcreateAnagramHeader.c test.h
	@echo "Done."

runtestcreateAnagramHeader: testcreateAnagramHeader 
	@echo "Running testcreateAnagramHeader" 
	@./testcreateAnagramHeader

# --- Test for createHashKey ---
testcreateHashKey: createHashKey.c testcreateHashKey.c charCompare.s pa3.h\
		   test.h 
	@echo "Compiling testcreateHashKey"
	gcc -g3 -o testcreateHashKey createHashKey.c testcreateHashKey.c\
		   charCompare.s test.h
	@echo "Done."

runtestcreateHashKey: testcreateHashKey 
	@echo "Running testcreateHashKey" 
	@./testcreateHashKey

# --- Test for stripNewLine ---
teststripNewLine: stripNewLine.s teststripNewLine.c pa3.h test.h 
	@echo "Compiling teststripNewLine"
	gcc -g3 -o teststripNewLine stripNewLine.s teststripNewLine.c test.h
	@echo "Done."

runteststripNewLine: teststripNewLine 
	@echo "Running teststripNewLine" 
	@./teststripNewLine

