#include "SFML_TextureAtlas.h"

SFML_TextureAtlas::SFML_TextureAtlas() {}
SFML_TextureAtlas::~SFML_TextureAtlas() {}

std::pair<std::string, std::string> Split(const std::string& text, const std::string& delimiter) {
    size_t pos = text.find_first_of(delimiter);
    return std::pair<std::string, std::string>(text.substr(0, pos), text.substr(pos + 1));
}

void SFML_TextureAtlas::loadFromFile(const std::string& path)
{
    std::string line;
    std::ifstream myfile(path);
    if (myfile.is_open())
    {
        while (std::getline(myfile, line))
        {
            switch (line[0]) {
            case '#': {
                auto delim1 = Split(line.substr(1), ",");
                auto delim2 = Split(delim1.second, ",");
                auto delim3 = Split(delim2.second, ",");
                auto delim4 = Split(delim3.second, ",");
                rect_vec.push_back(sf::IntRect(
                    sf::Vector2i(std::stoi(delim1.first), std::stoi(delim2.first)), 
                    sf::Vector2i(std::stoi(delim3.first), std::stoi(delim4.first))));
            }
                break;
            case ':': 
                this->txt.loadFromFile(line.substr(1)); 
                this->spr.setTexture(txt);
                break;
            }

        }
        myfile.close();
    }

}

const Texture& SFML_TextureAtlas::GetTexture(const int& index) const
{
    return std::move(Texture(index, rect_vec[index].width, rect_vec[index].height));
}

sf::Sprite& SFML_TextureAtlas::GetSprite(const Texture& texture) {
    spr.setTextureRect(rect_vec[texture.getTextureIndex()]);
    return spr;
}