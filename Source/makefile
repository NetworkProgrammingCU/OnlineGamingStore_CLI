# Capture the current directory of the make file
# =====================================================
DIR := ${CURDIR}

# Compiler and Compiler Args (default)
# =====================================================
compiler := cc
compilerArg := -o

# Server files
# =====================================================
svOutput := server.binary
svDriver := $(DIR)/Server/Driver.c

# Client files
# =====================================================


# Main Make Operation
# =====================================================
ALL: server client
server: $(svDriver)
	@echo Compiling Server Build. . .
	$(compiler) $(compilerArg) $(svOutput) $(svDriver)
	@echo Successfully Compiled Build!
client: Driver.c
	@echo Compiling Client Build. . .
	@echo Successfully Compiled Build!
clean:
	@echo Thrashing Compiled Builds. . .
	@echo Successfully Expunged Binary Builds!
