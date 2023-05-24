#include "include/employee.hpp"

Employee::Employee(const std::string& empName, bool hasCertificate)
    : name(empName), busy(false), forkliftCertificate(hasCertificate) {}

std::string Employee::getName() const {
    return name;
}

bool Employee::getBusy() const {
    return busy;
}

void Employee::setBusy(bool isBusy) {
    busy = isBusy;
}

bool Employee::getForkliftCertificate() const {
    return forkliftCertificate;
}

void Employee::setForkliftCertificate(bool hasCertificate) {
    forkliftCertificate = hasCertificate;
}
