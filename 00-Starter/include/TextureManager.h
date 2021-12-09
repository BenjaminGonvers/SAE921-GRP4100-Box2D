#pragma once
#include <SFML/Graphics.hpp>



class TextureManager
{
private:

	std::map<std::string, std::unique_ptr<sf::Texture>> texture_map_;

public:

	sf::Texture* GetNewTexture(const std::string& path);
};

