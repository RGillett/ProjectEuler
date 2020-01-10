/*******************************************************************************
* Poker Hands
* Author: Ryan Gillett
*******************************************************************************/
#include <iostream>
#include <fstream>

using namespace std;

class PokerHand
{
private:
    char cards[5][2];

    bool isHigher(char card1, char card2)
    {
        if (card1 == 'A')
        {
            return card2 != 'A';
        }
        else if (card1 == 'K')
        {
            return card2 != 'A' && card2 != 'K';
        }
        else if (card1 == 'Q')
        {
            return card2 != 'A' && card2 != 'K' && card2 != 'Q';
        }
        else if (card1 == 'J')
        {
            return card2 != 'A' && card2 != 'K' && card2 != 'Q' && card2 != 'J';
        }
        else if (card1 == 'T')
        {
            return card2 != 'A' && card2 != 'K' && card2 != 'Q' && card2 != 'J' && card2 != 'T';
        }
        else
        {
            return card1 > card2;
        }
    }

    void sortHand()
    {
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (isHigher(cards[i][0], cards[j][0]))
                {
                    char swapCard[2];
                    swapCard[0] = cards[i][0];
                    cards[i][0] = cards[j][0];
                    cards[j][0] = swapCard[0];
                    swapCard[1] = cards[i][1];
                    cards[i][1] = cards[j][1];
                    cards[j][1] = swapCard[1];
                }
            }
        }
    }

    int valueOf(char card)
    {
        switch (card)
        {
            case 'A':
                return 14;
                break;
            case 'K':
                return 13;
                break;
            case 'Q':
                return 12;
                break;
            case 'J':
                return 11;
                break;
            case 'T':
                return 10;
                break;
            default:
                return (card - '0');
        }
    }

    long long int sumHand()
    {
        long long int cardValueSum = 0;
        long long int valueMultiplier = 100000000;

        for (int i = 0; i < 5; i++)
        {
            cardValueSum += valueOf(cards[i][0]) * valueMultiplier;
            valueMultiplier /= 100;
        }

        return cardValueSum;
    }

    bool isRoyalFlush()
    {
        if (isStraightFlush())
        {
            return cards[0][0] == 'A';
        }
        return false;
    }

    bool isStraightFlush()
    {
        return isStraight() && isFlush();
    }

    int isFourOfAKind()
    {
        for (int i = 0; i < 2; i++)
        {
            if (cards[i][0] == cards[i+1][0] && cards[i][0] == cards[i+2][0] && cards[i][0] == cards[i+3][0])
            {
                return valueOf(cards[i][0]);
            }
        }
        return false;
    }

    int isFullHouse()
    {
        if (cards[0][0] == cards[1][0] && cards[3][0] == cards[4][0] && (cards[2][0] == cards[0][0] || cards[2][0] == cards[4][0]))
        {
            return valueOf(cards[2][0]);
        }
        return false;
    }

    bool isFlush()
    {
        return cards[0][1] == cards[1][1] && cards[0][1] == cards[2][1] && cards[0][1] == cards[3][1] && cards[0][1] == cards[4][1];
    }

    bool isStraight()
    {
        for (int i = 0; i < 4; i++)
        {
            switch (cards[i][0])
            {
                case 'A':
                    if (cards[i+1][0] != 'K')
                    {
                        return false;
                    }
                    break;
                case 'K':
                    if (cards[i+1][0] != 'Q')
                    {
                        return false;
                    }
                    break;
                case 'Q':
                    if (cards[i+1][0] != 'J')
                    {
                        return false;
                    }
                    break;
                case 'J':
                    if (cards[i+1][0] != 'T')
                    {
                        return false;
                    }
                    break;
                case 'T':
                    if (cards[i+1][0] != '9')
                    {
                        return false;
                    }
                    break;
                default:
                    if (cards[i][0] != cards[i+1][0] + 1)
                    {
                        return false;
                    }
                    break;
            }
        }
        return true;
    }

    int isThreeOfAKind()
    {
        for (int i = 0; i < 3; i++)
        {
            if (cards[i][0] == cards[i+1][0] && cards[i][0] == cards[i+2][0])
            {
                return valueOf(cards[i][0]);;
            }
        }
        return false;
    }

    int isTwoPair()
    {
        int pairCount = 0;
        int pairValueSum = 0;
        int multiplier = 100;
        for (int i = 0; i < 4; i++)
        {
            if (cards[i][0] == cards[i+1][0])
            {
                pairCount++;
                pairValueSum += valueOf(cards[i][0]) * multiplier;
                multiplier /= 100;
                i++;
            }
        }
        if (pairCount == 2)
        {
            return pairValueSum;
        }
        else
        {
            return false;
        }
    }

    int isPair()
    {
        for (int i = 0; i < 4; i++)
        {
            if (cards[i][0] == cards[i+1][0])
            {
                return valueOf(cards[i][0]);;
            }
        }
        return false;
    }

    long long int rankHand()
    {
        if (isRoyalFlush())
        {
            return 90000;
        }
        if (isStraightFlush())
        {
            return 80000;
        }
        if (isFourOfAKind())
        {
            return 70000 + isFourOfAKind();
        }
        if (isFullHouse())
        {
            return 60000 + isFullHouse();
        }
        if (isFlush())
        {
            return 50000;
        }
        if (isStraight())
        {
            return 40000;
        }
        if (isThreeOfAKind())
        {
            return 30000 + isThreeOfAKind();
        }
        if (isTwoPair())
        {
            return 20000 + isTwoPair();
        }
        if (isPair())
        {
            return 10000 + isPair();
        }

        return 0;
    }

public:
    void setHand(char cards[][2])
    {
        for (int i = 0; i < 5; i++)
        {
            this->cards[i][0] = cards[i][0];
            this->cards[i][1] = cards[i][1];
        }
        sortHand();

        return;
    }

    long long int scoreHand()
    {
        return rankHand() * 10000000000 + sumHand();
    }

};

/******************************************************************************
* Main
******************************************************************************/
int main()
{
    PokerHand hand1, hand2;
    int player1WinCount = 0;

    ifstream fin;
    char filename[] = "p054_poker.txt";

	fin.open(filename);
	if (fin.fail())
	{
		cout << "Error opening file \"" << filename <<"\" for reading." << endl;
		fin.close();
		return false;
	}

    bool setHand1 = true;

	while(!fin.eof())
	{
        char hand[5][2];

        for (int i = 0; i < 5; i++)
        {
		    fin >> hand[i];
        }

        if (setHand1)
        {
            hand1.setHand(hand);
        }
        else
        {
            hand2.setHand(hand);
        }
        setHand1 = !setHand1;

        if (setHand1)
        {
            player1WinCount += hand1.scoreHand() > hand2.scoreHand();
        }
	}

	fin.close();

    cout << player1WinCount;

    return 0;
}