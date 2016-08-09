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

#ifndef DISC_H
#define DISC_H
#include "dependency.h"
#include <string>
#include <list>
namespace raml {
    class Disc {
    public:
        Disc(std::string name, int year);
        void insert(raml::id3v1& tags);

        size_t size() {return songs.size(); }

        std::list<std::string> const getSongs() {return songs;}
    //protected:
        int year;
        std::string name;
        std::list<std::string> songs;
    };
}

#endif // DISC_H
