#pragma once
#include <deque>
#include <stack>

std::stack<int> superMerge(std::stack<int> s1, std::stack<int> s2);

std::stack<int> putHat(std::stack<int> s1, std::stack<int> s2);

std::queue<int> transformToQ(std::stack<int> s1);

bool isHat(std::stack<int> s1, std::stack<int> s2);

bool balancedP(std::stack<char> q1);

void change(std::stack<int> &s);