#include "Game.h"


Game::Game():world_(b2Vec2(0,0))
{
  
    

}

void Game::Init()
{
	window_.create(sf::VideoMode(1200, 800), "WorldCube!");
	window_.setFramerateLimit(60.0f);

	gravity_.Set(0.0f, -9.81f);
    world_.SetGravity(gravity_);

    box2_.setTexture(*texture_manager_.GetNewTexture("./data/box.png"));
    box2_.setColor(sf::Color(255, 100, 100, 100));
    box2_.setOrigin(35.f, 35.f);
    box2_.setPosition(600, 400);

    Game_Loader();
    Generate_Ground();

    window_.setMouseCursorVisible(false);
    
}

void Game::Game_Loop()
{

    while (window_.isOpen())
    {
        world_.Step(timeStep_, velocityIterations_, positionIterations_);
        
        mouse_pos_ = sf::Mouse::getPosition(window_);
        box2_.setPosition(mouse_pos_.x,mouse_pos_.y);

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
        {
            Reset_Player_Box();
        }

        window_.clear();
        window_.draw(box2_);
        Draw_Plateform();
        Player_Box_Create();
        Draw_Player_Box();
    	window_.display();
    }
}

void Game::Game_Loader()
{
    std::ifstream in("./data/level1.txt");
    std::string origine_tile;

    while (std::getline(in, origine_tile))
    {
        if (origine_tile.size() > 0)
        {
            int tile = std::stoi(origine_tile);
            first_map_.push_back(tile);
        }

    }
}


void Game::Generate_Ground()
{
   
    auto it = first_map_.begin();
    
		for (float axeY = 35; axeY <= 835; axeY += 70.f) 
        {
		 for (float axeX = 35; axeX <= 1235.f; axeX += 70.f)
		 {
             if (it != first_map_.end())
             {
                 int tile = *it;
                 if (tile != 0)
                 {
                     auto newGround = std::make_unique<Ground>(world_, axeX, axeY, tile);
                     newGround->pos_MAJ();
                     ground_imobile_vector.push_back(std::move(newGround));
                 }
                 ++it;
             }
		 }
		}
	
}

void Game::Draw_Plateform()
{
    for (const auto& i : ground_imobile_vector)
    {
       window_.draw( i->draw());
    }
}

void Game::Player_Box_Create()
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
        if (left_mouse_pressed_ == false)
        {
            if (level_authorized_box_ > number_box_) 
            {
                b2Vec2 vertices[4];
                vertices[0].Set(0.5, 0.5);
                vertices[1].Set(0.5, -0.5);
                vertices[2].Set(-0.5, -0.5);
                vertices[3].Set(-0.5, 0.5);
                player_box_mobile_vector.push_back(std::make_unique<PhysicalObject>(world_,texture_manager_.GetNewTexture("./data/box.png"), box2_.getPosition(),vertices,4,b2_dynamicBody));
                number_box_++;
            }
            left_mouse_pressed_ = true;
        }
	}else
	{
        left_mouse_pressed_ = false;
	}
}

void Game::Draw_Player_Box()
{
    for (const auto& i : player_box_mobile_vector)
    {
        i->pos_MAJ();
        window_.draw(i->draw());
    }
}

void Game::Reset_Player_Box()
{
        player_box_mobile_vector.clear();
        number_box_ = 0;
}