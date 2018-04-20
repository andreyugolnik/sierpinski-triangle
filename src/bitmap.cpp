/**********************************************\
*
*  Andrey A. Ugolnik
*  http://www.ugolnik.info
*  andrey@ugolnik.info
*
\**********************************************/

#include "bitmap.h"

cBitmap::cBitmap(uint32_t width, uint32_t height)
    : m_width(width)
    , m_height(height)
    , m_data(width * height)
{
}

cBitmap::~cBitmap()
{
}

void cBitmap::put(uint32_t x, uint32_t y, uint8_t val)
{
    const uint32_t idx = x + y * m_width;
    m_data[idx] = val;
}

const uint8_t* cBitmap::getData() const
{
    return m_data.data();
}

uint32_t cBitmap::getWidth() const
{
    return m_width;
}

uint32_t cBitmap::getHeight() const
{
    return m_height;
}
