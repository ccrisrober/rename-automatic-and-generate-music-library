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

#include "disc.h"

namespace raml {
    Disc::Disc(std::string name, int year) {
        this->name = name;
        this->year = year;
    }

    void Disc::insert(id3v1 &tags) {
        std::string title = tags.title;
        if(title.empty()) {
            title = "Unknown";
        }
        title = raml::remove_spaces(title);
        songs.push_back(title);
    }

}
