# gobang-vs-AI

用c++编写的五子棋程序，玩家VS电脑，电脑有点弱鸡，策略是在不让玩家赢的前提下选择最可能赢的位置下子，以后考虑用基于统计学习的方式来改进。
完成时间较早，粗糙。代码框架都没搞好。

This is a version written by c++ as player vs AI. I wrote this in 2015 when I first learned programming, so the structure is so poor, and I don't know what machine learning is. I will improve it later, or in the future of my life, including reconstruct the project project and using machine learning to let the AI do better.

This version computer fight play using a strategy that firstly it consider whether the player would win in next round, it will stop the player to win in this round, if the player has no chance to win next round, it will choose a place where five chesses will stand in line to lay up. So it's very easy, achieved by consideration of as more as possible situations.
