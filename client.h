#pragma once

#include "iclient.h"
#include "ibank.h"
#include "account.h"
#include "deposit.h"

#include <QString>
#include <memory>
#include <QSqlQueryModel>

class Client : public IClient
{
public:
    Client(int id, QString name, QString surname, QString patronymic, QString phoneNumber, QString email, QString passport, bool fromRB, std::shared_ptr<IBank> bank);
    virtual int getId() const override { return id; }
    virtual const QString& getName() const override { return name; }
    virtual const QString& getSurname() const override { return surname; }
    virtual const QString& getPatronymic() const override { return patronymic; }
    virtual const QString& getPhoneNumber() const override { return phoneNumber; }
    virtual const QString& getEmail() const override { return email; }
    virtual const QString& getPassport() const override { return passport; }
    virtual bool isFromRB() const override { return fromRB; }

    virtual QSqlQueryModel& getAccountQueryModel() const override;
    virtual void updateAccountQueryModel() const override;
    virtual void openAccount() override;
    virtual void closeAccount(int accountId) override;
    virtual Account getAccount(int accountId) override;
    virtual void putMoneyOnAccount(int accountId, double sum) override;
    virtual void withdrawMoneyFromAccount(int accountId, double sum) override;
    virtual void transferMoney(int srcAccountId, int dstAccountId, double sum) override;
    virtual void openDeposit(int term, double sum) override;
    virtual QSqlQueryModel& getDepositQueryModel() const override;
    virtual void updateDepositQueryModel() const override;
    virtual Deposit getDeposit(int depositId) override;

    virtual ~Client() = default;

private:
    int id;
    QString name;
    QString surname;
    QString patronymic;
    QString phoneNumber;
    QString email;
    QString passport;
    bool fromRB;
    std::shared_ptr<IBank> currentBank;
};

