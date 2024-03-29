#ifndef STARTSCENE_H
#define STARTSCENE_H

#include "button.h"
#include "pixmap.h"
#include "server.h"

#include <QGraphicsScene>
#include <QAction>
#include <QTextEdit>

class StartScene: public QGraphicsScene{
    Q_OBJECT

public:
    StartScene();
    void addButton(QAction *action);
    void setServerLogBackground();
    void switchToServer(Server *server);

private:
    void printServerInfo();

    //背景logo
    Pixmap *logo;
    QTextEdit *server_log;
    //当前启动画面的button
    QList<Button*> buttons;
};

#endif // STARTSCENE_H
