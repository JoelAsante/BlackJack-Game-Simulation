// BlackJack Game from Dealer Simulation

//including the libraries
#include <iostream>
#include <random>

using namespace std;
//Global
random_device rd;

//Declaration
int NextCard();
bool DealerStatus(int currentscore);
int simulateGame();
void keepTrack(int input);                       

int main()
{
    //input declaration
    int input;

    //Printing out intro messages
    cout << "Welcome To BlackJack, this program just simulates the probabilities of the dealer bustimg " <<'\n' <<endl;
    cout << "How many games do you want to simulate" << endl;

    //Taking input from user of how times the want to run the simulation
    cin >> input;

    //Calling the fuction of the multiple games
     keepTrack(input);

     return 0;

}

//Generates next card at ramdom
int NextCard()
{
    //random funtion
    int numGenerated;
      mt19937 mt(rd());
      uniform_int_distribution<>dis(1, 13);
      
      //assigning the random number to this
      numGenerated = dis(mt);

    return numGenerated;
      
}

//function to check dealer is busted or not
bool DealerStatus(int currentscore)
{
    //Checking if Dealer busted or not
    return currentscore >= 22 || currentscore >= 17;
}
    
//function that perform one pass of the game
int simulateGame()
{
    int currentscore = 0;
    int card[13] = {2,3,4,5,6,7,8,9,10,10,10,10,11};    

    while (DealerStatus(currentscore)==false)
    {
        //picking random card;
        int temp = card[NextCard()];

        //If the score is more than just stop it
        if (currentscore >= 17)
             break;

        // If the temp is not 11, just add normally
        if(temp!=11)
        {
            currentscore+=temp;
        }
        // If the score is 11 and between 6 and 10, it can add 11 because it wont bust
        else if (temp == 11 && (currentscore >= 6 && currentscore <= 10))
        {
            currentscore += 11;
        }

        //But if not, it will add 1
        else
        {
            currentscore += 1;
        }
    }
    return currentscore;
}    

//function to calculate the busts
void keepTrack(int input)
{
    int hold = 0;
    int bust = 0;

    //for loop to run multiple 
    for (int i=0; i<input; i++)
    {
        //Setting the score to the simulateGame function
        int score = simulateGame();

        //if score is more then 22 then busts then hold.
        if (score >= 22)
            bust += 1;
        else
            hold += 1;
    }
    //Printing the Probability and amount of games it busts
    cout<< bust <<" games out of the total "<< input << " games were busted"<<endl;
    cout<<"Probability of busts for the  given input = " << ((float)bust/input) * 100 << "%"<<endl;

}

