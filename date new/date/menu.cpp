#include "Tree/function/menu.h"
#include "Tree/function/action.h"
#include <iostream>

void write_start_text()
{
	std::cout << std::endl;
	std::cout << "What to do next:\n";
	std::cout << "  1 - add new data\n";
	std::cout << "  2 - show all data\n";
	std::cout << "  3 - find element (add working elment for: 4-7)\n";
	std::cout << "     4 - delete element\n";
	std::cout << "     5 - day of the week\n";
	std::cout << "     6 - diferent of data\n";
	std::cout << "     7 - add time\n";
	std::cout << "  8 - exit\n";
	std::cout << "answer:";
}

//Invokes all other functions, performing all actions with them.
void start_menu()
{	
	bool check = true; //Checkers for writing the initial text of a menu with functions.
	tree *begin = nullptr; //Pointer to the beginning of the tree
	tree *index = nullptr; //Pointer to the cell that is currently in use.

	for (;;)
	{
		int answer = 0;
		

		if (index)
			show(index, 0);
		if(check)
			write_start_text();
		
		
	
		std::cin >> answer;
	

		if (answer >= 1 && answer <= 8)
		{
			check = true;

			//Function to introduce a new tree element.
			if (answer == 1)
			{
				char jj = 'y';
				while (jj == 'y' || jj == 't')
				{
					if (jj == 'y')
					{
						if (begin == nullptr)
							begin = first_add();
						else
							add_node(begin);
					}

					std::cout << std::endl << std::endl << "Do you want to add one more data?\n  y - yes\n  n - no\nanswer:";
					std::cin >> jj;
					if (!(jj == 'y' || jj == 'n'))
					{
						std::cout << std::endl << "Wrong answer. Try again";
						jj = 't';
					}
				} 
			}
			//ѕише ус≥ дати.
			else if (answer == 2)
			{
				if (begin)
					show(begin, 1);
				else
					std::cout << "you didn`t have data now";
				std::cout << std::endl << std::endl;
			}
			//знаходить дату.
			else if (answer == 3)
			{
				if (begin)
				{
					show(begin, 1);
					index = find(begin);
				}
				else
				{
					std::cout << "you didn`t have date now";
					std::cout << std::endl << std::endl;
				}		
			}
			else if (answer == 4 && index)
			{
				delet(index, begin);
				index = nullptr;
			}
			//знаходженн€ дн€ тиждн€ 
			else if (answer == 5 && index)
			{
				std::cout << std::endl << std::endl;
				show(index, 0);
				index->d.d_day();
			}
			//р≥зниц€ двух дат
			else if (answer == 6 && index)
			{		
				show(begin, 1);
				std::cout << std::endl << "You need two index."  << std::endl << std::endl;

				tree* index22 = nullptr;
				index22 = find(begin);

				show(index22, 0);
				std::cout << " and ";
				show(index, 0);


				//Data noma;
				//noma.diferent(index->d, index22->d);
				int d_result = diferent(index->d, index22->d);
				std::cout << "Result = " << d_result;
			}
			//додати час
			else if (answer == 7 && index)
			{
				summ_time(begin, index);
			}
			//вих≥д
			else if (answer == 8)
			{

				break;
			}
			else if ((answer >= 4 && answer <= 7) && !index)
			{
				std::cout << "you must find data for work";
			}
		}
		else
		{
			std::cout<< "wrong number, try again.\nanswer:";
			check = false;
		}
	}

	std::cout << std::endl << "end of work" << std::endl;

}
