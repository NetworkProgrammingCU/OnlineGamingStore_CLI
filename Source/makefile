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
shComFunH := $(shDir)/CommonFunctions.h
shMyUNP := $(shDir)/myunp.h

# Server files
# =====================================================
svOutput := server.binary
svDir := $(DIR)/Server
svDriver := $(svDir)/Driver.c
svProgInfo := $(svDir)/ProgInformation.c

# Client files
# =====================================================


# Main Make Operation
# =====================================================
ALL: server client
server:
	@echo Compiling Server Build. . .
	@$(compiler) $(compilerArg) $(svOutput) -I $(shDir) -I $(svDir) $(shComFun) $(svProgInfo) $(svDriver)
	@echo Successfully Compiled Build!
client: Driver.c
	@echo Compiling Client Build. . .
	@echo Successfully Compiled Build!
clean:
	@echo Thrashing Compiled Builds. . .
	@rm $(svOutput)
	@echo Successfully Expunged Binary Builds!
