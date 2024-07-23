/* PROGRAMMING FUNDAMENTAL'S PROJECT FOR FALL 2022 BS(CS)
 * You need to define the required function in the part instructed here below.
 * Avoid making any unnecessary changes, particularly the ones you don't understand.
 * The different pieces should be defined using an array - uncomment the following code once you are done creating the array.
 * TIP: Understand thoroughly before getting started with coding.
 * */

//---Piece Starts to Fall When Game Starts---//
//arhamkhalid--22i-1156
#include <cstdlib>
#include <SFML/Graphics.hpp>
#include <time.h>
#include<sstream>
#include<iostream>
//using namespace std;
using namespace sf;

void blockrotate( int& delta_x , int& m);
      void instant(float& delay);
void shadow(float& timer , float& delay , int &m , int &colorNum , int& v );
      void destroyline(const int& M , const int& N );
void gameover(const int& M , const int& N , bool& over);
      void instant();
void reset(float& delay);
      void help(sf::Texture obj6);
void mainmenu(sf::Texture obj8);
     void endingscreen(sf::Texture obj6 , int& score);
void bombcheck(bool& bomb);
     void queuebomb(float& delay, int& colorNum , sf::Texture obj7);
void nextpiece(int &colorNum , int& m , int& p );
     void moverightshad( int& delta_x ,int& N);
void fallingPiece(float& timer, float& delay , int &colorNum , int&n ,int& m , int& p , int& v)

{

    if (timer>delay)
    {
   
        for (int i=0;i<4;i++){
            point_2[i][0]=point_1[i][0];
            
            point_2[i][1]=point_1[i][1];      //How much units downward
           
            point_1[i][1]+=1;    
                              
        }
        
        
        
        
        if (!anamoly())
        {
        int f=1;
        for(int j=0; j<4 ;j++)
        gameGrid[point_2[j][1]][point_2[j][0]]=colorNum;
        colorNum=1+rand()%7;
          n=0;
                  if(f==1)
             {
                  n=rand()%7;                  //this working correseponds to next piece function
                  f++;                         // as the next piece (n) should match 
                  m=n;
                  n=v;
             }
                  if(f!=1)
                  {
                   n=p;
                  } 
        for (int i=0;i<4;i++)
             {
       point_1[i][0] = BLOCKS[n][i] % 2;
       point_1[i][1] = BLOCKS[n][i] / 2;
       shadowpoint1[i][0] = BLOCKS[n][i] % 2;     //done on the logic to create a shadow block
       shadowpoint1[i][1] = BLOCKS[n][i] / 2;     //as done above
             }
            
       }
        
       
        timer=0;
  
    }
  
}  //end of function

/////////////////////////////////////////////
///*** START CODING YOUR FUNTIONS HERE ***///
void moveright(int& delta_x , const int& N )
{
	for (int l=0 ; l<4 ; l++)
     {
	point_1[l][0]+=1;	//one addition to its coordinate
     }
	if(!anamoly())
   {
	for (int y=0 ; y<4 ; y++)
	{
	point_1[y][0]=point_2[y][0];  //if exceds bounds resets
        }  
   } 
} //end of function  

  
void moveleft(int& delta_x , const int& N)
{
	for(int u=0 ; u<4 ; u++)
 	{
	point_1[u][0]-=1;
 	}
	    if(!anamoly())
         {
              for (int y=0 ; y<4 ; y++)
              {
		point_1[y][0]=point_2[y][0];

              } 
         }       
} //end of function
void blockrotate(int& delta_x , int& m ){
																/*int t=0;
															      if(m==0 && rotate==true ){
															       if (longline==1){
//first done with logic of case to case										       point_1[0][0]=point_1[0][0]-1;
//had problem reseting													       point_1[0][1]=point_1[0][1]+1;
																point_1[2][0]=point_1[2][0]+1;
															        point_1[2][1]=point_1[2][1]-1;
																point_1[3][0]=point_1[3][0]+2;
																point_1[3][1]=point_1[3][1]-2;
															       longline=2;
    																}
															      */
if(m!=1) //no square rotation
{
	for(int i=0 ; i<4 ; i++)
	{
	     int distx=0 ;
             int disty=0;
                distx=point_1[i][0]-point_1[1][0]; //dist in x from origin
                disty=point_1[i][1]-point_1[1][1]; //dist in y from orgin
                point_1[i][0]=point_1[i][0]-distx; //90 degree so adding in steps --translation
                point_1[i][0]=point_1[i][0]-disty;
                point_1[i][1]=point_1[i][1]-disty;
                point_1[i][1]+=distx;  
	}      

}
 	if(!anamoly())
    {
		for (int y=0 ; y<4 ; y++){
		point_1[y][0]=point_2[y][0];      //rotation anamoly not working                                  //working now
		point_1[y][1]=point_2[y][1];
	}
    }       
}//end of function 

void destroyline(const int& M , const int& N , int& score)
{
int count=M-1;
                                                                  //replaces down line by upper line
int k = M-1 ;
            while(k>0)
         {
           int checkline=0;
         for(int l= 0 ; l<N ; l++)
          {
             if(gameGrid[k][l]!=0)             //gamegrid not empty
              {
                 checkline++;
              }
         gameGrid[count][l]=gameGrid[k][l];
        }

       if(checkline<N)
       {
         count--; 
       } 
 k--;
      } 
    //count represents number of lines cleared   
	if(count==1){
	count=10;}    
	if(count==2){
	count=30;}
	if(count==3){
	count=60;}
	if(count==4){	
	count=100;}
	if(count==5){
	count=150;}
	if(count==6){
	count=210;}
	if(count==7){
	count=280;}
	if(count==8){
	count=360;}
	if(count==9){
	count=450;}
    score+=count; //calculation of score
    //count resets
}


void instant()
{
//hard falling
while(anamoly())
  {
int i=0;
	 while(i<4)
	 {
 	point_2[i][0]=point_1[i][0];
        point_2[i][1]=point_1[i][1];
        point_1[i][1]+=1;
        i++;
        }
  }  
if(!anamoly())
	{
int y=0;	
	while ( y<4 )
	   {
	     point_1[y][0]=point_2[y][0];
	     point_1[y][1]=point_2[y][1];
	     y++;
	   }
        }              
              
} //end of function
 
void shadow (float& timer , float& delay , int& m , int& colorNum , int& v)
   {
    for(int y=0 ; y<4 ; y++){
     for(int z=0 ; z<2 ; z++){
	shadowpoint1[y][z]=point_1[y][z];
	shadowpoint2[y][z]=point_2[y][z];
        } 
        //the blocks where generated above
        //copying the coordinates 
    }
while(anamoly1())  //new ananmoly for shadow piece
{                  //not really working
	for (int i=0;i<4;i++){
	shadowpoint1[i][1]+=1;}  
}  
               
   } //end of function
 
void reset(float& delay)
{
delay=0.5; //resets the delay
} 
void gameover(const int& M , const int& N , bool& over) 
{
int q=0;
do 
{
	if(gameGrid[0][q]!=0){
	over=1;}
	q++;
}
while(q<N-1);
}
void help(sf::Texture obj6)
{
sf::RenderWindow window(sf::VideoMode(700,700), title);
 sf::Sprite sprite;
              sf::Texture texture;           
              texture.loadFromFile("img/controls.png");               
              sprite.setTexture(texture);
              sprite.setPosition(0,0);
              while (window.isOpen()){
              window.clear();
              window.draw(sprite);
              window.display();
              sf::Event event;
               std::cout<<"press 2 to return "<<std::endl;
               int x=0;
               std::cin>>x;
               if(x==2){
               break;}
              while (window.pollEvent(event)){
              if((event.type== sf::Event::Closed)){
              window.close();
                      }
              }
           }   
 }    
void endingscreen(sf::Texture obj6 , int& score)
{
sf::RenderWindow window(sf::VideoMode(320,480), title);
sf::Sprite sprite;
              sf::Texture texture;           
              texture.loadFromFile("img/gameover.png");               
              sprite.setTexture(texture);
              sprite.setPosition(0,0);
              while (window.isOpen()){
              window.clear();
              window.draw(sprite);
              window.display();
              sf::Event event;
              
              while (window.pollEvent(event)){
              if((event.type== sf::Event::Closed))
              window.close();
              }
           }  
std::cout<<"your score was"<<std::endl; 
              std::cout<<score;                    
}  
        
void bombcheck(bool& bomb)
{
int num=0;
num=rand()%300+1;
	if(num==8){           
	bomb==true;

	}
	else{
	bomb==false;}
}
void queuebomb(float& delay , int& colorNum , sf::Texture obj7 )
{
bombpoint1[1][0]=BOMBMATRIX[0][0] %2;
bombpoint2[1][0]=BOMBMATRIX[0][0] /2;            
}   
     
void nextpiece(int& colorNum , int& m , int& p){
p=m+2;
if(p>7)
{
p=p-3;
}
	for (int i=0;i<4;i++)                           //copying the coordinates
     {  
                 for ( int j=0 ; j<2 ; j++)
        {
            		next1[j][0]=point_1[j][0];            
            		next2[j][1]=point_2[j][1];                                                
        }
    }    
           for (int i=0;i<4;i++){                     //generations
           next1[i][0] = BLOCKS[p][i]%2;              //along the lines of shadow
           next1[i][1] = BLOCKS[p][i]/2;              //worked
         }
}          

void mainmenu(sf::Texture obj8)
{


sf::RenderWindow window(sf::VideoMode(320,480), title);
sf::Sprite sprite5;
              sf::Texture texture5;           
              texture5.loadFromFile("img/welcome.png");               
              sprite5.setTexture(texture5);
              sprite5.setPosition(0,0);
              while (window.isOpen()){
              window.clear();
              window.draw(sprite5);
              window.display();
              sf::Event event;
              std::cout<<"press S to start , check terminal"<<std::endl;
               char x='\0';;
               std::cin>>x; 
               if(x=='s'){
               break;}
              while (window.pollEvent(event)){
              if((event.type== sf::Event::Closed))
              break;
              window.close();
              }
           }           
}  



   	
  

///*** YOUR FUNCTIONS END HERE ***///
/////////////////////////////////////

