#include "CharCounter.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <algorithm>

CharCounter::CharCounter(const std::string& nameOfFile)
    :fileName(nameOfFile)
{
    std::ifstream file;
    file.open(fileName, std::ios::out);

    if(file.good())
    {
        std::cout << "File name is correct" << std::endl;

        for(int i = 32; i < 128; i++)
        {
            mapOfChar[static_cast<char>(i)] = 0;
        }
    }
    else
    {
        std::cout << "ERROR file" << std::endl;;
    }

}

void CharCounter::print() const
{
    int Dec = 0;
    for(auto elem :mapOfChar)
    {
        std::cout << Dec << " [" << elem.first << "] = " << elem.second << std::endl;
        Dec++;
    }
}

void CharCounter::find()
{
    std::ifstream file;

    file.open(fileName);
    if(file.is_open())
    {
        std::string line;
        while(getline(file, line))
        {
            for(auto elem:line)
                {
                    mapOfChar[elem] ++;
                }
        }
    file.close();

    }
}

void CharCounter::printInSFMML()
{
    bool flag = true;
    int Dec = 33;
    unsigned int X = 1500, Y = 1000; 
    auto theMostRecentValue = std::max_element
    (
        std::begin(mapOfChar), std::end(mapOfChar),
        [] (const std::pair<char, int> & p1, const std::pair<char, int> & p2) {
            return p1.second < p2.second;
        }
    );

    float scale = 1 / lengthOfNumber(theMostRecentValue->second);

    sf::RenderWindow window(sf::VideoMode(X, Y), "Character Counter");
    sf::RectangleShape rectangle(sf::Vector2f(2, 10));
    sf::Font font;
    sf::Text text;
    window.clear(sf::Color::White);
    rectangle.setFillColor(sf::Color::Black);
    rectangle.setPosition(200.f, 900.f);
    rectangle.rotate(180);
    font.loadFromFile("ArialTh.ttf");
    text.setFont(font);
    text.setCharacterSize(12);

    
  
    while (window.isOpen())
    {
        sf::Event event;

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        if(flag)
        {
            for(auto elem: mapOfChar)
            {
                rectangle.setSize(sf::Vector2f(2.f, elem.second));
                rectangle.setScale(1, scale);
                rectangle.move(8.f, 0.f);
                text.setString(elem.first);
                text.setFillColor(sf::Color::Black);
                text.setPosition(rectangle.getPosition());
                text.setScale(-1, 1);
                window.draw(text);
                window.draw(rectangle);
            }
            flag = false;
        }


    window.display();
    }
}

 float CharCounter::lengthOfNumber(int n)
 {
    int number = 1;
    if(n > 1000)
    {
        while(n /= 100)
        {
            number *= 10;
        }
        
    }

    return number;
 }