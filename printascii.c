#include <stdio.h>
#include <stdlib.h>
#define length 128

// the following are the functions used in this program 
void printTable(int row, int column);
void checkCase(int asciiArr[], int currentChar);
int readValue();
int checkChar();

/****************************************************************************************************
 *	This program generates the ASCII table for values 0 thru 127 in columns varying between         *
 *  1 and 8. The number of columns are determined by the user. The user will continue to be         *
 *  prompt for correct input, if the character entered by the user does not match integer           *
 *  values between 1 and 8.									    								    *
 *__________________________________________________________________________________________________*
 *                                                                                                  *
 *	@author Paola Jiron                                                                             *
 ****************************************************************************************************/
        
int main(){

// global variables
int column;				// the number of columns
int row;				// "		" of rows
int flag;				// control variable for prompting the user for input
int tries = 0;			// on the 3rd user input, the user will be questioned if they want to continue 

printf("\nPress ENTER to begin.");			

while (flag != 0 && (flag = getchar()) == '\n'){	// ensures no repeated line output

	printf("Please enter a number from 1 thru 8. Then press ENTER.\n");	

		column = readValue();		// handle user input 

	if ( column != 0 ){		// avoid division by 0

		row = length/column;	// determine the number of rows (NOTE: int division will truncate the output)

		if ( length % column != 0 ){			// if the number of rows is odd..
	
			row = row + 1;			// increment the row size by 1 to ensure correct output
		}	
     }

	if ( column >= 1 && column <= 8 ){		// if the user enters correct input..

		printTable(row, column);		// ...call the function that prints the table
		flag = 0; 					// then, set the flag to false to quit prompt
	}
	
	tries++;		// at 3, it will begin to question if the user wants to continue the program
	
	if (tries < 3 && flag != 0){				
		printf("You have entered an unacceptable value. Let's try this again...\n");
	}	
	if ( tries >= 3 && flag != 0){			// questions user until they decide to stop or enter correct input
		printf("Would you like to continue?(Type Y for 'yes' or N for 'no' then press ENTER.)\n");
		   
		     int c;

			   while((c = getchar()) != EOF){	// continue until the user enters Y (for yes) or N (for no)
			   		if ( c == 'N' || c == 'n'){
						printf("Awe, Okay. GOODBYE!\n");
					
						flag = 0;		// sets flag to quit the program
						break;		// leave loop
					}
					if ( c == 'Y' || c == 'y'){
						tries = 0;		// reset the tries count to continue
						break;			// leave loop, but continue the program
					}
				} 	
	}
  }
  return 0;
}	// end of main function definitions

/******************************************************************************************************
 *  This function reads from standard input and determines whether the input is a non-numerical value.*
 *  If the input is a numerical value then it is converted into decimal value (using base 10 logic).  *
 *  The result is returned once the decimal representation of the input is computed.                  *
 ******************************************************************************************************/
 
int readValue(){

	int accumulator = 0;	// will contain the sum of values read (decimal representation)
	int c;
	
	while((c = checkChar()) != '\n'){	// continue until end of line is reached	
	
		c = getchar();						// get the next character entered
		accumulator= accumulator * 10;		// if here... convert to DECimal, there are more values to be read
		
		accumulator = accumulator + ( c - '0');		// add values
	}
	return accumulator;		// return the decimal value
	
} // end of readValue function definitions

/*******************************************************************************************************
 * This function simply determines whether or not the next character is pointer to End Of File. Then   *
 * it returns the following character whether there is one to be read or EOF itself.	       	       *
 *******************************************************************************************************/

int checkChar(){
	
	int c;		// will contain next character input
	
	c = getchar();		// get the next character in stdin (buffer read)
	if( c != EOF){			// read values until there aren't anymore to be read
	 ungetc(c, stdin);		// now.. place the character back in stdin (buffer read)
	 }
	return c;		// returns the character
	
}	// end of checkChar function definitions

/******************************************************************************************************
 * This function populates the ascii array and outputs a table containing ascii values from 0 to 127  *
 ******************************************************************************************************/

void printTable(int row, int column){


	// show the user what will be displayed
	
	printf("Number of rows computed: %3d \nNumber of columns requested by user: %3d\n\n", row, column);
	int currentChar = 0;
	
	int asciiArr[length];	// create an array of ascii characters with a size of 128
	
	// populate the array with values 0 thru 127
	
	for( int i = 0; i < length ; i++){
	
		asciiArr[i] = i;
	
	}
	// for each row...
	
	for ( int i = 0; i < row; i ++){
	
		// output the amount of columns determined by the user ....but
		
		for ( int j = 0; j < column && currentChar < length; j++){
		
			//...output three-characters bounded by "<",">" in place of non-printable
			//  entries like: control characters, space, delete, and so on.
			
			if ((currentChar >= 0 && currentChar <= 32) || currentChar == 127 ){
		
				// specify the output corresponding to each control character (values 0 thru 32 and 127)
				checkCase(asciiArr, currentChar);																		
				
			// otherwise, output the decimal value 
			// followed by it's corresponding ascii value
			
			}else{	
		
				printf("[%3d]:%5c  ", asciiArr[currentChar], asciiArr[currentChar]); 
			}
			currentChar++;	// move to the next character
		}
		printf("\n");
	}	
}	// end of printTable function definitions

/***************************************************************************************************** 
 *	This function swaps any value held in an array specified by the parameter.                       *
 *	The location is indicated by the currentChar parameter. If the location is                       *
 *      one of the trivial cases, the value in that location is swapped to the value                 *
 *      indicated in that case (NOTE: these values are not placed in the array, but                  *
 *	simply displayed in place of the values already in the array, otherwise there                    *
 *	will be a type mismatch exception).                                                              *
 *****************************************************************************************************/
void checkCase(int asciiArr[], int currentChar){

				switch(currentChar){
				
					case 0:
						printf("[%3d]:  <NIL>", asciiArr[currentChar]);
						break;
					case 1:
						printf("[%3d]:  <SOH>", asciiArr[currentChar]);
						break;
					case 2:
						printf("[%3d]:  <STX>", asciiArr[currentChar]);
						break;
					case 3:
						printf("[%3d]:  <ETX>", asciiArr[currentChar]);
						break;
					case 4:
						printf("[%3d]:  <EOT>", asciiArr[currentChar]);
						break;
					case 5:
						printf("[%3d]:  <ENQ>", asciiArr[currentChar]);
						break;
					case 6:
						printf("[%3d]:  <ACK>", asciiArr[currentChar]);
						break;
					case 7:
						printf("[%3d]:  <BEL>", asciiArr[currentChar]);
						break;
					case 8:
						printf("[%3d]:  < BS>", asciiArr[currentChar]);
						break;
					case 9:
						printf("[%3d]:  <TAB>", asciiArr[currentChar]);
						break;
					case 10:
						printf("[%3d]:  < NL>", asciiArr[currentChar]);
						break;
					case 11:
						printf("[%3d]:  < VT>", asciiArr[currentChar]);
						break;
					case 12:
						printf("[%3d]:  < FF>", asciiArr[currentChar]);
						break;
					case 13:
						printf("[%3d]:  < CR>", asciiArr[currentChar]);
						break;
					case 14:
						printf("[%3d]:  < SO>", asciiArr[currentChar]);
						break;
					case 15:
						printf("[%3d]:  < SI>", asciiArr[currentChar]);
						break;
					case 16:
						printf("[%3d]:  <DLE>", asciiArr[currentChar]);
						break;
					case 17:
						printf("[%3d]:  <DC1>", asciiArr[currentChar]);
						break;
					case 18:
						printf("[%3d]:  <DC2>", asciiArr[currentChar]);
						break;						
					case 19:
						printf("[%3d]:  <DC3>", asciiArr[currentChar]);
						break;	
					case 20:
						printf("[%3d]:  <DC4>", asciiArr[currentChar]);
						break;						
					case 21:
						printf("[%3d]:  <NAK>", asciiArr[currentChar]);
						break;
					case 22:
						printf("[%3d]:  <SYN>", asciiArr[currentChar]);
						break;												
					case 23:
						printf("[%3d]:  <ETB>", asciiArr[currentChar]);
						break;	
					case 24:
						printf("[%3d]:  <CAN>", asciiArr[currentChar]);
						break;
					case 25:
						printf("[%3d]:  < EM>", asciiArr[currentChar]);
						break;
					case 26:
						printf("[%3d]:  <SUB>", asciiArr[currentChar]);
						break;																	
					case 27:
						printf("[%3d]:  <ESC>", asciiArr[currentChar]);
						break;
					case 28:
						printf("[%3d]:  < FS>", asciiArr[currentChar]);
						break;
					case 29:
						printf("[%3d]:  < GS>", asciiArr[currentChar]);
						break;
					case 30:
						printf("[%3d]:  < RS>", asciiArr[currentChar]);
						break;
					case 31:
						printf("[%3d]:  < US>", asciiArr[currentChar]);
						break;	
					case 32:
						printf("[%3d]:  <SPC>", asciiArr[currentChar]);
						break;
					case 127:
						printf("[%3d]:  <DEL>", asciiArr[currentChar]);
						break;	
				}
} // end of checkCase function definitions