#include<iostream>
#include<string>
using namespace std;

class Book
{
	private:
		int bookId;
		string title;
		string author;
		double price;

	public:
		Book()
		{
			bookId = 101;
			title ="C++ Programming";
			author = "Bjame Stroustrup";
			price = 500.00;
		}

	Book(int id, string t, string a, double p)
	{
		bookId = id;
		title = t;
		author = a;
		price = p;
	}

	void display()
	{
		cout<<"Book ID:"<<bookId<<endl;
		cout<<"Title: "<<title<<endl;
		cout<<"Author: "<<author<<endl;
		cout<<"Price:Rs. "<<price<<endl;
		cout<<"----------------------"<<endl;
	}
};
int main()
{
	Book book1;
	Book book2(102, "Object Oriented Programming", "Robert Lafore", 650.00);
	cout<<"First Book Details: "<<endl;
	book1.display();

	cout<<"Second Book Details: "<<endl;
	book2.display();
	return 0;
}
