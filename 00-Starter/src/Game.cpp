#include "Game.h"


Game::Game():world_(b2Vec2(0,0))
{
    

}

void Game::Init()
{
	window_.create(sf::VideoMode(1200, 800), "WorldCube!");
	window_.setFramerateLimit(60.0f);

	gravity_.Set(0.0f, -50);
    world_.SetGravity(gravity_);

    Game_Loader();
    Generate_Ground();
    Create_Player();
    Create_Finish();

    

    window_.setMouseCursorVisible(true);
    
}

void Game::Game_Loop()
{

    while (window_.isOpen())
    {
        world_.Step(timeStep_, velocityIterations_, positionIterations_);
        
        mouse_pos_SFML_ = sf::Mouse::getPosition(window_);
        mouse_pos_B2D_.x = mouse_pos_SFML_.x;
        mouse_pos_B2D_.y = mouse_pos_SFML_.y;

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
        {
            Reset_Player_Box();
        }

        window_.clear();
        Check_Player_Action();
        Draw_Plateform();
        Player_Box_Create();
        Draw_Player_Box();
        Draw_Player_Character();
    	window_.display();


    }
}

void Game::Game_Loader()
{
    std::ifstream in("./data/level1.txt");
    std::string origine_tile;

    while (std::getline(in, origine_tile))
    {
        if (!origine_tile.empty())
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
    for (const auto& i : objects_vector_)
    {
        i->pos_MAJ();
        window_.draw(i->draw());
    }
}

void Game::Player_Box_Create()
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
        if (!left_mouse_pressed_)
        {
            if (level_authorized_box_ > number_box_) 
            {
                b2Vec2 vertices[4];
                vertices[0].Set(0.5, 0.5);
                vertices[1].Set(0.5, -0.5);
                vertices[2].Set(-0.5, -0.5);
                vertices[3].Set(-0.5, 0.5);
                player_box_mobile_vector.push_back(std::make_unique<PhysicalObject>(world_,texture_manager_.GetNewTexture("./data/box.png"),mouse_pos_B2D_,vertices,4,b2_dynamicBody));
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

void Game::Create_Player()
{
    sf::Vector2f pos(50,50);
    sf::Vector2f temp_pos(35,35);

    b2Vec2 vertices[4];
    vertices[0] = PhysicalObject::pixel_to_meter(temp_pos);
    temp_pos.x = -31;
    vertices[1] = PhysicalObject::pixel_to_meter(temp_pos);
    temp_pos.y = -57;
    vertices[2] = PhysicalObject::pixel_to_meter(temp_pos);
    temp_pos.x = 35;
    vertices[3] = PhysicalObject::pixel_to_meter(temp_pos);
    players_character_vector.push_back(std::make_unique<Player>(world_, texture_manager_.GetNewTexture("./data/alienGreen.png"),
        pos, vertices, 4, b2_dynamicBody));
   

}

void Game::Draw_Player_Character()
{
    for (const auto& i : players_character_vector)
    {
        i->pos_MAJ();
        window_.draw(i->draw());
    }
}

void Game::Check_Player_Action()
{
    for (const auto& i : players_character_vector)
    {
        i->Check_Player_Action();
    }

}

void Game::Create_Finish()
{
    
        sf::Vector2f pos(1155, 525);
        sf::Vector2f temp_pos(35, 35);

        b2Vec2 vertices[4];
        vertices[0] = PhysicalObject::pixel_to_meter(temp_pos);
        temp_pos.x = -35;
        vertices[1] = PhysicalObject::pixel_to_meter(temp_pos);
        temp_pos.y = -35;
        vertices[2] = PhysicalObject::pixel_to_meter(temp_pos);
        temp_pos.x = 35;
        vertices[3] = PhysicalObject::pixel_to_meter(temp_pos);
        objects_vector_.push_back(std::make_unique<PhysicalObject>(world_, texture_manager_.GetNewTexture("./data/flagRed.png"),
            pos, vertices, 4));
        

    
}
