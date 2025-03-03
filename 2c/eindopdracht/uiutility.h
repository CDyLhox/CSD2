#pragma once
#include <iostream>

class UiUtility{

	UiUtility();
	~UiUtility();

	 int retrieveUserSelection(std::string selectionOptions[], int numOptions);
	 bool userDecidesIfBypassed();
	private:


};
