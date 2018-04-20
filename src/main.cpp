/**********************************************\
*
*  Andrey A. Ugolnik
*  http://www.ugolnik.info
*  andrey@ugolnik.info
*
\**********************************************/

#include "bitmap.h"
#include "imagesaver.h"
#include "vector.h"

#include <cstdlib>
#include <ctime>

int main(int argc, const char* argv[])
{
    if (argc < 3)
    {
        ::printf("%s <width> <height> <outfile>\n", argv[0]);
        return -1;
    }

    const int width = ::atoi(argv[1]);
    const int height = ::atoi(argv[2]);
    auto filename = argv[3];

    ::srand(::time(nullptr));

    cBitmap bitmap(width, height);

    const cVector<float> A{ width * 0.5f, height * 0.01f }; //getRandomPoint(width, height) };
    bitmap.put(A.x, A.y, 255);

    const cVector<float> B{ width * 0.01f, height * 0.99f }; //getRandomPoint(width, height) };
    bitmap.put(B.x, B.y, 255);

    const cVector<float> C{ width * 0.99f, height * 0.99f }; //getRandomPoint(width, height) };
    bitmap.put(C.x, C.y, 255);

    cVector<float> current{ width * 0.5f, height * 0.5f };

    for (int i = 0; i < 50000; i++)
    {
        const auto v = (float)::rand() / RAND_MAX;
        if (v < 0.33f)
        {
            current = (A + current) * 0.5f;
        }
        else if (v < 0.66f)
        {
            current = (B + current) * 0.5f;
        }
        else
        {
            current = (C + current) * 0.5f;
        }

        bitmap.put(current.x, current.y, 255);
    }

    cImageSaver saver;
    return saver.save(bitmap.getData(), bitmap.getWidth(), bitmap.getHeight(), 1, filename);
}
