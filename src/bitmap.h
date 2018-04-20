/**********************************************\
*
*  Andrey A. Ugolnik
*  http://www.ugolnik.info
*  andrey@ugolnik.info
*
\**********************************************/

#pragma once

#include <cstdint>
#include <vector>

class cBitmap final
{
public:
    cBitmap(uint32_t width, uint32_t height);
    ~cBitmap();

    void put(uint32_t x, uint32_t y, uint8_t val);

    const uint8_t* getData() const;
    uint32_t getWidth() const;
    uint32_t getHeight() const;

private:
    const uint32_t m_width;
    const uint32_t m_height;
    std::vector<uint8_t> m_data;
};
