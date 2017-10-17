## Makefile template for CSE 30 -- PA4(mydiff)
#

HEADERS		= pa4.h pa4_strings.h lcs.h test.h

C_SRCS		= appendResult.c buildFileStruct.c displayResults.c\
		expandTabs.c main.c makeResults.c makeSymbolColBuffer.c\
		makeFileColBuffer.c setDisplayMode.c pa4_globals.c

# Extra credit
# stripWhitespace.c stripWSCompare.c stripWSAndIgnoreCaseCompare.c

ASM_SRCS	= freeFileStruct.s ignoreCaseCompare.s\
		printUsage.s stripNewLine.s defaultCompare.s

C_OBJS		= $(C_SRCS:.c=.o)

ASM_OBJS	= $(ASM_SRCS:.s=.o)

LIB_FLAG	= -llcs

LIB_DIR 	= . 

OBJS		= ${C_OBJS} ${ASM_OBJS}

EXE		= mysdiff

TEST_SRCS 	= testappendResult.c testbuildFileStruct.c testdefaultCompare.c\
		testfreeFileStruct.c testignoreCaseCompare.c testmakeResults.c\
		testmakeSymbolColBuffer.c testsetDisplayMode.c

TEST_EXE	= $(TEST_SRCS:.c=)  

TEST_DIR	= unit_tests

#
# Relevant man pages:
#
# man gcc
# man as
# man lint
#

GCC		= gcc
ASM		= $(GCC)
LINT		= lint

GCC_FLAGS	= -c -g -Wall -D__EXTENSIONS__ -std=c99
LINT_FLAGS1	= -c -err=warn
LINT_FLAGS2	= -u -err=warn
ASM_FLAGS	= -c -g
LD_FLAGS	= -g -Wall

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

$(EXE):	$(OBJS)
	@echo "2nd phase lint on all C source files ..."
	$(LINT) $(LINT_FLAGS2) *.ln
	@echo ""
	rm *.ln
	@echo "Linking all object modules ..."
	$(GCC) -o $(EXE) $(LD_FLAGS) $(OBJS) -L$(LIB_DIR) $(LIB_FLAG)
	@echo ""
	@echo "Done."

${C_OBJS}:      ${HEADERS}

clean:
	@echo "Cleaning up project directory ..."
	rm -f *.o a.out *.ln core $(EXE) $(TEST_EXE)
	@echo ""
	@echo "Clean."

new:
	make --no-print-directory clean
	make --no-print-directory

setupTest:
	# Move all headers into test directory
	cp $(HEADERS) $(TEST_DIR)

cleanTest:
	# Remove all header from test directory
	rm $(addprefix $(TEST_DIR)/,$(HEADERS))

# --- TESTING ---
LINT_TEST_FLAGS		= -x -u -err=warn

# General purpose compilation target
compileTest: setupTest\
	     $(addsuffix .o, $(basename $(DEPEND)))\
	     cleanTest
	# 2nd Lint
	@echo "2nd phase lint on all C source files ..."
	$(LINT) $(LINT_TEST_FLAGS) *.ln	
	@echo ""
	rm *.ln
	# Compilation 
	@echo "Compiling $(TEST_NAME)" 
	gcc -g3 -o $(TEST_NAME)\
	     	   $(notdir $(addsuffix .o, $(basename $(DEPEND))))\
		   -L$(LIB_DIR) $(LIB_FLAG)
	@echo "Done."


# --- testappendResults ---
testappendResult: appendResult.c $(TEST_DIR)/testappendResult.c 
	@$(MAKE) -s compileTest DEPEND="$^" TEST_NAME=testappendResult 

runtestappendResult: testappendResult
	@echo "Running $<"
	@./$<

# --- testbuildFileStruct ---
testbuildFileStruct: buildFileStruct.c stripNewLine.s\
		     $(TEST_DIR)/testbuildFileStruct.c 
	@$(MAKE) -s compileTest DEPEND="$^" TEST_NAME=testbuildFileStruct 

runtestbuildFileStruct: testbuildFileStruct
	@echo "Running $<"
	@./$<

# --- testdefaultCompare ---
testdefaultCompare: defaultCompare.s $(TEST_DIR)/testdefaultCompare.c 
	@$(MAKE) -s compileTest DEPEND="$^" TEST_NAME=testdefaultCompare 

runtestdefaultCompare: testdefaultCompare
	@echo "Running $<"
	@./$<

# --- testfreeFileStruct ---
testfreeFileStruct: freeFileStruct.s $(TEST_DIR)/testfreeFileStruct.c 
	@$(MAKE) -s compileTest DEPEND="$^" TEST_NAME=testfreeFileStruct 

runtestfreeFileStruct: testfreeFileStruct
	@echo "Running $<"
	@./$<

# --- testignoreCaseCompare ---
testignoreCaseCompare: ignoreCaseCompare.s $(TEST_DIR)/testignoreCaseCompare.c 
	@$(MAKE) -s compileTest DEPEND="$^" TEST_NAME=testignoreCaseCompare 

runtestignoreCaseCompare: testignoreCaseCompare
	@echo "Running $<"
	@./$<

# --- testmakeResults ---
testmakeResults: makeResults.c defaultCompare.s appendResult.c\
		 $(TEST_DIR)/testmakeResults.c 
	@$(MAKE) -s compileTest DEPEND="$^" TEST_NAME=testmakeResults 

runtestmakeResults: testmakeResults
	@echo "Running $<"
	@./$<

# --- testmakeSymbolColBuffer ---
testmakeSymbolColBuffer: makeSymbolColBuffer.c\
			 $(TEST_DIR)/testmakeSymbolColBuffer.c 
	@$(MAKE) -s compileTest DEPEND="$^" TEST_NAME=testmakeSymbolColBuffer 

runtestmakeSymbolColBuffer: testmakeSymbolColBuffer
	@echo "Running $<"
	@./$<

# --- testsetDisplayMode ---
testsetDisplayMode: setDisplayMode.c $(TEST_DIR)/testsetDisplayMode.c 
	@$(MAKE) -s compileTest DEPEND="$^" TEST_NAME=testsetDisplayMode 

runtestsetDisplayMode: testsetDisplayMode
	@echo "Running $<"
	@./$<

