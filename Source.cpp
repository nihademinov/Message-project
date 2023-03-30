#include <iostream>
using namespace std;
#include <assert.h>





class MessageText
{
public:
	string TextTitle;
	string TextName;

	MessageText()
	{
		TextTitle = " ";
		TextName = " ";
	}

	MessageText(string TextTitle, string TextName)
	{
		setTextTittle(TextTitle);
		setTextBody(TextName);
	}

	void printMessageText()
	{
		cout << "Message Text Info" << endl;
		cout << "Text Title: " << this->TextTitle << endl;
		cout << "Text Body: " << this->TextName << endl;
	}

	void setTextTittle(string TextTitle)
	{
		this->TextTitle = TextTitle;
	}
	void setTextBody(string TextName)
	{
		this->TextName = TextName;

	}
	
	

};

class SMS:virtual public MessageText
{
public:
	string NumberSender;
	string NumberSend;

	SMS()
	{
		NumberSender = "XXX XXX XX XX";
		NumberSend = "XXX XXX XX XX";
	}

	SMS(string TextTitle,string TextNamee, string NumberSender):MessageText(TextTitle, TextNamee)
	{
		setNumberSender(NumberSender);
	}


	SMS(string TextTitle, string  TextNamee, string NumberSender,string NumberSend) :MessageText(TextTitle, TextNamee)
	{
		setNumberSender(NumberSender);
		setNumberSend(NumberSend);

	}



	void setNumberSender(string NumberSender)
	{
		if (NumberSender == " ")
		{
			assert(!"Sender Number can not empty");
		}
		this->NumberSender = NumberSender;
	}

	void setNumberSend(string NumberSend)
	{
		if (NumberSend == " ")
		{
			assert(!"Number can not empty");
		}
		this->NumberSend = NumberSend;
	}

	string getNumSend()
	{
		return this->NumberSend;
	}
	string getNumSender()
	{
		return this->NumberSender;
	}




};

class Email :virtual public MessageText
{
public:
	string email;

	Email()
	{
		email = "*******@gmail.com";
	}

	Email(string TextTitle, string  TextNamee, string email) :MessageText(TextTitle, TextNamee)
	{
		setEmail(email);
	}
	Email(string email)
	{
		setEmail(email);
	}

	void setEmail(string email)
	{
		
		this->email = email;
	}

	

	string getEmail()
	{
		return this->email;
	}

};

class Service :public SMS, public Email
{
public:

	Service()
	{
		cout << "CHoice any service" << endl;
	}

	Service(string TextTitle, string TextNamee, string email) :Email(TextTitle, TextNamee, email)
	{

	}
	/*Service(string TextTitle, string TextNamee, string NumberSender) :SMS(TextTitle, TextNamee, NumberSender)
	{

	}
	Service(string TextTitle, string TextNamee, string email, string NumberSender) :Email(email), SMS(TextTitle, TextNamee, NumberSender)
	{

	}*/

	void print()
	{
		cout << "Message Text Info" << endl;
		cout << "Text Title: " << this->TextTitle << endl;
		cout << "Text Name: " << this->TextName << endl;
		cout << "Send number: " << this->NumberSend << endl;
		cout << "Sender number: " << this->NumberSender << endl;
		cout << "Sender number: " << this->NumberSender << endl;
		cout << "Email: " << this->email << endl;
	}
};


int main()
{
	Service s1("necesen?","NIhad","0555555");
	s1.print();
	
}