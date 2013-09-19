/*
 * Copyright (C) 2013 Canonical, Ltd.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; version 3.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * Authors: Michael Terry <michael.terry@canonical.com>
 */

#ifndef UNITY_ACCOUNTSSERVICE_H
#define UNITY_ACCOUNTSSERVICE_H

#include <QObject>
#include <QString>

class AccountsServiceDBusAdaptor;

class AccountsService: public QObject
{
    Q_OBJECT
    Q_PROPERTY (QString user
                READ getUser
                WRITE setUser
                NOTIFY userChanged)
    Q_PROPERTY (bool demoEdges
                READ getDemoEdges
                WRITE setDemoEdges
                NOTIFY demoEdgesChanged)
    Q_PROPERTY (QString backgroundFile
                READ getBackgroundFile
                NOTIFY backgroundFileChanged)
    Q_PROPERTY (bool statsWelcomeScreen
                READ statsWelcomeScreen
                NOTIFY statsWelcomeScreenChanged)

public:
    explicit AccountsService(QObject *parent = 0);

    QString getUser();
    void setUser(const QString &user);
    bool getDemoEdges();
    void setDemoEdges(bool demoEdges);
    QString getBackgroundFile();
    bool statsWelcomeScreen();

Q_SIGNALS:
    void userChanged();
    void demoEdgesChanged();
    void backgroundFileChanged();
    void statsWelcomeScreenChanged();

private Q_SLOTS:
    void propertiesChanged(const QString &user, const QString &interface, const QStringList &changed);
    void maybeChanged(const QString &user);

private:
    void updateDemoEdges();
    void updateBackgroundFile();
    void updateStatsWelcomeScreen();

    AccountsServiceDBusAdaptor *m_service;
    QString m_user;
    bool m_demoEdges;
    QString m_backgroundFile;
    bool m_statsWelcomeScreen;
};

#endif
