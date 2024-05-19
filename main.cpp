#include <iostream>
using namespace std;

// Base class Plan
#define SIZE 2
class Plan {
protected:
    int planId;
    float coverageLimit;
    string privacyPolicy;
public:
    Plan();
    Plan(int planId, float cLimit, string PP); //overloaded constructor
    void setDetails();
    void getDetails();
    void updateLimit();
    void updatePrivacyPolicy();
    RegisteredUser* users[SIZE]; // one plan use by many users
    ~Plan();
};

// Plan constructor
Plan::Plan(){
    planId = 0;
    coverageLimit = 0;
    privacyPolicy = "Privacy policy for Plan";
    cout << "Plan constructor" << endl;
}

Plan::Plan(int cplanId, float cLimit, string PP) {
    planId = cplanId;
    coverageLimit = cLimit;
    privacyPolicy = PP;
}

// Plan destructor
Plan::~Plan() {
    cout << "Plan Destructor called" << endl;
}

void Plan::setDetails() {}
void Plan::getDetails() {}
void Plan::updateLimit() {}
void Plan::updatePrivacyPolicy() {}

// Derived class PlanEmergency
class PlanEmergency : public Plan{
public:
    PlanEmergency();
};

PlanEmergency::PlanEmergency(){
    planId = 0;
    coverageLimit = 0;
    privacyPolicy = "Privacy policy for Plan Emergency";
    cout << "Plan emergency constructor" << endl;
}

// Derived class PlanFamily
class PlanFamily : public Plan {
public:
    PlanFamily();
};

PlanFamily::PlanFamily() {
    planId = 0;
    coverageLimit = 0;
    privacyPolicy = "Privacy policy for Plan Family";
    cout << "Plan family constructor" << endl;
}

// Derived class PlanChildren
class PlanChildren : public Plan{
private:
    int ageLimit;
public:
    PlanChildren();
    PlanChildren(int cplanId, float cLimit, string PP, int cAge) : Plan(cplanId, cLimit, PP) {}; //overloaded constructor
};

PlanChildren::PlanChildren() {
    planId = 0;
    ageLimit = 0;
    coverageLimit = 0;
    privacyPolicy = "Privacy policy for Plan Children";
    cout << "Plan children constructor" << endl;
}

PlanChildren::PlanChildren(int cplanId, float cLimit, string PP, int cAge) : Plan(cplanId, cLimit, PP) {
    planId = cplanId;
    ageLimit = cLimit;
    privacyPolicy = PP;
    ageLimit = cAge;
}

// Base class User
class User {
public:
    User();
    void contactAgent();
};

void User::contactAgent() {}

User::User() {
    cout << "User constructor" << endl;
}

// Derived class UnregisteredUser
class UnregisteredUser : public User {
public:
    void registerInSystem();
};

void UnregisteredUser::registerInSystem() {}

// Derived class RegisteredUser
class RegisteredUser : public User {
private:
    string name;
    string email;
    string address;
    Plan* cplan; //association relationship with plan

public:
    RegisteredUser();
    RegisteredUser(string pname, string pemail, string paddress); 
    void logIn();
    void deactivateAccount();
    void selectPlan(Plan* cplan);
    ~RegisteredUser();
};

RegisteredUser::RegisteredUser() {
    name = "";
    email = "";
    address = "";
}

RegisteredUser::RegisteredUser(string pname, string pemail, string paddress) {
    name = pname;
    email = pemail;
    address = paddress;
}

RegisteredUser::~RegisteredUser() {
    cout << "RegisteredUser Destructor called" << endl;
}

void RegisteredUser::logIn() {};
void RegisteredUser::deactivateAccount() {};
void RegisteredUser::selectPlan(Plan* cplan) {};

int main()
{
    PlanEmergency pe1;
    PlanFamily pf1;
    PlanChildren pc1;

    UnregisteredUser unregUser1;
    RegisteredUser regUser1;

    return 0;
}

