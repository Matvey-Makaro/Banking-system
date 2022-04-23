#include "user.h"

#include <utility>

User::User(QString login, QString password, QString name, QString surname, QString patronymic,
           QString phoneNumber, QString email, QString placeOfWork) :
    type(UserType::CLIENT), login(std::move(login)), password(std::move(password)),
    name(std::move(name)), surname(std::move(surname)), patronymic(std::move(patronymic)),
    phoneNumber(std::move(phoneNumber)), email(std::move(email)), placeOfWork(std::move(placeOfWork)), id(0)
{ }

UserType User::getType() const { return type; }
const QString& User::getLogin() const { return login; }
const QString& User::getPassword() const { return password; }
const QString& User::getName() const {return name; }
const QString& User::getSurname() const { return surname; }
const QString& User::getPatronymic() const { return patronymic; }
const QString& User::getPhoneNumber() const {return phoneNumber; }
const QString& User::getEmail() const { return email; }
const QString& User::getPlaceOfWork() const { return placeOfWork; }
const QString& User::getHashedPassword() const {return hashedPassword; }
void User::setHashedPassword(QString password) { hashedPassword = std::move(password); }
