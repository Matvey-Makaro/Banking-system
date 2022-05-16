#include "client_accounts_presenter.h"

ClientAccountsPresenter::ClientAccountsPresenter(std::shared_ptr<IClient> client, QObject *parent) :
    client(client) ,clientAccountsView(std::make_shared<ClientAccountsView>(this)) , QObject(parent)
{
    connect(clientAccountsView->getOpenAccountBtn(), SIGNAL(clicked()), this, SLOT(openAccount()));
    connect(clientAccountsView->getCloseAccountBtn(), SIGNAL(clicked()), this, SLOT(closeAccount()));
    connect(clientAccountsView->getWithdrawBtn(), SIGNAL(clicked()), this, SLOT(withdrawMoney()));
    connect(clientAccountsView->getTransferBtn(), SIGNAL(clicked()), this, SLOT(transferMoney()));
    connect(clientAccountsView->getPutMoneyBtn(), SIGNAL(clicked()), this, SLOT(putMoney()));
    connect(clientAccountsView->getShowAccInfoBtn(), SIGNAL(clicked()), this, SLOT(showAccountInfo()));
    connect(this, SIGNAL(showAccountInfo(QString)), clientAccountsView.get(), SLOT(showAccountInfo(QString)));
    clientAccountsView->show();
}

QSqlQueryModel &ClientAccountsPresenter::getAccountsQueryModel() const
{
    return client->getAccountQueryModel();
}

void ClientAccountsPresenter::openAccount()
{
    qDebug() << "Open account.\n";
    client->openAccount();
    client->updateAccountQueryModel();
}

void ClientAccountsPresenter::closeAccount()
{
    qDebug() << "Close account.\n";
    client->closeAccount(clientAccountsView->getIdOfSelectedAccount());
    client->updateAccountQueryModel();

}

void ClientAccountsPresenter::showAccountInfo()
{
    qDebug() << "Show account info.\n";
    emit showAccountInfo(client->getAccount(clientAccountsView->getIdOfSelectedAccount()).getInfo());
}

void ClientAccountsPresenter::putMoney()
{
    qDebug() << "Put money.\n";
    double sum = clientAccountsView->getPutMoneyFromClient();
    client->putMoneyOnAccount(clientAccountsView->getIdOfSelectedAccount(), sum);
}

void ClientAccountsPresenter::withdrawMoney()
{
    qDebug() << "Withdraw money.\n";
}

void ClientAccountsPresenter::transferMoney()
{
    qDebug() << "Transfer money.\n";
}

void ClientAccountsPresenter::changeCurrentAccountId(QListWidgetItem *listItem)
{
    qDebug() << "Change current account id(Еще не знаю зачем это).\n";
}
