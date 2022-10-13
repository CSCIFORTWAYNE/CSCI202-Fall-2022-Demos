#include "customer.h"

using namespace std;

customer::customer(int id, string name, string address, string phone)
{
    this->name = name;
    this->id = id;
    this->address = address;
    this->phone = phone;
}
customer::customer(const customer& cpyCustomer)
{
	this->name = cpyCustomer.name;
	this->id = cpyCustomer.id;
	this->address = cpyCustomer.address;
	this->phone = cpyCustomer.phone;
}
string customer::str() const
{
    ostringstream out;
    out << "(" << this->id << ") " << this->name << endl
        << this->address << endl
        << this->phone << endl;
    return out.str();
}
customer::~customer()
{
}
void customer::setName(string name)
{
	this->name = name;
}
void customer::setId(int id)
{
	this->id = id;
}
void customer::setAddress(string address)
{
	this->address = address;
}
void customer::setPhone(string phone)
{
	this->phone = phone;
}
int customer::getId()
{
	return id;
}
string customer::getAddress()
{
	return address;
}
string customer::getPhone()
{
	return phone;
}
string customer::getName()
{
	return name;
}

bool customer::operator>(const customer& oth)
{
	return this->id > oth.id;
}
bool customer::operator<(const customer& oth)
{
	return this->id < oth.id;	
}
bool customer::operator>=(const customer& oth)
{
	return this->id >= oth.id;
}
bool customer::operator<=(const customer& oth)
{
	return this->id <= oth.id;
}
bool customer::operator==(const customer& oth)
{
	return this->id == oth.id;
}
bool customer::operator!=(const customer& oth)
{
	return this->id != oth.id;
}

ostream& operator<<(ostream& out, const customer& c)
{
	out << c.str();
	return out;
}