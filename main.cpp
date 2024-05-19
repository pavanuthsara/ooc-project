#include <iostream>
#include <string>
using namespace std;

// Payment class 
class Payment {
private:
    int paymentId;
    float amount;
    string paymentDetails;
public:
    Payment();
    Payment(int pid, float pamount, string pdetails);
    void displayPaymentDetails();
    ~Payment();
};

Payment::Payment() {
    paymentId = 0;
    amount = 0;
    paymentDetails = "";
}
Payment::Payment(int pid, float pamount, string pdetails) {
    paymentId = pid;
    amount = pamount;
    paymentDetails = pdetails;
}
void Payment::displayPaymentDetails() {}
Payment::~Payment() {}

// Feedback class
class Feedback {
private:
    string description;
    int rating;
public:
    Feedback();
    Feedback(string desc, int rate);
    void addFeedback(string desc, int rate);
    void displayFeedback();
    ~Feedback();
};

Feedback::Feedback() {
    description = "";
    rating = 0;
}

Feedback::Feedback(string desc, int rate) {
    description = desc;
    rating = rate;
}

void Feedback::addFeedback(string desc, int rate) {}
void Feedback::displayFeedback() {}
Feedback::~Feedback() {}

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
    ~User();
};

void User::contactAgent() {}

User::User() {
    cout << "User constructor" << endl;
}

User::~User() {
    cout << "User destructor called" << endl;
}

// Derived class UnregisteredUser
class UnregisteredUser : public User {
public:
    UnregisteredUser();
    void registerInSystem();
    ~UnregisteredUser();
};

UnregisteredUser::UnregisteredUser() {
    cout << "UnregisteredUser constructor called" << endl;
}

void UnregisteredUser::registerInSystem() {}
UnregisteredUser::~UnregisteredUser() {}

// Derived class RegisteredUser
class RegisteredUser : public User {
private:
    string name;
    string email;
    string address;
    Plan* cplan; //association relationship with plan
    Feedback* fb[SIZE]; //aggregation relationship with feedback
    Claim* cl[SIZE]; //composisiton relationship with claim
    Payment* pym[SIZE]; //aggregation relationship with payment

public:
    RegisteredUser();
    RegisteredUser(string pname, string pemail, string paddress);
    RegisteredUser(string des1, float a1, string st1, string des2, float a2, string st2);
    void logIn();
    void deactivateAccount();
    void selectPlan(Plan* cplan);
    void addFeedback(Feedback* fb1, Feedback* fb2);
    void makePayment(Payment* pym1, Payment* pym2);
    ~RegisteredUser();
};

RegisteredUser::RegisteredUser() {
    name = "";
    email = "";
    address = "";
    cl[0] = new Claim("", 0, "");
    cl[1] = new Claim("", 0, "");
}

RegisteredUser::RegisteredUser(string pname, string pemail, string paddress) {
    name = pname;
    email = pemail;
    address = paddress;
}

RegisteredUser::RegisteredUser(string des1, float a1, string st1, string des2, float a2, string st2) {
    cl[0] = new Claim(des1, a1, st1);
    cl[1] = new Claim(des2, a2, st2);
}

void RegisteredUser::logIn() {}
void RegisteredUser::deactivateAccount() {}
void RegisteredUser::selectPlan(Plan* cplan) {}

void RegisteredUser::addFeedback(Feedback* fb1, Feedback* fb2) {
    fb[0] = fb1;
    fb[1] = fb2;
}

void RegisteredUser::makePayment(Payment* pym1, Payment* pym2) {
    pym[0] = pym1;
    pym[1] = pym2;
}

RegisteredUser::~RegisteredUser() {
    cout << "RegisteredUser Destructor called" << endl;
}

//Report class
class Report {
private:
    string reportName;
    string reportDescription;
public:
    Report();
    Report(string pname, string pdes);
    void setReportDetails();
    void displayReportDetails();
    ~Report();
};

Report::Report() {
    cout << "Report default constructor called" << endl;
}

Report::Report(string pname, string pdes) {
    reportName = pname;
    reportDescription = pdes;
}

void Report::setReportDetails() {}
void Report::displayReportDetails() {}
Report::~Report() {}



//Employee class
class Employee {
private:
    string name;
    string email;
    float salary;
    Report* rep;
public:
    Employee();
    Employee(string ename, string empemail, float esalary, Report *r);
    void setDetails(string pname, string pemail, float psalary);
    void displayDetails();
    void replayMessages();
    ~Employee();
};
Employee::Employee() {
    cout << "Employee constructor called" << endl;
}

Employee::Employee(string ename, string empemail, float esalary, Report *r){
    name = ename;
    email = empemail;
    salary = esalary;
    rep = r;
}

void Employee::setDetails(string pname, string pemail, float psalary) {}
void Employee::displayDetails() {}
void Employee::replayMessages() {}
Employee::~Employee() {}

//Complaint class
class Complaint {
private:
    Employee* emp;
    int compId;
    string type;
    string description;
    string status;

public:
    Complaint();
    Complaint(string complaintType, string complaintDescription,string complaintStatus);
    Complaint(int cmd, Employee* e);
    Complaint(int cmd);
    void setComplaint(string complaint);
    void resolveComplaint();
};

Complaint::Complaint(){
    cout << "Complaint constructor called" << endl;
}

Complaint::Complaint(string complaintType, string complaintDescription, string complaintStatus){
}
void Complaint::setComplaint(string complaint) {}
void Complaint::resolveComplaint(){}

Complaint::Complaint(int cmd, Employee* e){
    compId = cmd;
    emp = e;
}

Complaint::Complaint(int cmd){
    compId = cmd;
}

// Claim class
class Claim {
private:
    string description;
    float amount;
    string status;
public:
    Claim();
    Claim(string pdes, float pamount, string pstatus);
    void requestClaim();
    void approveClaimRequest();
    void disapproveClaimRequest();
    ~Claim();

};

Claim::Claim() {
    description = "";
    amount = 0;
    status = "";
};

Claim::Claim(string pdes, float pamount, string pstatus) {
    description = pdes;
    amount = pamount;
    status = pstatus;
}

void Claim::requestClaim() {}
void Claim::approveClaimRequest() {}
void Claim::disapproveClaimRequest() {}

Claim::~Claim() {
    cout << "Deleting Claim" << endl;
}

int main()
{
    PlanEmergency pe1;
    PlanFamily pf1;
    PlanChildren pc1;

    UnregisteredUser unregUser1;
    RegisteredUser* regUser1 = new RegisteredUser("Kamal", "kamal@mail.com", "address1");
    RegisteredUser* regUser2 = new RegisteredUser("Nimal", "nimal@mail.com", "address2");

    //make report objects
    Report* rep1 = new Report("Report 1", "Report description 1");
    Report* rep2 = new Report("Report 2", "Report description 2");

    //make Employee objects
    //make complaint objects
    //Complaint *cmp1 = new Complaint
    
    //make feedback objects
    Feedback* fb1 = new Feedback("Good service", 5);
    Feedback* fb2 = new Feedback("Good customer care", 5);
   
    //make claim objects
    Claim* cl1 = new Claim("Claim 1", 12000, "Pending");
    Claim* cl1 = new Claim("Claim 2", 13000, "Approved");

    //make payment objects
    Payment* p1 = new Payment(1, 12000, "Payment for 2023");
    Payment* p2 = new Payment(2, 11500, "Payment for 2024");

    return 0;
}

