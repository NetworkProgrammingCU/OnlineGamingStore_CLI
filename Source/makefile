# Capture the current directory of the make file
# =====================================================
DIR := ${CURDIR}

# Compiler and Compiler Args (default)
# =====================================================
compiler := cc
compilerArg := -o

# Shared files
# =====================================================
shDir := $(DIR)/Shared
shComFun := $(shDir)/CommonFunctions.c
shMyUNP := $(shDir)/myunp.h

# Server files
# =====================================================
svOutput := server.binary
svDriver := $(DIR)/Server/Driver.c

# Client files
# =====================================================


# Main Make Operation
# =====================================================
ALL: server client
server: $(shComFun) $(svDriver)
	@echo Compiling Server Build. . .
	$(compiler) $(compilerArg) $(svOutput) -I $(shDir) $(shComFun) $(shMyUNP) $(svDriver)
	@echo Successfully Compiled Build!
client: Driver.c
	@echo Compiling Client Build. . .
	@echo Successfully Compiled Build!
clean:
	@echo Thrashing Compiled Builds. . .
	@rm $(svOutput)
	@echo Successfully Expunged Binary Builds!
