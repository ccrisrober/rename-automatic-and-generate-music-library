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

#ifndef LIBRARY_H
#define LIBRARY_H

#include <unordered_map>
#include "band.h"
#include <QDir>
#include <QDirIterator>
#include <string>

namespace raml {
    class Library {
        public:
            Library();
            void init(QDir route, QDirIterator::IteratorFlags flags);

            raml::Band* operator[](std::string band);

            void generateHTML(std::string route);

            size_t size();

        protected:
            std::unordered_map<std::string, raml::Band*> library;
    };
}

#endif // LIBRARY_H
