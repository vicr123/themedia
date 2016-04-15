#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
//#include <QMediaPlaylist>
//#include <QMediaPlayer>
#include "openmedia.h"
#include <phonon/MediaObject>
#include <phonon/AudioOutput>
#include <QFileDialog>
#include <QList>
#include <QListWidgetItem>
#include <QTime>
#include <QSystemTrayIcon>
#include <QPixmap>
#include <QDBusMessage>
#include <QDBusConnection>
#include <QMessageBox>
#include <QDBusInterface>
#include <QTimer>
#include <QMouseEvent>
#include <QProgressDialog>
#include <QThread>
#include <phonon/AbstractMediaStream>
#include <phonon/MediaController>
#include "cddbworker.h"

using namespace Phonon;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionOpen_Media_triggered();

    void on_player_stateChanged(Phonon::State newState);

    void on_player_tick(qint64 time);

    void updatePlaylist();

    void on_player_totalTimeChanged(qint64 time);

    void on_playPause_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_actionExit_triggered();

    void on_player_hasVideoChanged(bool hasVideo);

    void on_pushButton_3_clicked();

    void on_controller_titleChanged(int titleNumber);

    void on_controller_availableTitlesChanged(int availableTitles);

    void on_playlistWidget_itemClicked(QListWidgetItem *item);

    void on_dvdRootMenu_clicked();

    void on_dvdTitleMenu_clicked();

private:
    Ui::MainWindow *ui;

    QList<MediaSource> playlist;
    int currentPlaylist;

    MediaObject* player;
    MediaController* controller;

    QTimer* mouseTimer = NULL;
    QList<QMap<QString, QString>> cddbinfo;
    //QMediaPlaylist* playlist;
    //QMediaPlayer* player;

    bool eventFilter(QObject *, QEvent *event);
};

#endif // MAINWINDOW_H
