#Macros to be used by the program
SRCDIR = ../src
EXTDIR = ../external
INCLUDEDIR = ../include
OBJDIR = ../obj
BINDIR = ../bin
REPORTDIR = ../reports
CFLAGS = -c -g -Wall -I${INCLUDEDIR} -I../external/include -DLOG_USE_COLOR

#creating build for the program(exe)
all:

	gcc ${CFLAGS}  ${SRCDIR}/main.c -o ${OBJDIR}/main.o
	gcc ${CFLAGS}  ${SRCDIR}/utilities.c -o ${OBJDIR}/utilities.o
	gcc ${CFLAGS}  ${SRCDIR}/userStoriesCRUD.c -o ${OBJDIR}/userStoriesCRUD.o
	gcc ${CFLAGS}  ${SRCDIR}/taskCRUD.c -o ${OBJDIR}/taskCRUD.o
	gcc ${CFLAGS}  ${SRCDIR}/featureCRUD.c -o ${OBJDIR}/featureCRUD.o
	gcc ${OBJDIR}/main.o ${OBJDIR}/utilities.o ${OBJDIR}/userStoriesCRUD.o ${OBJDIR}/taskCRUD.o ${OBJDIR}/featureCRUD.o -o  ${BINDIR}/main.bin

#Checking the memory leaks
memcheck:
	valgrind ${BINDIR}/main.bin 2> ${REPORTDIR}/memcheck.txt

#adding splint into the prgram
errorcheck:
	splint ${SRCDIR}/*.c -I ${INCLUDEDIR} > ${REPORTDIR}/errorcheck.txt

#Cleaning the unwanted files
clean:
	rm ${OBJDIR}/main.o ${OBJDIR}/utilities.o ${OBJDIR}/userStoriesCRUD.o ${OBJDIR}/taskCRUD.o ${OBJDIR}/featureCRUD.o