/* PROGRAMMING FUNDAMENTAL'S PROJECT FOR FALL 2022 BS(CS)
 * Shape of each piece is represented by rows in the array.
 * TIP: Name the array what is already been coded to avoid any unwanted errors.
 */
 //arhamkhalid--22i-1156
 int BLOCKS [7][4]=
 {
 {1,3,5,7}, //|
 {2,3,4,5}, //square -- no rotation
 {2,4,6,7}, //l
 {3,5,4,7}, //|-
 {1,3,5,4}, // inverted l
 {2,4,5,7}, // z
 {3,5,4,6}, // inverted z
  
 };
 
 int SHADOWBLOCKS [7][4]=
 {
 {1,3,5,7}, //|
 {2,3,4,5}, //square -- no rotation
 {2,4,6,7}, //l
 {3,5,4,7}, //|-
 {1,3,5,4}, // inverted l
 {2,4,5,7}, // z
 {3,5,4,6}, // inverted z

 };
 
 int NEXTBLOCK [7][4]=
 {
 {1,3,5,7}, //|
 {2,3,4,5}, //square -- no rotation
 {2,4,6,7}, //l
 {3,5,4,7}, //|-
 {1,3,5,4}, // inverted l
 {2,4,5,7}, // z
 {3,5,4,6}, // inverted z

 };
 
 int BOMBMATRIX [1][1] =
 {{1}};
