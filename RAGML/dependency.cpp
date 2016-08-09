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

#include "dependency.h"

namespace raml {
    id3v1 getTags (std::string& file, bool& error) {
        char* buffer = new char[128];
        //std::cout << "TAGs de fichero: " << file << std::endl;
        std::ifstream mp3(file.c_str(), std::ifstream::in);
        mp3.seekg(-128, ios::end);
        mp3.read (buffer,128);

        id3v1 tag;

        if (buffer[0] != 'T' || buffer[1] != 'A' || buffer[2] != 'G') {
            //cout << "id3v1 tag not found!! :(" << endl;
            error = true;
            return tag;
        }

        // copia a la estructura
        copy(buffer+3, buffer+33, tag.title);
        copy(buffer+33, buffer+63, tag.artist);
        copy(buffer+63, buffer+93, tag.album);
        copy(buffer+93, buffer+97, tag.year);
        copy(buffer+97, buffer+125, tag.comment);
        copy(buffer+126, buffer+127, &tag.track);
        copy(buffer+127, buffer+128, &tag.genre);

        // indico el final
        tag.title[30] = '\0';
        tag.artist[30] = '\0';
        tag.album[30] = '\0';
        tag.year[4] = '\0';
        tag.comment[28] = '\0';

        error = false;
        return tag;
    }

    char* genre[256] = {
            "Blues", "Classic Rock", "Country", "Dance", "Disco",
            "Funk", "Grunge", "Hip-Hop", "Jazz", "Metal", "New Age", "Oldies", "Other",
            "Pop", "R&B", "Rap", "Reggae", "Rock", "Techno", "Industrial", "Alternative",
            "Ska", "Death Metal", "Pranks", "Soundtrack", "Euro-Techno", "Ambient",
            "Trip-Hop", "Vocal", "Jazz+Funk", "Fusion", "Trance", "Classical", "Instrumental",
            "Acid", "House", "Game", "Sound Clip", "Gospel", "Noise", "Alt. Rock", "Bass",
            "Soul", "Punk", "Space", "Meditative", "Instrumental Pop", "Instrumental Rock",
            "Ethnic", "Gothic", "Darkwave", "Techno-Industrial", "Electronic", "Pop-Folk",
            "Eurodance", "Dream", "Southern Rock", "Comedy", "Cult", "Gangsta Rap", "Top 40",
            "Christian Rap", "Pop/Funk", "Jungle", "Native American", "Cabaret", "New Wave",
            "Psychedelic", "Rave", "Showtunes", "Trailer", "Lo-Fi", "Tribal", "Acid Punk",
            "Acid Jazz", "Polka", "Retro", "Musical", "Rock & Roll", "Hard Rock", "Folk",
            "Folk/Rock", "National Folk", "Swing", "Fast-Fusion", "Bebob", "Latin", "Revival",
            "Celtic", "Bluegrass", "Avantgarde", "Gothic Rock", "Progressive Rock",
            "Psychedelic Rock", "Symphonic Rock", "Slow Rock", "Big Band", "Chorus",
            "Easy Listening", "Acoustic", "Humour", "Speech", "Chanson", "Opera",
            "Chamber Music", "Sonata", "Symphony", "Booty Bass", "Primus", "Porn Groove",
            "Satire", "Slow Jam", "Club", "Tango", "Samba", "Folklore", "Ballad", "Power Ballad",
            "Rhythmic Soul", "Freestyle", "Duet", "Punk Rock", "Drum Solo", "A Cappella",
            "Euro-House", "Dance Hall", "Goa", "Drum & Bass", "Club-House", "Hardcore", "Terror",
            "Indie", "BritPop", "Negerpunk", "Polsk Punk", "Beat", "Christian Gangsta Rap",
            "Heavy Metal", "Black Metal", "Crossover", "Contemporary Christian", "Christian Rock",
        "Merengue", "Salsa", "Trash Metal", "Anime", "JPop", "Synthpop",0
    };

    string remove_spaces(const string &s) {
      int last = s.size() - 1;
      while (last >= 0 && s[last] == ' ')
        --last;
      return s.substr(0, last + 1);
    }

}
