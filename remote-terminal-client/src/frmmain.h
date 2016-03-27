// This application is under GNU GPLv3. Please read the COPYING.txt file for further terms and conditions of the license.
// Copyright © 2016 Matthew James 
// "Remote Terminal" is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
// "Remote Terminal" is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
// You should have received a copy of the GNU General Public License along with "Remote Terminal". If not, see http://www.gnu.org/licenses/.

#ifndef FRMMAIN_H
#define FRMMAIN_H

#include <QMainWindow>
#include <QString>
#include <QTimer>
#include <QKeyEvent>
#include <QDesktopServices>
#include <QSettings>
#include "client.h"
#include "crypto.h"
#include "frmabout.h"

namespace Ui {
    class frmMain;
}

class frmMain : public QMainWindow
{
    Q_OBJECT

public:
    explicit frmMain(QWidget *parent = 0);
    ~frmMain();

public slots:
    void ClearLog();
    void keyPressEvent(QKeyEvent* pe);
    void moveEvent(QMoveEvent*);
    void resizeEvent(QResizeEvent*);
    void closeEvent(QCloseEvent*);
    void LoadWindowSettings();
    void SaveWindowSettings();
    void txtCommand_textChanged();
    void itemAboutRemoteTerminal();
    void itemViewWebsite();
    void btnConnect_click();
    void CloseApplication();
    void Connect();
    void Disconnect();
    void SendCommands();
    void CheckMessages();

private:
    Ui::frmMain *ui;
    Crypto *crypto;
    frmAbout *aboutForm;
    QTimer message_timer; // Message check timer
    QStringList commands;
    int command_index;
};

#endif // FRMMAIN_H
