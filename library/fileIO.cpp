#include <iostream>
#include <fstream>
#include "../includes_usr/fileIO.h"
using namespace std;
/* clears, then loads books from the file filename
 * returns  COULD_NOT_OPEN_FILE if cannot open filename
 * 			NO_BOOKS_IN_LIBRARY if there are 0 entries in books
 * 			SUCCESS if all data is loaded
 * */
int loadBooks(std::vector<book> &books, const char* filename)
{
	books.clear();
	fstream inputFile;
	inputFile.open(filename);
	if(!inputFile.is_open()){
		return COULD_NOT_OPEN_FILE;
	}
	string input;
	while(!inputFile.eof()){
		book b;
		getline(inputFile, input, ',');
		if(input == "" || input == " "){
			break;
		}
		b.book_id = stoi(input);
		getline(inputFile, input, ',');
		b.title = input;
		getline(inputFile, input, ',');
		b.author = input;
		getline(inputFile, input, ',');
		int checkState = stoi(input);
		switch(checkState){
			case 0:
				b.state = UNKNOWN;
				break;
			case 1:
				b.state = IN;
				break;
			case 2:
				b.state = OUT;
				break;
		}
		getline(inputFile, input, '\n');
		b.loaned_to_patron_id = stoi(input);
		books.push_back(b);
	}
	inputFile.close();
	if(books.empty()){
		return NO_BOOKS_IN_LIBRARY;
	}
	return SUCCESS;
}

/* serializes books to the file filename
 * returns  COULD_NOT_OPEN_FILE if cannot open filename
 * 			NO_BOOKS_IN_LIBRARY if there are 0 entries books (do not create file)
 * 			SUCCESS if all data is saved
 * */
int saveBooks(std::vector<book> &books, const char* filename)
{
	if(books.empty()){
		return NO_BOOKS_IN_LIBRARY;
	}
	fstream inputFile;
	inputFile.open(filename);
	if(!inputFile.is_open()){
		return COULD_NOT_OPEN_FILE;
	}
	string input;
	while(!inputFile.eof()){
		book b;
		getline(inputFile, input, ',');
		if(input == "" || input == " "){
			break;
		}
		b.book_id = stoi(input);
		getline(inputFile, input, ',');
		b.title = input;
		getline(inputFile, input, ',');
		b.author = input;
		getline(inputFile, input, ',');
		int checkState = stoi(input);
		switch(checkState){
			case 0:
				b.state = UNKNOWN;
				break;
			case 1:
				b.state = IN;
				break;
			case 2:
				b.state = OUT;
				break;
		}
		getline(inputFile, input, '\n');
		b.loaned_to_patron_id = stoi(input);
		books.push_back(b);
	}
	inputFile.close();
	return SUCCESS;
}

/* clears, then loads patrons from the file filename
 * returns  COULD_NOT_OPEN_FILE if cannot open filename
 * 			NO_PATRONS_IN_LIBRARY if there are 0 entries in patrons
 * 			SUCCESS if all data is loaded
 * */
int loadPatrons(std::vector<patron> &patrons, const char* filename)
{
	patrons.clear();
	fstream inputFile;
	inputFile.open(filename);
	if(!inputFile.is_open()){
		return COULD_NOT_OPEN_FILE;
	}
	string input;
	while(!inputFile.eof()){
		patron p;
		getline(inputFile, input, ',');
		if(input == "" || input == " "){
			break;
		}
		p.patron_id = stoi(input);
		getline(inputFile, input, ',');
		p.name = input;
		getline(inputFile, input, '\n');
		p.number_books_checked_out = stoi(input);
	}
	inputFile.close();
	if(patrons.empty()){
		return NO_PATRONS_IN_LIBRARY;
	}
	return SUCCESS;
}

/* serializes patrons to the file filename
 * returns  COULD_NOT_OPEN_FILE if cannot open filename
 * 			NO_PATRONS_IN_LIBRARY if there are 0 entries in patrons  (do not create file)
 * 			SUCCESS if all data is saved
 * */
int savePatrons(std::vector<patron> &patrons, const char* filename)
{
	if(patrons.empty()){
		return NO_PATRONS_IN_LIBRARY;
	}
	fstream inputFile;
	inputFile.open(filename);
	if(!inputFile.is_open()){
		return COULD_NOT_OPEN_FILE;
	}
	string input;
	while(!inputFile.eof()){
		patron p;
		getline(inputFile, input, ',');
		if(input == "" || input == " "){
			break;
		}
		p.patron_id = stoi(input);
		getline(inputFile, input, ',');
		p.name = input;
		getline(inputFile, input, '\n');
		p.number_books_checked_out = stoi(input);
	}
	inputFile.close();
	return SUCCESS;
}
