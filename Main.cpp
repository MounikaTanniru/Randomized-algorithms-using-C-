#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

string dealCard();
bool checkDuplicate(string hand[], string aCard);
void dealHand(string hand[]);
void swapCards(string hand[]);
void convertToInt(string hand[], int numHand[2][5]);
string findWinner(string hand[]);
void game();

char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
char current_marker;
int current_player;

void reset()
{
    board[0][0] = '1';
    board[0][1] = '2';
    board[0][2] = '3';
    board[1][0] = '4';
    board[1][1] = '5';
    board[1][2] = '6';
    board[2][0] = '7';
    board[2][1] = '8';
    board[2][2] = '9';
}

int main()
{
    srand(time(NULL));
    int option, choice;
    bool stop = false;

    while (stop != true)
    {
        cout << "****GROUP 6 GAME****" << endl;
        cout << "1.Card game" << endl;
        cout << "2.Tic Tac Toe" << endl;
        cout << "3.Exit" << endl
             << endl;
        cout << "Choose your option : ";
        cin >> option;
        switch (option)
        {
        case 1:
            if (option == 1)
            {
                string hand[5] = {"", "", "", "", ""};
                dealHand(hand);
                for (int i = 0; i < 5; i++)
                    cout << endl
                         << (i + 1) << " - " << hand[i];

                char yesOrNo;
                cout << endl
                     << endl
                     << "Do you want to change cards? (y/n): ";
                cin >> yesOrNo;
                if (yesOrNo == 'y')
                {
                    swapCards(hand);
                    cout << endl
                         << "Your new cards are:" << endl;
                    for (int i = 0; i < 5; i++)
                        cout << (i + 1) << " - " << hand[i] << endl;
                    cout << endl;
                }

                cout << endl
                     << findWinner(hand) << endl;

                cin.ignore(256, '\n');
            }
            break;
        case 2:
            game();
            break;
        case 3:
            cout << "------Thank you!!!------";
            return 0;
        default:
            cout << "\n!!!You selected an invalid choice!!!\n";
            break;
        }
        cout << "*\n";
        cout << "Would you like to play again :\n";
        cout << "PRESS 1 for Yes\n";
        cout << "PRESS 0 for No : ";
        cin >> choice;

        system("CLS");
        if (choice == 0)
        {
            cout << "**Thank You**";
            return 0;
        }
    }
    return 0;
}

string dealCard()
{
    string card;

    int aSuit = (rand() % (4 - 1 + 1)) + 1;
    int aCard = (rand() % (13 - 1 + 1)) + 1;

    string face;
    switch (aSuit)
    {
    case 1:
        face = " of Hearts";
        break;
    case 2:
        face = " of Spades";
        break;
    case 3:
        face = " of Diamonds";
        break;
    case 4:
        face = " of Clubs";
        break;
    }
    string value;
    switch (aCard)
    {
    case 1:
        value = "Ace";
        break;
    case 2:
        value = "2";
        break;
    case 3:
        value = "3";
        break;
    case 4:
        value = "4";
        break;
    case 5:
        value = "5";
        break;
    case 6:
        value = "6";
        break;
    case 7:
        value = "7";
        break;
    case 8:
        value = "8";
        break;
    case 9:
        value = "9";
        break;
    case 10:
        value = "10";
        break;
    case 11:
        value = "Jack";
        break;
    case 12:
        value = "Queen";
        break;
    case 13:
        value = "King";
        break;
    }
    card = (value + face);
    return card;
}

bool checkDuplicate(string hand[], string aCard)
{
    bool duplicate = false;

    for (int i = 0; i < 5; i++)
    {
        if (hand[i] == aCard)
            duplicate = true;
    }

    return duplicate;
}

void dealHand(string hand[])
{
    for (int i = 0; i < 5; i++)
    {
        string j = dealCard();
        if (checkDuplicate(hand, j) == true)
            i--;
        else
            hand[i] = j;
    }
}

void swapCards(string hand[])
{
    char yesOrNo;

    for (int i = 0; i < 5; i++)
    {
        cout << "Change card " << (i + 1) << "? (y/n): ";
        cin.ignore(256, '\n');
        cin >> yesOrNo;

        if (yesOrNo == 'y')
        {
            string j;
            do
            {
                j = dealCard();
            } while (checkDuplicate(hand, j) == true);
            hand[i] = j;
        }
        else
        {
            continue;
        }
    }
}

void convertToInt(string hand[], int numHand[2][5])
{
    stringstream stream;

    for (int i = 0; i < 5; i++)
    {
        if (hand[i].substr(0, 2) == "10")
        {
            numHand[0][i] = 10;
        }
        else if (hand[i].substr(0, 1) == "A")
        {
            numHand[0][i] = 1;
        }
        else if (hand[i].substr(0, 1) == "J")
        {
            numHand[0][i] = 11;
        }
        else if (hand[i].substr(0, 1) == "Q")
        {
            numHand[0][i] = 12;
        }
        else if (hand[i].substr(0, 1) == "K")
        {
            numHand[0][i] = 13;
        }

        else
        {
            stream << hand[i].substr(0, 1);
            stream >> numHand[0][i];
            stream.str("");
            stream.clear();
        }
    }

    enum
    {
        HEARTS,
        SPADES,
        DIAMONDS,
        CLUBS
    };

    for (int i = 0; i < 5; i++)
    {
        if (hand[i].find("Hearts") != -1)
        {
            numHand[1][i] = HEARTS;
        }
        else if (hand[i].find("Spades") != -1)
        {
            numHand[1][i] = SPADES;
        }
        else if (hand[i].find("Diamonds") != -1)
        {
            numHand[1][i] = DIAMONDS;
        }
        else
        {
            numHand[1][i] = CLUBS;
        }
    }
}

string findWinner(string hand[])
{
    string result = "Sorry, better luck next time!";

    bool straightFlush = false;
    bool fourOfAKind = false;
    bool fullHouse = false;
    bool flush = false;
    bool straight = false;
    bool threeOfAKind = false;
    bool twoPair = false;
    bool onePair = false;

    enum
    {
        PAIR = 1,
        TWO_PAIR,
        THREE_OF_A_KIND,
        FULL_HOUSE,
        FOUR_OF_A_KIND = 6
    };

    int cards[2][5];
    convertToInt(hand, cards);
    vector<int> winners(0);
    for (int i = 0; i < 4; i++)
    {
        for (int j = i; j < 4; j++)
        {
            if (cards[0][i] == cards[0][j + 1])
                winners.push_back(cards[0][i]);
        }
    }
    if (winners.size() == FOUR_OF_A_KIND)
        fourOfAKind = true;
    else if (winners.size() == FULL_HOUSE)
        fullHouse = true;
    else if (winners.size() == THREE_OF_A_KIND)
        threeOfAKind = true;
    else if (winners.size() == TWO_PAIR)
        twoPair = true;
    else if (winners.size() == PAIR)
        onePair = true;

    vector<int> orderCards(0);
    for (int i = 0; i < 5; i++)
        orderCards.push_back(cards[0][i]);
    bool swapped = true;
    int j = 0;
    int tmp;
    while (swapped)
    {
        swapped = false;
        j++;
        for (int i = 0; i < (orderCards.size() - j); i++)
        {
            if (orderCards[i] > orderCards[i + 1])
            {
                tmp = orderCards[i];
                orderCards[i] = orderCards[i + 1];
                orderCards[i + 1] = tmp;
                swapped = true;
            }
        }
    }
    int checkStraight = orderCards.back();
    while (checkStraight != orderCards.front())
    {
        checkStraight--;
    }
    if (checkStraight == (orderCards.back() - (orderCards.size() - 1)))
    {
        straight = true;
    }
    else if ((orderCards[0] == 1) &&
             (orderCards[1] == 10) &&
             (orderCards[2] == 11) &&
             (orderCards[3] == 12) &&
             (orderCards[4] == 13))
    {
        straight = true;
    }

    for (int i = 0; i < 4; i++)
    {
        if (cards[1][i] == cards[1][i + 1])
        {
            flush = true;
        }
        else
        {
            flush = false;
            break;
        }
    }
    if ((straight == true) && (flush == true))
        straightFlush = true;

    if (straightFlush == true)
        result = "You have a Straight Flush!";
    else if (fourOfAKind == true)
        result = "You have a Four Of A Kind!";
    else if (fullHouse == true)
        result = "You have a Full House!";
    else if (flush == true)
        result = "You have a Flush!";
    else if (straight == true)
        result = "You have a Straight!";
    else if (threeOfAKind == true)
        result = "You have a Three Of A Kind!";
    else if (twoPair == true)
        result = "You have a Two Pair!";
    else if (onePair == true)
        result = "You have a Pair!";

    return result;
}

void drawBoard()
{
    cout << "____________\n";
    cout << "| " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << " | " << endl;
    cout << "____________\n";
    cout << "| " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << " | " << endl;
    cout << "____________\n";
    cout << "| " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << " | " << endl;
    cout << "____________\n";
}

bool placeMarker(int slot)
{
    int row = slot / 3;
    int col;

    if (slot % 3 == 0)
    {
        row = row - 1;
        col = 2;
    }
    else
    {
        col = slot % 3 - 1;
    }
    if (board[row][col] != 'X' && board[row][col] != 'O')
    {
        board[row][col] = current_marker;
        return true;
    }
    else
    {
        return false;
    }
}

int winner()
{
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
        {
            return current_player;
        }
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
        {
            return current_player;
        }
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
    {
        return current_player;
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
    {
        return current_player;
    }
    return 0;
}

void swap_player_and_marker()
{
    if (current_marker == 'X')
    {
        current_marker = 'O';
    }
    else
    {
        current_marker = 'X';
    }
    if (current_player == 1)
    {
        current_player = 2;
    }
    else
    {
        current_player = 1;
    }
}

void game()
{
    cout << "Player one, choose your marker from 'O' or 'X' :";
    char marker_p1;
    cin >> marker_p1;

    current_player = 1;

    current_marker = marker_p1;
    reset();
    drawBoard();

    int player_won;

    for (int i = 0; i < 9; i++)
    {
        cout << "It`s player " << current_player << "`s turn. Enter your slot: ";
        int slot;
        cin >> slot;

        if (slot < 1 || slot > 9)
        {
            cout << "That slot is invalid! Try another slot!";
            i--;
            continue;
        }

        if (!placeMarker(slot))
        {
            cout << "That slot occupied! Try another slot!";
            i--;
            continue;
        }
        drawBoard();

        player_won = winner();

        if (player_won == 1)
        {
            cout << "Player 1 won! Congratulations!";
            break;
        }
        if (player_won == 2)
        {
            cout << "Player 2 won! Congratulations!";
            break;
        }

        swap_player_and_marker();
    }
    if (player_won == 0)
    {
        cout << "That is a Tie!";
    }
}
