COURSE = cs240
SEMESTER = spring2022

CP_NUMBER = 2

LASTNAME = Sujkovic
GITUSERID = sujkovic

# The name of the executable
EXE = play

# Name files
REPODIR = ../$(COURSE)-$(SEMESTER)-cp$(CP_NUMBER)-$(GITUSERID)
TARFILE = CP$(CP_NUMBER)_$(LASTNAME)_$(USER)_$(GITUSERID).tar

FLAGS = -Wall -Wextra -g
CC = g++
BIN = bin
OBJ = obj

# Store executables in a subdirectory
all: $(BIN)/$(EXE)

# Reflects how the files may have been named in CP0
$(BIN)/$(EXE): $(OBJ)/Player.o $(OBJ)/Team.o $(OBJ)/Play.o $(OBJ)/League.o
	$(CC) $(FLAGS) $(OBJ)/Player.o $(OBJ)/Team.o $(OBJ)/Play.o $(OBJ)/League.o -o $@

$(OBJ)/Play.o: Play.cpp Player.h Team.h League.h Parser.h
	$(CC) $(FLAGS) -c Play.cpp -o $@

#note to self: i added the below 3

$(OBJ)/Player.o: Player.cpp Player.h
	$(CC) $(FLAGS) -c Player.cpp -o $@

$(OBJ)/Team.o: Team.cpp Team.h Player.h
	$(CC) $(FLAGS) -c Team.cpp -o $@

$(OBJ)/League.o: League.cpp League.h Team.h
	$(CC) $(FLAGS) -c League.cpp -o $@

# Run make tar to build a .tar.gz file appropriate for uploading to Brightspace
tar:	clean
	tar cvvf $(TARFILE) $(REPODIR)
	gzip $(TARFILE)

clean:
	rm -f $(OBJ)/*.o $(BIN)/$(EXE) *.tar.gz
