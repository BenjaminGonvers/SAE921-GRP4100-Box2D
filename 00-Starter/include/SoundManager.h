#pragma once
#include <map>
#include <SFML/audio.hpp>



class SoundManager
{
private:

	std::map<std::string, std::unique_ptr<sf::SoundBuffer>> sound_map_;

public:

	sf::SoundBuffer* GetNewSound(const std::string& path);
};

