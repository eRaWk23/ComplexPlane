#include "complexPlane.h"
#include <cmath>

ComplexPlane::ComplexPlane(int pixelWidth, int pixelHeight)
{
    m_pixel_size = {pixelWidth, pixelHeight};
    m_aspectRatio = static_cast<float>(pixelHeight)/pixelWidth;
    m_plane_center = {0,0};
    m_plane_size = {BASE_WIDTH,BASE_HEIGHT * m_aspectRatio};
    m_zoomCount = 0;
    m_state = State::CALCULATING;
    // Init VertexArray
    m_vArray.setPrimitiveType(sf::Points);
    m_vArray.resize(pixelWidth * pixelHeight);
}
        
void ComplexPlane::updateRender()
{
    if(m_state == State::CALCULATING)
    {
        for (int i = 0; i < m_pixel_size.y; i++)
        {
            for (int j = 0; j < m_pixel_size.x; j++)
            {
                m_vArray[j + i *m_pixel_size.x].position = sf::Vector2f(j, i);
                sf::Vector2f coord = mapPixelToCoords(sf::Vector2i(j,i));
                size_t iterations = countIterations(coord);
                Uint8 r,g,b;
                iterationToRGB(iterations,r, g, b);
            }
        }
    }
}

void ComplexPlane::zoomIn()
{
    ++m_zoomCount;

    float zoomFactor = pow(BASE_ZOOM, m_zoomCount);
    float newWidth = BASE_WIDTH * zoomFactor;
    float newHeight = BASE_HEIGHT * m_aspectRatio * zoomFactor;
    m_plane_size = {newWidth, newHeight};

    m_state = State::CALCULATING;

}

void ComplexPlane::zoomOut()
{
    --m_zoomCount;
    float zoomFactor = pow(BASE_ZOOM, m_zoomCount);
    float newWidth = BASE_WIDTH * zoomFactor;
    float newHeight = BASE_HEIGHT * m_aspectRatio * zoomFactor;
    m_plane_size = {newWidth, newHeight};

    m_state = State::CALCULATING;

}

void ComplexPlane::setCenter(Vector2i mousePixel)
{
    sf::Vector2f coords = mapPixelToCoords(mousePixel);
    m_plane_center = coords;
    m_state = State::CALCULATING;
}

void ComplexPlane::setMouseLocation(Vector2i mousePixel)
{
    Vector2f coords = mapPixelToCoords(mousePixel);
    m_mouseLocation.x = static_cast<int>(coords.x);
    m_mouseLocation.y = static_cast<int>(coords.y);
}

void ComplexPlane::loadText(Text& Text)
{

}

int ComplexPlane::countIterations(Vector2f coord)
{
    return 0;
}

Vector2f mapPixelToCoords(Vector2i mousePixel);

void iterationToRGB(size_t count, Uint8& g, Uint8& b)
{

}
