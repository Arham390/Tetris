/* PROGRAMMING FUNDAMENTAL'S PROJECT FOR FALL 2022 BS(CS)
 * This header contains the global/common variables of the project.
 * You don't really need to change anything.
 * TIP: After completing your project, you can make changes for aesthetics.
 * */
//arhamkhalid--22i-1156
//---Title: PF-Project, Fall-2022 for BS(CS)---//
const char title[] = "PF-Project, Fall-2022";

//---Height and Width of the Actual Interactive Game---//
const int M = 20;   //Number of rows for a piece to cover on the screen (not the entire screen) = 20
const int N = 10;   //Number of columns for a piece to cover on the screen (not the entire screen) = 10

//---The Actual Interactive Game Grid - Built Over (MxN)---//
int gameGrid[M][N] = {0};

//---To Hold the Coordinates of the Piece---//
int point_1[4][2], point_2[4][2];

//shadow array
int shadowpoint1[4][2] , shadowpoint2[4][2];
int bombpoint1[4][2] , bombpoint2[4][2];
int nextpoint1[4][2] , nextpoint2[4][2];
int next1[4][2] , next2[4][2];
//---Check Uncertain Conditions---//
bool anamoly(){
    for (int i=0;i<4;i++)
        if (point_1[i][0]<0 || point_1[i][0]>=N || point_1[i][1]>=M)
            return 0;
        else if (gameGrid[point_1[i][1]][point_1[i][0]])
            return 0;
    return 1;
};
bool anamoly1(){
    for (int i=0;i<4;i++)
        if (shadowpoint1[i][0]<0 || shadowpoint1[i][0]>=M || shadowpoint1[i][1]>=N)
            return 0;
        else if (gameGrid[shadowpoint1[i][1]][shadowpoint1[i][0]])
            return 0;
    return 1;
};



