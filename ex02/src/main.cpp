/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 11:12:20 by jmagand           #+#    #+#             */
/*   Updated: 2026/05/18 14:25:01 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>

static void testSubject(MutantStack<int> &mstack)
{
    std::cout << "=== SUBJECT ===" << std::endl;

    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    std::cout << std::endl;
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::stack<int> s(mstack);
    return;
}

static void testCopyConstructor()
{
    std::cout << "\n=== COPY CONSTRUCTOR ===" << std::endl;

    MutantStack<int> original;
    original.push(10);
    original.push(20);
    original.push(30);

    MutantStack<int> copy(original);

    std::cout << "Original size: " << original.size() << std::endl;
    std::cout << "Copy size: " << copy.size() << std::endl;

    MutantStack<int>::iterator it = copy.begin();
    MutantStack<int>::iterator ite = copy.end();
    while (it != ite)
    {
        std::cout << "Copy: " << *it << std::endl;
        ++it;
    }
}

static void testAssignmentOperator()
{
    std::cout << "\n=== ASSIGNMENT OPERATOR ===" << std::endl;

    MutantStack<int> source;
    source.push(100);
    source.push(200);

    MutantStack<int> target;
    target.push(1);
    target = source;

    std::cout << "Target size after assignment: " << target.size() << std::endl;

    MutantStack<int>::iterator it = target.begin();
    MutantStack<int>::iterator ite = target.end();
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
}

static void testReverseIterator()
{
    std::cout << "\n=== REVERSE ITERATOR ===" << std::endl;

    MutantStack<int> mstack;
    mstack.push(1);
    mstack.push(2);
    mstack.push(3);

    MutantStack<int>::reverse_iterator rit = mstack.rbegin();
    MutantStack<int>::reverse_iterator rite = mstack.rend();

    std::cout << "Reverse order:" << std::endl;
    while (rit != rite)
    {
        std::cout << *rit << std::endl;
        ++rit;
    }
    std::cout << "Top: " << mstack.top() << std::endl;
}

static void testConstIterator()
{
    std::cout << "\n=== CONST ITERATOR ===" << std::endl;

    MutantStack<int> mstack;
    mstack.push(42);
    mstack.push(43);
    mstack.push(44);

    const MutantStack<int> &const_ref = mstack;

    MutantStack<int>::const_iterator cit = const_ref.begin();
    MutantStack<int>::const_iterator cite = const_ref.end();

    std::cout << "order:" << std::endl;
    while (cit != cite)
    {
        std::cout << *cit << std::endl;
        ++cit;
    }
    std::cout << "Top: " << mstack.top() << std::endl;
}

int main()
{
    MutantStack<int> mstack;

    testSubject(mstack);
    testCopyConstructor();
    testAssignmentOperator();
    testReverseIterator();
    testConstIterator();

    return 0;
}

// #include <list>
// int main()
// {
//     std::list<int> mstack;
    
//     mstack.push_back(5);
//     mstack.push_back(17);
//     std::cout << mstack.back() << std::endl;
//     mstack.pop_back();
//     std::cout << mstack.size() << std::endl;
    
//     mstack.push_back(3);
//     mstack.push_back(5);
//     mstack.push_back(737);
//     //[...]
//     mstack.push_back(0);
//     std::cout << std::endl;
    
//     std::list<int>::iterator it = mstack.begin();
//     std::list<int>::iterator ite = mstack.end();
//     ++it;
//     --it;
//     while (it != ite)
//     {
//         std::cout << *it << std::endl;
//         ++it;
//     }
    
//     std::stack<int, std::list<int> > s(mstack);
    
//     return 0;
// }