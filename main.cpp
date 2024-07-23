/* PROGRAMMING FUNDAMENTAL'S PROJECT FOR FALL 2022 BS(CS)
 * You don't need to change anything in the driver code/main function except the part(s) where instructed.
 * You are expected to define your functionalities in the "functionality.h" header and call them here in the instructed part(s).
 * The game is started with a small box, you need to create other possible in "pieces.h" file in form of array.
    E.g., Syntax for 2 pieces, each having four coordinates -> int Pieces[2][4];
 * Load the images into the textures objects from img directory.
 * Don't make any changes to the "utils.h" header file except for changing the coordinate of screen or global variables of the game.
 * SUGGESTION: If you want to make changes in "utils.h", do it once you complete rest of the functionalities.
 * TIP: You can study SFML for drawing scenes, sprites and window.
 * */
 //arhamkhalid--22i-1156
#include <cstdlib>
#include <SFML/Graphics.hpp>
#include <time.h>
#include "utils.h"
#include "pieces.h"
#include "functionality.h"
#include <sstream>
#include<iostream>
using namespace sf;

int main(){


    srand(time(0));
    RenderWindow window(VideoMode(700, 700), title);
    Texture obj1, obj2, obj3, obj4 , obj5 , obj6 , obj7 , obj8 ;
    /*
        Load "frames.png","tiles.png" and "background.png" for Texture objects
    */
    obj1.loadFromFile("img/tiles.png");
    obj2.loadFromFile("img/background.png");
    obj3.loadFromFile("img/frame.png");
    obj4.loadFromFile("img/shadow.png");
    obj5.loadFromFile("img/nexttile.png");
    obj7.loadFromFile("img/bombpixel.png");                      //declearation of objects from what i understood
    obj8.loadFromFile("img/welcome.png");
    Sprite sprite(obj1) , background(obj2), frame(obj3);
    Sprite sprite1(obj4) ;
    Sprite sprite2(obj5);
    Sprite sprite4(obj7);
    int delta_x=0, colorNum=1 , score = 0;
    float timer=0, delay=0.3;                     //some predecleared 
    bool rotate=0 , over=0;                       //others decleared to be used by reference
    int m=0;
    int n=0;
    Clock clock;
    
    bool bomb= false;
    int bombcond=0;
    int once=0;
    int p=0;   
    int v=0;
    while (window.isOpen()){
        float time = clock.getElapsedTime().asSeconds();
        clock.restart();
        timer+=time;

        //---Event Listening Part---//
        Event e;
                  while (window.pollEvent(e)){                    //Event is occurring - until the game is in running state
                   if (e.type == Event::Closed)                   //If cross/close is clicked/pressed
                       window.close();                            //Opened window disposes
                  
                                         
                                       if (e.type == Event::KeyPressed) {             //If any other key (not cross) is pressed
                                                  if (e.key.code == Keyboard::Up){    //Check if the other key pressed is UP key
                                                                                            
                                                            rotate = true;                    //rotation gets true
                                                               blockrotate( delta_x , m ); 
                                                       }

                                          
                                        else if (e.key.code == Keyboard::Left){     //Check if the other key pressed is LEFT key
                  
                                                  delta_x = -1;                   //Change in X-Axis - Negative
                                                
                                                  moveleft( delta_x , N);
                   
                                                 }                          
                                       else if (e.key.code == Keyboard::Right){    //Check if the other key pressed is RIGHT key
                    
                                                  delta_x = 1;                     //Change in X-Axis - Positive
                    				
                  				   moveright( delta_x , N);            
                  				                                
                                           }
          }//end of e type event
               
        
                                    if (Keyboard::isKeyPressed(Keyboard::Space))
                                      {   
                                                        instant();                   // to hard drop the piece
                                                        
                                      }
        
           					if (Keyboard::isKeyPressed(Keyboard::Down))
           				{   							//Just another way to detect key presses without event listener
            						delay=0.05;                            //If DOWN key is pressed, delay in falling piece decreases from 0 to 0.05
           				}
               
            
   } //end of first while

                                          ///////////////////////////////////////////////
                                          ///*** START CALLING YOUR FUNCTIONS HERE ***///
                                            
                                                        if(once==0)
                                                        {
                                                             mainmenu(obj8); //pops up main menu on a new window
                                                         }
                                                             bombcheck( bomb); //function made to check if bomb becomes true on a probability
                                                 if(bomb==true)
                                              {
                                              queuebomb(delay, colorNum , obj7 ); //made on the logic that if upper chance true then bomb is to be spawned
                                             }
                                           if (Keyboard::isKeyPressed(Keyboard::P))
                   {  
                                            sf::Sprite sprite;
                                            sf::Texture texture;           
                                            texture.loadFromFile("img/menu.png");               
                                            sprite.setTexture(texture);
                                            sprite.setPosition(0,0);
              				     while (window.isOpen())
                            {
                                            window.clear();
                                            window.draw(sprite);
                                            window.display();
                                            sf::Event event;
                                           if(Keyboard::isKeyPressed(Keyboard::Num1)){
                                           break;
                                           }
                                           if(Keyboard::isKeyPressed(Keyboard::Num2)){
                                           help(obj6);                                    //display controls
                                           }
                                           if(Keyboard::isKeyPressed(Keyboard::Num4)){
                                           return 0;
                                           }
               
                                           while (window.pollEvent(event))
                                      {
                                           if((event.type== sf::Event::Closed))
                                           {
                                           window.close();
                                           }
                                      }
                               }   
             
 				            delay=0.4;     //so that returns from menu with same block falling speed
                  } 
                              
                                 
                                          fallingPiece(timer, delay , colorNum , n , m , p , v );
                                 
       			           nextpiece (colorNum , m  ,p );
          
           			           reset(delay);
           					
           				  gameover( M , N , over);
           				  
        				shadow(timer , delay , m , colorNum , v );
        				  
       				destroyline( M , N ,score);
       				
       		       if(over==true)
       		       {
       		       endingscreen(obj6,score);           //done to show ending screen once lost
          		       return 0;
          		       }
          		
          		
                               //Example: fallingPiece() function is called here
        ///*** YOUR CALLING STATEMENTS END HERE ***///
        //////////////////////////////////////////////


        window.clear(Color::Black);
        window.draw(background);
        for (int i=0; i<M; i++){
            for (int j=0; j<N; j++){
                if (gameGrid[i][j]==0)
                    continue;
                sprite.setTextureRect(IntRect(gameGrid[i][j]*18,0,18,18));
                sprite.setPosition(j*18,i*18);
                sprite.move(28,31); //offset
                window.draw(sprite);
            }
        }
        for (int i=0; i<4; i++){
            sprite.setTextureRect(IntRect(colorNum*18,0,18,18));
            sprite.setPosition(point_1[i][0]*18,point_1[i][1]*18);
            sprite.move(28,31);
            window.draw(sprite);
            
          }
     
          
     for (int i=0; i<4; i++){
            sprite2.setTextureRect(IntRect(colorNum*18,0,18,18));
            sprite2.setPosition(next1[i][0]*18,next1[i][1]*18);
            sprite2.move(228,31);
            window.draw(sprite2);  
          }           
          
     
        
      for (int i=0; i<4; i++){
            sprite1.setTextureRect(IntRect(colorNum*18,0,18,18));
            sprite1.setPosition(point_1[i][0]*18,point_1[i][1]*18);
            sprite1.move(28,231);
            window.draw(sprite1);
            
          } 
     /* for (int i=0; i<4; i++){
            sprite4.setTextureRect(IntRect(colorNum*18,0,18,18));
            sprite4.setPosition(point_1[i][0]*18,point_1[i][1]*18);
            sprite4.move(28,0);
            window.draw(sprite4);
            
          } */ //drawing it just works like normal piece same problem as shadow     
         
        //---The Final on Which Everything is Drawn Over is Loaded---//
        window.draw(frame);
        //---The Window that now Contains the Frame is Displayed---//
        window.display();
 
once++;
    }
    delay=0.5;
    std::cout<<"your score was ";
    std::cout<<score; 
    std::cout<<std::endl;
     
    return 0;
}


