#include "SoundManager.h"





sf::SoundBuffer* SoundManager::GetNewSound(const std::string & path)
	{
		
		const auto texture = sound_map_.find(path);

		if (texture != sound_map_.end())
		{
			return texture->second.get();
		}

		auto newSound = std::make_unique<sf::SoundBuffer>();
		if (newSound->loadFromFile(path))
		{
			const auto sound_buffer_ptr = newSound.get();
			sound_map_[path] = std::move(newSound);
			return sound_buffer_ptr;
		}

		return nullptr;
	}

