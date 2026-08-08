//
// Created by FFlyingFish on 8/2/26.
//

#ifndef QT6QMLAPP_CONTROLLS_H
#define QT6QMLAPP_CONTROLLS_H

#include <QObject>
#include <QtQml>
#include <QQuickWindow>
#include <QPixmap>
#include <QString>

namespace MTG_size_editer {
    class controlls : public QObject {
        Q_OBJECT
        QML_ELEMENT
        QML_NAMED_ELEMENT(Controlls)
    public:
        explicit controlls(QObject *parent = nullptr) : QObject(parent) {}

        Q_INVOKABLE bool logg(QObject *goober, int name);
        Q_INVOKABLE void setMultC(float multX, float multY);
        Q_INVOKABLE float getMultY();
        Q_INVOKABLE void setMultY(float mult);
        Q_INVOKABLE float getMultX();
        Q_INVOKABLE void setMultX(float mult);
        Q_INVOKABLE void stringToVec(QString s);
        Q_INVOKABLE int getDex();
        Q_INVOKABLE QString getImgByDex(int ig);
        Q_INVOKABLE void setCard();
        Q_INVOKABLE void skip(int i);
        Q_INVOKABLE void logger (QString s);
        Q_INVOKABLE void save(int x, int y, int wid, int hei,int dex, QString pic);
        Q_INVOKABLE int getPos(int dex, int wit);
        Q_INVOKABLE QString getPic(int dex);
        Q_INVOKABLE void exporter(int dex);


    public slots:
        // Q_INVOKABLE void update();

    private:
        float mult = 1.0f;
        QObject* m_qmlImage = nullptr;
    };
} // MTG_size_editer

#endif //QT6QMLAPP_CONTROLLS_H
