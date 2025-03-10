#pragma once
#include <iostream>


// in een aparte thread zetten 
class UiUtility{

	UiUtility();
	~UiUtility();

	void Prepare () // zet de retreiveuserselection aan in een aparte thread zodat hij niet blokkeerd

	 int retrieveUserSelection(std::string selectionOptions[], int numOptions);
	 bool userDecidesIfBypassed();
	private:


};
