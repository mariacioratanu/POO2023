#include <iostream>
#include <string>
#include <vector>

// I preferred to keep the code in a single file instead of the usual separation into classes, headers, and cpp files. I hope it is ok.

// Enumeration for contact types
enum class ContactType
{
    Friend,
    Acquaintance,
    Colleague
};

// Abstract base class Contact
class Contact
{
public:
    Contact(const std::string& name) : name(name) {} // Constructor initializes the name of the contact
    virtual ~Contact() {} // Virtual destructor to ensure proper destruction of derived objects
    virtual void printDetails() const = 0; // Pure virtual function that must be implemented by derived classes
    const std::string& getName() const
    { // Getter function for the name of the contact
        return name;
    }

protected:
    std::string name; // Protected member variable for the name of the contact
};



// Derived class Friend
class Friend : public Contact
{
public:
   Friend(const std::string& name, const std::string& birthday, const std::string& phoneNumber, const std::string& address)
        : Contact(name), type(ContactType::Friend), birthday(birthday), phoneNumber(phoneNumber), address(address) {} // Constructor initializes the base class and additional member variables specific to Friend
    void printDetails() const override
    { // Overrides the virtual function to print Friend-specific details
        std::cout << "Friend - Name: " << name << ", Birthday: " << birthday << ", Phone Number: " << phoneNumber << ", Address: " << address << std::endl;
    }

private:
    std::string birthday;
    std::string phoneNumber;
    std::string address;
    ContactType type;  // Adaugã membrul type
};

// Derived class Acquaintance
class Acquaintance : public Contact
{
public:
   Acquaintance(const std::string& name, const std::string& phoneNumber)
        : Contact(name), type(ContactType::Acquaintance), phoneNumber(phoneNumber) {} // Constructor initializes the base class and additional member variables specific to Acquaintance

    void printDetails() const override
    { // Overrides the virtual function to print Acquaintance-specific details
        std::cout << "Acquaintance - Name: " << name << ", Phone Number: " << phoneNumber << std::endl;
    }

private:
    std::string phoneNumber;
    ContactType type;  // Adaugã membrul type
};

// Derived class Colleague
class Colleague : public Contact
{
public:
    Colleague(const std::string& name, const std::string& phoneNumber, const std::string& company, const std::string& address)
        : Contact(name), type(ContactType::Colleague), phoneNumber(phoneNumber), company(company), address(address) {} // Constructor initializes the base class and additional member variables specific to Colleague

    void printDetails() const override
    { // Overrides the virtual function to print Colleague-specific details
        std::cout << "Colleague - Name: " << name << ", Phone Number: " << phoneNumber << ", Company: " << company << ", Address: " << address << std::endl;
    }

private:
    std::string phoneNumber;
    std::string company;
    std::string address;
    ContactType type;  // Adaugã membrul type
};

// Class Agenda
class Agenda {
public:
    void addContact(Contact* contact)
    { // Adds a contact to the agenda
        contacts.push_back(contact);
    }

    Contact* findContact(const std::string& name) const
    { // Finds a contact in the agenda by name
        for (const auto& contact : contacts)
        {
            if (contact->getName() == name)
            {
                return contact;
            }
        }
        return nullptr;
    }

    std::vector<Contact*> getFriends() const
    { // Retrieves a list of contacts that are friends
        std::vector<Contact*> friends;
        for (const auto& contact : contacts)
        {
            if (dynamic_cast<Friend*>(contact))
            { // Checks if the contact is of type Friend
                friends.push_back(contact);
            }
        }
        return friends;
    }

    void removeContact(const std::string& name)
    { // Removes a contact from the agenda by name
        auto it = contacts.begin();
        while (it != contacts.end())
        {
            if ((*it)->getName() == name)
            {
                delete *it;
                it = contacts.erase(it);
            } else
            {
                ++it;
            }
        }
    }

    ~Agenda() { // Destructor to properly clean up the dynamically allocated contacts
        for (const auto& contact : contacts)
        {
            delete contact;
        }
    }

private:
    std::vector<Contact*> contacts; // Vector to store the contacts in the agenda
};

int main()
{
    Agenda agenda;

    Contact* friend1 = new Friend("Brad Pitt", "1980-01-01", "123456789", "123 Main St"); // Creating a Friend object with specific details
    Contact* friend2 = new Friend("Angelina Jolie", "1990-05-10", "987654321", "456 Elm St"); // Creating another Friend object with specific details
    Contact* acquaintance1 = new Acquaintance("Leonardo DiCaprio", "555555555"); // Creating an Acquaintance object with specific details
    Contact* acquaintance2 = new Acquaintance("Jennifer Lawrence", "777777777");
    Contact* colleague1 = new Colleague("Tom Hanks", "999999999", "ABC Company", "789 Oak Ave"); // Creating a Colleague object with specific details
    Contact* colleague2 = new Colleague("Dwayne Johnson", "111111111", "XYZ Corporation", "321 Maple St");

    agenda.addContact(friend1); // Adding the contacts to the agenda
    agenda.addContact(friend2);
    agenda.addContact(acquaintance1);
    agenda.addContact(acquaintance2);
    agenda.addContact(colleague1);
    agenda.addContact(colleague2);

    Contact* foundContact1 = agenda.findContact("Jennifer Lawrence"); // Finding a contact by name
    if (foundContact1)
    {
        foundContact1->printDetails(); // Printing the details of the found contact
    } else
    {
        std::cout << "Contact not found." << std::endl;
    }

    Contact* foundContact2 = agenda.findContact("Tom Hanks"); // Finding another contact by name
    if (foundContact2)
    {
        foundContact2->printDetails(); // Printing the details of the found contact
    } else
    {
        std::cout << "Contact not found." << std::endl;
    }

    std::vector<Contact*> friends = agenda.getFriends(); // Getting a list of friends from the agenda
    std::cout << "Friends:" << std::endl;
    for (const auto& friendContact : friends)
    {
        friendContact->printDetails(); // Printing the details of each friend
    }

    std::cout << "Removing contact: Dwayne Johnson" << std::endl;
    agenda.removeContact("Dwayne Johnson"); // Removing a contact from the agenda

    delete friend1; // Deleting the dynamically allocated objects
    delete friend2;
    delete acquaintance1;
    delete acquaintance2;
    delete colleague1;
    delete colleague2;

    return 0;
}
