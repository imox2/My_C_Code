/* C program to create the following structure:

							5 5 5 5 5 5 5 5 5 
							5 4 4 4 4 4 4 4 5 
							5 4 3 3 3 3 3 4 5 
							5 4 3 2 2 2 3 4 5 
							5 4 3 2 1 2 3 4 5 
							5 4 3 2 2 2 3 4 5 
							5 4 3 3 3 3 3 4 5 
							5 4 4 4 4 4 4 4 5 
							5 5 5 5 5 5 5 5 5 
*/							



#include<stdio.h>

int main()
{
	int input_number; //to store the number
	int i,j; // variable to run the loop
	int index; //to store how many rows and column a particular number takes; eg 3 takes 5 row and column
	int varnum; // a Number which will start with the highest number (number supplied by user) and this number will constantly change
	int lowest_num_of_row; // Lowest number in the row, used as a row starts with highest number then it is decreased till lowest and then increased agin at last
	int go_up_to; // Go upto this column number without changing lowest_num_of_row after that increase to end of column number
	int difference; // difference between highest and lowest row no, used to calculate go_up_to variable
	int row; //stores the row no having 1 as its element, used to duplicate upper part of matrix to lower part
	int lowest_num_of_row_check; //duplicate of lowest_num_of_row used for checking and breaking out of loop when lowest num is 1
	int add=1; //after breaking out of loop,used for copying as upper matrix is identical to lower.
	int highest_num=9; // upto 9 support as 10 will mess with the formatting
	int num_to_add=8; // highest number required for highest number input, 9 would require 17 rows and 17column, so 9+8=17
	int mat[17][17];

	printf("Enter the number between 1 and 9:");
	scanf("%d",&input_number);

	if(input_number<0||input_number>9)
	{
		printf("Please try a number in range 1-9\n");
	}

	else
	{
		while(highest_num!=input_number) // calculates the number to be added to form the formation for 3 we need to add 2 extra row
		{
			num_to_add=num_to_add-1;
			highest_num=highest_num-1;
		}
		
		index=input_number+num_to_add; //final row and column needed
	
		for(i=0;i<index;i++)
		{	
			varnum=input_number; //row starts with highest number and then changes
			lowest_num_of_row=varnum-i; // as 0th contains only the number inputed
			lowest_num_of_row_check=lowest_num_of_row; //for checking and breaking when lowest number is 1
			difference=varnum-lowest_num_of_row; // diffrence needed to calculate which column should we go upto before increasing value
			go_up_to=(index-1)-difference;
			for(j=0;j<index;j++)
			{

				if(j<=go_up_to) //upto that number number can only be decreases and be constant after j reaches go_up_to num is increased to the end of column
				{
					mat[i][j]=varnum;
					if(varnum>lowest_num_of_row) //if lowest not yet reached, decrease, if reached, no change required upto the go_upto_value
					{
						varnum--;
					}
				}
				else
				{	
					lowest_num_of_row++; //go_up_to reached so now increase upto end of column
					mat[i][j]=lowest_num_of_row;
				}
			}

			if(lowest_num_of_row_check==1) //we have to calculate only till the row that has 1 as its lowest value, then break
			{
					
				break;
			}
		}
		
	

		row=i;
		while((row+add)<index)
		{
			for(j=0;j<index;j++)
			{
				mat[row+add][j]=mat[row-add][j]; //copying of upper matrix and lower matrix
			}
			add++;
		}
			
		for(i=0;i<index;i++)
		{
			for(j=0;j<index;j++)
			{
				printf("%d ",mat[i][j] );
			}
			printf("\n");
		}
	}	
	return 0;	
}