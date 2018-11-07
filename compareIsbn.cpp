#include"Sales_data.h"

bool compareIsbn(const Sales_data& item1, const Sales_data& item2)
{
	return item1.isbn() < item2.isbn();
}
