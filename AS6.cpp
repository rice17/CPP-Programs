//A very simple program to show Exception Handling in C++


#include <iostream>
using namespace std;

class div
{
	private:
		float x, y, res;
	public:
		void input()
		{
			cout<<"Enter x and y for x/y : ";
			cin>>x>>y;
		}
		void divide()
		{
			try
			{
				if(y==0)
				{
					throw "Cannot divide by zero\n";
				}
			}
			catch(const char *s)
				{
					cout<<s;
				}
			res=x/y;
			if(y != 0)
				cout<<res;
		}
};

int main()
{
	div h;
	char ch='y';
	while(ch == 'y' || ch == 'Y')
	{
		h.input();
		h.divide();
		cout<<"\nWant to continue? (Y/N)\n";
		cin>>ch;
	}
	return 0;
}

