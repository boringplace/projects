.MAIN: all
.PHONY: clean
.SILENT: clean

all: safety-instruction

# Note the two compilation stages. This is needed to perform:
# 1. Table of Contents resolution
# 2. Conditional compilation
safety-instruction: safety-instruction.tex
	git clean -f -e "*.pdf" ./
	pdflatex safety-instruction.tex
	pdflatex -output-directory=${.CURDIR} "\include{safety-instruction}"

clean:
	git clean -fdx ./

