#pragma once
#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>
#include <Ground.h>
#include <PhysicalObject.h>
#include <NonPhysicalObject.h>
#include <TextureManager.h>
#include <vector>
#include <Player.h>
#include <fstream>
class Game
{
private:
    
    sf::RenderWindow window_;

  

	

    b2Vec2 gravity_;
    b2World world_;
    
	b2BodyDef ground_body_def_;
    b2Body* ground_body_;
    b2PolygonShape ground_box_;


    
    float timeStep_ = 1.0f / 60.0f ;
    int32 velocityIterations_ = 6;
    int32 positionIterations_ = 2;
    sf::Event event;

    int level_authorized_box_ = 1000;
    int number_box_ = 0;

    std::vector<std::unique_ptr<Ground>> ground_imobile_vector;
    std::vector<std::unique_ptr<PhysicalObject>> player_box_mobile_vector;
    std::vector<std::unique_ptr<NonPhysicalObject>> objects_vector_;
    std::vector<std::unique_ptr<Player>> players_character_vector;

    

    sf::Vector2i mouse_pos_SFML_;
    sf::Vector2f mouse_pos_B2D_;

    bool left_mouse_pressed_ = false;
    

    std::vector<int> first_map_;

    TextureManager texture_manager_;


public:

    Game();

    void Init();

    void Game_Loop();

    void Game_Loader();
    void Generate_Ground();
    void Draw_Plateform();

    void Player_Box_Create();
    void Draw_Player_Box();

    void Reset_Player_Box();

    void Create_Player();
    void Draw_Player_Character();
    void Check_Player_Action();
    void Create_Finish();
};

