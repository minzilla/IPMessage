// This file is part of QIpMsg.
//
// QIpMsg is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// QIpMsg is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with QIpMsg.  If not, see <http://www.gnu.org/licenses/>.
//

#ifndef SYSTRAY_H
#define SYSTRAY_H

#include <QObject>
#include <QMap>
#include <QList>
#include <QTimer>
#include <QSystemTrayIcon>
#include "msg_window.h"
#include "chat_window.h"
#include "msg.h"

class QAction;
class QMenu;
class QActionGroup;
class QIcon;

class MainWindow;

class Systray : public QObject
{
    Q_OBJECT

public:
    Systray(QObject *parent = 0);
    ~Systray();

    void show();

    QList<MainWindow *> mainWindowList;

    //icon twinkle
    void notifyMessage(ChatWindow* pw = NULL);
    void clearNotify();

protected:
    void timerEvent(QTimerEvent *event);

private slots:
    void updateToolTip(int i);
    void updateTransferCount(int);
    void twinkleIcon();

private slots:
    void trayIconActivated(QSystemTrayIcon::ActivationReason reason);
    void setup();
    void about();
    void quit();
    void readLog();
    void setAllWindowVisible();
    void showTransferFile();
    void showUser();

private:
    void createActions();
    void createLeaveMenu();
    void createMenus();
    void createIconSet();
    void createConnections();

    void createMainWindow();
    void destroyMainWindowList();
    void visibleAllMainWindow();

    QAction *showTransferFileAction;
    QAction *delAckWindowAction;
    QAction *topWindowAction;
    QAction *setupAction;
    QAction *aboutAction;
    QAction *aboutQtAction;
    QAction *readMsgLogAction;
    QMenu *leaveMenu;
    QAction *quitAction;

    //add by wallace young for ubuntu 11.04+
    QAction *showUserListAction;

    QActionGroup *leaveActionGroup;
    QSystemTrayIcon *trayIcon;
    QMenu *trayIconMenu;

    QString m_iconKey;
    QTimer *m_timer;
};

#endif // !SYSTRAY_H

