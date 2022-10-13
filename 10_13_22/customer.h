#include <string>
#include <sstream>

using namespace std;

class customer
{
private:
    string name;
    int id;
    string address;
    string phone;
	string str() const;
public:
    customer(int id, string name,string address, string phone);
	customer(const customer&);
	void setName(string name);
	void setId(int id);
	void setAddress(string address);
	void setPhone(string phone);
	int getId();
	string getAddress();
	string getPhone();
	string getName();
	bool operator>(const customer&);
	bool operator<(const customer&);
	bool operator>=(const customer&);
	bool operator<=(const customer&);
	bool operator==(const customer&);
	bool operator!=(const customer&);
    friend ostream& operator<<(ostream&, const customer&);
    ~customer();
};