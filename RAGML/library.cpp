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

#include "library.h"
#include "Dependency.h"
#include <iostream>

namespace raml {
    Library::Library() {
    }

    void Library::init(QDir route, QDirIterator::IteratorFlags flags) {
        QDirIterator iterator(route.absolutePath(), flags);

        QString actDir = route.absolutePath() + QString("/");
        bool error;

        std::cout << route.absolutePath().toUtf8().constData() << std::endl;

        while (iterator.hasNext()) {
            iterator.next();
            if (iterator.fileInfo().isDir()) {
                QString filename = iterator.fileName();
                if((filename.compare(".") != 0) && (filename.compare("..") != 0)) {
                    //std::cout << filename.toUtf8().constData() << std::endl;
                    actDir = iterator.filePath() + QString("/");
                }
            } else {
                std::string path = (actDir + iterator.fileName()).toUtf8().constData();
                QFile f(QString(path.c_str()));
                id3v1 tag = getTags(path, error);
                if(!error) {
                    std::string artist = tag.artist;
                    if(artist.empty()) {
                        artist = "Unknown";
                    }
                    artist = remove_spaces(artist);
                    raml::Band* band = library[artist];
                    if(band == NULL) {
                        std::string style;
                        int si = (int)tag.genre;
                        if(si >= 0 && si < 256) {
                            style = genre[si];
                        } else {
                            style = "Unknown";
                        }
                        band = new raml::Band(artist, style);
                        std::cout << "Creo banda " << band->name << "\t" << tag.title << std::endl;
                    }
                    band->insert(tag);
                    library[artist] = band;
                }
            }
        }
    }


    raml::Band* Library::operator[](std::string band) {
        return library[band];
    }

    void Library::generateHTML(std::string route) {
        foreach (auto& kv, library) {
            std::ofstream ofs(route + "/" + kv.first + ".html");
            ofs << "<h1>" << kv.second->name << "</h1>" << std::endl;
            ofs << "<p>Estilo: " << kv.second->style << "</p>";
            std::cout << "D:/library/" + kv.first + ".html" << std::endl;
            kv.second->generateHTML(ofs);
            ofs.close();
        }
    }

    size_t Library::size() {
        return library.size();
    }
}
