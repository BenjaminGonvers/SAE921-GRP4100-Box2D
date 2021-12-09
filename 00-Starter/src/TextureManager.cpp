#include "TextureManager.h"





sf::Texture* TextureManager::GetNewTexture(const std::string & path)
	{
		// ReSharper disable once CppTooWideScopeInitStatement
		const auto texture = texture_map_.find(path);

		if (texture != texture_map_.end())
		{
			return texture->second.get();
		}

		auto newTexture = std::make_unique<sf::Texture>();
		if (newTexture->loadFromFile(path))
		{
			const auto copy = newTexture.get();
			texture_map_[path] = std::move(newTexture);
			return copy;
		}

		const std::string urg_texture_name = "./data/blockerMad.png";
		const auto urg_texture = texture_map_.find(urg_texture_name);

		if (urg_texture != texture_map_.end())
		{
			return urg_texture->second.get();
		}

		newTexture->loadFromFile(urg_texture_name);
		
		const auto copy = newTexture.get();
		texture_map_[path] = std::move(newTexture);
		return copy;

	}