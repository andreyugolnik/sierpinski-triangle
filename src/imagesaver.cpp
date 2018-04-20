/**********************************************\
*
*  Andrey A. Ugolnik
*  http://www.ugolnik.info
*  andrey@ugolnik.info
*
\**********************************************/

#include "imagesaver.h"

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb/stb_image_write.h"

#include <algorithm>
#include <cstring>
#include <string>

cImageSaver::cImageSaver()
{
}

cImageSaver::~cImageSaver()
{
}

cImageSaver::Type cImageSaver::getWriter(const char* filename) const
{
    const auto point = ::strrchr(filename, '.');
    if (point != nullptr)
    {
        std::string ext = point;
        std::transform(ext.begin(), ext.end(), ext.begin(), ::tolower);

        struct sCompare
        {
            Type type;
            const char* ext;
        };

        static const sCompare List[] = {
            { Type::png, ".png" },
            { Type::bmp, ".bmp" },
            { Type::tga, ".tga" },
            { Type::tga, ".targa" },
        };

        for (auto& t : List)
        {
            if (::strcmp(t.ext, ext.c_str()) == 0)
            {
                return t.type;
            }
        }
    }

    return Type::unknown;
}

bool cImageSaver::save(const uint8_t* data, int width, int height, int comp, const char* filename) const
{
    const int w = width;
    const int h = height;
    const int stride = w * comp;

    auto type = getWriter(filename);
    switch (type)
    {
    case Type::unknown:
    case Type::png:
        return stbi_write_png(filename, w, h, comp, data, stride) != 0;

    case Type::bmp:
        return stbi_write_bmp(filename, w, h, comp, data) != 0;

    case Type::tga:
        return stbi_write_tga(filename, w, h, comp, data) != 0;
    }

    return false;
}
