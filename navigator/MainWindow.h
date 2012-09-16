#ifndef NAV_MAINWINDOW_H
#define NAV_MAINWINDOW_H

#include <QFontMetricsF>
#include <QMainWindow>
#include <QMap>
#include <QSplitter>
#include <QTreeView>

#include "History.h"
#include "TextWidthCalculator.h"

namespace Nav {

namespace Ui {
class MainWindow;
}

class File;
class FolderWidget;
class MainWindow;
class Project;
class Ref;
class SourceWidget;

extern MainWindow *theMainWindow;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(Project &project, QWidget *parent = 0);
    ~MainWindow();
    History::Location currentLocation();
    void navigateToFile(File *file);
    void navigateToRef(const Ref &ref);

private slots:
    void actionViewFileList();
    void actionOpenGotoWindow();
    void actionBack();
    void actionForward();
    void sourceWidgetFileChanged(File *file);
    void folderWidgetSelectionChanged();
    void areBackAndForwardEnabled(bool &backEnabled, bool &forwardEnabled);
    void actionCopyFilePath();
    void actionRevealInSideBar();


protected:
    void closeEvent(QCloseEvent *event);

private:
    History m_history;
    Ui::MainWindow *ui;
    QSplitter *m_splitter;
    FolderWidget *m_folderWidget;
    SourceWidget *m_sourceWidget;
};

} // namespace Nav

#endif // NAV_MAINWINDOW_H
