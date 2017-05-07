//  Simple war card game using our stack implementation.
//
//  war.cc
//  card
//
//  Created by Thomas BARRAS on 17-05-04.
//  Copyright © 2017 Exced. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include <iostream>

#include "cardstack.h"

int main(int argc, const char *argv[])
{
    const int player_capacity = 50;               // number of cards of each player
    const int max_capacity = player_capacity * 2; // distribution stack
    const int game_number = 3;                    // number of games played

    // random seed
    srand(time(NULL));

    // distribution stack
    card::CardStack distribution_stack = card::CardStack(max_capacity);
    distribution_stack.fullfillRandom();
    // stack of both players
    card::CardStack stack1 = card::CardStack(player_capacity);
    card::CardStack gain_stack1 = card::CardStack(max_capacity);
    card::CardStack stack2 = card::CardStack(player_capacity);
    card::CardStack gain_stack2 = card::CardStack(max_capacity);

    // games
    for (int game_i = 0; game_i < game_number; game_i++)
    {
        // new game
        distribution_stack.shuffle();
        bool distribution_token = true; // true if player1, false if player2
        // cards distribution
        card::Card card;
        while (!distribution_stack.empty())
        {
            card = distribution_stack.pop();
            distribution_token ? stack1.push(card) : stack2.push(card);
            distribution_token = !distribution_token;
        }

        // game loop
        card::Card card1;
        card::Card card2;
        while (!stack1.empty() && !stack2.empty())
        {
            // cards confrontation
            card1 = stack1.pop();
            card2 = stack2.pop();
            if (card1 == card2)
            { // both players gain his own card
                gain_stack1.push(card1);
                gain_stack2.push(card2);
            }
            else if (card1 < card2)
            { // player2 wins this turn
                gain_stack2.push(card1);
                gain_stack2.push(card2);
            }
            else
            { // player1 wins this turn
                gain_stack1.push(card1);
                gain_stack1.push(card2);
            }
        }

        // score player1
        float score_player1 = 0;
        while (!gain_stack1.empty())
        {
            card1 = gain_stack1.pop();
            score_player1 += card1.score();
            distribution_stack.push(card1);
        }

        // score player2
        float score_player2 = 0;
        while (!gain_stack2.empty())
        {
            card2 = gain_stack2.pop();
            score_player2 += card2.score();
            distribution_stack.push(card2);
        }

        // output winner
        if (score_player1 == score_player2)
        {
            std::cout << "Equality ! Score: " << score_player1 << std::endl;
        }
        else if (score_player1 < score_player2)
        {
            std::cout << "Player2 wins ! Score: " << score_player2 << std::endl;
        }
        else
        {
            std::cout << "Player1 wins ! Score: " << score_player1 << std::endl;
        }

    } // end of game

    return 0;
}