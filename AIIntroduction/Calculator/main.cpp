#include "define.h"
#include "stack.h"
#include "Helper.h"
#include "Search.h"
#include "Compute.h"



int main() {

	std::cout << "\033c";
	std::cout << "\033[1;33m------------------------------- Calculator -------------------------------\033[0m\n";
	std::cout << "\033[1;33m-------------------- Version: 1.0, Made by Doven Tang --------------------\033[0m\n";
	std::cout << "\033[1;33m--------------------------------------------------------------------------\033[0m\n\n";
	std::cout << "\033[4;32mInstructions:\033[0m This calculator is designed to perform various calculations, \n";
	std::cout << "encompassing common symbols such as logarithmic operations, trigonometric \n";
	std::cout << "functions, root of powers, factorials, radians, and angles. Moreover, it \n";
	std::cout << "includes the capability to compute minimumand maximum values for any given \n";
	std::cout << "function and give numerical solution of any single variable equation. While \n";
	std::cout << "the calculator is powerful, please be aware that Version 1.0 may exhibit \n";
	std::cout << "instability and potential miscalculations.\n\n";
	std::cout << "\033[4;32mHere are come examples:\033[0m\n";
	std::cout << "  \033[1;33mIn: 0-3+5*8    Out: 37\033[0m\n";
	std::cout << "    Avoid putting the minus sign first, and use 0-number instead.\n";
	std::cout << "  \033[1;33mIn: cos0+ln(e^2)    Out: 3\033[0m\n";
	std::cout << "    Use 'pai' for PI and 'e' for the base of the natural logarithm.\n";
	std::cout << "  \033[1;33mIn: (1+3)!+2*sin30`    Out: 25\033[0m\n";
	std::cout << "    Use '`' to represent the Angle. The default input is radians\n";
	std::cout << "  \033[1;33mIn: min((_0-2)^2+(_1-3)^2+1)    Out: 1, (2,3)\033[0m\n";
	std::cout << "    Minimize any function in this way as well as maximize. \n";
	std::cout << "    Use '_' to mark unknown variables, '_0' and '_1' are variables.\n";
	std::cout << "  \033[1;33mIn: solve((_0-2)^2+(_0-3)^2-10)    Out: 3.54546e-26, 0.320551\033[0m\n";
	std::cout << "    This algorithm can only give one solution to a single valued equation. \n";
	std::cout << "    Use '_0' to mark the unknown variable.\n\n";

	while (true) {
restart:
		// input and analysis
		char* string_expression;
		input(string_expression);
		char string_extract[MAX_OPERATE_NUMBER][MAX_OPERATE_NAME] = { 0 };
		extract_string(string_expression, string_extract);

		// quit
		if (strcmp(string_extract[0], "quit") == 0) {
			std::cout << "\n-----------------------------------Quit-----------------------------------\n\n\n\n";
			return 0;
		}

		// solve mode
		else if (string_extract[0][0] == 'A') {
			string_extract[0][0] = 'y';
			Point min_point = NULL;
			int again_times = 0;
			int unknown_number = 0;
			int length = 0;
			for (int temp = 0; string_extract[length][0] != '\0'; length++)
				if (string_extract[length][0] == '_') {
					temp = string_extract[length][1] - 47;
					if (unknown_number < temp) 
						unknown_number = temp;
				}
			string_extract[length-1][0] = '^';
			string_extract[length][0] = '2';
			string_extract[length+1][0] = ')';
solve_again:
			to_global(string_extract);
			try {
				min_point = Search_min(&Compute_with_unknown, unknown_number, TOLERANCE);
			} catch (...) {
				std::cout << "Error! Restart...\n"; goto restart;
			}
			double min_value = Compute_with_unknown(min_point);
			if (min_value > FAIL_BOUND && again_times < RETRY_TIMES) {
				again_times++;
				goto solve_again;
			} else if (min_value > FAIL_BOUND) {
				std::cout << "Solve fail, Make sure the equation is solvable.\n";
				goto restart;
			} // fail 
			std::cout << "Tolerance is: " << min_value << "\nSolution is: ";
			for (int i = 0; i < unknown_number - 1; i++)
				std::cout << min_point[i] << ",";
			std::cout << min_point[unknown_number - 1] << "\n";
		}

		// min-max mode
		else if (string_extract[0][0] == 'w' || string_extract[0][0] == 'x') {
			if (string_extract[0][0] == 'w')
				string_extract[0][0] = 'y';
			else if (string_extract[0][0] == 'x')
				string_extract[0][0] = 'z';
			int unknown_number = 0;
			Point min_point = NULL;
			for (int i = 0, temp = 0; string_extract[i][0] != '\0'; i++)
				if (string_extract[i][0] == '_') {
					temp = string_extract[i][1] - 47;
					if (unknown_number < temp)
						unknown_number = temp;
				}
			to_global(string_extract);
			try {
				min_point = Search_min(&Compute_with_unknown, unknown_number, TOLERANCE);
			} catch (...) {
				std::cout << "Error! Restart...\n"; goto restart; 
			}
			double min_value = Compute_with_unknown(min_point);
			// print 
			std::cout << "Extreme numebr is: " << min_value << "\nExtreme point is: (";
			for (int i = 0; i < unknown_number - 1; i++)
				std::cout << min_point[i] << ",";
			std::cout << min_point[unknown_number - 1] << ")\n";
		}

		// calculate mode
		else {
			double result = Compute(string_extract);
			std::cout << "Result is: " << result << "\n";
		}

	}
	return -1;
}