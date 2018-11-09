#include"Base.h"

int main()
{
	Pub_Derv d1;
	Priv_Derv d2;
	Proc_Derv d3;
	Derived_from_Public dd1;
	Derived_from_Private dd2;
	Derived_from_Protected dd3;

	Base *p = &d1;
	d1.pub_mem();
	
	//d2.pub_mem(); // error pub_mem is a private member in private derived class(see line 30);
	//p = &d2;
	//error : cannot cast 'Proc_Derv' to its protected base class 'Base'
	//p = &d3;

	p = &dd1;

	//error : cannot cast 'Derived_from_Privare' to its private base class 'Base'
	//p = &dd2;
	//error : cannot cast 'Derived_from_protected' to it's protected base class 'Base'
	//p = &dd3;

	return 0;
}
