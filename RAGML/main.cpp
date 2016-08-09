/**This file is part of RAGML.

Foobar is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

Foobar is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with RAGML.  If not, see <http://www.gnu.org/licenses/>.

Author: Cristian Rodríguez Bernal (maldicion069)
*/

#include <iostream>
#include <fstream>
#include <QFile>
#include <QDir>
#include <QDirIterator>
#include "library.h"
#include "Dependency.h"
using namespace std;

void scanDir(QDir dir, QDirIterator::IteratorFlags flags) {
    QDirIterator iterator(dir.absolutePath(), flags);

    QString actDir = dir.absolutePath() + QString("/");
    bool error;

    std::cout << dir.absolutePath().toUtf8().constData() << std::endl;

    while (iterator.hasNext()) {
        iterator.next();
        if (iterator.fileInfo().isDir()) {
            QString filename = iterator.fileName();
            if((filename.compare(".") != 0) && (filename.compare("..") != 0)) {
                std::cout << filename.toUtf8().constData() << std::endl;
                actDir = iterator.filePath() + QString("/");
            }
        } else {
            std::string path = (actDir + iterator.fileName()).toUtf8().constData();
            QFile f(QString(path.c_str()));
            raml::id3v1 tag = raml::getTags(path, error);
            if(!error) {
                QString name = actDir + QString(tag.artist) + QString(" - ") + QString(tag.title) + QString(".mp3");
                std::cout << "\t" << iterator.fileName().toUtf8().constData() << ": " << f.rename(name) << std::endl;
            }
        }
    }
}

int main(int argc, char *argv[]) {
    QDir dir;
    std::string htmlroute = "C:/";
    auto flag = QDirIterator::NoIteratorFlags;
    if(argc >= 2) { //Only path
        if(argc == 2) {
            dir.setPath(QString(argv[1]));
        }
        if (argc == 3) {
            htmlroute = argv[2];
        }
        if (argc == 4) {
            if(strcmp(argv[3], "-d") == 0) {
                flag = QDirIterator::Subdirectories;
            }
        }
    } else {
        dir.setPath(QString("D:/DISCOS TERMINADOS"));
    }
    std::cout << std::boolalpha;    // Activate boolean writing

    //scanDir(dir, flag);

    raml::Library library;
    library.init(dir, flag);

    std::cout << library.size() << std::endl;

    library.generateHTML(htmlroute);

    std::cout << raml::genre[17] << "\t" << raml::genre[24] << std::endl;

    std::cout << "END" << std::endl;
    return 0;
}
