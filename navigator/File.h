#ifndef NAV_FILE_H
#define NAV_FILE_H

#include <QList>
#include <QString>
#include <cassert>
#include <string>
#include <utility>
#include <vector>

#include "FolderItem.h"
//#include "Misc.h"

namespace Nav {

class File : public FolderItem
{
    friend class FileManager;

private:
    File(Folder *parent, const QString &path);

public:
    Folder *parent() { return m_parent; }
    bool isFolder() { return false; }
    File *asFile() { return this; }
    QString path();
    QString title();

    QString content() {
        ensureLoaded();
        return m_content;
    }

    int lineCount() {
        ensureLoaded();
        return m_lines.size();
    }

    // 0-based line number
    int lineStart(int line) {
        ensureLoaded();
        assert(line < lineCount());
        return m_lines[line].first;
    }

    // 0-based line number
    int lineLength(int line) {
        ensureLoaded();
        assert(line < lineCount());
        return m_lines[line].second;
    }

    // 0-based line number
    QStringRef lineContent(int line) {
        ensureLoaded();
        return QStringRef(&m_content, lineStart(line), lineLength(line));
    }

private:
    void loadFile();

    void ensureLoaded() {
        if (!m_loaded)
            loadFile();
    }

    Folder *m_parent;
    QString m_path;
    bool m_loaded;
    QString m_content;
    std::vector<std::pair<int, int> > m_lines;
};

} // namespace Nav

#endif // NAV_FILE_H
