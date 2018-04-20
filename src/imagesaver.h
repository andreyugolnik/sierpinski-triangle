/**********************************************\
*
*  Andrey A. Ugolnik
*  http://www.ugolnik.info
*  andrey@ugolnik.info
*
\**********************************************/

#pragma once

#include <cstdint>

class cImageSaver final
{
public:
    cImageSaver();
    ~cImageSaver();

    bool save(const uint8_t* data, int width, int height, int comp, const char* filename) const;

private:
    enum class Type
    {
        png,
        bmp,
        tga,
        unknown,
    };

    Type getWriter(const char* filename) const;
};
