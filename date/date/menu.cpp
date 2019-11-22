#include "Header Files/function/menu.h"
#include "Header Files/function/action.h"
#include <iostream>

void write_start_text()
{
	std::cout << std::endl;
	std::cout << "What to do next:\n";
	std::cout << "  1 - add new date\n";
	std::cout << "  2 - show all date\n";
	std::cout << "  3 - found element (add working elment for: 4-7)\n";
	std::cout << "     4 - delete element\n";
	std::cout << "     5 - day of the week\n";
	std::cout << "     6 - diferent of date\n";
	std::cout << "     7 - add time\n";
	std::cout << "  8 - exit\n";
	std::cout << "answer:";
}

void start_menu()
{	
	bool check = true;
	tree* begin = nullptr;
	tree *index = nullptr;

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

			//записуЇ дати.
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

					std::cout << std::endl << std::endl << "Do you want add more date?\n  y - yes\n  n - no\nanswer:";
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
					std::cout << "you didn`t have date now";
				std::cout << std::endl << std::endl;
			}
			//знаходить дату.
			else if (answer == 3)
			{
				if (begin)
				{
					show(begin, 1);
					index = found(begin);
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
				index22 = found(begin);

				show(index22, 0);
				std::cout << " and ";
				show(index, 0);


				date noma;
				noma.diferent(index, index22);
			}
			//додати час
			else if (answer == 7 && index)
			{
				index->d.summ_time(begin, index);
			}
			//вих≥д
			else if (answer == 8)
			{

				break;
			}
			else if ((answer >= 4 && answer <= 7) && !index)
			{
				std::cout << "you must found date for work";
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
