#pragma once
#include <string>

class Employee {
private:
    const std::string name;
    bool busy;
    bool forkliftCertificate;

public:
    Employee(const std::string& empName, bool hasCertificate);

    std::string getName() const;
    bool getBusy() const;
    void setBusy(bool isBusy);
    bool getForkliftCertificate() const;
    void setForkliftCertificate(bool hasCertificate);
};