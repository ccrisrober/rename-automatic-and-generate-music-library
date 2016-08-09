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

#ifndef DEPENDENCY_H
#define DEPENDENCY_H

#include <fstream>
#include <iostream>
using namespace std;

namespace raml {
    struct id3v1 {
        char title[31];
        char artist[31];
        char album[31];
        char year[5];
        char comment[29];
        char track;
        char genre;
    };
    extern char* genre[256];
    id3v1 getTags (std::string& file, bool& error);

    string remove_spaces(const string &s);
}

#endif // DEPENDENCY_H
