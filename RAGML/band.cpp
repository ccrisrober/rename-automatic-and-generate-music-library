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

#include "band.h"
#include <fstream>
namespace raml {
    Band::Band(std::string name, std::string style) {
        this->name = name;
        this->style = style;
    }

    void Band::insert(id3v1 &tags) {
        std::string album = tags.album;
        if(album.empty()) {
            album = "Unknown";
        }
        album = remove_spaces(album);
        raml::Disc* disc = bandDiscs[album];
        if(disc == NULL) {
            disc = new raml::Disc(album, atoi(tags.year));
        }
        disc->insert(tags);
        bandDiscs[album] = disc;
    }

    void Band::generateHTML(std::ofstream& ofs) {
       for(auto it = bandDiscs.begin(); it != bandDiscs.end(); ++it) {
            ofs << "<h2>" << it->second->name << " (" << it->second->year << ")" << "</h2>" << std::endl;
            std::list<std::string> songs = it->second->getSongs();
            ofs << "<ul>";
            for(auto it2 = songs.begin(); it2 != songs.end(); ++it2) {
                ofs << "<li>" << *it2 << "</li>";
            }
            ofs << "</ul>";
        }
    }
}
